//---------------------------------------------------------------------------
/*
	TJS2 Script Engine
	Copyright (C) 2000 W.Dee <dee@kikyou.info> and contributors

	See details of license at "license.txt"
*/
//---------------------------------------------------------------------------
// TJS Global String Map
//---------------------------------------------------------------------------
#ifndef KIRIKIRI2_CORE_TJS2_TJS_GLOBAL_STRING_MAP_H
#define KIRIKIRI2_CORE_TJS2_TJS_GLOBAL_STRING_MAP_H

#include "kirikiri2/core/tjs2/tjsString.h"

namespace KiriKiri2 {
namespace TJS {
//---------------------------------------------------------------------------
// tTJSGlobalStringMap - hash map to keep constant strings shared
//---------------------------------------------------------------------------
extern void TJSAddRefGlobalStringMap();
extern void TJSReleaseGlobalStringMap();
TJS_EXP_FUNC_DEF(ttstr, TJSMapGlobalStringMap, (const ttstr &string));
//---------------------------------------------------------------------------
} // namespace TJS
} // namespace KiriKiri2
#endif
