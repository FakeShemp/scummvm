//---------------------------------------------------------------------------
/*
	TJS2 Script Engine
	Copyright (C) 2000 W.Dee <dee@kikyou.info> and contributors

	See details of license at "license.txt"
*/
//---------------------------------------------------------------------------
// TJS Math class implementation
//---------------------------------------------------------------------------
#ifndef KIRIKIRI2_CORE_TJS2_TJS_MATH_H
#define KIRIKIRI2_CORE_TJS2_TJS_MATH_H

#include "kirikiri2/core/tjs2/tjsNative.h"

namespace KiriKiri2 {
namespace TJS {

//---------------------------------------------------------------------------
class tTJSNC_Math : public tTJSNativeClass {
public:
	tTJSNC_Math();

private:
	static tjs_uint32 ClassID;
};
//---------------------------------------------------------------------------
} // namespace TJS
} // namespace KiriKiri2

#endif
