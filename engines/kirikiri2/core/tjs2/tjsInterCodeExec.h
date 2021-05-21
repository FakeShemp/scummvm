//---------------------------------------------------------------------------
/*
	TJS2 Script Engine
	Copyright (C) 2000 W.Dee <dee@kikyou.info> and contributors

	See details of license at "license.txt"
*/
//---------------------------------------------------------------------------
// Intermediate Code Execution
//---------------------------------------------------------------------------

#ifndef KIRIKIRI2_CORE_TJS2_TJS_INTER_CODE_EXEC_H
#define KIRIKIRI2_CORE_TJS2_TJS_INTER_CODE_EXEC_H

namespace KiriKiri2 {
namespace TJS {
//---------------------------------------------------------------------------
extern void TJSVariantArrayStackAddRef();
extern void TJSVariantArrayStackRelease();
extern void TJSVariantArrayStackCompact();
extern void TJSVariantArrayStackCompactNow();
//---------------------------------------------------------------------------
} // namespace TJS
} // namespace KiriKiri2
#endif
