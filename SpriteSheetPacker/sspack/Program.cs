#region MIT License

/*
 * Copyright (c) 2009-2010 Nick Gravelyn (nick@gravelyn.com), Markus Ewald (cygon@nuclex.org)
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a 
 * copy of this software and associated documentation files (the "Software"), 
 * to deal in the Software without restriction, including without limitation 
 * the rights to use, copy, modify, merge, publish, distribute, sublicense, 
 * and/or sell copies of the Software, and to permit persons to whom the Software 
 * is furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all 
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, 
 * INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A 
 * PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT 
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION 
 * OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE 
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE. 
 * 
 */

#endregion

using System;
using System.Collections.Generic;
using System.Drawing;
using System.IO;
using System.Text.RegularExpressions;
using System.Diagnostics;

namespace sspack
{
	public enum FailCode
	{
		FailedParsingArguments = 1,
		ImageExporter,
		MapExporter,
		NoImages,
		ImageNameCollision,

		FailedToLoadImage,
		FailedToPackImage,
		FailedToCreateImage,
		FailedToSaveImage,
		FailedToSaveMap
	}

    public static class Helper
    {
        public static void RecurseDirs(string dir, ref List<String> dirs)
        {
            //  now iterate trough all subdirs
            DirectoryInfo resInfo = new DirectoryInfo(dir);
            foreach (FileInfo i in resInfo.GetFiles())
            {
                if (i.Extension != ".png")
                    continue;

                //Console.WriteLine("Packing:\t" + i.Name);
                String path = dir + i.Name;
                path = Path.GetFullPath(path);

                if (!File.Exists(path))
                    continue;

                //dirs += "" + path + "\n";
                dirs.Add(path);
            }

            foreach (DirectoryInfo d in resInfo.GetDirectories())
            {
                //Console.WriteLine("Directory:\t" + d.Name);
                RecurseDirs(dir + @"\" + d.Name + @"\", ref dirs);
            }
        }

        public static List<string> GetPNGFilesInDirectory(string dir)
        {
            List<string> o = new List<string>();
            RecurseDirs(dir, ref o);
            return o;
        }

        public static void Write(String str, ConsoleColor c)
        {
            Console.ForegroundColor = c;
            Console.WriteLine(str);
            Console.ResetColor();
        }

        public static void Write(String str)
        {
            Write(str, ConsoleColor.White);
        }

        public static void WriteError(String str)
        {
            Write(str, ConsoleColor.Red);
        }

        public static void WriteSUCCESS(String str)
        {
            Write(str, ConsoleColor.Green);
        }
    }

    public class Partitioner
    {
        int index = 0;

        int filesInitiated = 0;
        int filesCompleted = 0;

        public void Save(Bitmap image, Dictionary<string, Rectangle> map)
        {
            Cocos2DMapExporter cm = new Cocos2DMapExporter();
            PngImageExporter ie = new PngImageExporter();

            String oi = index == 0 ? Program.outImage : Path.GetFileNameWithoutExtension(Program.outImage) + index + Path.GetExtension(Program.outImage);
            String om = index == 0 ? Program.outMap : Path.GetFileNameWithoutExtension(Program.outMap) + index + Path.GetExtension(Program.outMap);            
            
            Program.arguments.image = oi;
            Program.arguments.map = om;

            cm.Save(om, map);
            ie.Save(oi, image);

            Helper.Write("Sheet " + index + " saved to disk!\r\n", ConsoleColor.Cyan);
            ++index;
        }

        //  Recoursive method
        public bool ExportHalf(List<string> files)
        {
            if (files.Count == 0)
            {
                Helper.Write("SKIPPING EMPTY PARTITION");
                return false;
            }

            filesInitiated += files.Count;

            Helper.Write("\r\nStarting new partition (" + filesCompleted + " / " + filesInitiated + "): " + files.Count);

            int half = files.Count / 2;
            List<string> left = new List<string>();
            List<string> right = new List<string>();

            int ind = 0;
            foreach (String file in files)
            {
                if (ind <= half)
                    left.Add(file);
                else
                    right.Add(file);
                ++ind;
            }

            Bitmap outImage;
            Dictionary<string, Rectangle> outMap;

            ImagePacker p = new ImagePacker();
            bool okLeft = p.PackImage(left, Program.pow2, Program.sqrt, Program.maxHeight, Program.maxHeight, Program.split, true, out outImage, out outMap) == 0;
            if (okLeft)
            {
                filesCompleted += left.Count;

                Save(outImage, outMap);
                Helper.WriteSUCCESS("Partition done: " + left.Count + " (LEFT)");
            }
            else
            {
                ExportHalf(left);
            }

            //p = new ImagePacker();            
            bool okRight = p.PackImage(right, Program.pow2, Program.sqrt, Program.maxHeight, Program.maxHeight, Program.split, true, out outImage, out outMap) == 0;
            if (okRight)
            {
                filesCompleted += right.Count;                
                Save(outImage, outMap);

                Helper.WriteSUCCESS("Partition done: " + right.Count + " (RIGHT)");
            }
            else
            {                
                ExportHalf(right);
            }

            return true;
        }

