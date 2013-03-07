using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Text;
using System.Threading.Tasks;

namespace ResourcePacker
{
    class Program
    {

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

                //dirs += " " + '"' + path + '"';
                dirs += " " + path + "\n";
            }

            foreach (DirectoryInfo d in resInfo.GetDirectories())
            {
                Console.WriteLine("Directory:\t" + d.Name);
                RecurseDirs(dir + @"\" + d.Name + @"\", ref dirs);
            }
        }

        static void Main(string[] args)
        {
            Console.WriteLine("Resource Packer 1.0");
            

            //String pf86 = Environment.GetFolderPath(Environment.SpecialFolder.ProgramFilesX86);
            String path = @"..\Utils\sspack.exe";
            String generatedInput = "input.data";
            String outData = "assetData.txt";
            String outImage = "assetData.png";

            if (!File.Exists(path))
            {
                Console.WriteLine("Cannot find TexturePacker\r\n" + path + "\r\n");
                return;
            }

            Console.WriteLine("Found TexturePacker!\r\nStarting!");

            int maxWidth = 4096;
            int maxHeight = 4096;
            String param = @"/il:" + generatedInput +" /map:" + outData + " /image:" + outImage + " /mw:" + maxWidth + " /mh:" + maxHeight;
            param += @" /pow2 /sqr";

            String dirs = "";

            String dir = Directory.GetCurrentDirectory();
            dir = Path.Combine(dir, @"..\Resources\");
            dir = Path.GetFullPath(dir);

            //if (!Directory.Exists(dir))
            //{
            //    Console.WriteLine("Cannot find resources directory at:\r\n" + dir + "\r\n");
            //    return;
            //}

            //  now remove old instances
            File.Delete(outData);
            File.Delete(outImage);

            RecurseDirs(dir, ref dirs);
            System.IO.File.WriteAllText(generatedInput, dirs);
            
            Console.WriteLine(dirs);
            //param += " " + dirs;

            try
            {
                ProcessStartInfo info = new ProcessStartInfo() ;
                info.Arguments = param;
                info.CreateNoWindow = true;
                info.FileName = path;
                //info.WorkingDirectory = dir;
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
                if (File.Exists(dir + outData) && File.Exists(dir + outImage))
                    success = true;
                
                Console.WriteLine("\r\nDONE!");

                Console.ForegroundColor = success ? ConsoleColor.Green : ConsoleColor.Red;

                Console.WriteLine(success ? "SUCCESS" : "FAILURE");
                Console.ResetColor();

                Console.Read();

            }
            catch (Exception)
            {
                Console.WriteLine("Could not start TexturePacker");
            }
        }

    }
}
