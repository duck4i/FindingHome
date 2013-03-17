using System;
using System.Collections.Generic;
using System.Text;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;

namespace GLEED2D
{
    partial class EnemyChipmunk : EntityItem
    {
        public override string getName(string refCount)
        {
            return "Chipmunk_" + refCount;
        }

        public override void drawInEditor(SpriteBatch sb)
        {
            Texture2D texture = Texture2D.FromFile(sb.GraphicsDevice, @"..\Resources\system\enemies\chipmunk.png");
            Rectangle rc = new Rectangle((int) Position.X, (int) Position.Y, shapeWidth - 10, shapeHeight - 10);
            sb.Draw(texture, rc, Color.White);

            rc.Y += 50;

            EntityItem.drawStringInCenter(sb, Name, rc);            

        }
    }
}
