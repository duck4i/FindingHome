using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Text;
using System.Drawing;

namespace ResourcePacker
{
    class Program
    {
        static String packerInputFile = "assetdata.dat";
        static String packerImageFile = "assetdata.png";
        static String packerMapFile = "assetdata.plist";

        static String   packerPath = @"sspack.exe";
        static int      maxWidth = 4096;
        static int      maxHeight = 4096;
        static int padding = 1;
        
        static bool requireSquare = false;
        static bool requirePow2 = true;
        static int outputWidth = maxWidth;
        static int outputHeight = maxHeight;
        

        /// <summary>
        /// Gets the dimensions of an image.
        /// </summary>
        /// <param name="path">The path of the image to get the dimensions of.</param>
        /// <returns>The dimensions of the specified image.</returns>
        /// <exception cref="ArgumentException">The image was of an unrecognised format.</exception>
        public static Size GetDimensions(string path)
        {
            try
            {
                using (FileStream stream = new FileStream(path, FileMode.Open, FileAccess.Read))
                {
                    using (Image tif = Image.FromStream(stream, false, false))
                    {
                        float width = tif.PhysicalDimension.Width;
                        float height = tif.PhysicalDimension.Height;
                        return new Size((int)width, (int)height);
                    }
                }
            }
            catch (Exception) { }
            return new Size(0, 0);
        }

