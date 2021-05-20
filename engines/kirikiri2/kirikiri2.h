/* ScummVM - Graphic Adventure Engine
 *
 * ScummVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the COPYRIGHT
 * file distributed with this source distribution.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 */

#ifndef KIRIKIRI2_KIRIKIRI2_H
#define KIRIKIRI2_KIRIKIRI2_H

#include "common/error.h"
#include "common/hash-str.h"
#include "common/random.h"
#include "common/scummsys.h"
#include "common/system.h"
#include "common/util.h"
#include "engines/engine.h"
#include "engines/savestate.h"
#include "graphics/surface.h"

namespace KiriKiri2 {

#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 200

enum KiriKiri2DebugChannels {
	kDebugPath = 1 << 0,
	kDebugGraphics = 1 << 1
};

struct KiriKiri2GameDescription;

class KiriKiri2Engine : public Engine {
private:
	const KiriKiri2GameDescription *_gameDescription;
	Common::RandomSource _randomSource;

protected:
	// Engine APIs
	virtual Common::Error run();

public:
	KiriKiri2Engine(OSystem *syst, const KiriKiri2GameDescription *gameDesc);
	virtual ~KiriKiri2Engine();
	void GUIError(const Common::String &msg);

	void set_window_title(const char *str) {
		// No implementation
	}

	uint32 getFeatures() const;

	/**
	 * Returns the current list of savegames
	 */
	SaveStateList listSaves() const;

	/**
	 * Gets a random number
	 */
	uint32 getRandomNumber(uint maxNum) {
		return _randomSource.getRandomNumber(maxNum);
	}

	/**
	 * Sets the random number seed
	 */
	void setRandomNumberSeed(uint32 seed) {
		_randomSource.setSeed(seed);
	}
};

extern KiriKiri2Engine *g_vm;

} // namespace KiriKiri2

#endif