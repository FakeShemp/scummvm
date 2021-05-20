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

#include "kirikiri2/metaengine.h"
#include "kirikiri2/detection.h"
#include "kirikiri2/kirikiri2.h"

const char *KiriKiri2MetaEngine::getName() const {
	return "kirikiri2";
}

Common::Error KiriKiri2MetaEngine::createInstance(OSystem *syst, Engine **engine, const ADGameDescription *desc) const {
	const KiriKiri2::KiriKiri2GameDescription *gd = (const KiriKiri2::KiriKiri2GameDescription *)desc;

	*engine = new KiriKiri2::KiriKiri2Engine(syst, gd);
	return Common::kNoError;
}

#if PLUGIN_ENABLED_DYNAMIC(KIRIKIRI2)
REGISTER_PLUGIN_DYNAMIC(KIRIKIRI2, PLUGIN_TYPE_ENGINE, KiriKiri2MetaEngine);
#else
REGISTER_PLUGIN_STATIC(KIRIKIRI2, PLUGIN_TYPE_ENGINE, KiriKiri2MetaEngine);
#endif