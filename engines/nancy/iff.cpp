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

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 */

#include "nancy/nancy.h"
#include "nancy/iff.h"
#include "nancy/resource.h"

#include "common/memstream.h"
#include "common/iff_container.h"
#include "common/debug.h"

namespace Nancy {

IFF::~IFF() {
	for (uint i = 0; i < _chunks.size(); i++)
		delete[] _chunks[i].buf;
}

bool IFF::callback(Common::IFFChunk &c) {
	Chunk chunk;
	chunk.id = c._type;

	if (chunk.id == ID_DATA) {
		debugN(3, "IFF::callback: Skipping 'DATA' chunk\n");
		return false;
	}

	chunk.size = c._size;
	chunk.buf = new byte[chunk.size];
	c._stream->read(chunk.buf, chunk.size);

	if (c._stream->err())
		error("IFF::callback: error reading '%s' chunk", idToString(chunk.id).c_str());

	debugN(3, "IFF::callback: Adding '%s' chunk\n", idToString(chunk.id).c_str());
	_chunks.push_back(chunk);

	return false;
}

bool IFF::load() {
	byte *data;
	uint size;
	data = _vm->_res->loadData("ciftree", _name, size);

	if (!data)
		return false;

	// Scan the file for DATA chunks, completely ignoring IFF structure
	// Presumably the string "DATA" is not allowed inside of chunks...
	uint offset = 0;

	while (offset < size - 3) {
		uint32 id = READ_BE_UINT32(data + offset);
		if (id == ID_DATA) {
			// Replace 'DATA' with standard 'FORM' for the parser
			WRITE_BE_UINT32(data + offset, ID_FORM);
			Common::MemoryReadStream stream(data + offset, size - offset);
			Common::IFFParser iff(&stream);
			Common::Functor1Mem< Common::IFFChunk &, bool, IFF > c(this, &IFF::callback);
			iff.parse(c);
			offset += 16; // Original engine skips 16, while 12 seems more logical
		} else
			++offset;
	}

	delete[] data;
	return true;
}

const byte *IFF::getChunk(uint32 id, uint &size) const {
	for (uint i = 0; i < _chunks.size(); ++i) {
		const Chunk &chunk = _chunks[i];
		if (chunk.id == id) {
			size = chunk.size;
			return chunk.buf;
		}
	}

	return 0;
}

Common::String IFF::idToString(uint32 id) {
	Common::String s;
	while (id) {
		s += id >> 24;
		id <<= 8;
	}
	return s;
}

} // End of namespace Nancy