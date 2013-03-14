cc.log("Credits scene loaded");

var CreditsMenuLayer = cc.LayerColor.extend(
{
	ctor: function()
	{
		this._super();
		cc.associateWithNative(this, cc.LayerColor);
		this.init(cc.c4b(255, 255, 255, 255));
		this.loadItems();
	},
	loadItems: function()
	{
		var label = cc.LabelTTF.create("Credits screne", gg.Font, 32);
		label.setPosition(cc.p(gg.Width / 2, gg.Height / 2));
		label.setColor(cc.c3b(0, 0, 0));		
		this.addChild(label);
	}
	
});

