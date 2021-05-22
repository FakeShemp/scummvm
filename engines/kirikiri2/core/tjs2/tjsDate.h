//---------------------------------------------------------------------------
/*
	TJS2 Script Engine
	Copyright (C) 2000 W.Dee <dee@kikyou.info> and contributors

	See details of license at "license.txt"
*/
//---------------------------------------------------------------------------
// Date class implementation
//---------------------------------------------------------------------------

#ifndef KIRIKIRI2_CORE_TJS2_TJS_DATE_H
#define KIRIKIRI2_CORE_TJS2_TJS_DATE_H

#include "kirikiri2/core/tjs2/tjsNative.h"
// #include <time.h>

namespace KiriKiri2 {
namespace TJS {
//---------------------------------------------------------------------------
class tTJSNI_Date : public tTJSNativeInstance {
public:
	tTJSNI_Date();
	time_t DateTime;

private:
};

//---------------------------------------------------------------------------
class tTJSNC_Date : public tTJSNativeClass {
public:
	tTJSNC_Date();

	static tjs_uint32 ClassID;

private:
	tTJSNativeInstance *CreateNativeInstance();
};
//---------------------------------------------------------------------------
} // namespace TJS
} // namespace KiriKiri2
#endif
