#ifndef __game_h__
#define __game_h__

#include "cocos2d.h"
#include "ScriptingCore.h"
#include "cocos2d_specifics.hpp"

extern JSClass  *js_game_GameInstance_class;
extern JSObject *js_game_GameInstance_prototype;

JSBool js_game_GameInstance_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_game_GameInstance_finalize(JSContext *cx, JSObject *obj);
void js_register_game_GameInstance(JSContext *cx, JSObject *global);
void register_all_game(JSContext* cx, JSObject* obj);
JSBool js_game_GameInstance_setScene(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_game_GameInstance_newGame(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_game_GameInstance_setScale(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_game_GameInstance_purge(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_game_GameInstance_getPlayer(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_game_GameInstance_getNextLevel(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_game_GameInstance_getScene(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_game_GameInstance_exit(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_game_GameInstance_getScale(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_game_GameInstance_setPlayer(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_game_GameInstance_setNextLevel(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_game_GameInstance_sharedInstance(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_game_GameInstance_GameInstance(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *js_game_MainScene_class;
extern JSObject *js_game_MainScene_prototype;

JSBool js_game_MainScene_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_game_MainScene_finalize(JSContext *cx, JSObject *obj);
void js_register_game_MainScene(JSContext *cx, JSObject *global);
void register_all_game(JSContext* cx, JSObject* obj);
JSBool js_game_MainScene_init(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_game_MainScene_create(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_game_MainScene_scene(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_game_MainScene_MainScene(JSContext *cx, uint32_t argc, jsval *vp);
#endif

