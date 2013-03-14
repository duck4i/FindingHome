/*
	Global include file for the engine. Injected directly from the engine on startup. Do not modify.
	Paths are dependant on set working directory which is .\Resources
*/

//	Include SYSTEM libraries
require("scripting/system/jsb.js");

//	Include USER libraries
require("scripting/generated/gameapi.js");

//	SET DEFAULT SHORTCUTS AND SETTINGS

gg.Font = "Arial";
gg.Director = cc.Director.getInstance();

gg.WinSize = gg.Director.getWinSize();
gg.Width = gg.WinSize.width;
gg.Height = gg.WinSize.height;


//	Say its all OK if you get this far
cc.log("JavaScript scripting support ON-LINE.");