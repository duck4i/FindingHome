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
    public partial class EntityItem : Item
    {
        
        [XmlIgnore()]
        protected const int shapeWidth = 100;

        [XmlIgnore()]
        protected const int shapeHeight = 100;
        

        [XmlIgnore()]
        protected Color fontColor;

        [XmlIgnore()]
        protected Color shapeColor;

        [XmlIgnore()]
        protected Color hoverShapeColor;

        public EntityItem() : base()
        {
            fontColor = Color.Navy;
            shapeColor = Color.LightGray;
            hoverShapeColor = Color.Red;
        }

        public override Item clone()
        {
            EntityItem res = (EntityItem)MemberwiseClone();
            res.CustomProperties = new SerializableDictionary(CustomProperties);
            res.hovering = false;
            return res;
        }

        public override bool CanRotate()
        {
            return false;
        }

        public override bool CanScale()
        {
            return false;
        }

        public override Rectangle getBoundingBox()
        {
            return new Rectangle(0, 0, shapeWidth, shapeHeight);
        }

        public override void drawInEditor(SpriteBatch sb)
        {
            if (!Visible)
                return;

            Rectangle rc = new Rectangle((int)Position.X, (int)Position.Y, shapeWidth, shapeHeight);

            //  draw shape
            Primitives.Instance.drawBoxFilled(sb, rc, hovering ? hoverShapeColor : shapeColor);

            drawStringInCenter(sb, Name, rc);
        }

        public override void drawSelectionFrame(SpriteBatch sb, Matrix matrix, Color color)
        {
            Rectangle rc = new Rectangle((int)Position.X, (int)Position.Y, shapeWidth, shapeHeight);
            Primitives.Instance.drawBox(sb, rc.Transform(matrix), color, 4);
        }

        public override bool contains(Vector2 worldpos)
        {
            Rectangle rc = new Rectangle((int)Position.X, (int)Position.Y, shapeWidth, shapeHeight);
            if (rc.Contains((int)worldpos.X, (int)worldpos.Y))
                return true;
            return false;
        }

        public override string getNamePrefix()
        {
            return "Entity_";
        }

        public virtual string getName(string refCount)
        {
            return getNamePrefix() + refCount;
        }

        /// <summary>
        /// Draws the given string as large as possible inside the boundaries Rectangle without going
        /// outside of it.  This is accomplished by scaling the string (since the SpriteFont has a specific
        /// size).
        /// 
        /// If the string is not a perfect match inside of the boundaries (which it would rarely be), then
        /// the string will be absolutely-centered inside of the boundaries.
        /// </summary>
        /// <param name="font"></param>
        /// <param name="strToDraw"></param>
        /// <param name="boundaries"></param>
        static public void DrawString(SpriteBatch spriteBatch, SpriteFont font, string strToDraw, Rectangle boundaries, Color color)
        {
            Vector2 size = font.MeasureString(strToDraw);

            float xScale = (boundaries.Width / size.X);
            float yScale = (boundaries.Height / size.Y);

            // Taking the smaller scaling value will result in the text always fitting in the boundaires.
            float scale = Math.Min(xScale, yScale);

            // Figure out the location to absolutely-center it in the boundaries rectangle.
            int strWidth = (int)Math.Round(size.X * scale);
            int strHeight = (int)Math.Round(size.Y * scale);
            Vector2 position = new Vector2();
            position.X = (((boundaries.Width - strWidth) / 2) + boundaries.X);
            position.Y = (((boundaries.Height - strHeight) / 2) + boundaries.Y);

            // A bunch of settings where we just want to use reasonable defaults.
            float rotation = 0.0f;
            Vector2 spriteOrigin = new Vector2(0, 0);
            float spriteLayer = 0.0f; // all the way in the front
            SpriteEffects spriteEffects = new SpriteEffects();

            // Draw the string to the sprite batch!
            spriteBatch.DrawString(font, strToDraw, position, color, rotation, spriteOrigin, scale, spriteEffects, spriteLayer);
        } // end DrawString()

        public static void drawStringInCenter(SpriteBatch sb, string text, Rectangle rc)
        {            
            //  measure, center and draw string on shape
            SpriteFont sf = Game1.Instance.entitiesFont;

            int margin = 5;
            rc.X += margin;            
            rc.Width -= 2 * margin;            

            DrawString(sb, sf, text, rc, Color.Navy);            
        }


    }
}