        public bool success() { Helper.Write("\r\n" + filesCompleted + " / " + filesInitiated); return filesCompleted == filesInitiated; }
    }

	public class Program
	{
        public static List<String> PNGFiles;
        public static String outImage = "assetData.png";
        public static String outMap = "assetData.plist";
        public static int maxWidth = 4096;
        public static int maxHeight = maxWidth;
        public static int split = 1;
        public static bool pow2 = true;
        public static bool sqrt = false;   

        public static ProgramArguments arguments;

		static int Main(string[] args)
		{
            if (args.Length != 0)
			    return Launch(args);

            Console.Clear();
            Helper.Write("SpriteSheet Creator makes sprite sheets from directory.", ConsoleColor.Yellow);
            Helper.Write("v.1.0 - @mihailogazda", ConsoleColor.Yellow);
            Helper.Write("Call with /? for help", ConsoleColor.Magenta);

            arguments = new ProgramArguments();
            PNGFiles = Helper.GetPNGFilesInDirectory(@"..\Resources\");

            Helper.WriteSUCCESS("\r\nFound files counted: " + PNGFiles.Count);
         
            Bitmap outputImage;
            Dictionary<string, Rectangle> outputMap;

            //  Pack all in one - try at least
            ImagePacker p = new ImagePacker();            
            int status = p.PackImage(PNGFiles, pow2, sqrt, maxWidth, maxHeight, split, true, out outputImage, out outputMap);
            if (status == 0)
            {
                //  Success
                Cocos2DMapExporter cm = new Cocos2DMapExporter();
                PngImageExporter ie = new PngImageExporter();

                cm.Save(outMap, outputMap);
                ie.Save(outImage, outputImage);

                Helper.WriteSUCCESS("Saved " + outImage + " from first try!");
            }
            else
            {
                Helper.Write("\r\nCannot pack in single try.", ConsoleColor.Yellow);
                
                //  split in two and try that way
                Partitioner part = new Partitioner();
                part.ExportHalf(PNGFiles);

                if (part.success())
                    Helper.WriteSUCCESS("All partitions written.");
                else
                    Helper.WriteError("Not all partitions written.");
            }

            //Console.ReadKey();

#if FALSE   //  catastrophically slow
            //  If package failed do that for all images
            else
            {
                List<string> curr = new List<string>();
                List<string> last = curr;
                int index = 0;

                foreach (String file in PNGFiles)
                {
                    curr.Add(file);
                    Helper.Write("Packing (" + index + "): " + file);

                    p = new ImagePacker();
                    bool ok = p.PackImage(curr, pow2, sqrt, maxWidth, maxHeight, split, true, out outputImage, out outputMap) == 0;
                    if (ok)
                    {
                        last = curr;
                        Helper.Write("OK", ConsoleColor.Gray);
                    }
                    else
                    {
                        Helper.Write("Cannot fit. Making new sheet.", ConsoleColor.Gray);

                        //  failed - pack last good configuration
                        ok = p.PackImage(last, pow2, sqrt, maxWidth, maxHeight, split, true, out outputImage, out outputMap) == 0;
                        curr = new List<string>();
                        last = curr;

                        if (ok)
                        {
                            String oi = index == 0 ? outImage : Path.GetFileNameWithoutExtension(outImage) + index + Path.GetExtension(outImage);
                            String om = index == 0 ? outMap : Path.GetFileNameWithoutExtension(outMap) + index + Path.GetExtension(outMap);

                            cm.Save(om, outputMap);
                            ie.Save(oi, outputImage);

                            index++;
                            Helper.WriteSUCCESS("Success for sheet : " + index + " " + oi);
                        }
                        else
                            Helper.WriteError("Error for sheet : " + index);
                    }
                }
            }
#endif

            return 0;
		}

		public static int Launch(string[] args)
		{
			//ProgramArguments arguments = ProgramArguments.Parse(args);
            arguments = ProgramArguments.Parse(args);

            if (arguments == null)
            {
                Console.WriteLine("Invalid params");
                return (int)FailCode.FailedParsingArguments;
            }
                                    
            // make sure we have our list of exporters
            Exporters.Load();

            // try to find matching exporters
            IImageExporter imageExporter = null;
            IMapExporter mapExporter = null;

            string imageExtension = Path.GetExtension(arguments.image).Substring(1).ToLower();
            foreach (var exporter in Exporters.ImageExporters)
            {
                if (exporter.ImageExtension.ToLower() == imageExtension)
                {
                    imageExporter = exporter;
                    break;
                }
            }

            if (imageExporter == null)
            {
                Console.WriteLine("Failed to find exporters for specified image type.");
                return (int)FailCode.ImageExporter;
            }

            if (!string.IsNullOrEmpty(arguments.map))
            {
                string mapExtension = Path.GetExtension(arguments.map).Substring(1).ToLower();
                foreach (var exporter in Exporters.MapExporters)
                {
                    if (exporter.MapExtension.ToLower() == mapExtension)
                    {
                        mapExporter = exporter;
                        break;
                    }
                }

                if (mapExporter == null)
                {
                    Console.WriteLine("Failed to find exporters for specified map type.");
                    return (int)FailCode.MapExporter;
                }
            }

            // compile a list of images
            List<string> images = new List<string>();
            FindImages(arguments, images);

            // make sure we found some images
            if (images.Count == 0)
            {
                Console.WriteLine("No images to pack.");
                return (int)FailCode.NoImages;
            }

            // make sure no images have the same name if we're building a map
            if (mapExporter != null)
            {
                for (int i = 0; i < images.Count; i++)
                {
                    string str1 = Path.GetFileNameWithoutExtension(images[i]);

                    for (int j = i + 1; j < images.Count; j++)
                    {
                        string str2 = Path.GetFileNameWithoutExtension(images[j]);

                        if (str1 == str2)
                        {
                            Console.WriteLine("Two images have the same name: {0} = {1}", images[i], images[j]);
                            return (int)FailCode.ImageNameCollision;
                        }
                    }
                }
            }

            // generate our output
            ImagePacker imagePacker = new ImagePacker();
            Bitmap outputImage;
            Dictionary<string, Rectangle> outputMap;

            // pack the image, generating a map only if desired
            int result = imagePacker.PackImage(images, arguments.pow2, arguments.sqr, arguments.mw, arguments.mh, arguments.pad, mapExporter != null, out outputImage, out outputMap);
            if (result != 0)
            {
                //  place error
                Console.WriteLine("There was an error making the image sheet.");
                FailCode f = (FailCode)result;
                Console.WriteLine("Error: " + f.ToString());
                return result;
            }

            // try to save using our exporters
            try
            {
                if (File.Exists(arguments.image))
                    File.Delete(arguments.image);
                imageExporter.Save(arguments.image, outputImage);
            }
            catch (Exception e)
            {
                Console.WriteLine("Error saving file: " + e.Message);
                return (int)FailCode.FailedToSaveImage;
            }

            if (mapExporter != null)
            {
                try
                {
                    if (File.Exists(arguments.map))
                        File.Delete(arguments.map);
                    mapExporter.Save(arguments.map, outputMap);
                }
                catch (Exception e)
                {
                    Console.WriteLine("Error saving file: " + e.Message);
                    return (int)FailCode.FailedToSaveMap;
                }
            }            
                
                


			

			return 0;
		}

		private static void FindImages(ProgramArguments arguments, List<string> images)
		{
			List<string> inputFiles = new List<string>();

			if (!string.IsNullOrEmpty(arguments.il))
			{
				using (StreamReader reader = new StreamReader(arguments.il))
				{
					while (!reader.EndOfStream)
					{
						inputFiles.Add(reader.ReadLine());
					}
				}
			}

			if (arguments.input != null)
			{
				inputFiles.AddRange(arguments.input);
			}

			foreach (var str in inputFiles)
			{
				if (MiscHelper.IsImageFile(str))
				{
					images.Add(str);
				}
			}
		}
	}
}
