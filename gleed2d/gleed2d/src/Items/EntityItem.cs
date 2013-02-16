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
        const int shapeWidth = 100;

        [XmlIgnore()]
        const int shapeHeight = 100;

        [XmlIgnore()]
        Color fontColor;

        [XmlIgnore()]
        Color shapeColor;

        [XmlIgnore()]
        Color hoverShapeColor;

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

        public override void drawInEditor(SpriteBatch sb)
        {
            if (!Visible)
                return;

            Rectangle rc = new Rectangle((int)Position.X, (int)Position.Y, shapeWidth, shapeHeight);

            //  draw shape
            Primitives.Instance.drawBoxFilled(sb, rc, hovering ? hoverShapeColor : shapeColor);

            //  measure, center and draw string on shape
            SpriteFont sf = Game1.Instance.entitiesFont;
            Vector2 smes = sf.MeasureString(Name);

            Vector2 pos = Position;
            pos.X += shapeWidth / 2 - smes.X / 2;
            pos.Y += shapeHeight / 2 - smes.Y / 2;

            sb.DrawString(Game1.Instance.entitiesFont, Name, pos, Color.Navy);
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
    }
}
