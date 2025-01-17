﻿using System;
using System.Collections.Generic;
using System.IO;
using System.Xml;
using System.Xml.Serialization;
using Forms = System.Windows.Forms;
using System.ComponentModel;
using System.Text;
using System.Drawing.Design;
using System.Windows.Forms;
using CustomUITypeEditors;
using Microsoft.Xna.Framework;

namespace GLEED2D
{    
    public partial class Level
    {
        [XmlIgnore()]
        public string selectedlayers;
        [XmlIgnore()]
        public string selecteditems;

        public class EditorVars
        {
            public int NextItemNumber;
            public string ContentRootFolder;
            public Vector2 CameraPosition;
            public string Version;
        }

        [XmlIgnore()]
        [Category(" General")]
        [Description("When the level is saved, each texture is saved with a path relative to this folder."
                     + "You should set this to the \"Content.RootDirectory\" of your game project.")]
        [EditorAttribute(typeof(FolderUITypeEditor), typeof(System.Drawing.Design.UITypeEditor))]
        public String ContentRootFolder
        {
            get
            {
                return EditorRelated.ContentRootFolder;
            }
            set
            {
                EditorRelated.ContentRootFolder = value;
            }
        }

        [XmlIgnore()]
        [DisplayName("Weather Enabled"), Category(" Level Settings"), Description("Controls Weather system. Disable for indoor levels to improve speed.")]
        public bool pWeatherEnabled
        {
            get { return WeatherActive; }
            set { WeatherActive = value; }
        }

        [XmlIgnore()]
        [DisplayName("Scene Zoom"), Category(" Level Settings"), Description("Controls how close camera is to the player.")]
        public float pCameraZoom
        {
            get { return CameraZoom; }
            set { CameraZoom = value; }
        }

        [XmlIgnore()]
        [DisplayName("Forward Thrust"), Category(" Player Settings"), Description("(D: 25.0) Forward trhust force on player.")]
        public float pPlayerThrust
        {
            get { return PlayerThrust; }
            set { PlayerThrust = value; }
        }

        [XmlIgnore()]
        [DisplayName("Jump Height"), Category(" Player Settings"), Description("(D: 280.0) Jump height setting for player.")]
        public float pPlayerJump
        {
            get { return PlayerJump; }
            set { PlayerJump = value; }
        }

        [XmlIgnore()]
        [DisplayName("Max Speed"), Category(" Player Settings"), Description("(D: 10.0) Maximum speed of the player.")]
        public float pPlayerMaxSpeed
        {
            get { return PlayerMaxSpeed; }
            set { PlayerMaxSpeed = value; }
        }

        [XmlIgnore()]
        [DisplayName("Shift Modifier"), Category(" Player Settings"), Description("(D: 1.45) Multiplies jump and speed values.")]
        public float pShiftModifier
        {
            get { return PlayerShiftModifier; }
            set { PlayerShiftModifier = value; }
        }


        [XmlIgnore()]
        [DisplayName("In Air Modifier"), Category(" Player Settings"), Description("(D: 0.3) Multiplies speed values when player mid air.")]
        public float pMidAirModifier
        {
            get { return PlayerMidAirModifier; }
            set { PlayerMidAirModifier = value; }
        }     

        EditorVars editorrelated = new EditorVars();
        [Browsable(false)]
        public EditorVars EditorRelated
        {
            get
            {
                return editorrelated;
            }
            set
            {
                editorrelated = value;
            }
        }

        [XmlIgnore()]
        public Forms.TreeNode treenode;


        public string getNextItemNumber()
        {
            return (++EditorRelated.NextItemNumber).ToString("0000");
        }


        public void export(string filename)
        {
            foreach (Layer l in Layers)
            {
                foreach (Item i in l.Items)
                {
                    if (i is TextureItem)
                    {
                        TextureItem ti = (TextureItem)i;
                        ti.texture_filename = RelativePath(ContentRootFolder, ti.texture_fullpath);
                        //ti.asset_name = ti.texture_filename.Substring(0, ti.texture_filename.LastIndexOf('.'));
                        
                        int lastDirSpearator = ti.texture_filename.LastIndexOf(@"\");
                        if (lastDirSpearator != -1)
                        {
                            lastDirSpearator++;
                            ti.asset_name = ti.asset_name = ti.texture_filename.Substring(lastDirSpearator, ti.texture_filename.Length - lastDirSpearator);
                        }
                        else
                            ti.asset_name = ti.texture_filename;
                        
                    }
                }
            }


            XmlTextWriter writer = new XmlTextWriter(filename, null);
            writer.Formatting = Formatting.Indented;
            writer.Indentation = 4;

            XmlSerializer serializer = new XmlSerializer(typeof(Level));
            serializer.Serialize(writer, this);

            writer.Close();

        }



        public string RelativePath(string relativeTo, string pathToTranslate)
        {
            /*
            string[] absoluteDirectories = relativeTo.Split('\\');
            string[] relativeDirectories = pathToTranslate.Split('\\');

            //Get the shortest of the two paths
            int length = absoluteDirectories.Length < relativeDirectories.Length ? absoluteDirectories.Length : relativeDirectories.Length;

            //Use to determine where in the loop we exited
            int lastCommonRoot = -1;
            int index;

            //Find common root
            for (index = 0; index < length; index++)
                if (absoluteDirectories[index] == relativeDirectories[index])
                    lastCommonRoot = index;
                else
                    break;

            //If we didn't find a common prefix then throw
            if (lastCommonRoot == -1)
                // throw new ArgumentException("Paths do not have a common base");
                return pathToTranslate;

            //Build up the relative path
            StringBuilder relativePath = new StringBuilder();

            //Add on the ..
            for (index = lastCommonRoot + 1; index < absoluteDirectories.Length; index++)
                if (absoluteDirectories[index].Length > 0) relativePath.Append("..\\");

            //Add on the folders
            for (index = lastCommonRoot + 1; index < relativeDirectories.Length - 1; index++)
                relativePath.Append(relativeDirectories[index] + "\\");

            relativePath.Append(relativeDirectories[relativeDirectories.Length - 1]);

            return relativePath.ToString();
             */

            String basePath = Path.GetFullPath(relativeTo);
            String destPath = Path.GetFullPath(pathToTranslate);

            Uri origin = new Uri(basePath);
            Uri path = new Uri(destPath);
            
            string ret = origin.MakeRelative(path);
            ret = ret.Replace(@"/", @"\");

            return ret;
        }








    }








}
