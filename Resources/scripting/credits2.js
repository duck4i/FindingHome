cc.log("Credits scene loaded");

//	Logic
var CreditsMenuActions = 
{
	doBack: function()
	{
		var sc = cc.Scene.create();
		sc.addChild(new MainMenuLayer());
		var anim = cc.TransitionSlideInL.create(gg.AnimationShort, sc);		
		gg.Director.replaceScene(anim);
	}
};



//	View Code Bellow
var CreditsMenuLayer = cc.LayerColor.extend(
{
	ctor: function()
	{
		this._super();
		cc.associateWithNative(this, cc.LayerColor);
		this.init(cc.c4b(250, 100, 0, 255));
		this.loadItems();
	},
	loadItems: function()
	{
		var l = new MainMenuLayer();
		var b = l.setBackground(this);
		b.setFlipX(true);
		
		var label = cc.LabelTTF.create("Credits screen", gg.Font, 64);
		label.setPosition(cc.p(10, gg.Height - 20));
		label.setAnchorPoint(cc.p(0, 1));
		this.addChild(label);
		
		var back = cc.MenuItemFont.create("Back", CreditsMenuActions.doBack, CreditsMenuActions);
		
		var menu = cc.Menu.create(back);
		menu.setPosition(cc.p(/*gg.Width -*/ 100, 50));
		this.addChild(menu);
	}
});

