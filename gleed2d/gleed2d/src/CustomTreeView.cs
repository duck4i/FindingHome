using System;
using System.Drawing;
using System.Windows.Forms;
using System.Drawing.Drawing2D;

public class CustomTreeView : TreeView
{
    public CustomTreeView()
    {
        this.DrawMode = TreeViewDrawMode.OwnerDrawText;
    }
    protected override void OnDrawNode(DrawTreeNodeEventArgs e)
    {
        TreeNodeStates state = e.State;
        Font font = e.Node.NodeFont ?? e.Node.TreeView.Font;
        Color fore = e.Node.ForeColor;
        if (fore == Color.Empty) fore = e.Node.TreeView.ForeColor;
        if (e.Node == e.Node.TreeView.SelectedNode)
        {
            fore = SystemColors.HighlightText;
            Rectangle r = e.Bounds;            

            e.Graphics.FillRectangle(SystemBrushes.Highlight, r);
            r.Width -= 1;
            r.Height -= 1;

            GraphicsPath p = GetRoundedRect(r, 2);

            e.Graphics.DrawPath(SystemPens.HotTrack, p);
            //e.Graphics.DrawRectangle(SystemPens.HotTrack, r);
            //ControlPaint.DrawFocusRectangle(e.Graphics, e.Bounds, fore, SystemColors.Highlight);
            
            TextRenderer.DrawText(e.Graphics, e.Node.Text, font, e.Bounds, fore, TextFormatFlags.GlyphOverhangPadding);
        }
        else
        {
            e.Graphics.FillRectangle(SystemBrushes.Window, e.Bounds);
            TextRenderer.DrawText(e.Graphics, e.Node.Text, font, e.Bounds, fore, TextFormatFlags.GlyphOverhangPadding);
        }
    }

    private GraphicsPath GetRoundedRect(RectangleF baseRect, float radius)
    {
        // if corner radius is less than or equal to zero, 
        // return the original rectangle 
        if (radius <= 0.0F)
        {
            GraphicsPath mPath = new GraphicsPath();
            mPath.AddRectangle(baseRect);
            mPath.CloseFigure();
            return mPath;
        }

        // if the corner radius is greater than or equal to 
        // half the width, or height (whichever is shorter) 
        // then return a capsule instead of a lozenge 
        if (radius >= (Math.Min(baseRect.Width, baseRect.Height)) / 2.0)
            return GetCapsule(baseRect);

        // create the arc for the rectangle sides and declare 
        // a graphics path object for the drawing 
        float diameter = radius * 2.0F;
        SizeF sizeF = new SizeF(diameter, diameter);
        RectangleF arc = new RectangleF(baseRect.Location, sizeF);
        GraphicsPath path = new System.Drawing.Drawing2D.GraphicsPath();

        // top left arc 
        path.AddArc(arc, 180, 90);

        // top right arc 
        arc.X = baseRect.Right - diameter;
        path.AddArc(arc, 270, 90);

        // bottom right arc 
        arc.Y = baseRect.Bottom - diameter;
        path.AddArc(arc, 0, 90);

        // bottom left arc
        arc.X = baseRect.Left;
        path.AddArc(arc, 90, 90);

        path.CloseFigure();
        return path;
    }

    private GraphicsPath GetCapsule(RectangleF baseRect)
    {
        float diameter;
        RectangleF arc;
        GraphicsPath path = new System.Drawing.Drawing2D.GraphicsPath();
        try
        {
            if (baseRect.Width > baseRect.Height)
            {
                // return horizontal capsule 
                diameter = baseRect.Height;
                SizeF sizeF = new SizeF(diameter, diameter);
                arc = new RectangleF(baseRect.Location, sizeF);
                path.AddArc(arc, 90, 180);
                arc.X = baseRect.Right - diameter;
                path.AddArc(arc, 270, 180);
            }
            else if (baseRect.Width < baseRect.Height)
            {
                // return vertical capsule 
                diameter = baseRect.Width;
                SizeF sizeF = new SizeF(diameter, diameter);
                arc = new RectangleF(baseRect.Location, sizeF);
                path.AddArc(arc, 180, 180);
                arc.Y = baseRect.Bottom - diameter;
                path.AddArc(arc, 0, 180);
            }
            else
            {
                // return circle 
                path.AddEllipse(baseRect);
            }
        }
        catch (Exception ex)
        {
            path.AddEllipse(baseRect);
        }
        finally
        {
            path.CloseFigure();
        }
        return path;
    }
}