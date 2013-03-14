/*
	Global include file for the engine. Injected directly from the engine on startup. Do not modify.
	Paths are dependant on set working directory which is .\Resources
*/

var SYS_FOLDER = "Scripting/";

//	Include SYSTEM libraries
require(SYS_FOLDER + "system/jsb.js");

//	Include USER libraries
require(SYS_FOLDER + "generated/gameapi.js");

//	SET DEFAULT SHORTCUTS AND SETTINGS

//	Global Vars
gg.Font = "Arial";
gg.Director = cc.Director.getInstance();

gg.WinSize = gg.Director.getWinSize();
gg.Width = gg.WinSize.width;
gg.Height = gg.WinSize.height;

//	Animation settings
gg.AnimationLong = 2;
gg.AnimationMedium = 1.5;
gg.AnimationShort = 1;








//	Say its all OK if you get this far
cc.log("JavaScript scripting support ON-LINE.");