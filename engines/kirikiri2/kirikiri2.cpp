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

#include "kirikiri2/kirikiri2.h"
#include "common/config-manager.h"
#include "common/debug-channels.h"
#include "common/events.h"
#include "common/file.h"
#include "common/scummsys.h"
#include "kirikiri2/detection.h"

namespace KiriKiri2 {

KiriKiri2Engine *g_vm;

KiriKiri2Engine::KiriKiri2Engine(OSystem *syst, const KiriKiri2GameDescription *gameDesc) : Engine(syst),
																							_gameDescription(gameDesc), _randomSource("KiriKiri2") {
	g_vm = this;
	DebugMan.addDebugChannel(kDebugPath, "Path", "Pathfinding debug level");
	DebugMan.addDebugChannel(kDebugGraphics, "Graphics", "Graphics debug level");
}

KiriKiri2Engine::~KiriKiri2Engine() {
}

uint32 KiriKiri2Engine::getFeatures() const {
	return _gameDescription->desc.flags;
}

Common::Error KiriKiri2Engine::run() {
	return Common::kNoError;
}

SaveStateList KiriKiri2Engine::listSaves() const {
	return getMetaEngine()->listSaves(_targetName.c_str());
}

} // namespace KiriKiri2