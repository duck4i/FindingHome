using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace GLEED2D
{
    public enum BehaviorType
    {
        Unkown,
        Solid,
        Movable,
        Collectable,
        Platform
    };

    public partial class SelectBehavior : Form
    {
        public BehaviorType behavior;

        public SelectBehavior()
        {
            InitializeComponent();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            behavior = BehaviorType.Unkown;
            Close();
        }

        private void SelectBehavior_Load(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {


            Close();
        }

        

        void populateTitleAndDescription()
        {
            var p = behaviorList.FocusedItem;
            if (p == null)
                return;

            String s = behaviorList.FocusedItem.Text;
            String title = "";
            String description = "";

            if (s == "Solid")
            {
                title = "Solid Items";
                description = "Immovable items that can be used for ground or making walls.";
                behavior = BehaviorType.Solid;
            }
            else if (s == "Movable")
            {
                title = "Movable Items";
                description = "Collidable items that can be moved around, eg. balls. Must be solid.";
                behavior = BehaviorType.Movable;
            }
            else if (s == "Bouncing")
            {
                title = "Bouncable Items";
                description = "Items bounce when hit. Must be movable.";
                behavior = BehaviorType.Movable;
            }
            else if (s == "Platform")
            {
                title = "Platform Items";
                description = "Walkable on top, player can jump from beneath.";
                behavior = BehaviorType.Platform;
            }
            else if (s == "Collectable")
            {
                title = "Collectable Items";
                description = "Disapear when touched by player. Can trigger collect event.";
                behavior = BehaviorType.Collectable;
            }

            labelTitle.Text = title;
            labelDescription.Text = description;
        }

        private void behaviorList_SelectedIndexChanged(object sender, EventArgs e)
        {
            populateTitleAndDescription();
        }

    }
}
