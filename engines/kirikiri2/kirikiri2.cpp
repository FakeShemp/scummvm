#include "common/scummsys.h"

#include "common/config-manager.h"
#include "common/debug-channels.h"
#include "common/debug.h"
#include "common/error.h"
#include "common/events.h"
#include "common/file.h"
#include "common/fs.h"
#include "common/system.h"

#include "engines/util.h"

#include "kirikiri2/kirikiri2.h"

namespace KiriKiri2 {

KiriKiri2Engine::KiriKiri2Engine(OSystem *syst)
	: Engine(syst) {
	debug("KiriKiri2Engine::KiriKiri2Engine");
}

KiriKiri2Engine::~KiriKiri2Engine() {
	debug("KiriKiri2Engine::~KiriKiri2Engine");

	// Dispose your resources here

	// Remove all of our debug levels here
	DebugMan.clearAllDebugChannels();
}

Common::Error KiriKiri2Engine::run() {
	return Common::kNoError;
}
} // namespace KiriKiri2