using System.Collections.Generic;
using System.Drawing;
using System.IO;
using System;

namespace sspack
{
    public class Cocos2DMapExporter : IMapExporter
    {
        public string MapExtension
        {
            get { return "plist"; }
        }

        public void Save(string filename, Dictionary<string, Rectangle> map)
        {
            // copy the files list and sort alphabetically
            string[] keys = new string[map.Count];
            map.Keys.CopyTo(keys, 0);
            List<string> outputFiles = new List<string>(keys);
            outputFiles.Sort();

            using (StreamWriter writer = new StreamWriter(filename))
            {
                //  OPEN_DOCUMENT - form header
                writer.WriteLine("<?xml version=\"1.0\" encoding=\"UTF-8\"?>");
                writer.WriteLine("<!DOCTYPE plist PUBLIC \"-//Apple Computer//DTD PLIST 1.0//EN\" \"http://www.apple.com/DTDs/PropertyList-1.0.dtd\">");
                writer.WriteLine("<plist version=\"1.0\">");
                writer.WriteLine("\t<dict>");

                //  OPEN_ASSETS
                writer.WriteLine("\t\t<key>frames</key>");                
                writer.WriteLine("\t\t<dict>");

                foreach (var image in outputFiles)
                {
                    // get the destination rectangle
                    Rectangle destination = map[image];

                    /*
                     *
                        <dict>
                            <key>frame</key>
                            <string>{{707,0},{101,171}}</string>
                            <key>offset</key>
                            <string>{0,0}</string>
                            <key>rotated</key>
                            <false/>
                            <key>sourceColorRect</key>
                            <string>{{0,0},{101,171}}</string>
                            <key>sourceSize</key>
                            <string>{101,171}</string>
                        </dict>
                     **/

                    // write out the destination rectangle for this bitmap
                    writer.WriteLine("\t\t\t<key>" + Path.GetFileName(image) + "</key>");
                    writer.WriteLine("\t\t\t<dict>");

                    int ox = 0;
                    int oy = 0;
                    int x = destination.X;
                    int y = destination.Y;
                    int w = destination.Width;
                    int h = destination.Height;

                    writer.WriteLine("\t\t\t\t<key>frame</key>");
                    writer.WriteLine("\t\t\t\t<string>{{" + x + "," + y + "},{" + w + "," + h + "}}</string>");

                    writer.WriteLine("\t\t\t\t<key>offset</key>");
                    writer.WriteLine("\t\t\t\t<string>{" + ox + "," + oy + "}</string>");

                    writer.WriteLine("\t\t\t\t<key>sourceColorRect</key>");
                    writer.WriteLine("\t\t\t\t<string>{{" + ox + "," + oy + "},{" + w + "," + h + "}}</string>");

                    writer.WriteLine("\t\t\t\t<key>sourceSize</key>");
                    writer.WriteLine("\t\t\t\t<string>{" + w + "," + h + "}</string>");

                    writer.WriteLine("\t\t\t\t<key>rotated</key>");
                    writer.WriteLine("\t\t\t\t<false/>");

                    writer.WriteLine("\t\t\t</dict>");

                }// endforeach

                //  CLOSE_ASSETS
                writer.WriteLine("\t\t</dict>");


                //  START_METADATA
                //  metadata
                /*
                    <key>metadata</key>
                    <dict>
                        <key>format</key>
                        <integer>2</integer>
                        <key>realTextureFileName</key>
                        <string>frogger.png</string>
                        <key>size</key>
                        <string>{512,1024}</string>
                        <key>smartupdate</key>
                        <string>$TexturePacker:SmartUpdate:794d137ee473c8fffc3af024827b24a0$</string>
                        <key>textureFileName</key>
                        <string>frogger.png</string>
                    </dict>
                 */
                writer.WriteLine("\t\t<key>metadata</key>");
                writer.WriteLine("\t\t<dict>");

                writer.WriteLine("\t\t\t<key>format</key>");
                writer.WriteLine("\t\t\t<integer>2</integer>");

                writer.WriteLine("\t\t\t<key>realTextureFileName</key>");
                writer.WriteLine("\t\t\t<string>" + Program.arguments.image + "</string>");

                writer.WriteLine("\t\t\t<key>textureFileName</key>");
                writer.WriteLine("\t\t\t<string>" + Program.arguments.image + "</string>");

                Size s = GetDimensions(Program.arguments.image);
                int width = s.Width;
                int height = s.Height;

                writer.WriteLine("\t\t\t<key>size</key>");
                writer.WriteLine("\t\t\t<string>{" + width + "," + height + "}</string>");

                writer.WriteLine("\t\t</dict>");
                //  END_METADATA

                //  CLOSE_DOCUMENT
                writer.WriteLine("\t</dict>");                
                writer.WriteLine("</plist>");
            }
        }

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
                        float hresolution = tif.HorizontalResolution;
                        float vresolution = tif.VerticalResolution;

                        return new Size((int)width, (int)height);
                    }
                }
            }
            catch (Exception ) { }
            return new Size(0, 0);
        }
    }
}
