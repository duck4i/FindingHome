//	Include file
require(SYS_FOLDER + "credits.js")

cc.log("Main menu loaded");

//	Actions controller
var MenuItemActions = {
	doPlay : function()
	{
		var scene =  gg.MainScene.scene();
		gg.Director.replaceScene(scene);
	},
	doLoad: function() {
		cc.log("TODO: LOAD");
	},
	doSave: function() {
		cc.log("TODO: SAVE");
	},
	doCredits : function()
	{
		var sc = cc.Scene.create();
		sc.addChild(new CreditsMenuLayer());
		gg.Director.replaceScene(sc);
	},
	doExit : function()
	{
		var g = new gg.Game();
		g.exit();
	}
};

//
//	VIEW CODE BELLOW
//

var menuItems = [
	["Play", MenuItemActions.doPlay],
	["", null],
	["Load game", MenuItemActions.doLoad],
	["Save game", MenuItemActions.doSave],
	["", null],
	["Credits", MenuItemActions.doCredits],
	["", null],
	["Exit", MenuItemActions.doExit]
];

//	Main menu layer
var MainMenuLayer = cc.LayerColor.extend(
{
	menu: null,
	
	ctor : function()
	{
		this._super();
		cc.associateWithNative( this, cc.LayerColor );
		this.init(cc.c4b(250, 100, 0, 255));
		this.load();
	},
	load : function()
	{
		var title = cc.LabelTTF.create("Finding Home", gg.Font, 64);		
		title.setColor(cc.c3b(255, 255, 255));
		title.setPosition(cc.p(gg.Width / 2.0, gg.Height / 2.0));
		this.addChild(title);							

		this.createMenuItems();
		this.scheduleUpdate();
	},
	createMenuItems: function()
	{
		cc.log("Found " + menuItems.length + " items");
		menu = cc.Menu.create();
		
		for (var i =0; i < menuItems.length; i++)
		{
			var item = menuItems[i][0];
			var action = menuItems[i][1];
			if (item == "")			
				continue;			
			
			cc.log("Item " + item);
			var text = cc.MenuItemFont.create(item, action, MenuItemActions);
			menu.addChild(text);			
		}
		
		menu.alignItemsVertically();
		
		var posx = gg.Width / 2;
		var posy = gg.Height / 2 - menuItems.length * 20;
		
		menu.setPosition(cc.p(posx, posy));
		this.addChild(menu);
	},
	update : function()
	{
		
	}
});

//	create scene and add main layer
var scene = cc.Scene.create();
scene.addChild(new MainMenuLayer());

//	then run it
gg.Director.runWithScene(scene);