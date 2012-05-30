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

#include "qtlttypessavestates.h"
#include <libtorrent/session.hpp>

QtLtSaveStates* QtLtSaveStates::m_Instance = 0;

const int QtLtSaveStates::save_settings()               { return libtorrent::session::save_settings;}
const int QtLtSaveStates::save_dht_settings()           { return libtorrent::session::save_dht_settings;}
const int QtLtSaveStates::save_dht_state()              { return libtorrent::session::save_dht_state;}
const int QtLtSaveStates::save_i2p_proxy()              { return libtorrent::session::save_i2p_proxy;}
const int QtLtSaveStates::save_encryption_settings()    { return libtorrent::session::save_encryption_settings;}
const int QtLtSaveStates::save_as_map()                 { return libtorrent::session::save_as_map;}
const int QtLtSaveStates::save_proxy()                  { return libtorrent::session::save_proxy;}
