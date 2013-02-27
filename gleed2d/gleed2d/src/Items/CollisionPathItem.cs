using System;
using System.Collections.Generic;
using System.Text;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;


namespace GLEED2D
{
    public partial class CollisionPathItem
    {
        public CollisionPathItem(Vector2[] points)
            : base(points)
        {            
        }

        public override string getNamePrefix()
        {
            return "CollisionPath_";
        }

    }
}
