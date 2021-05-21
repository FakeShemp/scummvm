//---------------------------------------------------------------------------
/*
	TJS2 Script Engine
	Copyright (C) 2000 W.Dee <dee@kikyou.info> and contributors

	See details of license at "license.txt"
*/
//---------------------------------------------------------------------------
// Conditional Compile Control
//---------------------------------------------------------------------------

#ifndef KIRIKIRI2_CORE_TJS2_TJS_COMPILE_CONTROL_H
#define KIRIKIRI2_CORE_TJS2_TJS_COMPILE_CONTROL_H

#include "kirikiri2/core/tjs2/tjsString.h"

namespace TJS {
//---------------------------------------------------------------------------
class tTJS;
class tTJSPPExprParser {
public:
	tTJSPPExprParser(tTJS *tjs, const tjs_char *script);
	~tTJSPPExprParser();

	tjs_int32 Parse();

	tTJS *TJS;
	tjs_int GetNext(tjs_int &value);

	tTJS *GetTJS() { return TJS; }

	const tjs_char *GetString(tjs_int idx) const;

	tjs_int32 Result;

private:
	std::vector<ttstr> IDs;

	const tjs_char *Script;
	const tjs_char *Current;
};
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
} // namespace TJS

#endif
