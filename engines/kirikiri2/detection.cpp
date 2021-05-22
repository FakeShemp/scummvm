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

#include "base/plugins.h"
#include "common/system.h"
#include "kirikiri2/detection.h"
#include "kirikiri2/detection_tables.h"

KiriKiri2MetaEngineDetection::KiriKiri2MetaEngineDetection() : AdvancedMetaEngineDetection(KiriKiri2::GAME_DESCRIPTIONS,
	sizeof(KiriKiri2::KiriKiri2GameDescription), KiriKiri2::KIRIKIRI2_GAMES) {
	static const char *const DIRECTORY_GLOBS[2] = { "usecode", 0 };
	_maxScanDepth = 2;
	_directoryGlobs = DIRECTORY_GLOBS;
}

REGISTER_PLUGIN_STATIC(KIRIKIRI2_DETECTION, PLUGIN_TYPE_ENGINE_DETECTION, KiriKiri2MetaEngineDetection);