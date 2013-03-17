//	Include file
require(SYS_FOLDER + "credits2.js")
require(SYS_FOLDER + "settings2.js")

cc.log("Main menu loaded");

//	Actions controller
var MenuItemActions = {
	doPlay : function()
	{
		var scene =  gg.MainScene.scene();
		cc.log("MainScene loaded from JS");
		var anim = cc.TransitionFade.create(gg.AnimationMedium, scene);
		gg.Director.replaceScene(anim);
	},
	doLoad: function() {
		cc.log("TODO: LOAD");
	},
	doSave: function() {
		cc.log("TODO: SAVE");
	},
	doCredits : function()
	{
		var sc = new CreditsMenuLayer();
		var anim = cc.TransitionSlideInR.create(gg.AnimationShort, sc);		
		gg.Director.replaceScene(anim);
	},
	doSettings: function(){
		var sc = new SettingsMenuLayer();
		var anim = cc.TransitionSlideInL.create(gg.AnimationShort, sc);		
		gg.Director.replaceScene(anim);
	},
	doExit : function()
	{
		var g = new gg.GameInstance();
		g.exit();
	}
};

//
//	VIEW CODE BELLOW
//

var menuItems = [
	["", null],
	["", null],
	["Play", MenuItemActions.doPlay],
	["", null],
	//["Load game", MenuItemActions.doLoad],
	//["Save game", MenuItemActions.doSave],
	//["", null],
	["Credits", MenuItemActions.doCredits],
	["", null],
	["Settings", MenuItemActions.doSettings],
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
	
	setBackground: function(parent)
	{
		var back = cc.Sprite.create("system/background.png");
		back.setAnchorPoint(cc.p(0, 0));
		back.setScale(0.7);
		parent.addChild(back);
		return back;
	},
	load : function()
	{
		this.setBackground(this);
	
		var title = cc.LabelTTF.create("Finding Home", gg.Font, 64);		
		title.setColor(cc.c3b(255, 255, 255));
		title.setPosition(cc.p(gg.Width / 2, (gg.Height * 0.85)));		
		this.addChild(title);							

		this.createMenuItems();
		this.animateMenu();
		
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
			text.setAnchorPoint(cc.p(0, 0.5));					
			menu.addChild(text);			
		}
		
		menu.alignItemsVertically();
		
		var posx = 30;
		var posy = menuItems.length * 15;
		
		menu.setPosition(cc.p(posx, posy));
		this.addChild(menu);
	},
	animateMenu: function()
	{
		//no animation
		return;
		
		var anim, anim2;
		var skew = -1, scale = 0.99, time = gg.AnimationLong;			
		
		anim = cc.RepeatForever.create(cc.Sequence.create(cc.EaseBackInOut.create(cc.SkewBy.create(time, skew, skew)), cc.EaseBackInOut.create(cc.SkewBy.create(time, -skew, -skew))));
		anim2 = cc.RepeatForever.create(cc.Sequence.create(cc.EaseBackInOut.create(cc.ScaleTo.create(time, scale, scale)), cc.EaseBackInOut.create(cc.ScaleTo.create(time, 1, 1))));
		
		cc.log("Running animation: " + anim);		
		menu.runAction(anim);
		menu.runAction(anim2);
	},
	update : function()
	{
		
	}
});

//	create scene and add main layer
var scene = new MainMenuLayer();

//	then run it
gg.Director.runWithScene(scene);