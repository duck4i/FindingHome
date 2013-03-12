cc.log("Main menu loaded");

//	defines
var director = cc.Director.getInstance();
var winSize = director.getWinSize();
var font = "Arial";


//	Main menu layer
var MainMenuLayer = cc.LayerColor.extend(
{
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
		var pos = cc.p(winSize.width / 2.0, winSize.height / 2.0);
		
		title.setColor(cc.c3b(255, 255, 255));
		title.setPosition(pos);
		title.setAnchorPoint(cc.p(0.5, 0.5));
		
		this.addChild(title);
		

	
	
		this.scheduleUpdate();
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