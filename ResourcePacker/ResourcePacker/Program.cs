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

                dirs += " " + '"' + path + '"';
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
            

            String pf86 = Environment.GetFolderPath(Environment.SpecialFolder.ProgramFilesX86);
            String path = pf86 + @"\CodeAndWeb\TexturePacker\bin\TexturePacker.exe";
            String outData = "assetData.plist";
            String outImage = "assetData.png";

            if (!File.Exists(path))
            {
                Console.WriteLine("Cannot find TexturePacker\r\n" + path + "\r\n");
                return;
            }

            Console.WriteLine("Found TexturePacker!\r\nStarting!");

            String param = @" --data " + outData + " --sheet " + outImage;
            param += @" --max-size 8192 --format cocos2d --algorithm Basic --trim-mode None";

            String dirs = "";

            String dir = Directory.GetCurrentDirectory();
            dir = Path.Combine(dir, @"..\Resources\");
            dir = Path.GetFullPath(dir);

            if (!Directory.Exists(dir))
            {
                Console.WriteLine("Cannot find resources directory at:\r\n" + dir + "\r\n");
                return;
            }

            //  now remove old instances
            File.Delete(dir + outData);
            File.Delete(dir + outImage);


            RecurseDirs(dir, ref dirs);

            //Console.WriteLine(dirs);
            param += " " + dirs;

            try
            {
                ProcessStartInfo info = new ProcessStartInfo() ;
                info.Arguments = param;
                info.CreateNoWindow = true;
                info.FileName = path;
                info.WorkingDirectory = dir;
                info.RedirectStandardOutput = true;
                info.UseShellExecute = false;

                Console.WriteLine();
                Process proc = Process.Start(info);
                while (!proc.StandardOutput.EndOfStream)
                {
                    string line = proc.StandardOutput.ReadLine();
                    Console.WriteLine(line);
                }
                Console.WriteLine("\r\nDONE!");    
            }
            catch (Exception)
            {
                Console.WriteLine("Could not start TexturePacker");
            }
        }

    }
}
