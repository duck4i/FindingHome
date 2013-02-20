using System;
using System.ComponentModel;
using System.Xml;
using System.Xml.Schema;
using System.Xml.Serialization;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;
using System.Collections.Generic;
using CustomUITypeEditors;
using System.Drawing.Design;
using System.Windows.Forms;

namespace GLEED2D
{
    public partial class PlayerItem : EntityItem
    {
        public static PlayerItem Instance;        

        public PlayerItem() : base()
        {
            PlayerItem.Instance = this;
        }

        ~PlayerItem() 
        {
            PlayerItem.Instance = null;
        }

        public override string getName(string refCount)
        {
            return "Player";
        }

        public override void load(Microsoft.Xna.Framework.Content.ContentManager cm)
        {
            base.load(cm);
            PlayerItem.Instance = this;            
        }
    }
}
