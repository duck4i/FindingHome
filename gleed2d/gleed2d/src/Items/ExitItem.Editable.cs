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
    public partial class ExitItem : EntityItem
    {
        [XmlIgnore()]
        [DisplayName("Width"), Category(" General"), Description("Width of Exit entity range.")]
        public float pWidth
        {
            set { Width = value; }
            get { return Width; }
        }

        [XmlIgnore()]
        [DisplayName("Height"), Category(" General"), Description("Height of Exit entity range.")]
        public float pHeight
        {
            set { Height = value; }
            get { return Height; }
        }

        [XmlIgnore()]
        [DisplayName("Next level"), Category(" Exit condition"), Description("Enter the filename (unquoted and without the path, e.g. Level4.xml) of level to load.")]
        public string pNextLevel
        {
            set { NextLevel = value; }
            get { return NextLevel; }
        }

        [XmlIgnore()]
        [DisplayName("Scale"), Category(" General"), Description("Scale for exit condition, affects size")]
        public Vector2 pScale
        {
            set { Scale = value; }
            get { return Scale; }
        }

        public ExitItem() : base()
        {
            NextLevel = "";
            pScale = new Vector2(1, 1);
            
            Width = shapeWidth;
            Height = shapeHeight;
        }

        public override string getNamePrefix()
        {
            return "Exit_";
        }
        
        public override void drawInEditor(SpriteBatch sb)
        {
            Rectangle rc = new Rectangle((int) Position.X, (int) Position.Y, (int) (Width * pScale.X), (int) (Height * pScale.Y));
            Color c = hovering ? hoverShapeColor : Color.DarkGray;
            c.A = 150;
            
            Primitives.Instance.drawBoxFilled(sb, rc, c);

            drawStringInCenter(sb, Name, rc);
        }

        public override void drawSelectionFrame(SpriteBatch sb, Matrix matrix, Color color)
        {
            Rectangle rc = new Rectangle((int)Position.X, (int)Position.Y, (int) (Width * pScale.X), (int) (Height * pScale.Y));
            Primitives.Instance.drawBox(sb, rc.Transform(matrix), color, 4);
        }

        public override bool contains(Vector2 worldpos)
        {
            Rectangle rc = new Rectangle((int)Position.X, (int)Position.Y, (int) (Width * pScale.X), (int) (Height * pScale.Y));
            return rc.Contains((int) worldpos.X, (int) worldpos.Y);
        }

        public override bool CanScale()
        {
            return true;
        }

        public override void setScale(Vector2 scale)
        {
            pScale = scale;
        }

        public override Vector2 getScale()
        {
            return pScale;
        }
        
    }
}
