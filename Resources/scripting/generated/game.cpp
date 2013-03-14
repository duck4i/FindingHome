#include "jsapi.h"
#include "jsfriendapi.h"
#include "js_bindings_config.h"
#include "game.hpp"
#include "generate.h"

template<class T>
static JSBool dummy_constructor(JSContext *cx, uint32_t argc, jsval *vp) {
	TypeTest<T> t;
	T* cobj = new T();
	cobj->autorelease();
	js_type_class_t *p;
	uint32_t typeId = t.s_id();
	HASH_FIND_INT(_js_global_type_ht, &typeId, p);
	assert(p);
	JSObject *_tmp = JS_NewObject(cx, p->jsclass, p->proto, p->parentProto);
	js_proxy_t *pp;
	JS_NEW_PROXY(pp, cobj, _tmp);
	JS_AddObjectRoot(cx, &pp->obj);
	JS_SET_RVAL(cx, vp, OBJECT_TO_JSVAL(_tmp));

	return JS_TRUE;
}

static JSBool empty_constructor(JSContext *cx, uint32_t argc, jsval *vp) {
	return JS_FALSE;
}


JSClass  *js_game_Game_class;
JSObject *js_game_Game_prototype;

JSBool js_game_Game_newGame(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	Game* cobj = (Game *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");

	if (argc == 0) {
		cobj->newGame();
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_game_Game_exit(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	Game* cobj = (Game *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");

	if (argc == 0) {
		cobj->exit();
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_game_Game_doSomething(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	Game* cobj = (Game *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");

	if (argc == 0) {
		cobj->doSomething();
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_game_Game_constructor(JSContext *cx, uint32_t argc, jsval *vp)
{

	if (argc == 0) {
		Game* cobj = new Game();
#ifdef COCOS2D_JAVASCRIPT
		cocos2d::CCObject *_ccobj = dynamic_cast<cocos2d::CCObject *>(cobj);
		if (_ccobj) {
			_ccobj->autorelease();
		}
#endif
		TypeTest<Game> t;
		js_type_class_t *typeClass;
		uint32_t typeId = t.s_id();
		HASH_FIND_INT(_js_global_type_ht, &typeId, typeClass);
		assert(typeClass);
		JSObject *obj = JS_NewObject(cx, typeClass->jsclass, typeClass->proto, typeClass->parentProto);
		JS_SET_RVAL(cx, vp, OBJECT_TO_JSVAL(obj));
		// link the native object with the javascript object
		js_proxy_t *p;
		JS_NEW_PROXY(p, cobj, obj);
#ifdef COCOS2D_JAVASCRIPT
		JS_AddNamedObjectRoot(cx, &p->obj, "Game");
#endif
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}



void js_game_Game_finalize(JSFreeOp *fop, JSObject *obj) {
}

void js_register_game_Game(JSContext *cx, JSObject *global) {
	js_game_Game_class = (JSClass *)calloc(1, sizeof(JSClass));
	js_game_Game_class->name = "Game";
	js_game_Game_class->addProperty = JS_PropertyStub;
	js_game_Game_class->delProperty = JS_PropertyStub;
	js_game_Game_class->getProperty = JS_PropertyStub;
	js_game_Game_class->setProperty = JS_StrictPropertyStub;
	js_game_Game_class->enumerate = JS_EnumerateStub;
	js_game_Game_class->resolve = JS_ResolveStub;
	js_game_Game_class->convert = JS_ConvertStub;
	js_game_Game_class->finalize = js_game_Game_finalize;
	js_game_Game_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

	static JSPropertySpec properties[] = {
		{0, 0, 0, 0, 0}
	};

	static JSFunctionSpec funcs[] = {
		JS_FN("newGame", js_game_Game_newGame, 0, JSPROP_PERMANENT | JSPROP_SHARED),
		JS_FN("exit", js_game_Game_exit, 0, JSPROP_PERMANENT | JSPROP_SHARED),
		JS_FN("doSomething", js_game_Game_doSomething, 0, JSPROP_PERMANENT | JSPROP_SHARED),
		JS_FS_END
	};

	JSFunctionSpec *st_funcs = NULL;

	js_game_Game_prototype = JS_InitClass(
		cx, global,
		NULL, // parent proto
		js_game_Game_class,
		js_game_Game_constructor, 0, // constructor
		properties,
		funcs,
		NULL, // no static properties
		st_funcs);
	// make the class enumerable in the registered namespace
	JSBool found;
	JS_SetPropertyAttributes(cx, global, "Game", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

	// add the proto and JSClass to the type->js info hash table
	TypeTest<Game> t;
	js_type_class_t *p;
	uint32_t typeId = t.s_id();
	HASH_FIND_INT(_js_global_type_ht, &typeId, p);
	if (!p) {
		p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
		p->type = typeId;
		p->jsclass = js_game_Game_class;
		p->proto = js_game_Game_prototype;
		p->parentProto = NULL;
		HASH_ADD_INT(_js_global_type_ht, type, p);
	}
}


JSClass  *js_game_MainScene_class;
JSObject *js_game_MainScene_prototype;

JSBool js_game_MainScene_init(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	MainScene* cobj = (MainScene *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");

	if (argc == 0) {
		bool ret = cobj->init();
		jsval jsret;
		jsret = BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_game_MainScene_create(JSContext *cx, uint32_t argc, jsval *vp)
{
	MainScene* ret = MainScene::create();
	jsval jsret;
	do {
		if (ret) {
			js_proxy_t *proxy = js_get_or_create_proxy<MainScene>(cx, ret);
			jsret = OBJECT_TO_JSVAL(proxy->obj);
		} else {
			jsret = JSVAL_NULL;
		}
	} while (0);
	JS_SET_RVAL(cx, vp, jsret);
	return JS_TRUE;
}

JSBool js_game_MainScene_scene(JSContext *cx, uint32_t argc, jsval *vp)
{
	cocos2d::CCScene* ret = MainScene::scene();
	jsval jsret;
	do {
		if (ret) {
			js_proxy_t *proxy = js_get_or_create_proxy<cocos2d::CCScene>(cx, ret);
			jsret = OBJECT_TO_JSVAL(proxy->obj);
		} else {
			jsret = JSVAL_NULL;
		}
	} while (0);
	JS_SET_RVAL(cx, vp, jsret);
	return JS_TRUE;
}

JSBool js_game_MainScene_constructor(JSContext *cx, uint32_t argc, jsval *vp)
{

	if (argc == 0) {
		MainScene* cobj = new MainScene();
#ifdef COCOS2D_JAVASCRIPT
		cocos2d::CCObject *_ccobj = dynamic_cast<cocos2d::CCObject *>(cobj);
		if (_ccobj) {
			_ccobj->autorelease();
		}
#endif
		TypeTest<MainScene> t;
		js_type_class_t *typeClass;
		uint32_t typeId = t.s_id();
		HASH_FIND_INT(_js_global_type_ht, &typeId, typeClass);
		assert(typeClass);
		JSObject *obj = JS_NewObject(cx, typeClass->jsclass, typeClass->proto, typeClass->parentProto);
		JS_SET_RVAL(cx, vp, OBJECT_TO_JSVAL(obj));
		// link the native object with the javascript object
		js_proxy_t *p;
		JS_NEW_PROXY(p, cobj, obj);
#ifdef COCOS2D_JAVASCRIPT
		JS_AddNamedObjectRoot(cx, &p->obj, "MainScene");
#endif
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}



void js_game_MainScene_finalize(JSFreeOp *fop, JSObject *obj) {
}

void js_register_game_MainScene(JSContext *cx, JSObject *global) {
	js_game_MainScene_class = (JSClass *)calloc(1, sizeof(JSClass));
	js_game_MainScene_class->name = "MainScene";
	js_game_MainScene_class->addProperty = JS_PropertyStub;
	js_game_MainScene_class->delProperty = JS_PropertyStub;
	js_game_MainScene_class->getProperty = JS_PropertyStub;
	js_game_MainScene_class->setProperty = JS_StrictPropertyStub;
	js_game_MainScene_class->enumerate = JS_EnumerateStub;
	js_game_MainScene_class->resolve = JS_ResolveStub;
	js_game_MainScene_class->convert = JS_ConvertStub;
	js_game_MainScene_class->finalize = js_game_MainScene_finalize;
	js_game_MainScene_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

	static JSPropertySpec properties[] = {
		{0, 0, 0, 0, 0}
	};

	static JSFunctionSpec funcs[] = {
		JS_FN("init", js_game_MainScene_init, 0, JSPROP_PERMANENT | JSPROP_SHARED),
		JS_FS_END
	};

	static JSFunctionSpec st_funcs[] = {
		JS_FN("create", js_game_MainScene_create, 0, JSPROP_PERMANENT | JSPROP_SHARED),
		JS_FN("scene", js_game_MainScene_scene, 0, JSPROP_PERMANENT | JSPROP_SHARED),
		JS_FS_END
	};

	js_game_MainScene_prototype = JS_InitClass(
		cx, global,
		NULL, // parent proto
		js_game_MainScene_class,
		js_game_MainScene_constructor, 0, // constructor
		properties,
		funcs,
		NULL, // no static properties
		st_funcs);
	// make the class enumerable in the registered namespace
	JSBool found;
	JS_SetPropertyAttributes(cx, global, "MainScene", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

	// add the proto and JSClass to the type->js info hash table
	TypeTest<MainScene> t;
	js_type_class_t *p;
	uint32_t typeId = t.s_id();
	HASH_FIND_INT(_js_global_type_ht, &typeId, p);
	if (!p) {
		p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
		p->type = typeId;
		p->jsclass = js_game_MainScene_class;
		p->proto = js_game_MainScene_prototype;
		p->parentProto = NULL;
		HASH_ADD_INT(_js_global_type_ht, type, p);
	}
}

void register_all_game(JSContext* cx, JSObject* obj) {
	// first, try to get the ns
	jsval nsval;
	JSObject *ns;
	JS_GetProperty(cx, obj, "gg", &nsval);
	if (nsval == JSVAL_VOID) {
		ns = JS_NewObject(cx, NULL, NULL, NULL);
		nsval = OBJECT_TO_JSVAL(ns);
		JS_SetProperty(cx, obj, "gg", &nsval);
	} else {
		JS_ValueToObject(cx, nsval, &ns);
	}
	obj = ns;

	js_register_game_MainScene(cx, obj);
	js_register_game_Game(cx, obj);
}

