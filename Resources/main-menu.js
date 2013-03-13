cc.log("Main menu loaded");

//	defines
var director = cc.Director.getInstance();
var winSize = director.getWinSize();
var font = "Arial";

//	Actions controller
var MenuItemActions = {
	doPlay : function() 
	{
		cc.log("TODO: PLAY");
	},
	doLoad: function() {
		cc.log("TODO: LOAD");
	},
	doSave: function() {
		cc.log("TODO: SAVE");
	},	
	doCredits : function()
	{
		cc.log("TODO: CREDITS");
	},
	doExit : function()
	{
		cc.log("TODO: EXIT");
	}
};

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
		var title = cc.LabelTTF.create("Finding Home", font, 64);		
		title.setColor(cc.c3b(255, 255, 255));
		title.setPosition(cc.p(winSize.width / 2.0, winSize.height / 2.0));
		this.addChild(title);							
							
		this.createMenuItems();		
	
		this.setTouchEnabled(true);
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
			{			
				continue;
			}
			
			cc.log("Item " + item);
			var text = cc.MenuItemFont.create(item, action, MenuItemActions);
			menu.addChild(text);			
		}
		
		menu.alignItemsVertically();
		
		var posx = winSize.width / 2;
		var posy = winSize.height / 2 - menuItems.length * 20;
		
		menu.setPosition(cc.p(posx, posy));
		this.addChild(menu);
	},
	update : function()
	{
		
	}
});

//	create scene and add main layer
var scene = cc.Scene.create();

var layer = new MainMenuLayer();
scene.addChild(layer);

//	then run it
director.runWithScene(scene);