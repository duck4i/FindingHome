/*
	Global include file for the engine. Do not modify.
	Paths are dependant on set working directory which is .\Resources
*/

var debug = true;

//	Include
require("scripting/system/jsb.js");

//	Say its all OK
cc.log("JavaScript scripting support ON-LINE.");
if (debug)
	cc.dumpConfig();

