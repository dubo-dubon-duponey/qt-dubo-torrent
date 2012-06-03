/**
 * Copyright (c) 2012, WebItUp
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
 *
 * Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
 * Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "qtlttypestorrentstates.h"
#include <libtorrent/torrent.hpp>

using namespace RoxeeTorrent;

QtLtTorrentStates* QtLtTorrentStates::m_Instance = 0;

const int QtLtTorrentStates::queued_for_checking()  { return libtorrent::torrent_status::queued_for_checking; }
const int QtLtTorrentStates::checking_files()       { return libtorrent::torrent_status::checking_files; }
const int QtLtTorrentStates::downloading_metadata() { return libtorrent::torrent_status::downloading_metadata; }
const int QtLtTorrentStates::downloading()          { return libtorrent::torrent_status::downloading; }
const int QtLtTorrentStates::finished()             { return libtorrent::torrent_status::finished; }
const int QtLtTorrentStates::seeding()              { return libtorrent::torrent_status::seeding; }
const int QtLtTorrentStates::allocating()           { return libtorrent::torrent_status::allocating; }
const int QtLtTorrentStates::checking_resume_data() { return libtorrent::torrent_status::checking_resume_data; }