        static void RecurseDirs(string dir, ref string dirs)
        {
            //  now iterate trough all subdirs
            DirectoryInfo resInfo = new DirectoryInfo(dir);
            foreach (FileInfo i in resInfo.GetFiles())
            {
                if (i.Extension != ".png")
                    continue;

                Console.WriteLine("Packing:\t" + i.Name);
                String path = dir + i.Name;
                path = Path.GetFullPath(path);
                
                if (!File.Exists(path))
                    continue;

                dirs += "" + path + "\n";
            }

            foreach (DirectoryInfo d in resInfo.GetDirectories())
            {
                Console.WriteLine("Directory:\t" + d.Name);
                RecurseDirs(dir + @"\" + d.Name + @"\", ref dirs);
            }
        }

        static string GetPNGFilesInDirectory(string dir)
        {
            string o = "";
            RecurseDirs(dir, ref o);
            return o;
        }

        /// <summary>
        /// Gets list of files sorted by file sizes, from biggest to smallest.
        /// </summary>
        /// <param name="list"></param>
        /// <returns></returns>
        static List<string> GetSortedListFromPNGs(string list)
        {
            string[] ar = list.Split('\n');
            List<string> o = new List<string>();

            foreach (String s in ar)
                if (s.Length > 0)
                    o.Add(s);

            o.Sort(
                (f1, f2) =>
                {
                    Size s1 = GetDimensions(f1);
                    Size s2 = GetDimensions(f2);

                    if (s1 == s2)
                        return 0;

                    int surface1 = s1.Width * s1.Height;
                    int surface2 = s2.Width * s2.Height;

                    if (surface1 > surface2)
                        return -1;
                    else if (surface1 < surface2)
                        return 1;

                    return 0;
                });

            return o;
        }

        /*
        private bool TestPackingImages(int testWidth, int testHeight, Dictionary<string, Rectangle> testImagePlacement, List<String> files)
        {
            // create the rectangle packer
            ArevaloRectanglePacker rectanglePacker = new ArevaloRectanglePacker(testWidth, testHeight);

            foreach (var image in files)
            {
                // get the bitmap for this file
                Size size = imageSizes[image];

                // pack the image
                Point origin;
                if (!rectanglePacker.TryPack(size.Width + padding, size.Height + padding, out origin))
                {
                    return false;
                }

                // add the destination rectangle to our dictionary
                testImagePlacement.Add(image, new Rectangle(origin.X, origin.Y, size.Width + padding, size.Height + padding));
            }

            return true;
        }

        // This method does some trickery type stuff where we perform the TestPackingImages method over and over, 
        // trying to reduce the image size until we have found the smallest possible image we can fit.
        private bool PackImageRectangles()
        {
            // create a dictionary for our test image placements
            Dictionary<string, Rectangle> testImagePlacement = new Dictionary<string, Rectangle>();

            // get the size of our smallest image
            int smallestWidth = int.MaxValue;
            int smallestHeight = int.MaxValue;
            foreach (var size in imageSizes)
            {
                smallestWidth = Math.Min(smallestWidth, size.Value.Width);
                smallestHeight = Math.Min(smallestHeight, size.Value.Height);
            }

            // we need a couple values for testing
            int testWidth = outputWidth;
            int testHeight = outputHeight;

            bool shrinkVertical = false;

            // just keep looping...
            while (true)
            {
                // make sure our test dictionary is empty
                testImagePlacement.Clear();

                // try to pack the images into our current test size
                if (!TestPackingImages(testWidth, testHeight, testImagePlacement))
                {
                    // if that failed...

                    // if we have no images in imagePlacement, i.e. we've never succeeded at PackImages,
                    // show an error and return false since there is no way to fit the images into our
                    // maximum size texture
                    if (imagePlacement.Count == 0)
                        return false;

                    // otherwise return true to use our last good results
                    if (shrinkVertical)
                        return true;

                    shrinkVertical = true;
                    testWidth += smallestWidth + padding + padding;
                    testHeight += smallestHeight + padding + padding;
                    continue;
                }

                // clear the imagePlacement dictionary and add our test results in
                imagePlacement.Clear();
                foreach (var pair in testImagePlacement)
                    imagePlacement.Add(pair.Key, pair.Value);

                // figure out the smallest bitmap that will hold all the images
                testWidth = testHeight = 0;
                foreach (var pair in imagePlacement)
                {
                    testWidth = Math.Max(testWidth, pair.Value.Right);
                    testHeight = Math.Max(testHeight, pair.Value.Bottom);
                }

                // subtract the extra padding on the right and bottom
                if (!shrinkVertical)
                    testWidth -= padding;
                testHeight -= padding;

                // if we require a power of two texture, find the next power of two that can fit this image
                if (requirePow2)
                {
                    testWidth = MiscHelper.FindNextPowerOfTwo(testWidth);
                    testHeight = MiscHelper.FindNextPowerOfTwo(testHeight);
                }

                // if we require a square texture, set the width and height to the larger of the two
                if (requireSquare)
                {
                    int max = Math.Max(testWidth, testHeight);
                    testWidth = testHeight = max;
                }

                // if the test results are the same as our last output results, we've reached an optimal size,
                // so we can just be done
                if (testWidth == outputWidth && testHeight == outputHeight)
                {
                    if (shrinkVertical)
                        return true;

                    shrinkVertical = true;
                }

                // save the test results as our last known good results
                outputWidth = testWidth;
                outputHeight = testHeight;

                // subtract the smallest image size out for the next test iteration
                if (!shrinkVertical)
                    testWidth -= smallestWidth;
                testHeight -= smallestHeight;
            }
        }
        */

        static List<List<String>> GetSheetsFromList(List<String> list)
        {
            List<List<String>> o = new List<List<String>>();
            float maxSurface = maxWidth * maxHeight;
            float separator = 1;  // 1px

            List<String> curr = new List<String>();
            float currSurface = 0;           
            foreach (String s in list)
            {
                Size ss = GetDimensions(s);
                float ssurf = (ss.Width + separator) * (ss.Height + separator);

                if (currSurface + ssurf >= maxSurface)
                {                    
                    o.Add(curr);                    
                    currSurface = 0;
                    curr = new List<string>();
                }
                else
                {
                    curr.Add(s);
                    currSurface += ssurf;
                }
            }

            //  elements exist that are not in the list
            if (curr.Count > 0)
                o.Add(curr);

            return o;
        }

        static bool StartPacker(string infile, string outfile, string outmapfile)
        {

            String param = @"/il:" + infile + " /map:" + outmapfile + " /image:" + outfile + " /mw:" + maxWidth + " /mh:" + maxHeight;
            param += (requirePow2 ? " /pow2" : "") + (requireSquare ? " /sqr" : "");

            try
            {
                ProcessStartInfo info = new ProcessStartInfo();
                info.Arguments = param;
                info.CreateNoWindow = true;
                info.FileName = packerPath;                
                info.WorkingDirectory = Directory.GetCurrentDirectory();
                info.RedirectStandardOutput = true;
                info.UseShellExecute = false;

                Console.WriteLine();
                Process proc = Process.Start(info);
                while (!proc.StandardOutput.EndOfStream)
                {
                    string line = proc.StandardOutput.ReadLine();
                    Console.WriteLine(line);
                }

                bool success = false;
                if (File.Exists(outfile) && File.Exists(outmapfile))
                    success = true;

                Console.ForegroundColor = success ? ConsoleColor.Green : ConsoleColor.Red;
                Console.WriteLine((success ? "SUCCESS" : "FAILURE") + ":\t" + infile);
                Console.ResetColor();

                return success;
            }
            catch (Exception) { }
            return false;
        }

        static void Main(string[] args)
        {
            Console.WriteLine("Resource Packer 1.0");

            if (!File.Exists(packerPath))
            {
                Console.WriteLine("Cannot find TexturePacker\r\n" + packerPath + "\r\n");
                return;
            }

            Console.WriteLine("Found TexturePacker!\r\nStarting!");

            //  calculate files needed and create lists
            String dir = Directory.GetCurrentDirectory();
            dir = Path.Combine(dir, @"..\Resources\");
            dir = Path.GetFullPath(dir);

            String files = GetPNGFilesInDirectory(dir);
            List<String> fileList = GetSortedListFromPNGs(files);

            //  Get SpriteSheet lists from 
            List<List<String>> sheetLists = GetSheetsFromList(fileList);

            //  pack each list
            if (sheetLists.Count == 0)
            {
                Console.WriteLine("Resource Packer found 0 sheets to pack");                
            }
            else if (sheetLists.Count == 1)
            {
                File.Delete(packerInputFile);
                File.Delete(packerImageFile);
                File.Delete(packerMapFile);

                String cs = String.Join("\n", sheetLists[0].ToArray());
                File.WriteAllText(packerInputFile, cs);
                bool ok = StartPacker(packerInputFile, packerImageFile, packerMapFile);
            }
            else
            {
                int counter = 0;
                foreach (List<String> sheet in sheetLists)
                {
                    String infile = Path.GetFileNameWithoutExtension(packerInputFile) + counter + Path.GetExtension(packerInputFile);
                    String outfile = Path.GetFileNameWithoutExtension(packerImageFile) + counter + Path.GetExtension(packerImageFile);
                    String outmapfile = Path.GetFileNameWithoutExtension(packerMapFile) + counter + Path.GetExtension(packerMapFile);

                    File.Delete(infile);
                    File.Delete(outfile);
                    File.Delete(outmapfile);

                    String cs = String.Join("\n", sheet.ToArray());
                    File.WriteAllText(infile, cs);

                    bool ok = StartPacker(infile, outfile, outmapfile);

                    ++counter;
                }
            }


            //RecurseDirs(dir, ref dirs);
            //System.IO.File.WriteAllText(generatedInput, files);
            
            //Console.WriteLine(dirs);
            //param += " " + dirs;

            Console.WriteLine("\r\nDONE!");
            /*
            Console.ForegroundColor = success ? ConsoleColor.Green : ConsoleColor.Red;
            Console.WriteLine(success ? "SUCCESS" : "FAILURE");
            Console.ResetColor();
            */
            Console.Read();
        }

    }
}
