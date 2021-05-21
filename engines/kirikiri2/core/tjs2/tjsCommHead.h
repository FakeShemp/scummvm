//---------------------------------------------------------------------------
/*
	TJS2 Script Engine
	Copyright (C) 2000 W.Dee <dee@kikyou.info> and contributors

	See details of license at "license.txt"
*/
//---------------------------------------------------------------------------
// tjs common header
//---------------------------------------------------------------------------

/*
	Add headers that would not be frequently changed.
*/
#ifndef KIRIKIRI2_CORE_TJS2_TJS_COMM_HEAD_H
#define KIRIKIRI2_CORE_TJS2_TJS_COMM_HEAD_H

#ifdef TJS_SUPPORT_VCL
#include <vcl.h>
#endif

#ifdef __WIN32__
#include <windows.h>
#endif

#include "kirikiri2/lib/std/string.h"
#ifndef __USE_UNIX98
#define __USE_UNIX98
#endif
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

#include "kirikiri2/lib/std/vector.h"
#include <stdexcept>
#include "kirikiri2/lib/std/string.h"

#include "kirikiri2/core/tjs2/tjsConfig.h"

#include "kirikiri2/core/tjs2/tjs.h"

typedef std::basic_string<KiriKiri2::TJS::tjs_char> stdstring;
typedef std::basic_string<KiriKiri2::TJS::tjs_nchar> stdnstring;

#ifdef TJS_SUPPORT_VCL
#pragma intrinsic strcpy
#pragma intrinsic strcmp // why these are needed?
#endif

//---------------------------------------------------------------------------
#endif
