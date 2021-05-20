#ifndef KIRIKIRI2_H
#define KIRIKIRI2_H

#include "common/random.h"
#include "common/serializer.h"
#include "engines/engine.h"
#include "gui/debugger.h"

namespace KiriKiri2 {
class Console;

// our engine debug channels
enum {
	kKiriKiri2DebugExample = 1 << 0,
	kKiriKiri2DebugExample2 = 1 << 1
	// next new channel must be 1 << 2 (4)
	// the current limitation is 32 debug channels (1 << 31 is the last one)
};

class KiriKiri2Engine : public Engine {
public:
	KiriKiri2Engine(OSystem *syst);
	~KiriKiri2Engine();

protected:
	virtual Common::Error run();
};

class Console : public GUI::Debugger {
public:
	Console(KiriKiri2Engine *vm) {
	}
	virtual ~Console(void) {
	}
};
} // namespace KiriKiri2

#endif // KIRIKIRI2_H