#ifndef __game_h__
#define __game_h__

#include "cocos2d.h"
#include "ScriptingCore.h"
#include "cocos2d_specifics.hpp"

extern JSClass  *js_game_Game_class;
extern JSObject *js_game_Game_prototype;

JSBool js_game_Game_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_game_Game_finalize(JSContext *cx, JSObject *obj);
void js_register_game_Game(JSContext *cx, JSObject *global);
void register_all_game(JSContext* cx, JSObject* obj);
JSBool js_game_Game_exit(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_game_Game_doSomething(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_game_Game_Game(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *js_game_NODEINFO_class;
extern JSObject *js_game_NODEINFO_prototype;

JSBool js_game_NODEINFO_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_game_NODEINFO_finalize(JSContext *cx, JSObject *obj);
void js_register_game_NODEINFO(JSContext *cx, JSObject *global);
void register_all_game(JSContext* cx, JSObject* obj);
JSBool js_game_NODEINFO_NODEINFO(JSContext *cx, uint32_t argc, jsval *vp);
#endif

