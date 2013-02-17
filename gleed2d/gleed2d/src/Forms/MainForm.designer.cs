namespace GLEED2D
{
    partial class MainForm
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(MainForm));
            System.Windows.Forms.ListViewItem listViewItem1 = new System.Windows.Forms.ListViewItem("Player", "EntityPlayer.png");
            System.Windows.Forms.ListViewItem listViewItem2 = new System.Windows.Forms.ListViewItem("Exit", "EntityExit.png");
            System.Windows.Forms.ListViewItem listViewItem3 = new System.Windows.Forms.ListViewItem("Bat", 0);
            System.Windows.Forms.ListViewItem listViewItem4 = new System.Windows.Forms.ListViewItem("Crow", 1);
            System.Windows.Forms.ListViewItem listViewItem5 = new System.Windows.Forms.ListViewItem("Rectangle", 0);
            System.Windows.Forms.ListViewItem listViewItem6 = new System.Windows.Forms.ListViewItem("Circle", 1);
            System.Windows.Forms.ListViewItem listViewItem7 = new System.Windows.Forms.ListViewItem("Path", 2);
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            this.statusStrip1 = new System.Windows.Forms.StatusStrip();
            this.toolStripStatusLabel1 = new System.Windows.Forms.ToolStripStatusLabel();
            this.toolStripStatusLabel2 = new System.Windows.Forms.ToolStripStatusLabel();
            this.toolStripStatusLabel3 = new System.Windows.Forms.ToolStripStatusLabel();
            this.toolStripStatusLabel4 = new System.Windows.Forms.ToolStripStatusLabel();
            this.treeView1 = new System.Windows.Forms.TreeView();
            this.imageList2 = new System.Windows.Forms.ImageList(this.components);
            this.propertyGrid1 = new System.Windows.Forms.PropertyGrid();
            this.CustomPropertyContextMenu = new System.Windows.Forms.ContextMenuStrip(this.components);
            this.deleteCustomPropertyToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.ItemContextMenu = new System.Windows.Forms.ContextMenuStrip(this.components);
            this.ItemCenterViewEntry = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator5 = new System.Windows.Forms.ToolStripSeparator();
            this.renameToolStripMenuItem1 = new System.Windows.Forms.ToolStripMenuItem();
            this.deleteToolStripMenuItem1 = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator3 = new System.Windows.Forms.ToolStripSeparator();
            this.moveUpToolStripMenuItem1 = new System.Windows.Forms.ToolStripMenuItem();
            this.moveDownToolStripMenuItem1 = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator10 = new System.Windows.Forms.ToolStripSeparator();
            this.addCustomPropertyToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.fileToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.newToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.openToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.saveToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.saveAsToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator1 = new System.Windows.Forms.ToolStripSeparator();
            this.exitToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.editToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.undoMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.redoMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator9 = new System.Windows.Forms.ToolStripSeparator();
            this.selectAllToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.viewToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.ViewGrid = new System.Windows.Forms.ToolStripMenuItem();
            this.ViewSnapToGrid = new System.Windows.Forms.ToolStripMenuItem();
            this.ViewWorldOrigin = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator24 = new System.Windows.Forms.ToolStripSeparator();
            this.runToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.runLevelInYourOwnApplicationToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.ToolsMenu = new System.Windows.Forms.ToolStripMenuItem();
            this.moveSelectedItemsToLayerToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.copySelectedItemsToLayerToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator7 = new System.Windows.Forms.ToolStripSeparator();
            this.linkItemsByACustomPropertyToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator16 = new System.Windows.Forms.ToolStripSeparator();
            this.alignHorizontallyToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.alignVerticallyToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.alignRotationToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.alignScaleToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator6 = new System.Windows.Forms.ToolStripSeparator();
            this.settingsToolStripMenuItem1 = new System.Windows.Forms.ToolStripMenuItem();
            this.updatesToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.checkForUpdatesToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator14 = new System.Windows.Forms.ToolStripSeparator();
            this.sendErrorLogFileToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.helpToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.quickGuideToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.aboutToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStrip1 = new System.Windows.Forms.ToolStrip();
            this.newToolStripButton = new System.Windows.Forms.ToolStripButton();
            this.openToolStripButton = new System.Windows.Forms.ToolStripButton();
            this.saveToolStripButton = new System.Windows.Forms.ToolStripButton();
            this.toolStripSeparator = new System.Windows.Forms.ToolStripSeparator();
            this.undoButton = new System.Windows.Forms.ToolStripSplitButton();
            this.redoButton = new System.Windows.Forms.ToolStripSplitButton();
            this.toolStripSeparator8 = new System.Windows.Forms.ToolStripSeparator();
            this.toolStripLabel1 = new System.Windows.Forms.ToolStripLabel();
            this.zoomcombo = new System.Windows.Forms.ToolStripComboBox();
            this.zoomFitButton = new System.Windows.Forms.ToolStripButton();
            this.toolStripSeparator17 = new System.Windows.Forms.ToolStripSeparator();
            this.ShowGridButton = new System.Windows.Forms.ToolStripButton();
            this.SnapToGridButton = new System.Windows.Forms.ToolStripButton();
            this.ShowWorldOriginButton = new System.Windows.Forms.ToolStripButton();
            this.toolStripSeparator12 = new System.Windows.Forms.ToolStripSeparator();
            this.sendToMainStripButton = new System.Windows.Forms.ToolStripButton();
            this.sendToBackStripButton = new System.Windows.Forms.ToolStripButton();
            this.toolStripSeparator21 = new System.Windows.Forms.ToolStripSeparator();
            this.toolStripLabel2 = new System.Windows.Forms.ToolStripLabel();
            this.addBehaviorStripButton = new System.Windows.Forms.ToolStripButton();
            this.toolStripButton3 = new System.Windows.Forms.ToolStripButton();
            this.toolStripButton5 = new System.Windows.Forms.ToolStripButton();
            this.toolStripSeparator22 = new System.Windows.Forms.ToolStripSeparator();
            this.toolStripSplitButton1 = new System.Windows.Forms.ToolStripDropDownButton();
            this.toggleSolidToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripMenuItem3 = new System.Windows.Forms.ToolStripMenuItem();
            this.toggleCollectableToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator23 = new System.Windows.Forms.ToolStripSeparator();
            this.clearSolidToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.clearDynamciToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.clearCollectibleToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator19 = new System.Windows.Forms.ToolStripSeparator();
            this.toolStripButton2 = new System.Windows.Forms.ToolStripButton();
            this.LayerContextMenu = new System.Windows.Forms.ContextMenuStrip(this.components);
            this.duplicateToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator11 = new System.Windows.Forms.ToolStripSeparator();
            this.renameToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.deleteToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator2 = new System.Windows.Forms.ToolStripSeparator();
            this.LayerMoveUpEntry = new System.Windows.Forms.ToolStripMenuItem();
            this.LayerMoveDownEntry = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator18 = new System.Windows.Forms.ToolStripSeparator();
            this.toolStripMenuItem1 = new System.Windows.Forms.ToolStripMenuItem();
            this.splitContainer1 = new System.Windows.Forms.SplitContainer();
            this.splitContainer3 = new System.Windows.Forms.SplitContainer();
            this.toolStripContainer1 = new System.Windows.Forms.ToolStripContainer();
            this.treetools = new System.Windows.Forms.ToolStrip();
            this.toolStripButton1 = new System.Windows.Forms.ToolStripButton();
            this.buttonDelete = new System.Windows.Forms.ToolStripButton();
            this.toolStripSeparator4 = new System.Windows.Forms.ToolStripSeparator();
            this.butonMoveUp = new System.Windows.Forms.ToolStripButton();
            this.buttonMoveDown = new System.Windows.Forms.ToolStripButton();
            this.splitContainer2 = new System.Windows.Forms.SplitContainer();
            this.tabControl1 = new System.Windows.Forms.TabControl();
            this.tabPage1 = new System.Windows.Forms.TabPage();
            this.splitContainer4 = new System.Windows.Forms.SplitContainer();
            this.panel1 = new System.Windows.Forms.Panel();
            this.panel5 = new System.Windows.Forms.Panel();
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.panel4 = new System.Windows.Forms.Panel();
            this.label1 = new System.Windows.Forms.Label();
            this.panel3 = new System.Windows.Forms.Panel();
            this.buttonFolderUp = new System.Windows.Forms.Button();
            this.chooseFolder = new System.Windows.Forms.Button();
            this.panel2 = new System.Windows.Forms.Panel();
            this.comboBox1 = new System.Windows.Forms.ComboBox();
            this.label2 = new System.Windows.Forms.Label();
            this.listView1 = new System.Windows.Forms.ListView();
            this.imageList96 = new System.Windows.Forms.ImageList(this.components);
            this.EntitiesTabPage = new System.Windows.Forms.TabPage();
            this.entitiesListView = new System.Windows.Forms.ListView();
            this.entitiesImageList = new System.Windows.Forms.ImageList(this.components);
            this.EnemiesTabPage = new System.Windows.Forms.TabPage();
            this.listView3 = new System.Windows.Forms.ListView();
            this.enemiesImageList = new System.Windows.Forms.ImageList(this.components);
            this.tabPage2 = new System.Windows.Forms.TabPage();
            this.listView2 = new System.Windows.Forms.ListView();
            this.imageList1 = new System.Windows.Forms.ImageList(this.components);
            this.imageList48 = new System.Windows.Forms.ImageList(this.components);
            this.imageList64 = new System.Windows.Forms.ImageList(this.components);
            this.imageList128 = new System.Windows.Forms.ImageList(this.components);
            this.imageList256 = new System.Windows.Forms.ImageList(this.components);
            this.backgroundWorker1 = new System.ComponentModel.BackgroundWorker();
            this.LevelContextMenu = new System.Windows.Forms.ContextMenuStrip(this.components);
            this.centerViewToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.addLayerToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator13 = new System.Windows.Forms.ToolStripSeparator();
            this.toolStripMenuItem2 = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator15 = new System.Windows.Forms.ToolStripSeparator();
            this.toolStripMenuItem6 = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator20 = new System.Windows.Forms.ToolStripSeparator();
            this.insertGameLayersToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            this.statusStrip1.SuspendLayout();
            this.CustomPropertyContextMenu.SuspendLayout();
            this.ItemContextMenu.SuspendLayout();
            this.menuStrip1.SuspendLayout();
            this.toolStrip1.SuspendLayout();
            this.LayerContextMenu.SuspendLayout();
            this.splitContainer1.Panel1.SuspendLayout();
            this.splitContainer1.Panel2.SuspendLayout();
            this.splitContainer1.SuspendLayout();
            this.splitContainer3.Panel1.SuspendLayout();
            this.splitContainer3.Panel2.SuspendLayout();
            this.splitContainer3.SuspendLayout();
            this.toolStripContainer1.ContentPanel.SuspendLayout();
            this.toolStripContainer1.TopToolStripPanel.SuspendLayout();
            this.toolStripContainer1.SuspendLayout();
            this.treetools.SuspendLayout();
            this.splitContainer2.Panel1.SuspendLayout();
            this.splitContainer2.Panel2.SuspendLayout();
            this.splitContainer2.SuspendLayout();
            this.tabControl1.SuspendLayout();
            this.tabPage1.SuspendLayout();
            this.splitContainer4.Panel1.SuspendLayout();
            this.splitContainer4.Panel2.SuspendLayout();
            this.splitContainer4.SuspendLayout();
            this.panel1.SuspendLayout();
            this.panel5.SuspendLayout();
            this.panel4.SuspendLayout();
            this.panel3.SuspendLayout();
            this.panel2.SuspendLayout();
            this.EntitiesTabPage.SuspendLayout();
            this.EnemiesTabPage.SuspendLayout();
            this.tabPage2.SuspendLayout();
            this.LevelContextMenu.SuspendLayout();
            this.SuspendLayout();
            // 
            // pictureBox1
            // 
            this.pictureBox1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.pictureBox1.Location = new System.Drawing.Point(0, 0);
            this.pictureBox1.Margin = new System.Windows.Forms.Padding(0);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(751, 440);
            this.pictureBox1.TabIndex = 0;
            this.pictureBox1.TabStop = false;
            this.pictureBox1.MouseLeave += new System.EventHandler(this.pictureBox1_MouseLeave);
            this.pictureBox1.PreviewKeyDown += new System.Windows.Forms.PreviewKeyDownEventHandler(this.pictureBox1_PreviewKeyDown);
            this.pictureBox1.DragOver += new System.Windows.Forms.DragEventHandler(this.pictureBox1_DragOver);
            this.pictureBox1.DragDrop += new System.Windows.Forms.DragEventHandler(this.pictureBox1_DragDrop);
            this.pictureBox1.Resize += new System.EventHandler(this.pictureBox1_Resize);
            this.pictureBox1.DragLeave += new System.EventHandler(this.pictureBox1_DragLeave);
            this.pictureBox1.DragEnter += new System.Windows.Forms.DragEventHandler(this.pictureBox1_DragEnter);
            this.pictureBox1.MouseEnter += new System.EventHandler(this.pictureBox1_MouseEnter);
            // 
            // statusStrip1
            // 
            this.statusStrip1.GripStyle = System.Windows.Forms.ToolStripGripStyle.Visible;
            this.statusStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.toolStripStatusLabel1,
            this.toolStripStatusLabel2,
            this.toolStripStatusLabel3,
            this.toolStripStatusLabel4});
            this.statusStrip1.Location = new System.Drawing.Point(0, 694);
            this.statusStrip1.Name = "statusStrip1";
            this.statusStrip1.RenderMode = System.Windows.Forms.ToolStripRenderMode.Professional;
            this.statusStrip1.Size = new System.Drawing.Size(1002, 22);
            this.statusStrip1.TabIndex = 1;
            this.statusStrip1.Text = "statusStrip1";
            // 
            // toolStripStatusLabel1
            // 
            this.toolStripStatusLabel1.AutoSize = false;
            this.toolStripStatusLabel1.BorderSides = ((System.Windows.Forms.ToolStripStatusLabelBorderSides)((((System.Windows.Forms.ToolStripStatusLabelBorderSides.Left | System.Windows.Forms.ToolStripStatusLabelBorderSides.Top)
                        | System.Windows.Forms.ToolStripStatusLabelBorderSides.Right)
                        | System.Windows.Forms.ToolStripStatusLabelBorderSides.Bottom)));
            this.toolStripStatusLabel1.BorderStyle = System.Windows.Forms.Border3DStyle.SunkenOuter;
            this.toolStripStatusLabel1.Name = "toolStripStatusLabel1";
            this.toolStripStatusLabel1.Size = new System.Drawing.Size(650, 17);
            this.toolStripStatusLabel1.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // toolStripStatusLabel2
            // 
            this.toolStripStatusLabel2.AutoSize = false;
            this.toolStripStatusLabel2.BorderSides = ((System.Windows.Forms.ToolStripStatusLabelBorderSides)((((System.Windows.Forms.ToolStripStatusLabelBorderSides.Left | System.Windows.Forms.ToolStripStatusLabelBorderSides.Top)
                        | System.Windows.Forms.ToolStripStatusLabelBorderSides.Right)
                        | System.Windows.Forms.ToolStripStatusLabelBorderSides.Bottom)));
            this.toolStripStatusLabel2.BorderStyle = System.Windows.Forms.Border3DStyle.SunkenOuter;
            this.toolStripStatusLabel2.Name = "toolStripStatusLabel2";
            this.toolStripStatusLabel2.Size = new System.Drawing.Size(113, 17);
            this.toolStripStatusLabel2.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // toolStripStatusLabel3
            // 
            this.toolStripStatusLabel3.AutoSize = false;
            this.toolStripStatusLabel3.BorderSides = ((System.Windows.Forms.ToolStripStatusLabelBorderSides)((((System.Windows.Forms.ToolStripStatusLabelBorderSides.Left | System.Windows.Forms.ToolStripStatusLabelBorderSides.Top)
                        | System.Windows.Forms.ToolStripStatusLabelBorderSides.Right)
                        | System.Windows.Forms.ToolStripStatusLabelBorderSides.Bottom)));
            this.toolStripStatusLabel3.BorderStyle = System.Windows.Forms.Border3DStyle.SunkenOuter;
            this.toolStripStatusLabel3.Name = "toolStripStatusLabel3";
            this.toolStripStatusLabel3.Size = new System.Drawing.Size(109, 17);
            this.toolStripStatusLabel3.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // toolStripStatusLabel4
            // 
            this.toolStripStatusLabel4.AutoSize = false;
            this.toolStripStatusLabel4.BorderSides = ((System.Windows.Forms.ToolStripStatusLabelBorderSides)((((System.Windows.Forms.ToolStripStatusLabelBorderSides.Left | System.Windows.Forms.ToolStripStatusLabelBorderSides.Top)
                        | System.Windows.Forms.ToolStripStatusLabelBorderSides.Right)
                        | System.Windows.Forms.ToolStripStatusLabelBorderSides.Bottom)));
            this.toolStripStatusLabel4.BorderStyle = System.Windows.Forms.Border3DStyle.SunkenOuter;
            this.toolStripStatusLabel4.Name = "toolStripStatusLabel4";
            this.toolStripStatusLabel4.Size = new System.Drawing.Size(60, 17);
            this.toolStripStatusLabel4.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // treeView1
            // 
            this.treeView1.AllowDrop = true;
            this.treeView1.CheckBoxes = true;
            this.treeView1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.treeView1.HideSelection = false;
            this.treeView1.ImageIndex = 5;
            this.treeView1.ImageList = this.imageList2;
            this.treeView1.LabelEdit = true;
            this.treeView1.Location = new System.Drawing.Point(0, 0);
            this.treeView1.Name = "treeView1";
            this.treeView1.SelectedImageIndex = 5;
            this.treeView1.Size = new System.Drawing.Size(239, 275);
            this.treeView1.TabIndex = 2;
            this.treeView1.AfterCheck += new System.Windows.Forms.TreeViewEventHandler(this.treeView1_AfterCheck);
            this.treeView1.AfterLabelEdit += new System.Windows.Forms.NodeLabelEditEventHandler(this.treeView1_AfterLabelEdit);
            this.treeView1.DragDrop += new System.Windows.Forms.DragEventHandler(this.treeView1_DragDrop);
            this.treeView1.AfterSelect += new System.Windows.Forms.TreeViewEventHandler(this.treeView1_AfterSelect);
            this.treeView1.MouseDown += new System.Windows.Forms.MouseEventHandler(this.treeView1_MouseDown);
            this.treeView1.KeyDown += new System.Windows.Forms.KeyEventHandler(this.treeView1_KeyDown);
            this.treeView1.ItemDrag += new System.Windows.Forms.ItemDragEventHandler(this.treeView1_ItemDrag);
            this.treeView1.DragOver += new System.Windows.Forms.DragEventHandler(this.treeView1_DragOver);
            // 
            // imageList2
            // 
            this.imageList2.ImageStream = ((System.Windows.Forms.ImageListStreamer)(resources.GetObject("imageList2.ImageStream")));
            this.imageList2.TransparentColor = System.Drawing.Color.Transparent;
            this.imageList2.Images.SetKeyName(0, "icon_layer.png");
            this.imageList2.Images.SetKeyName(1, "icon_texture_item.png");
            this.imageList2.Images.SetKeyName(2, "icon_rectangle_item.png");
            this.imageList2.Images.SetKeyName(3, "icon_circle_item.png");
            this.imageList2.Images.SetKeyName(4, "icon_path_item.png");
            this.imageList2.Images.SetKeyName(5, "icon_level.png");
            this.imageList2.Images.SetKeyName(6, "icon_item_entity.png");
            // 
            // propertyGrid1
            // 
            this.propertyGrid1.ContextMenuStrip = this.CustomPropertyContextMenu;
            this.propertyGrid1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.propertyGrid1.Location = new System.Drawing.Point(0, 0);
            this.propertyGrid1.Name = "propertyGrid1";
            this.propertyGrid1.PropertySort = System.Windows.Forms.PropertySort.Categorized;
            this.propertyGrid1.Size = new System.Drawing.Size(239, 333);
            this.propertyGrid1.TabIndex = 3;
            this.propertyGrid1.ToolbarVisible = false;
            this.propertyGrid1.Enter += new System.EventHandler(this.propertyGrid1_Enter);
            this.propertyGrid1.PropertyValueChanged += new System.Windows.Forms.PropertyValueChangedEventHandler(this.propertyGrid1_PropertyValueChanged);
            // 
            // CustomPropertyContextMenu
            // 
            this.CustomPropertyContextMenu.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.deleteCustomPropertyToolStripMenuItem});
            this.CustomPropertyContextMenu.Name = "CustomPropertyContextMenu";
            this.CustomPropertyContextMenu.Size = new System.Drawing.Size(201, 26);
            this.CustomPropertyContextMenu.Opening += new System.ComponentModel.CancelEventHandler(this.CustomPropertyContextMenu_Opening);
            // 
            // deleteCustomPropertyToolStripMenuItem
            // 
            this.deleteCustomPropertyToolStripMenuItem.Name = "deleteCustomPropertyToolStripMenuItem";
            this.deleteCustomPropertyToolStripMenuItem.Size = new System.Drawing.Size(200, 22);
            this.deleteCustomPropertyToolStripMenuItem.Text = "Delete Custom Property";
            this.deleteCustomPropertyToolStripMenuItem.Click += new System.EventHandler(this.deleteCustomProperty);
            // 
            // ItemContextMenu
            // 
            this.ItemContextMenu.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.ItemCenterViewEntry,
            this.toolStripSeparator5,
            this.renameToolStripMenuItem1,
            this.deleteToolStripMenuItem1,
            this.toolStripSeparator3,
            this.moveUpToolStripMenuItem1,
            this.moveDownToolStripMenuItem1,
            this.toolStripSeparator10,
            this.addCustomPropertyToolStripMenuItem});
            this.ItemContextMenu.Name = "ItemContextMenu";
            this.ItemContextMenu.Size = new System.Drawing.Size(190, 154);
            // 
            // ItemCenterViewEntry
            // 
            this.ItemCenterViewEntry.Name = "ItemCenterViewEntry";
            this.ItemCenterViewEntry.ShortcutKeys = System.Windows.Forms.Keys.F4;
            this.ItemCenterViewEntry.Size = new System.Drawing.Size(189, 22);
            this.ItemCenterViewEntry.Text = "Center View";
            this.ItemCenterViewEntry.Click += new System.EventHandler(this.ActionCenterView);
            // 
            // toolStripSeparator5
            // 
            this.toolStripSeparator5.Name = "toolStripSeparator5";
            this.toolStripSeparator5.Size = new System.Drawing.Size(186, 6);
            // 
            // renameToolStripMenuItem1
            // 
            this.renameToolStripMenuItem1.Name = "renameToolStripMenuItem1";
            this.renameToolStripMenuItem1.ShortcutKeys = System.Windows.Forms.Keys.F2;
            this.renameToolStripMenuItem1.Size = new System.Drawing.Size(189, 22);
            this.renameToolStripMenuItem1.Text = "Rename";
            this.renameToolStripMenuItem1.Click += new System.EventHandler(this.ActionRename);
            // 
            // deleteToolStripMenuItem1
            // 
            this.deleteToolStripMenuItem1.Name = "deleteToolStripMenuItem1";
            this.deleteToolStripMenuItem1.ShortcutKeys = System.Windows.Forms.Keys.Delete;
            this.deleteToolStripMenuItem1.Size = new System.Drawing.Size(189, 22);
            this.deleteToolStripMenuItem1.Text = "Delete";
            this.deleteToolStripMenuItem1.Click += new System.EventHandler(this.ActionDelete);
            // 
            // toolStripSeparator3
            // 
            this.toolStripSeparator3.Name = "toolStripSeparator3";
            this.toolStripSeparator3.Size = new System.Drawing.Size(186, 6);
            // 
            // moveUpToolStripMenuItem1
            // 
            this.moveUpToolStripMenuItem1.Name = "moveUpToolStripMenuItem1";
            this.moveUpToolStripMenuItem1.ShortcutKeyDisplayString = "";
            this.moveUpToolStripMenuItem1.ShortcutKeys = System.Windows.Forms.Keys.F7;
            this.moveUpToolStripMenuItem1.Size = new System.Drawing.Size(189, 22);
            this.moveUpToolStripMenuItem1.Text = "Move Up";
            this.moveUpToolStripMenuItem1.Click += new System.EventHandler(this.ActionMoveUp);
            // 
            // moveDownToolStripMenuItem1
            // 
            this.moveDownToolStripMenuItem1.Name = "moveDownToolStripMenuItem1";
            this.moveDownToolStripMenuItem1.ShortcutKeys = System.Windows.Forms.Keys.F8;
            this.moveDownToolStripMenuItem1.Size = new System.Drawing.Size(189, 22);
            this.moveDownToolStripMenuItem1.Text = "Move Down";
            this.moveDownToolStripMenuItem1.Click += new System.EventHandler(this.ActionMoveDown);
            // 
            // toolStripSeparator10
            // 
            this.toolStripSeparator10.Name = "toolStripSeparator10";
            this.toolStripSeparator10.Size = new System.Drawing.Size(186, 6);
            // 
            // addCustomPropertyToolStripMenuItem
            // 
            this.addCustomPropertyToolStripMenuItem.Name = "addCustomPropertyToolStripMenuItem";
            this.addCustomPropertyToolStripMenuItem.Size = new System.Drawing.Size(189, 22);
            this.addCustomPropertyToolStripMenuItem.Text = "Add Custom Property";
            this.addCustomPropertyToolStripMenuItem.Click += new System.EventHandler(this.ActionAddCustomProperty);
            // 
            // menuStrip1
            // 
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.fileToolStripMenuItem,
            this.editToolStripMenuItem,
            this.viewToolStripMenuItem,
            this.runToolStripMenuItem,
            this.ToolsMenu,
            this.updatesToolStripMenuItem,
            this.helpToolStripMenuItem});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.RenderMode = System.Windows.Forms.ToolStripRenderMode.Professional;
            this.menuStrip1.Size = new System.Drawing.Size(1002, 24);
            this.menuStrip1.TabIndex = 4;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // fileToolStripMenuItem
            // 
            this.fileToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.newToolStripMenuItem,
            this.openToolStripMenuItem,
            this.saveToolStripMenuItem,
            this.saveAsToolStripMenuItem,
            this.toolStripSeparator1,
            this.exitToolStripMenuItem});
            this.fileToolStripMenuItem.Name = "fileToolStripMenuItem";
            this.fileToolStripMenuItem.Size = new System.Drawing.Size(37, 20);
            this.fileToolStripMenuItem.Text = "File";
            // 
            // newToolStripMenuItem
            // 
            this.newToolStripMenuItem.Image = ((System.Drawing.Image)(resources.GetObject("newToolStripMenuItem.Image")));
            this.newToolStripMenuItem.Name = "newToolStripMenuItem";
            this.newToolStripMenuItem.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.N)));
            this.newToolStripMenuItem.Size = new System.Drawing.Size(148, 22);
            this.newToolStripMenuItem.Text = "New";
            this.newToolStripMenuItem.Click += new System.EventHandler(this.FileNew);
            // 
            // openToolStripMenuItem
            // 
            this.openToolStripMenuItem.Image = ((System.Drawing.Image)(resources.GetObject("openToolStripMenuItem.Image")));
            this.openToolStripMenuItem.Name = "openToolStripMenuItem";
            this.openToolStripMenuItem.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.O)));
            this.openToolStripMenuItem.Size = new System.Drawing.Size(148, 22);
            this.openToolStripMenuItem.Text = "Open";
            this.openToolStripMenuItem.Click += new System.EventHandler(this.FileOpen);
            // 
            // saveToolStripMenuItem
            // 
            this.saveToolStripMenuItem.Image = ((System.Drawing.Image)(resources.GetObject("saveToolStripMenuItem.Image")));
            this.saveToolStripMenuItem.Name = "saveToolStripMenuItem";
            this.saveToolStripMenuItem.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.S)));
            this.saveToolStripMenuItem.Size = new System.Drawing.Size(148, 22);
            this.saveToolStripMenuItem.Text = "Save";
            this.saveToolStripMenuItem.Click += new System.EventHandler(this.FileSave);
            // 
            // saveAsToolStripMenuItem
            // 
            this.saveAsToolStripMenuItem.Name = "saveAsToolStripMenuItem";
            this.saveAsToolStripMenuItem.ShortcutKeys = System.Windows.Forms.Keys.F12;
            this.saveAsToolStripMenuItem.Size = new System.Drawing.Size(148, 22);
            this.saveAsToolStripMenuItem.Text = "Save As...";
            this.saveAsToolStripMenuItem.Click += new System.EventHandler(this.FileSaveAs);
            // 
            // toolStripSeparator1
            // 
            this.toolStripSeparator1.Name = "toolStripSeparator1";
            this.toolStripSeparator1.Size = new System.Drawing.Size(145, 6);
            // 
            // exitToolStripMenuItem
            // 
            this.exitToolStripMenuItem.Image = global::GLEED2D.Properties.Resources._8;
            this.exitToolStripMenuItem.Name = "exitToolStripMenuItem";
            this.exitToolStripMenuItem.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.E)));
            this.exitToolStripMenuItem.Size = new System.Drawing.Size(148, 22);
            this.exitToolStripMenuItem.Text = "Exit";
            this.exitToolStripMenuItem.Click += new System.EventHandler(this.FileExit);
            // 
            // editToolStripMenuItem
            // 
            this.editToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.undoMenuItem,
            this.redoMenuItem,
            this.toolStripSeparator9,
            this.selectAllToolStripMenuItem});
            this.editToolStripMenuItem.Name = "editToolStripMenuItem";
            this.editToolStripMenuItem.Size = new System.Drawing.Size(39, 20);
            this.editToolStripMenuItem.Text = "Edit";
            // 
            // undoMenuItem
            // 
            this.undoMenuItem.Enabled = false;
            this.undoMenuItem.Image = ((System.Drawing.Image)(resources.GetObject("undoMenuItem.Image")));
            this.undoMenuItem.Name = "undoMenuItem";
            this.undoMenuItem.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.Z)));
            this.undoMenuItem.Size = new System.Drawing.Size(164, 22);
            this.undoMenuItem.Text = "Undo";
            this.undoMenuItem.Click += new System.EventHandler(this.EditUndo);
            // 
            // redoMenuItem
            // 
            this.redoMenuItem.Enabled = false;
            this.redoMenuItem.Image = ((System.Drawing.Image)(resources.GetObject("redoMenuItem.Image")));
            this.redoMenuItem.Name = "redoMenuItem";
            this.redoMenuItem.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.R)));
            this.redoMenuItem.Size = new System.Drawing.Size(164, 22);
            this.redoMenuItem.Text = "Redo";
            this.redoMenuItem.Click += new System.EventHandler(this.EditRedo);
            // 
            // toolStripSeparator9
            // 
            this.toolStripSeparator9.Name = "toolStripSeparator9";
            this.toolStripSeparator9.Size = new System.Drawing.Size(161, 6);
            // 
            // selectAllToolStripMenuItem
            // 
            this.selectAllToolStripMenuItem.Name = "selectAllToolStripMenuItem";
            this.selectAllToolStripMenuItem.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.A)));
            this.selectAllToolStripMenuItem.Size = new System.Drawing.Size(164, 22);
            this.selectAllToolStripMenuItem.Text = "Select All";
            this.selectAllToolStripMenuItem.Click += new System.EventHandler(this.EditSelectAll);
            // 
            // viewToolStripMenuItem
            // 
            this.viewToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.ViewGrid,
            this.ViewSnapToGrid,
            this.ViewWorldOrigin,
            this.toolStripSeparator24});
            this.viewToolStripMenuItem.Name = "viewToolStripMenuItem";
            this.viewToolStripMenuItem.Size = new System.Drawing.Size(44, 20);
            this.viewToolStripMenuItem.Text = "View";
            this.viewToolStripMenuItem.Click += new System.EventHandler(this.viewToolStripMenuItem_Click);
            // 
            // ViewGrid
            // 
            this.ViewGrid.CheckOnClick = true;
            this.ViewGrid.Image = ((System.Drawing.Image)(resources.GetObject("ViewGrid.Image")));
            this.ViewGrid.Name = "ViewGrid";
            this.ViewGrid.Size = new System.Drawing.Size(142, 22);
            this.ViewGrid.Text = "Grid";
            this.ViewGrid.CheckedChanged += new System.EventHandler(this.ViewGrid_CheckedChanged);
            // 
            // ViewSnapToGrid
            // 
            this.ViewSnapToGrid.CheckOnClick = true;
            this.ViewSnapToGrid.Image = ((System.Drawing.Image)(resources.GetObject("ViewSnapToGrid.Image")));
            this.ViewSnapToGrid.Name = "ViewSnapToGrid";
            this.ViewSnapToGrid.Size = new System.Drawing.Size(142, 22);
            this.ViewSnapToGrid.Text = "Snap to Grid";
            this.ViewSnapToGrid.CheckedChanged += new System.EventHandler(this.ViewSnapToGrid_CheckedChanged);
            // 
            // ViewWorldOrigin
            // 
            this.ViewWorldOrigin.CheckOnClick = true;
            this.ViewWorldOrigin.Image = ((System.Drawing.Image)(resources.GetObject("ViewWorldOrigin.Image")));
            this.ViewWorldOrigin.Name = "ViewWorldOrigin";
            this.ViewWorldOrigin.Size = new System.Drawing.Size(142, 22);
            this.ViewWorldOrigin.Text = "World Origin";
            this.ViewWorldOrigin.CheckedChanged += new System.EventHandler(this.ViewWorldOrigin_CheckedChanged);
            // 
            // toolStripSeparator24
            // 
            this.toolStripSeparator24.Name = "toolStripSeparator24";
            this.toolStripSeparator24.Size = new System.Drawing.Size(139, 6);
            // 
            // runToolStripMenuItem
            // 
            this.runToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.runLevelInYourOwnApplicationToolStripMenuItem});
            this.runToolStripMenuItem.Name = "runToolStripMenuItem";
            this.runToolStripMenuItem.Size = new System.Drawing.Size(40, 20);
            this.runToolStripMenuItem.Text = "Run";
            // 
            // runLevelInYourOwnApplicationToolStripMenuItem
            // 
            this.runLevelInYourOwnApplicationToolStripMenuItem.Image = ((System.Drawing.Image)(resources.GetObject("runLevelInYourOwnApplicationToolStripMenuItem.Image")));
            this.runLevelInYourOwnApplicationToolStripMenuItem.Name = "runLevelInYourOwnApplicationToolStripMenuItem";
            this.runLevelInYourOwnApplicationToolStripMenuItem.ShortcutKeys = System.Windows.Forms.Keys.F5;
            this.runLevelInYourOwnApplicationToolStripMenuItem.Size = new System.Drawing.Size(144, 22);
            this.runLevelInYourOwnApplicationToolStripMenuItem.Text = "Run Level";
            this.runLevelInYourOwnApplicationToolStripMenuItem.ToolTipText = "Run Level in your own application. To use this, define the appropriate settings i" +
                "n the Tools->Settings dialog.";
            this.runLevelInYourOwnApplicationToolStripMenuItem.Click += new System.EventHandler(this.RunLevel);
            // 
            // ToolsMenu
            // 
            this.ToolsMenu.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.moveSelectedItemsToLayerToolStripMenuItem,
            this.copySelectedItemsToLayerToolStripMenuItem,
            this.toolStripSeparator7,
            this.linkItemsByACustomPropertyToolStripMenuItem,
            this.toolStripSeparator16,
            this.alignHorizontallyToolStripMenuItem,
            this.alignVerticallyToolStripMenuItem,
            this.alignRotationToolStripMenuItem,
            this.alignScaleToolStripMenuItem,
            this.toolStripSeparator6,
            this.settingsToolStripMenuItem1});
            this.ToolsMenu.Name = "ToolsMenu";
            this.ToolsMenu.Size = new System.Drawing.Size(48, 20);
            this.ToolsMenu.Text = "Tools";
            this.ToolsMenu.MouseEnter += new System.EventHandler(this.ToolsMenu_MouseEnter);
            this.ToolsMenu.Click += new System.EventHandler(this.ToolsMenu_Click);
            // 
            // moveSelectedItemsToLayerToolStripMenuItem
            // 
            this.moveSelectedItemsToLayerToolStripMenuItem.Image = ((System.Drawing.Image)(resources.GetObject("moveSelectedItemsToLayerToolStripMenuItem.Image")));
            this.moveSelectedItemsToLayerToolStripMenuItem.Name = "moveSelectedItemsToLayerToolStripMenuItem";
            this.moveSelectedItemsToLayerToolStripMenuItem.Size = new System.Drawing.Size(362, 22);
            this.moveSelectedItemsToLayerToolStripMenuItem.Text = "Move Selected Items to Layer...";
            this.moveSelectedItemsToLayerToolStripMenuItem.ToolTipText = "Moves the selected Items to another existing layer.";
            this.moveSelectedItemsToLayerToolStripMenuItem.Click += new System.EventHandler(this.ToolsMoveToLayer);
            // 
            // copySelectedItemsToLayerToolStripMenuItem
            // 
            this.copySelectedItemsToLayerToolStripMenuItem.Image = ((System.Drawing.Image)(resources.GetObject("copySelectedItemsToLayerToolStripMenuItem.Image")));
            this.copySelectedItemsToLayerToolStripMenuItem.Name = "copySelectedItemsToLayerToolStripMenuItem";
            this.copySelectedItemsToLayerToolStripMenuItem.Size = new System.Drawing.Size(362, 22);
            this.copySelectedItemsToLayerToolStripMenuItem.Text = "Copy Selected Items to Layer...";
            this.copySelectedItemsToLayerToolStripMenuItem.ToolTipText = "Copies the selected Items to another existing layer.";
            this.copySelectedItemsToLayerToolStripMenuItem.Click += new System.EventHandler(this.ToolsCopyToLayer);
            // 
            // toolStripSeparator7
            // 
            this.toolStripSeparator7.Name = "toolStripSeparator7";
            this.toolStripSeparator7.Size = new System.Drawing.Size(359, 6);
            // 
            // linkItemsByACustomPropertyToolStripMenuItem
            // 
            this.linkItemsByACustomPropertyToolStripMenuItem.Image = ((System.Drawing.Image)(resources.GetObject("linkItemsByACustomPropertyToolStripMenuItem.Image")));
            this.linkItemsByACustomPropertyToolStripMenuItem.Name = "linkItemsByACustomPropertyToolStripMenuItem";
            this.linkItemsByACustomPropertyToolStripMenuItem.ShortcutKeys = ((System.Windows.Forms.Keys)(((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.Shift)
                        | System.Windows.Forms.Keys.L)));
            this.linkItemsByACustomPropertyToolStripMenuItem.Size = new System.Drawing.Size(362, 22);
            this.linkItemsByACustomPropertyToolStripMenuItem.Text = "Link Selected Items by a CustomProperty";
            this.linkItemsByACustomPropertyToolStripMenuItem.ToolTipText = "Only active if exactly two Items are selected. Adds a Custom Property of type \"It" +
                "em\" resulting in the first Item referring to the Second one. \r\nTwo-way linking a" +
                "lso possible.";
            this.linkItemsByACustomPropertyToolStripMenuItem.Click += new System.EventHandler(this.ToolsLinkItems);
            // 
            // toolStripSeparator16
            // 
            this.toolStripSeparator16.Name = "toolStripSeparator16";
            this.toolStripSeparator16.Size = new System.Drawing.Size(359, 6);
            // 
            // alignHorizontallyToolStripMenuItem
            // 
            this.alignHorizontallyToolStripMenuItem.Image = ((System.Drawing.Image)(resources.GetObject("alignHorizontallyToolStripMenuItem.Image")));
            this.alignHorizontallyToolStripMenuItem.Name = "alignHorizontallyToolStripMenuItem";
            this.alignHorizontallyToolStripMenuItem.ShortcutKeys = ((System.Windows.Forms.Keys)(((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.Shift)
                        | System.Windows.Forms.Keys.H)));
            this.alignHorizontallyToolStripMenuItem.Size = new System.Drawing.Size(362, 22);
            this.alignHorizontallyToolStripMenuItem.Text = "Align Horizontally";
            this.alignHorizontallyToolStripMenuItem.ToolTipText = "Adjust the Y-Coordinate of all selected items to be the same as the first selecte" +
                "d item.";
            this.alignHorizontallyToolStripMenuItem.Click += new System.EventHandler(this.ToolsAlignHorizontally);
            // 
            // alignVerticallyToolStripMenuItem
            // 
            this.alignVerticallyToolStripMenuItem.Image = ((System.Drawing.Image)(resources.GetObject("alignVerticallyToolStripMenuItem.Image")));
            this.alignVerticallyToolStripMenuItem.Name = "alignVerticallyToolStripMenuItem";
            this.alignVerticallyToolStripMenuItem.ShortcutKeys = ((System.Windows.Forms.Keys)(((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.Shift)
                        | System.Windows.Forms.Keys.V)));
            this.alignVerticallyToolStripMenuItem.Size = new System.Drawing.Size(362, 22);
            this.alignVerticallyToolStripMenuItem.Text = "Align Vertically";
            this.alignVerticallyToolStripMenuItem.ToolTipText = "Adjust the X-Coordinate of all selected items to be the same as the first selecte" +
                "d item.";
            this.alignVerticallyToolStripMenuItem.Click += new System.EventHandler(this.ToolsAlignVertically);
            // 
            // alignRotationToolStripMenuItem
            // 
            this.alignRotationToolStripMenuItem.Image = ((System.Drawing.Image)(resources.GetObject("alignRotationToolStripMenuItem.Image")));
            this.alignRotationToolStripMenuItem.Name = "alignRotationToolStripMenuItem";
            this.alignRotationToolStripMenuItem.ShortcutKeys = ((System.Windows.Forms.Keys)(((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.Shift)
                        | System.Windows.Forms.Keys.R)));
            this.alignRotationToolStripMenuItem.Size = new System.Drawing.Size(362, 22);
            this.alignRotationToolStripMenuItem.Text = "Align Rotation";
            this.alignRotationToolStripMenuItem.ToolTipText = "Adjust the rotation of all selected items to be the same as the first selected it" +
                "em.";
            this.alignRotationToolStripMenuItem.Click += new System.EventHandler(this.ToolsAlignRotation);
            // 
            // alignScaleToolStripMenuItem
            // 
            this.alignScaleToolStripMenuItem.Image = ((System.Drawing.Image)(resources.GetObject("alignScaleToolStripMenuItem.Image")));
            this.alignScaleToolStripMenuItem.Name = "alignScaleToolStripMenuItem";
            this.alignScaleToolStripMenuItem.ShortcutKeys = ((System.Windows.Forms.Keys)(((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.Shift)
                        | System.Windows.Forms.Keys.S)));
            this.alignScaleToolStripMenuItem.Size = new System.Drawing.Size(362, 22);
            this.alignScaleToolStripMenuItem.Text = "Align Scale";
            this.alignScaleToolStripMenuItem.ToolTipText = "Adjust the Scale of all selected items to be the same as the first selected item." +
                "";
            this.alignScaleToolStripMenuItem.Click += new System.EventHandler(this.ToolsAlignScale);
            // 
            // toolStripSeparator6
            // 
            this.toolStripSeparator6.Name = "toolStripSeparator6";
            this.toolStripSeparator6.Size = new System.Drawing.Size(359, 6);
            // 
            // settingsToolStripMenuItem1
            // 
            this.settingsToolStripMenuItem1.Image = ((System.Drawing.Image)(resources.GetObject("settingsToolStripMenuItem1.Image")));
            this.settingsToolStripMenuItem1.Name = "settingsToolStripMenuItem1";
            this.settingsToolStripMenuItem1.ShortcutKeys = System.Windows.Forms.Keys.F9;
            this.settingsToolStripMenuItem1.Size = new System.Drawing.Size(362, 22);
            this.settingsToolStripMenuItem1.Text = "Settings";
            this.settingsToolStripMenuItem1.ToolTipText = "The Settings Dialog.";
            this.settingsToolStripMenuItem1.Click += new System.EventHandler(this.ToolsSettings);
            // 
            // updatesToolStripMenuItem
            // 
            this.updatesToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.checkForUpdatesToolStripMenuItem,
            this.toolStripSeparator14,
            this.sendErrorLogFileToolStripMenuItem});
            this.updatesToolStripMenuItem.Name = "updatesToolStripMenuItem";
            this.updatesToolStripMenuItem.Size = new System.Drawing.Size(61, 20);
            this.updatesToolStripMenuItem.Text = "Support";
            // 
            // checkForUpdatesToolStripMenuItem
            // 
            this.checkForUpdatesToolStripMenuItem.Image = global::GLEED2D.Properties.Resources._68;
            this.checkForUpdatesToolStripMenuItem.Name = "checkForUpdatesToolStripMenuItem";
            this.checkForUpdatesToolStripMenuItem.Size = new System.Drawing.Size(241, 22);
            this.checkForUpdatesToolStripMenuItem.Text = "Check for updates";
            this.checkForUpdatesToolStripMenuItem.Click += new System.EventHandler(this.checkForUpdatesToolStripMenuItem_Click);
            // 
            // toolStripSeparator14
            // 
            this.toolStripSeparator14.Name = "toolStripSeparator14";
            this.toolStripSeparator14.Size = new System.Drawing.Size(238, 6);
            // 
            // sendErrorLogFileToolStripMenuItem
            // 
            this.sendErrorLogFileToolStripMenuItem.Image = global::GLEED2D.Properties.Resources._58;
            this.sendErrorLogFileToolStripMenuItem.Name = "sendErrorLogFileToolStripMenuItem";
            this.sendErrorLogFileToolStripMenuItem.Size = new System.Drawing.Size(241, 22);
            this.sendErrorLogFileToolStripMenuItem.Text = "Send error log file to developers";
            this.sendErrorLogFileToolStripMenuItem.Click += new System.EventHandler(this.sendErrorLogFileToolStripMenuItem_Click);
            // 
            // helpToolStripMenuItem
            // 
            this.helpToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.quickGuideToolStripMenuItem,
            this.aboutToolStripMenuItem});
            this.helpToolStripMenuItem.Name = "helpToolStripMenuItem";
            this.helpToolStripMenuItem.Size = new System.Drawing.Size(44, 20);
            this.helpToolStripMenuItem.Text = "Help";
            // 
            // quickGuideToolStripMenuItem
            // 
            this.quickGuideToolStripMenuItem.Name = "quickGuideToolStripMenuItem";
            this.quickGuideToolStripMenuItem.Size = new System.Drawing.Size(136, 22);
            this.quickGuideToolStripMenuItem.Text = "QuickGuide";
            this.quickGuideToolStripMenuItem.Click += new System.EventHandler(this.HelpQuickGuide);
            // 
            // aboutToolStripMenuItem
            // 
            this.aboutToolStripMenuItem.Image = global::GLEED2D.Properties.Resources._15;
            this.aboutToolStripMenuItem.Name = "aboutToolStripMenuItem";
            this.aboutToolStripMenuItem.ShortcutKeys = System.Windows.Forms.Keys.F1;
            this.aboutToolStripMenuItem.Size = new System.Drawing.Size(136, 22);
            this.aboutToolStripMenuItem.Text = "About";
            this.aboutToolStripMenuItem.Click += new System.EventHandler(this.HelpAbout);
            // 
            // toolStrip1
            // 
            this.toolStrip1.GripStyle = System.Windows.Forms.ToolStripGripStyle.Hidden;
            this.toolStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.newToolStripButton,
            this.openToolStripButton,
            this.saveToolStripButton,
            this.toolStripSeparator,
            this.undoButton,
            this.redoButton,
            this.toolStripSeparator8,
            this.toolStripLabel1,
            this.zoomcombo,
            this.zoomFitButton,
            this.toolStripSeparator17,
            this.ShowGridButton,
            this.SnapToGridButton,
            this.ShowWorldOriginButton,
            this.toolStripSeparator12,
            this.sendToMainStripButton,
            this.sendToBackStripButton,
            this.toolStripSeparator21,
            this.toolStripLabel2,
            this.addBehaviorStripButton,
            this.toolStripButton3,
            this.toolStripButton5,
            this.toolStripSeparator22,
            this.toolStripSplitButton1,
            this.toolStripSeparator19,
            this.toolStripButton2});
            this.toolStrip1.Location = new System.Drawing.Point(0, 24);
            this.toolStrip1.Name = "toolStrip1";
            this.toolStrip1.RenderMode = System.Windows.Forms.ToolStripRenderMode.Professional;
            this.toolStrip1.Size = new System.Drawing.Size(1002, 25);
            this.toolStrip1.Stretch = true;
            this.toolStrip1.TabIndex = 5;
            this.toolStrip1.Text = "toolStrip1";
            // 
            // newToolStripButton
            // 
            this.newToolStripButton.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.newToolStripButton.Image = ((System.Drawing.Image)(resources.GetObject("newToolStripButton.Image")));
            this.newToolStripButton.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.newToolStripButton.Name = "newToolStripButton";
            this.newToolStripButton.Size = new System.Drawing.Size(23, 22);
            this.newToolStripButton.Text = "&New";
            this.newToolStripButton.Click += new System.EventHandler(this.FileNew);
            // 
            // openToolStripButton
            // 
            this.openToolStripButton.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.openToolStripButton.Image = ((System.Drawing.Image)(resources.GetObject("openToolStripButton.Image")));
            this.openToolStripButton.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.openToolStripButton.Name = "openToolStripButton";
            this.openToolStripButton.Size = new System.Drawing.Size(23, 22);
            this.openToolStripButton.Text = "&Open";
            this.openToolStripButton.Click += new System.EventHandler(this.FileOpen);
            // 
            // saveToolStripButton
            // 
            this.saveToolStripButton.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.saveToolStripButton.Image = ((System.Drawing.Image)(resources.GetObject("saveToolStripButton.Image")));
            this.saveToolStripButton.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.saveToolStripButton.Name = "saveToolStripButton";
            this.saveToolStripButton.Size = new System.Drawing.Size(23, 22);
            this.saveToolStripButton.Text = "&Save";
            this.saveToolStripButton.ToolTipText = "Save";
            this.saveToolStripButton.Click += new System.EventHandler(this.FileSave);
            // 
            // toolStripSeparator
            // 
            this.toolStripSeparator.Name = "toolStripSeparator";
            this.toolStripSeparator.Size = new System.Drawing.Size(6, 25);
            // 
            // undoButton
            // 
            this.undoButton.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.undoButton.Image = ((System.Drawing.Image)(resources.GetObject("undoButton.Image")));
            this.undoButton.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.undoButton.Name = "undoButton";
            this.undoButton.Size = new System.Drawing.Size(32, 22);
            this.undoButton.Text = "toolStripButton2";
            this.undoButton.ToolTipText = "Undo";
            this.undoButton.ButtonClick += new System.EventHandler(this.EditUndo);
            this.undoButton.DropDownItemClicked += new System.Windows.Forms.ToolStripItemClickedEventHandler(this.UndoManyCommands);
            // 
            // redoButton
            // 
            this.redoButton.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.redoButton.Enabled = false;
            this.redoButton.Image = ((System.Drawing.Image)(resources.GetObject("redoButton.Image")));
            this.redoButton.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.redoButton.Name = "redoButton";
            this.redoButton.Size = new System.Drawing.Size(32, 22);
            this.redoButton.Text = "toolStripButton3";
            this.redoButton.ToolTipText = "Redo";
            this.redoButton.ButtonClick += new System.EventHandler(this.EditRedo);
            this.redoButton.DropDownItemClicked += new System.Windows.Forms.ToolStripItemClickedEventHandler(this.RedoManyCommands);
            // 
            // toolStripSeparator8
            // 
            this.toolStripSeparator8.Name = "toolStripSeparator8";
            this.toolStripSeparator8.Size = new System.Drawing.Size(6, 25);
            // 
            // toolStripLabel1
            // 
            this.toolStripLabel1.Name = "toolStripLabel1";
            this.toolStripLabel1.Size = new System.Drawing.Size(42, 22);
            this.toolStripLabel1.Text = "Zoom:";
            // 
            // zoomcombo
            // 
            this.zoomcombo.FlatStyle = System.Windows.Forms.FlatStyle.Standard;
            this.zoomcombo.Name = "zoomcombo";
            this.zoomcombo.Size = new System.Drawing.Size(75, 25);
            this.zoomcombo.TextChanged += new System.EventHandler(this.zoomcombo_TextChanged);
            // 
            // zoomFitButton
            // 
            this.zoomFitButton.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.zoomFitButton.Image = ((System.Drawing.Image)(resources.GetObject("zoomFitButton.Image")));
            this.zoomFitButton.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.zoomFitButton.Name = "zoomFitButton";
            this.zoomFitButton.Size = new System.Drawing.Size(23, 22);
            this.zoomFitButton.Text = "Set zoom so all content is visible";
            this.zoomFitButton.ToolTipText = "Set zoom to fit all contents";
            this.zoomFitButton.Click += new System.EventHandler(this.toolStripButton4_Click);
            // 
            // toolStripSeparator17
            // 
            this.toolStripSeparator17.Name = "toolStripSeparator17";
            this.toolStripSeparator17.Size = new System.Drawing.Size(6, 25);
            // 
            // ShowGridButton
            // 
            this.ShowGridButton.CheckOnClick = true;
            this.ShowGridButton.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.ShowGridButton.Image = ((System.Drawing.Image)(resources.GetObject("ShowGridButton.Image")));
            this.ShowGridButton.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.ShowGridButton.Name = "ShowGridButton";
            this.ShowGridButton.Size = new System.Drawing.Size(23, 22);
            this.ShowGridButton.Text = "toolStripButton4";
            this.ShowGridButton.ToolTipText = "Show Grid";
            this.ShowGridButton.CheckedChanged += new System.EventHandler(this.ShowGridButton_CheckedChanged);
            // 
            // SnapToGridButton
            // 
            this.SnapToGridButton.CheckOnClick = true;
            this.SnapToGridButton.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.SnapToGridButton.Image = ((System.Drawing.Image)(resources.GetObject("SnapToGridButton.Image")));
            this.SnapToGridButton.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.SnapToGridButton.Name = "SnapToGridButton";
            this.SnapToGridButton.Size = new System.Drawing.Size(23, 22);
            this.SnapToGridButton.Text = "toolStripButton4";
            this.SnapToGridButton.ToolTipText = "Snap to Grid";
            this.SnapToGridButton.CheckedChanged += new System.EventHandler(this.SnapToGridButton_CheckedChanged);
            // 
            // ShowWorldOriginButton
            // 
            this.ShowWorldOriginButton.CheckOnClick = true;
            this.ShowWorldOriginButton.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.ShowWorldOriginButton.Image = ((System.Drawing.Image)(resources.GetObject("ShowWorldOriginButton.Image")));
            this.ShowWorldOriginButton.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.ShowWorldOriginButton.Name = "ShowWorldOriginButton";
            this.ShowWorldOriginButton.Size = new System.Drawing.Size(23, 22);
            this.ShowWorldOriginButton.Text = "toolStripButton4";
            this.ShowWorldOriginButton.ToolTipText = "Show World Origin";
            this.ShowWorldOriginButton.CheckedChanged += new System.EventHandler(this.ShowWorldOriginButton_CheckedChanged);
            // 
            // toolStripSeparator12
            // 
            this.toolStripSeparator12.Name = "toolStripSeparator12";
            this.toolStripSeparator12.Size = new System.Drawing.Size(6, 25);
            // 
            // sendToMainStripButton
            // 
            this.sendToMainStripButton.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.sendToMainStripButton.Image = ((System.Drawing.Image)(resources.GetObject("sendToMainStripButton.Image")));
            this.sendToMainStripButton.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.sendToMainStripButton.Name = "sendToMainStripButton";
            this.sendToMainStripButton.Size = new System.Drawing.Size(23, 22);
            this.sendToMainStripButton.Text = "Send selected items to layer above ";
            this.sendToMainStripButton.Click += new System.EventHandler(this.sendToMainStripButton_Click);
            // 
            // sendToBackStripButton
            // 
            this.sendToBackStripButton.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.sendToBackStripButton.Image = ((System.Drawing.Image)(resources.GetObject("sendToBackStripButton.Image")));
            this.sendToBackStripButton.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.sendToBackStripButton.Name = "sendToBackStripButton";
            this.sendToBackStripButton.Size = new System.Drawing.Size(23, 22);
            this.sendToBackStripButton.Text = "Send selected items to layer bellow";
            this.sendToBackStripButton.Click += new System.EventHandler(this.sendToBackStripButton_Click);
            // 
            // toolStripSeparator21
            // 
            this.toolStripSeparator21.Name = "toolStripSeparator21";
            this.toolStripSeparator21.Size = new System.Drawing.Size(6, 25);
            // 
            // toolStripLabel2
            // 
            this.toolStripLabel2.Name = "toolStripLabel2";
            this.toolStripLabel2.Size = new System.Drawing.Size(61, 22);
            this.toolStripLabel2.Text = "Behaviors:";
            // 
            // addBehaviorStripButton
            // 
            this.addBehaviorStripButton.Image = ((System.Drawing.Image)(resources.GetObject("addBehaviorStripButton.Image")));
            this.addBehaviorStripButton.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.addBehaviorStripButton.Name = "addBehaviorStripButton";
            this.addBehaviorStripButton.Size = new System.Drawing.Size(49, 22);
            this.addBehaviorStripButton.Text = "Add";
            // 
            // toolStripButton3
            // 
            this.toolStripButton3.Image = ((System.Drawing.Image)(resources.GetObject("toolStripButton3.Image")));
            this.toolStripButton3.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.toolStripButton3.Name = "toolStripButton3";
            this.toolStripButton3.Size = new System.Drawing.Size(64, 22);
            this.toolStripButton3.Text = "Toggle";
            // 
            // toolStripButton5
            // 
            this.toolStripButton5.Image = ((System.Drawing.Image)(resources.GetObject("toolStripButton5.Image")));
            this.toolStripButton5.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.toolStripButton5.Name = "toolStripButton5";
            this.toolStripButton5.Size = new System.Drawing.Size(70, 22);
            this.toolStripButton5.Text = "Remove";
            // 
            // toolStripSeparator22
            // 
            this.toolStripSeparator22.Name = "toolStripSeparator22";
            this.toolStripSeparator22.Size = new System.Drawing.Size(6, 25);
            // 
            // toolStripSplitButton1
            // 
            this.toolStripSplitButton1.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.toggleSolidToolStripMenuItem,
            this.toolStripMenuItem3,
            this.toggleCollectableToolStripMenuItem,
            this.toolStripSeparator23,
            this.clearSolidToolStripMenuItem,
            this.clearDynamciToolStripMenuItem,
            this.clearCollectibleToolStripMenuItem});
            this.toolStripSplitButton1.Image = ((System.Drawing.Image)(resources.GetObject("toolStripSplitButton1.Image")));
            this.toolStripSplitButton1.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.toolStripSplitButton1.Name = "toolStripSplitButton1";
            this.toolStripSplitButton1.Size = new System.Drawing.Size(67, 22);
            this.toolStripSplitButton1.Text = "Quick";
            // 
            // toggleSolidToolStripMenuItem
            // 
            this.toggleSolidToolStripMenuItem.Name = "toggleSolidToolStripMenuItem";
            this.toggleSolidToolStripMenuItem.Size = new System.Drawing.Size(160, 22);
            this.toggleSolidToolStripMenuItem.Text = "Set Solid";
            // 
            // toolStripMenuItem3
            // 
            this.toolStripMenuItem3.Name = "toolStripMenuItem3";
            this.toolStripMenuItem3.Size = new System.Drawing.Size(160, 22);
            this.toolStripMenuItem3.Text = "Set Dynamic";
            // 
            // toggleCollectableToolStripMenuItem
            // 
            this.toggleCollectableToolStripMenuItem.Name = "toggleCollectableToolStripMenuItem";
            this.toggleCollectableToolStripMenuItem.Size = new System.Drawing.Size(160, 22);
            this.toggleCollectableToolStripMenuItem.Text = "Set Collectable";
            // 
            // toolStripSeparator23
            // 
            this.toolStripSeparator23.Name = "toolStripSeparator23";
            this.toolStripSeparator23.Size = new System.Drawing.Size(157, 6);
            // 
            // clearSolidToolStripMenuItem
            // 
            this.clearSolidToolStripMenuItem.Name = "clearSolidToolStripMenuItem";
            this.clearSolidToolStripMenuItem.Size = new System.Drawing.Size(160, 22);
            this.clearSolidToolStripMenuItem.Text = "Clear Solid";
            // 
            // clearDynamciToolStripMenuItem
            // 
            this.clearDynamciToolStripMenuItem.Name = "clearDynamciToolStripMenuItem";
            this.clearDynamciToolStripMenuItem.Size = new System.Drawing.Size(160, 22);
            this.clearDynamciToolStripMenuItem.Text = "Clear Dynamic";
            this.clearDynamciToolStripMenuItem.Click += new System.EventHandler(this.clearDynamciToolStripMenuItem_Click);
            // 
            // clearCollectibleToolStripMenuItem
            // 
            this.clearCollectibleToolStripMenuItem.Name = "clearCollectibleToolStripMenuItem";
            this.clearCollectibleToolStripMenuItem.Size = new System.Drawing.Size(160, 22);
            this.clearCollectibleToolStripMenuItem.Text = "Clear Collectible";
            // 
            // toolStripSeparator19
            // 
            this.toolStripSeparator19.Name = "toolStripSeparator19";
            this.toolStripSeparator19.Size = new System.Drawing.Size(6, 25);
            // 
            // toolStripButton2
            // 
            this.toolStripButton2.Image = ((System.Drawing.Image)(resources.GetObject("toolStripButton2.Image")));
            this.toolStripButton2.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.toolStripButton2.Name = "toolStripButton2";
            this.toolStripButton2.Size = new System.Drawing.Size(78, 22);
            this.toolStripButton2.Text = "Run Level";
            this.toolStripButton2.ToolTipText = "Run Level in your own application. To use this, define the appropriate settings i" +
                "n the Tools->Settings dialog.";
            this.toolStripButton2.Click += new System.EventHandler(this.RunLevel);
            // 
            // LayerContextMenu
            // 
            this.LayerContextMenu.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.duplicateToolStripMenuItem,
            this.toolStripSeparator11,
            this.renameToolStripMenuItem,
            this.deleteToolStripMenuItem,
            this.toolStripSeparator2,
            this.LayerMoveUpEntry,
            this.LayerMoveDownEntry,
            this.toolStripSeparator18,
            this.toolStripMenuItem1});
            this.LayerContextMenu.Name = "LayerContextMenu";
            this.LayerContextMenu.Size = new System.Drawing.Size(190, 154);
            // 
            // duplicateToolStripMenuItem
            // 
            this.duplicateToolStripMenuItem.Name = "duplicateToolStripMenuItem";
            this.duplicateToolStripMenuItem.ShortcutKeyDisplayString = "";
            this.duplicateToolStripMenuItem.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.D)));
            this.duplicateToolStripMenuItem.Size = new System.Drawing.Size(189, 22);
            this.duplicateToolStripMenuItem.Text = "Duplicate";
            this.duplicateToolStripMenuItem.Click += new System.EventHandler(this.ActionDuplicate);
            // 
            // toolStripSeparator11
            // 
            this.toolStripSeparator11.Name = "toolStripSeparator11";
            this.toolStripSeparator11.Size = new System.Drawing.Size(186, 6);
            // 
            // renameToolStripMenuItem
            // 
            this.renameToolStripMenuItem.Name = "renameToolStripMenuItem";
            this.renameToolStripMenuItem.ShortcutKeys = System.Windows.Forms.Keys.F2;
            this.renameToolStripMenuItem.Size = new System.Drawing.Size(189, 22);
            this.renameToolStripMenuItem.Text = "Rename";
            this.renameToolStripMenuItem.Click += new System.EventHandler(this.ActionRename);
            // 
            // deleteToolStripMenuItem
            // 
            this.deleteToolStripMenuItem.Name = "deleteToolStripMenuItem";
            this.deleteToolStripMenuItem.ShortcutKeys = System.Windows.Forms.Keys.Delete;
            this.deleteToolStripMenuItem.Size = new System.Drawing.Size(189, 22);
            this.deleteToolStripMenuItem.Text = "Delete";
            this.deleteToolStripMenuItem.Click += new System.EventHandler(this.ActionDelete);
            // 
            // toolStripSeparator2
            // 
            this.toolStripSeparator2.Name = "toolStripSeparator2";
            this.toolStripSeparator2.Size = new System.Drawing.Size(186, 6);
            // 
            // LayerMoveUpEntry
            // 
            this.LayerMoveUpEntry.Name = "LayerMoveUpEntry";
            this.LayerMoveUpEntry.ShortcutKeys = System.Windows.Forms.Keys.F7;
            this.LayerMoveUpEntry.Size = new System.Drawing.Size(189, 22);
            this.LayerMoveUpEntry.Text = "Move Up";
            this.LayerMoveUpEntry.TextAlign = System.Drawing.ContentAlignment.MiddleRight;
            this.LayerMoveUpEntry.Click += new System.EventHandler(this.ActionMoveUp);
            // 
            // LayerMoveDownEntry
            // 
            this.LayerMoveDownEntry.Name = "LayerMoveDownEntry";
            this.LayerMoveDownEntry.ShortcutKeys = System.Windows.Forms.Keys.F8;
            this.LayerMoveDownEntry.Size = new System.Drawing.Size(189, 22);
            this.LayerMoveDownEntry.Text = "Move Down";
            this.LayerMoveDownEntry.Click += new System.EventHandler(this.ActionMoveDown);
            // 
            // toolStripSeparator18
            // 
            this.toolStripSeparator18.Name = "toolStripSeparator18";
            this.toolStripSeparator18.Size = new System.Drawing.Size(186, 6);
            // 
            // toolStripMenuItem1
            // 
            this.toolStripMenuItem1.Name = "toolStripMenuItem1";
            this.toolStripMenuItem1.Size = new System.Drawing.Size(189, 22);
            this.toolStripMenuItem1.Text = "Add Custom Property";
            this.toolStripMenuItem1.Click += new System.EventHandler(this.ActionAddCustomProperty);
            // 
            // splitContainer1
            // 
            this.splitContainer1.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.splitContainer1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.splitContainer1.FixedPanel = System.Windows.Forms.FixedPanel.Panel1;
            this.splitContainer1.Location = new System.Drawing.Point(0, 49);
            this.splitContainer1.Name = "splitContainer1";
            // 
            // splitContainer1.Panel1
            // 
            this.splitContainer1.Panel1.Controls.Add(this.splitContainer3);
            // 
            // splitContainer1.Panel2
            // 
            this.splitContainer1.Panel2.Controls.Add(this.splitContainer2);
            this.splitContainer1.Size = new System.Drawing.Size(1002, 645);
            this.splitContainer1.SplitterDistance = 243;
            this.splitContainer1.TabIndex = 6;
            // 
            // splitContainer3
            // 
            this.splitContainer3.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.splitContainer3.Dock = System.Windows.Forms.DockStyle.Fill;
            this.splitContainer3.FixedPanel = System.Windows.Forms.FixedPanel.Panel2;
            this.splitContainer3.Location = new System.Drawing.Point(0, 0);
            this.splitContainer3.Name = "splitContainer3";
            this.splitContainer3.Orientation = System.Windows.Forms.Orientation.Horizontal;
            // 
            // splitContainer3.Panel1
            // 
            this.splitContainer3.Panel1.Controls.Add(this.toolStripContainer1);
            // 
            // splitContainer3.Panel2
            // 
            this.splitContainer3.Panel2.Controls.Add(this.propertyGrid1);
            this.splitContainer3.Size = new System.Drawing.Size(243, 645);
            this.splitContainer3.SplitterDistance = 304;
            this.splitContainer3.TabIndex = 0;
            // 
            // toolStripContainer1
            // 
            // 
            // toolStripContainer1.ContentPanel
            // 
            this.toolStripContainer1.ContentPanel.Controls.Add(this.treeView1);
            this.toolStripContainer1.ContentPanel.Size = new System.Drawing.Size(239, 275);
            this.toolStripContainer1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.toolStripContainer1.Location = new System.Drawing.Point(0, 0);
            this.toolStripContainer1.Name = "toolStripContainer1";
            this.toolStripContainer1.Size = new System.Drawing.Size(239, 300);
            this.toolStripContainer1.TabIndex = 0;
            this.toolStripContainer1.Text = "toolStripContainer1";
            // 
            // toolStripContainer1.TopToolStripPanel
            // 
            this.toolStripContainer1.TopToolStripPanel.Controls.Add(this.treetools);
            this.toolStripContainer1.TopToolStripPanel.RenderMode = System.Windows.Forms.ToolStripRenderMode.System;
            // 
            // treetools
            // 
            this.treetools.Dock = System.Windows.Forms.DockStyle.None;
            this.treetools.GripStyle = System.Windows.Forms.ToolStripGripStyle.Hidden;
            this.treetools.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.toolStripButton1,
            this.buttonDelete,
            this.toolStripSeparator4,
            this.butonMoveUp,
            this.buttonMoveDown});
            this.treetools.Location = new System.Drawing.Point(3, 0);
            this.treetools.Name = "treetools";
            this.treetools.Size = new System.Drawing.Size(101, 25);
            this.treetools.TabIndex = 0;
            // 
            // toolStripButton1
            // 
            this.toolStripButton1.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.toolStripButton1.Image = ((System.Drawing.Image)(resources.GetObject("toolStripButton1.Image")));
            this.toolStripButton1.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.toolStripButton1.Name = "toolStripButton1";
            this.toolStripButton1.Size = new System.Drawing.Size(23, 22);
            this.toolStripButton1.Text = "toolStripButton1";
            this.toolStripButton1.ToolTipText = "New Layer (N)";
            this.toolStripButton1.Click += new System.EventHandler(this.ActionNewLayer);
            // 
            // buttonDelete
            // 
            this.buttonDelete.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.buttonDelete.Image = ((System.Drawing.Image)(resources.GetObject("buttonDelete.Image")));
            this.buttonDelete.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.buttonDelete.Name = "buttonDelete";
            this.buttonDelete.Size = new System.Drawing.Size(23, 22);
            this.buttonDelete.Text = "Delete";
            this.buttonDelete.ToolTipText = "Delete (Del)";
            this.buttonDelete.Click += new System.EventHandler(this.ActionDelete);
            // 
            // toolStripSeparator4
            // 
            this.toolStripSeparator4.Name = "toolStripSeparator4";
            this.toolStripSeparator4.Size = new System.Drawing.Size(6, 25);
            // 
            // butonMoveUp
            // 
            this.butonMoveUp.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.butonMoveUp.Image = ((System.Drawing.Image)(resources.GetObject("butonMoveUp.Image")));
            this.butonMoveUp.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.butonMoveUp.Name = "butonMoveUp";
            this.butonMoveUp.Size = new System.Drawing.Size(23, 22);
            this.butonMoveUp.Text = "toolStripButton3";
            this.butonMoveUp.ToolTipText = "Move Up (F7)";
            this.butonMoveUp.Click += new System.EventHandler(this.ActionMoveUp);
            // 
            // buttonMoveDown
            // 
            this.buttonMoveDown.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.buttonMoveDown.Image = ((System.Drawing.Image)(resources.GetObject("buttonMoveDown.Image")));
            this.buttonMoveDown.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.buttonMoveDown.Name = "buttonMoveDown";
            this.buttonMoveDown.Size = new System.Drawing.Size(23, 22);
            this.buttonMoveDown.Text = "toolStripButton4";
            this.buttonMoveDown.ToolTipText = "Move Down (F8)";
            this.buttonMoveDown.Click += new System.EventHandler(this.ActionMoveDown);
            // 
            // splitContainer2
            // 
            this.splitContainer2.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.splitContainer2.Dock = System.Windows.Forms.DockStyle.Fill;
            this.splitContainer2.FixedPanel = System.Windows.Forms.FixedPanel.Panel2;
            this.splitContainer2.Location = new System.Drawing.Point(0, 0);
            this.splitContainer2.Name = "splitContainer2";
            this.splitContainer2.Orientation = System.Windows.Forms.Orientation.Horizontal;
            // 
            // splitContainer2.Panel1
            // 
            this.splitContainer2.Panel1.BackColor = System.Drawing.SystemColors.Control;
            this.splitContainer2.Panel1.Controls.Add(this.pictureBox1);
            // 
            // splitContainer2.Panel2
            // 
            this.splitContainer2.Panel2.BackColor = System.Drawing.SystemColors.Control;
            this.splitContainer2.Panel2.Controls.Add(this.tabControl1);
            this.splitContainer2.Size = new System.Drawing.Size(755, 645);
            this.splitContainer2.SplitterDistance = 444;
            this.splitContainer2.TabIndex = 0;
            // 
            // tabControl1
            // 
            this.tabControl1.Controls.Add(this.tabPage1);
            this.tabControl1.Controls.Add(this.EntitiesTabPage);
            this.tabControl1.Controls.Add(this.EnemiesTabPage);
            this.tabControl1.Controls.Add(this.tabPage2);
            this.tabControl1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.tabControl1.HotTrack = true;
            this.tabControl1.Location = new System.Drawing.Point(0, 0);
            this.tabControl1.Name = "tabControl1";
            this.tabControl1.SelectedIndex = 0;
            this.tabControl1.Size = new System.Drawing.Size(751, 193);
            this.tabControl1.TabIndex = 0;
            // 
            // tabPage1
            // 
            this.tabPage1.Controls.Add(this.splitContainer4);
            this.tabPage1.Location = new System.Drawing.Point(4, 22);
            this.tabPage1.Name = "tabPage1";
            this.tabPage1.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage1.Size = new System.Drawing.Size(743, 167);
            this.tabPage1.TabIndex = 0;
            this.tabPage1.Text = "Textures";
            this.tabPage1.UseVisualStyleBackColor = true;
            // 
            // splitContainer4
            // 
            this.splitContainer4.Dock = System.Windows.Forms.DockStyle.Fill;
            this.splitContainer4.FixedPanel = System.Windows.Forms.FixedPanel.Panel1;
            this.splitContainer4.Location = new System.Drawing.Point(3, 3);
            this.splitContainer4.Name = "splitContainer4";
            this.splitContainer4.Orientation = System.Windows.Forms.Orientation.Horizontal;
            // 
            // splitContainer4.Panel1
            // 
            this.splitContainer4.Panel1.Controls.Add(this.panel1);
            // 
            // splitContainer4.Panel2
            // 
            this.splitContainer4.Panel2.Controls.Add(this.listView1);
            this.splitContainer4.Size = new System.Drawing.Size(737, 161);
            this.splitContainer4.SplitterDistance = 32;
            this.splitContainer4.TabIndex = 8;
            // 
            // panel1
            // 
            this.panel1.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.panel1.Controls.Add(this.panel5);
            this.panel1.Controls.Add(this.panel4);
            this.panel1.Controls.Add(this.panel3);
            this.panel1.Controls.Add(this.panel2);
            this.panel1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.panel1.Location = new System.Drawing.Point(0, 0);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(737, 32);
            this.panel1.TabIndex = 7;
            // 
            // panel5
            // 
            this.panel5.Controls.Add(this.textBox1);
            this.panel5.Dock = System.Windows.Forms.DockStyle.Fill;
            this.panel5.Location = new System.Drawing.Point(43, 0);
            this.panel5.Name = "panel5";
            this.panel5.Padding = new System.Windows.Forms.Padding(0, 5, 0, 0);
            this.panel5.Size = new System.Drawing.Size(462, 32);
            this.panel5.TabIndex = 3;
            // 
            // textBox1
            // 
            this.textBox1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.textBox1.Location = new System.Drawing.Point(0, 5);
            this.textBox1.Name = "textBox1";
            this.textBox1.ReadOnly = true;
            this.textBox1.Size = new System.Drawing.Size(462, 20);
            this.textBox1.TabIndex = 1;
            // 
            // panel4
            // 
            this.panel4.Controls.Add(this.label1);
            this.panel4.Dock = System.Windows.Forms.DockStyle.Left;
            this.panel4.Location = new System.Drawing.Point(0, 0);
            this.panel4.Name = "panel4";
            this.panel4.Size = new System.Drawing.Size(43, 32);
            this.panel4.TabIndex = 2;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(3, 8);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(39, 13);
            this.label1.TabIndex = 0;
            this.label1.Text = "Folder:";
            // 
            // panel3
            // 
            this.panel3.Controls.Add(this.buttonFolderUp);
            this.panel3.Controls.Add(this.chooseFolder);
            this.panel3.Dock = System.Windows.Forms.DockStyle.Right;
            this.panel3.Location = new System.Drawing.Point(505, 0);
            this.panel3.Name = "panel3";
            this.panel3.Size = new System.Drawing.Size(113, 32);
            this.panel3.TabIndex = 1;
            // 
            // buttonFolderUp
            // 
            this.buttonFolderUp.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.buttonFolderUp.Image = ((System.Drawing.Image)(resources.GetObject("buttonFolderUp.Image")));
            this.buttonFolderUp.Location = new System.Drawing.Point(7, 4);
            this.buttonFolderUp.Name = "buttonFolderUp";
            this.buttonFolderUp.Size = new System.Drawing.Size(32, 23);
            this.buttonFolderUp.TabIndex = 4;
            this.buttonFolderUp.UseVisualStyleBackColor = true;
            this.buttonFolderUp.Click += new System.EventHandler(this.buttonFolderUp_Click);
            // 
            // chooseFolder
            // 
            this.chooseFolder.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.chooseFolder.Location = new System.Drawing.Point(45, 4);
            this.chooseFolder.Name = "chooseFolder";
            this.chooseFolder.Size = new System.Drawing.Size(60, 23);
            this.chooseFolder.TabIndex = 5;
            this.chooseFolder.Text = "Choose...";
            this.chooseFolder.UseVisualStyleBackColor = true;
            this.chooseFolder.Click += new System.EventHandler(this.chooseFolder_Click);
            // 
            // panel2
            // 
            this.panel2.Controls.Add(this.comboBox1);
            this.panel2.Controls.Add(this.label2);
            this.panel2.Dock = System.Windows.Forms.DockStyle.Right;
            this.panel2.Location = new System.Drawing.Point(618, 0);
            this.panel2.Name = "panel2";
            this.panel2.Size = new System.Drawing.Size(119, 32);
            this.panel2.TabIndex = 0;
            // 
            // comboBox1
            // 
            this.comboBox1.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.comboBox1.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.comboBox1.FormattingEnabled = true;
            this.comboBox1.Location = new System.Drawing.Point(40, 5);
            this.comboBox1.Name = "comboBox1";
            this.comboBox1.Size = new System.Drawing.Size(74, 21);
            this.comboBox1.TabIndex = 2;
            this.comboBox1.SelectedIndexChanged += new System.EventHandler(this.comboSize_SelectedIndexChanged);
            // 
            // label2
            // 
            this.label2.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(4, 9);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(30, 13);
            this.label2.TabIndex = 3;
            this.label2.Text = "Size:";
            // 
            // listView1
            // 
            this.listView1.AllowDrop = true;
            this.listView1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.listView1.HideSelection = false;
            this.listView1.LargeImageList = this.imageList96;
            this.listView1.Location = new System.Drawing.Point(0, 0);
            this.listView1.MultiSelect = false;
            this.listView1.Name = "listView1";
            this.listView1.ShowItemToolTips = true;
            this.listView1.Size = new System.Drawing.Size(737, 125);
            this.listView1.TabIndex = 6;
            this.listView1.UseCompatibleStateImageBehavior = false;
            this.listView1.MouseDoubleClick += new System.Windows.Forms.MouseEventHandler(this.listView1_MouseDoubleClick);
            this.listView1.DragDrop += new System.Windows.Forms.DragEventHandler(this.listView1_DragDrop);
            this.listView1.GiveFeedback += new System.Windows.Forms.GiveFeedbackEventHandler(this.listView1_GiveFeedback);
            this.listView1.ItemDrag += new System.Windows.Forms.ItemDragEventHandler(this.listView1_ItemDrag);
            this.listView1.DragOver += new System.Windows.Forms.DragEventHandler(this.listView1_DragOver);
            this.listView1.Click += new System.EventHandler(this.listView1_Click);
            // 
            // imageList96
            // 
            this.imageList96.ColorDepth = System.Windows.Forms.ColorDepth.Depth32Bit;
            this.imageList96.ImageSize = new System.Drawing.Size(96, 96);
            this.imageList96.TransparentColor = System.Drawing.Color.Transparent;
            // 
            // EntitiesTabPage
            // 
            this.EntitiesTabPage.Controls.Add(this.entitiesListView);
            this.EntitiesTabPage.Location = new System.Drawing.Point(4, 22);
            this.EntitiesTabPage.Name = "EntitiesTabPage";
            this.EntitiesTabPage.Padding = new System.Windows.Forms.Padding(3);
            this.EntitiesTabPage.Size = new System.Drawing.Size(739, 167);
            this.EntitiesTabPage.TabIndex = 2;
            this.EntitiesTabPage.Text = "Game Entities ";
            this.EntitiesTabPage.UseVisualStyleBackColor = true;
            // 
            // entitiesListView
            // 
            this.entitiesListView.CausesValidation = false;
            this.entitiesListView.Dock = System.Windows.Forms.DockStyle.Fill;
            this.entitiesListView.HideSelection = false;
            this.entitiesListView.Items.AddRange(new System.Windows.Forms.ListViewItem[] {
            listViewItem1,
            listViewItem2});
            this.entitiesListView.LargeImageList = this.entitiesImageList;
            this.entitiesListView.Location = new System.Drawing.Point(3, 3);
            this.entitiesListView.MultiSelect = false;
            this.entitiesListView.Name = "entitiesListView";
            this.entitiesListView.Size = new System.Drawing.Size(733, 161);
            this.entitiesListView.TabIndex = 0;
            this.entitiesListView.UseCompatibleStateImageBehavior = false;
            this.entitiesListView.MouseDoubleClick += new System.Windows.Forms.MouseEventHandler(this.entitiesListView_MouseDoubleClick);
            this.entitiesListView.SelectedIndexChanged += new System.EventHandler(this.listView3_SelectedIndexChanged);
            // 
            // entitiesImageList
            // 
            this.entitiesImageList.ImageStream = ((System.Windows.Forms.ImageListStreamer)(resources.GetObject("entitiesImageList.ImageStream")));
            this.entitiesImageList.TransparentColor = System.Drawing.Color.Transparent;
            this.entitiesImageList.Images.SetKeyName(0, "EntityExit.png");
            this.entitiesImageList.Images.SetKeyName(1, "EntityPlayer.png");
            // 
            // EnemiesTabPage
            // 
            this.EnemiesTabPage.Controls.Add(this.listView3);
            this.EnemiesTabPage.Location = new System.Drawing.Point(4, 22);
            this.EnemiesTabPage.Name = "EnemiesTabPage";
            this.EnemiesTabPage.Padding = new System.Windows.Forms.Padding(3);
            this.EnemiesTabPage.Size = new System.Drawing.Size(739, 167);
            this.EnemiesTabPage.TabIndex = 3;
            this.EnemiesTabPage.Text = "Enemies";
            this.EnemiesTabPage.UseVisualStyleBackColor = true;
            // 
            // listView3
            // 
            this.listView3.Dock = System.Windows.Forms.DockStyle.Fill;
            this.listView3.HideSelection = false;
            this.listView3.Items.AddRange(new System.Windows.Forms.ListViewItem[] {
            listViewItem3,
            listViewItem4});
            this.listView3.LargeImageList = this.enemiesImageList;
            this.listView3.Location = new System.Drawing.Point(3, 3);
            this.listView3.MultiSelect = false;
            this.listView3.Name = "listView3";
            this.listView3.Size = new System.Drawing.Size(733, 161);
            this.listView3.TabIndex = 0;
            this.listView3.UseCompatibleStateImageBehavior = false;
            // 
            // enemiesImageList
            // 
            this.enemiesImageList.ImageStream = ((System.Windows.Forms.ImageListStreamer)(resources.GetObject("enemiesImageList.ImageStream")));
            this.enemiesImageList.TransparentColor = System.Drawing.Color.Transparent;
            this.enemiesImageList.Images.SetKeyName(0, "EnemyBat.png");
            this.enemiesImageList.Images.SetKeyName(1, "EnemyCrow.png");
            // 
            // tabPage2
            // 
            this.tabPage2.Controls.Add(this.listView2);
            this.tabPage2.Location = new System.Drawing.Point(4, 22);
            this.tabPage2.Name = "tabPage2";
            this.tabPage2.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage2.Size = new System.Drawing.Size(739, 167);
            this.tabPage2.TabIndex = 1;
            this.tabPage2.Text = "Primitives";
            this.tabPage2.UseVisualStyleBackColor = true;
            // 
            // listView2
            // 
            this.listView2.Dock = System.Windows.Forms.DockStyle.Fill;
            this.listView2.HideSelection = false;
            listViewItem5.ToolTipText = "A simple rectangle defined by position, width and height. Rectangle Primitives ca" +
                "n be scaled but not rotated.";
            listViewItem6.ToolTipText = "A simple circle defined by position and radius. Circle Primitives can be scaled b" +
                "ut not rotated.";
            listViewItem7.ToolTipText = "A Path is an array of Vector2. Path Primitives can be rotated and scaled.";
            this.listView2.Items.AddRange(new System.Windows.Forms.ListViewItem[] {
            listViewItem5,
            listViewItem6,
            listViewItem7});
            this.listView2.LargeImageList = this.imageList1;
            this.listView2.Location = new System.Drawing.Point(3, 3);
            this.listView2.MultiSelect = false;
            this.listView2.Name = "listView2";
            this.listView2.ShowItemToolTips = true;
            this.listView2.Size = new System.Drawing.Size(733, 161);
            this.listView2.TabIndex = 0;
            this.listView2.UseCompatibleStateImageBehavior = false;
            this.listView2.MouseDoubleClick += new System.Windows.Forms.MouseEventHandler(this.listView2_MouseDoubleClick);
            // 
            // imageList1
            // 
            this.imageList1.ImageStream = ((System.Windows.Forms.ImageListStreamer)(resources.GetObject("imageList1.ImageStream")));
            this.imageList1.TransparentColor = System.Drawing.Color.Transparent;
            this.imageList1.Images.SetKeyName(0, "primitive_rectangle.png");
            this.imageList1.Images.SetKeyName(1, "primitive_circle.png");
            this.imageList1.Images.SetKeyName(2, "primitive_path.png");
            // 
            // imageList48
            // 
            this.imageList48.ColorDepth = System.Windows.Forms.ColorDepth.Depth32Bit;
            this.imageList48.ImageSize = new System.Drawing.Size(48, 48);
            this.imageList48.TransparentColor = System.Drawing.Color.Transparent;
            // 
            // imageList64
            // 
            this.imageList64.ColorDepth = System.Windows.Forms.ColorDepth.Depth32Bit;
            this.imageList64.ImageSize = new System.Drawing.Size(64, 64);
            this.imageList64.TransparentColor = System.Drawing.Color.Transparent;
            // 
            // imageList128
            // 
            this.imageList128.ColorDepth = System.Windows.Forms.ColorDepth.Depth32Bit;
            this.imageList128.ImageSize = new System.Drawing.Size(128, 128);
            this.imageList128.TransparentColor = System.Drawing.Color.Transparent;
            // 
            // imageList256
            // 
            this.imageList256.ColorDepth = System.Windows.Forms.ColorDepth.Depth32Bit;
            this.imageList256.ImageSize = new System.Drawing.Size(256, 256);
            this.imageList256.TransparentColor = System.Drawing.Color.Transparent;
            // 
            // backgroundWorker1
            // 
            this.backgroundWorker1.WorkerReportsProgress = true;
            this.backgroundWorker1.WorkerSupportsCancellation = true;
            this.backgroundWorker1.DoWork += new System.ComponentModel.DoWorkEventHandler(this.backgroundWorker1_DoWork);
            this.backgroundWorker1.RunWorkerCompleted += new System.ComponentModel.RunWorkerCompletedEventHandler(this.backgroundWorker1_RunWorkerCompleted);
            this.backgroundWorker1.ProgressChanged += new System.ComponentModel.ProgressChangedEventHandler(this.backgroundWorker1_ProgressChanged);
            // 
            // LevelContextMenu
            // 
            this.LevelContextMenu.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.centerViewToolStripMenuItem,
            this.addLayerToolStripMenuItem,
            this.toolStripSeparator13,
            this.toolStripMenuItem2,
            this.toolStripSeparator15,
            this.toolStripMenuItem6,
            this.toolStripSeparator20,
            this.insertGameLayersToolStripMenuItem});
            this.LevelContextMenu.Name = "ItemContextMenu";
            this.LevelContextMenu.RenderMode = System.Windows.Forms.ToolStripRenderMode.Professional;
            this.LevelContextMenu.Size = new System.Drawing.Size(190, 132);
            this.LevelContextMenu.Opening += new System.ComponentModel.CancelEventHandler(this.LevelContextMenu_Opening);
            // 
            // centerViewToolStripMenuItem
            // 
            this.centerViewToolStripMenuItem.Name = "centerViewToolStripMenuItem";
            this.centerViewToolStripMenuItem.ShortcutKeys = System.Windows.Forms.Keys.F4;
            this.centerViewToolStripMenuItem.Size = new System.Drawing.Size(189, 22);
            this.centerViewToolStripMenuItem.Text = "Center View";
            this.centerViewToolStripMenuItem.Click += new System.EventHandler(this.ActionCenterView);
            // 
            // addLayerToolStripMenuItem
            // 
            this.addLayerToolStripMenuItem.Name = "addLayerToolStripMenuItem";
            this.addLayerToolStripMenuItem.Size = new System.Drawing.Size(189, 22);
            this.addLayerToolStripMenuItem.Text = "Add Layer";
            this.addLayerToolStripMenuItem.Click += new System.EventHandler(this.ActionNewLayer);
            // 
            // toolStripSeparator13
            // 
            this.toolStripSeparator13.Name = "toolStripSeparator13";
            this.toolStripSeparator13.Size = new System.Drawing.Size(186, 6);
            // 
            // toolStripMenuItem2
            // 
            this.toolStripMenuItem2.Name = "toolStripMenuItem2";
            this.toolStripMenuItem2.ShortcutKeys = System.Windows.Forms.Keys.F2;
            this.toolStripMenuItem2.Size = new System.Drawing.Size(189, 22);
            this.toolStripMenuItem2.Text = "Rename";
            this.toolStripMenuItem2.Click += new System.EventHandler(this.ActionRename);
            // 
            // toolStripSeparator15
            // 
            this.toolStripSeparator15.Name = "toolStripSeparator15";
            this.toolStripSeparator15.Size = new System.Drawing.Size(186, 6);
            // 
            // toolStripMenuItem6
            // 
            this.toolStripMenuItem6.Name = "toolStripMenuItem6";
            this.toolStripMenuItem6.Size = new System.Drawing.Size(189, 22);
            this.toolStripMenuItem6.Text = "Add Custom Property";
            this.toolStripMenuItem6.Click += new System.EventHandler(this.ActionAddCustomProperty);
            // 
            // toolStripSeparator20
            // 
            this.toolStripSeparator20.Name = "toolStripSeparator20";
            this.toolStripSeparator20.Size = new System.Drawing.Size(186, 6);
            // 
            // insertGameLayersToolStripMenuItem
            // 
            this.insertGameLayersToolStripMenuItem.Name = "insertGameLayersToolStripMenuItem";
            this.insertGameLayersToolStripMenuItem.Size = new System.Drawing.Size(189, 22);
            this.insertGameLayersToolStripMenuItem.Text = "Insert Game Layers";
            this.insertGameLayersToolStripMenuItem.Click += new System.EventHandler(this.insertGameLayersToolStripMenuItem_Click);
            // 
            // MainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1002, 716);
            this.Controls.Add(this.splitContainer1);
            this.Controls.Add(this.toolStrip1);
            this.Controls.Add(this.statusStrip1);
            this.Controls.Add(this.menuStrip1);
            this.DoubleBuffered = true;
            this.Location = new System.Drawing.Point(10, 10);
            this.MainMenuStrip = this.menuStrip1;
            this.Name = "MainForm";
            this.Text = "Finding Home Editor";
            this.Load += new System.EventHandler(this.MainForm_Load);
            this.FormClosed += new System.Windows.Forms.FormClosedEventHandler(this.MainForm_FormClosed);
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.MainForm_FormClosing);
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            this.statusStrip1.ResumeLayout(false);
            this.statusStrip1.PerformLayout();
            this.CustomPropertyContextMenu.ResumeLayout(false);
            this.ItemContextMenu.ResumeLayout(false);
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.toolStrip1.ResumeLayout(false);
            this.toolStrip1.PerformLayout();
            this.LayerContextMenu.ResumeLayout(false);
            this.splitContainer1.Panel1.ResumeLayout(false);
            this.splitContainer1.Panel2.ResumeLayout(false);
            this.splitContainer1.ResumeLayout(false);
            this.splitContainer3.Panel1.ResumeLayout(false);
            this.splitContainer3.Panel2.ResumeLayout(false);
            this.splitContainer3.ResumeLayout(false);
            this.toolStripContainer1.ContentPanel.ResumeLayout(false);
            this.toolStripContainer1.TopToolStripPanel.ResumeLayout(false);
            this.toolStripContainer1.TopToolStripPanel.PerformLayout();
            this.toolStripContainer1.ResumeLayout(false);
            this.toolStripContainer1.PerformLayout();
            this.treetools.ResumeLayout(false);
            this.treetools.PerformLayout();
            this.splitContainer2.Panel1.ResumeLayout(false);
            this.splitContainer2.Panel2.ResumeLayout(false);
            this.splitContainer2.ResumeLayout(false);
            this.tabControl1.ResumeLayout(false);
            this.tabPage1.ResumeLayout(false);
            this.splitContainer4.Panel1.ResumeLayout(false);
            this.splitContainer4.Panel2.ResumeLayout(false);
            this.splitContainer4.ResumeLayout(false);
            this.panel1.ResumeLayout(false);
            this.panel5.ResumeLayout(false);
            this.panel5.PerformLayout();
            this.panel4.ResumeLayout(false);
            this.panel4.PerformLayout();
            this.panel3.ResumeLayout(false);
            this.panel2.ResumeLayout(false);
            this.panel2.PerformLayout();
            this.EntitiesTabPage.ResumeLayout(false);
            this.EnemiesTabPage.ResumeLayout(false);
            this.tabPage2.ResumeLayout(false);
            this.LevelContextMenu.ResumeLayout(false);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.StatusStrip statusStrip1;
        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStrip toolStrip1;
        private System.Windows.Forms.ToolStripMenuItem fileToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem exitToolStripMenuItem;
        public System.Windows.Forms.PropertyGrid propertyGrid1;
        private System.Windows.Forms.ToolStripButton newToolStripButton;
        private System.Windows.Forms.ToolStripButton openToolStripButton;
        private System.Windows.Forms.ToolStripButton saveToolStripButton;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator;
        public System.Windows.Forms.TreeView treeView1;
        public System.Windows.Forms.PictureBox pictureBox1;
        private System.Windows.Forms.ToolStripMenuItem renameToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem deleteToolStripMenuItem;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator2;
        private System.Windows.Forms.ToolStripMenuItem LayerMoveUpEntry;
        private System.Windows.Forms.ToolStripMenuItem LayerMoveDownEntry;
        public System.Windows.Forms.ContextMenuStrip LayerContextMenu;
        public System.Windows.Forms.ToolStripStatusLabel toolStripStatusLabel1;
        private System.Windows.Forms.SplitContainer splitContainer1;
        private System.Windows.Forms.SplitContainer splitContainer3;
        private System.Windows.Forms.SplitContainer splitContainer2;
        public System.Windows.Forms.ToolStripStatusLabel toolStripStatusLabel2;
        public System.Windows.Forms.ToolStripStatusLabel toolStripStatusLabel3;
        public System.Windows.Forms.ToolStripStatusLabel toolStripStatusLabel4;
        private System.Windows.Forms.ToolStripMenuItem helpToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem aboutToolStripMenuItem;
        private System.Windows.Forms.ToolStripLabel toolStripLabel1;
        public System.Windows.Forms.ToolStripComboBox zoomcombo;
        private System.Windows.Forms.ToolStripMenuItem newToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem openToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem saveToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem saveAsToolStripMenuItem;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator1;
        private System.Windows.Forms.ToolStripMenuItem renameToolStripMenuItem1;
        private System.Windows.Forms.ToolStripMenuItem deleteToolStripMenuItem1;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator3;
        private System.Windows.Forms.ToolStripMenuItem moveUpToolStripMenuItem1;
        private System.Windows.Forms.ToolStripMenuItem moveDownToolStripMenuItem1;
        public System.Windows.Forms.ContextMenuStrip ItemContextMenu;
        private System.Windows.Forms.ToolStripContainer toolStripContainer1;
        private System.Windows.Forms.ToolStrip treetools;
        private System.Windows.Forms.ToolStripButton toolStripButton1;
        private System.Windows.Forms.ToolStripButton buttonDelete;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator4;
        private System.Windows.Forms.ToolStripButton butonMoveUp;
        private System.Windows.Forms.ToolStripButton buttonMoveDown;
        private System.Windows.Forms.ToolStripMenuItem ItemCenterViewEntry;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator5;
        private System.Windows.Forms.ToolStripMenuItem ToolsMenu;
        private System.Windows.Forms.ToolStripMenuItem settingsToolStripMenuItem1;
        private System.Windows.Forms.ToolStripMenuItem alignHorizontallyToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem alignVerticallyToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem alignRotationToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem alignScaleToolStripMenuItem;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator6;
        private System.Windows.Forms.ToolStripMenuItem moveSelectedItemsToLayerToolStripMenuItem;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator7;
        private System.Windows.Forms.ToolStripMenuItem copySelectedItemsToLayerToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem editToolStripMenuItem;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator8;
        public System.Windows.Forms.ToolStripMenuItem undoMenuItem;
        public System.Windows.Forms.ToolStripMenuItem redoMenuItem;
        public System.Windows.Forms.ToolStripSplitButton undoButton;
        public System.Windows.Forms.ToolStripSplitButton redoButton;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator9;
        private System.Windows.Forms.ToolStripMenuItem selectAllToolStripMenuItem;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator10;
        private System.Windows.Forms.ToolStripMenuItem addCustomPropertyToolStripMenuItem;
        private System.Windows.Forms.TabControl tabControl1;
        private System.Windows.Forms.TabPage tabPage1;
        private System.Windows.Forms.Button chooseFolder;
        private System.Windows.Forms.Button buttonFolderUp;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.ComboBox comboBox1;
        private System.Windows.Forms.TextBox textBox1;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.ListView listView1;
        private System.Windows.Forms.ImageList imageList48;
        private System.Windows.Forms.ImageList imageList96;
        private System.Windows.Forms.ImageList imageList64;
        private System.Windows.Forms.ImageList imageList128;
        private System.Windows.Forms.ImageList imageList256;
        private System.ComponentModel.BackgroundWorker backgroundWorker1;
        private System.Windows.Forms.TabPage tabPage2;
        public System.Windows.Forms.ListView listView2;
        private System.Windows.Forms.ToolStripMenuItem duplicateToolStripMenuItem;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator11;
        private System.Windows.Forms.ToolStripMenuItem runToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem runLevelInYourOwnApplicationToolStripMenuItem;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator12;
        private System.Windows.Forms.ToolStripButton toolStripButton2;
        public System.Windows.Forms.ContextMenuStrip LevelContextMenu;
        private System.Windows.Forms.ToolStripMenuItem toolStripMenuItem2;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator15;
        private System.Windows.Forms.ToolStripMenuItem toolStripMenuItem6;
        public System.Windows.Forms.ImageList imageList2;
        private System.Windows.Forms.ToolStripMenuItem addLayerToolStripMenuItem;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator13;
        private System.Windows.Forms.ContextMenuStrip CustomPropertyContextMenu;
        private System.Windows.Forms.ToolStripMenuItem deleteCustomPropertyToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem viewToolStripMenuItem;
        public System.Windows.Forms.ToolStripMenuItem ViewGrid;
        public System.Windows.Forms.ToolStripMenuItem ViewWorldOrigin;
        private System.Windows.Forms.ToolStripMenuItem centerViewToolStripMenuItem;
        private System.Windows.Forms.ToolStripButton ShowGridButton;
        private System.Windows.Forms.ToolStripButton ShowWorldOriginButton;
        private System.Windows.Forms.ToolStripMenuItem linkItemsByACustomPropertyToolStripMenuItem;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator16;
        private System.Windows.Forms.ImageList imageList1;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator17;
        private System.Windows.Forms.ToolStripMenuItem quickGuideToolStripMenuItem;
        private System.Windows.Forms.ToolStripButton SnapToGridButton;
        public System.Windows.Forms.ToolStripMenuItem ViewSnapToGrid;
        private System.Windows.Forms.ToolStripMenuItem toolStripMenuItem1;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator18;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator20;
        private System.Windows.Forms.ToolStripMenuItem insertGameLayersToolStripMenuItem;
        private System.Windows.Forms.ToolStripButton sendToMainStripButton;
        private System.Windows.Forms.ToolStripButton sendToBackStripButton;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator21;
        private System.Windows.Forms.TabPage EntitiesTabPage;
        private System.Windows.Forms.TabPage EnemiesTabPage;
        private System.Windows.Forms.ImageList entitiesImageList;
        private System.Windows.Forms.ImageList enemiesImageList;
        internal System.Windows.Forms.ListView entitiesListView;
        internal System.Windows.Forms.ListView listView3;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.Panel panel2;
        private System.Windows.Forms.Panel panel4;
        private System.Windows.Forms.Panel panel3;
        private System.Windows.Forms.Panel panel5;
        private System.Windows.Forms.ToolStripButton zoomFitButton;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator19;
        private System.Windows.Forms.SplitContainer splitContainer4;
        private System.Windows.Forms.ToolStripButton addBehaviorStripButton;
        private System.Windows.Forms.ToolStripLabel toolStripLabel2;
        private System.Windows.Forms.ToolStripButton toolStripButton3;
        private System.Windows.Forms.ToolStripMenuItem updatesToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem checkForUpdatesToolStripMenuItem;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator14;
        private System.Windows.Forms.ToolStripMenuItem sendErrorLogFileToolStripMenuItem;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator22;
        private System.Windows.Forms.ToolStripButton toolStripButton5;
        private System.Windows.Forms.ToolStripDropDownButton toolStripSplitButton1;
        private System.Windows.Forms.ToolStripMenuItem toggleSolidToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem toolStripMenuItem3;
        private System.Windows.Forms.ToolStripMenuItem toggleCollectableToolStripMenuItem;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator23;
        private System.Windows.Forms.ToolStripMenuItem clearSolidToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem clearDynamciToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem clearCollectibleToolStripMenuItem;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator24;
    }
}