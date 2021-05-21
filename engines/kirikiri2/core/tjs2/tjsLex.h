//---------------------------------------------------------------------------
/*
	TJS2 Script Engine
	Copyright (C) 2000 W.Dee <dee@kikyou.info> and contributors

	See details of license at "license.txt"
*/
//---------------------------------------------------------------------------
// TJS2 lexical analyzer
//---------------------------------------------------------------------------
#ifndef KIRIKIRI2_CORE_TJS2_TJS_LEX_H
#define KIRIKIRI2_CORE_TJS2_TJS_LEX_H

#include "kirikiri2/core/tjs2/tjsConfig.h"
#include "kirikiri2/core/tjs2/tjsVariant.h"
#include "kirikiri2/lib/std/vector.h"
#include <deque>

extern bool tjsEnableDicFuncQuickHack;
// Defining this enables quick-hack, avoiding the dictionary/array parser
// memory overflow.
// This is done with replacing %[ ... ] to function { return %[ ... ]; }()
// and replacing [ ... ] to function { return [ ... ]; }().
// These replacing is applied for expression which starts with "%[" or "[",
// may cause some sideeffects....

namespace KiriKiri2 {
namespace TJS {
//---------------------------------------------------------------------------
extern tjs_int TJSHexNum(tjs_char ch) throw();
extern tjs_int TJSOctNum(tjs_char ch) throw();
extern tjs_int TJSDecNum(tjs_char ch) throw();
extern tjs_int TJSBinNum(tjs_char ch) throw();

bool TJSParseString(tTJSVariant &val, const tjs_char **ptr);
bool TJSParseNumber(tTJSVariant &val, const tjs_char **ptr);
void TJSReservedWordsHashAddRef();
void TJSReservedWordsHashRelease();
enum tTJSSkipCommentResult { scrContinue,
							 scrEnded,
							 scrNotComment };
//---------------------------------------------------------------------------
class tTJSScriptBlock;
class tTJSLexicalAnalyzer {
public:
	tTJSLexicalAnalyzer(tTJSScriptBlock *block, const tjs_char *script,
						bool exprmode, bool resneeded);
	~tTJSLexicalAnalyzer();

private:
	const tjs_char *Current;
	tjs_int PrevPos;
	tjs_int PrevToken;
	bool First;
	bool ExprMode;
	bool ResultNeeded;
	tjs_int NestLevel;

	bool DicFunc; //----- dicfunc quick-hack

	struct tTokenPair {
		tjs_int token;
		tjs_int value;

		tTokenPair(tjs_int token, tjs_int value) {
			this->token = token;
			this->value = value;
		}
	};

	std::deque<tTokenPair> RetValDeque;

	//	bool BlockBrace;

	bool RegularExpression;
	bool BareWord;

	enum tEmbeddableExpressionState { evsStart,
									  evsNextIsStringLiteral,
									  evsNextIsExpression };

	struct tEmbeddableExpressionData {
		tEmbeddableExpressionState State;
		tjs_int WaitingNestLevel;
		tjs_int WaitingToken;
		tjs_char Delimiter;
		bool NeedPlus;
	};

	std::vector<tEmbeddableExpressionData> EmbeddableExpressionDataStack;

	tTJSScriptBlock *Block;

	tjs_char *Script;

	tTJSSkipCommentResult SkipUntil_endif();
	tTJSSkipCommentResult ProcessPPStatement();

	tjs_int GetToken(tjs_int &value);

	tjs_int32 ParsePPExpression(const tjs_char *start,
								tjs_int n);

	void PreProcess(void);

	std::vector<tTJSVariant *> Values;

	tjs_int PutValue(const tTJSVariant &val);

	tjs_int IfLevel; // @if nesting level

public:
	const tTJSVariant &GetValue(tjs_int idx) const {
		return *Values[idx];
	}
	const tjs_char *GetString(tjs_int idx) const {
		return Values[idx]->GetString();
	}

	void Free(void);

	//	void NextBraceIsBlockBrace();

	tjs_int GetCurrentPosition();

	tjs_int GetNext(tjs_int &value);

	void SetStartOfRegExp(void);
	void SetNextIsBareWord();
};
//---------------------------------------------------------------------------

} // namespace TJS
} // namespace KiriKiri2
#endif
