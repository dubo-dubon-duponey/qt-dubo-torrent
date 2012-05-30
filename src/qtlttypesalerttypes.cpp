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

#include "qtlttypesalerttypes.h"
#include <libtorrent/alert_types.hpp>

QtltAlertTypes* QtltAlertTypes::m_Instance = 0;

const int QtltAlertTypes::all()             { return libtorrent::alert::all_categories;}
const int QtltAlertTypes::debug()           { return libtorrent::alert::debug_notification;}
const int QtltAlertTypes::dht()             { return libtorrent::alert::dht_notification;}
const int QtltAlertTypes::error()           { return libtorrent::alert::error_notification;}
const int QtltAlertTypes::ip_block()        { return libtorrent::alert::ip_block_notification;}
const int QtltAlertTypes::peer()            { return libtorrent::alert::peer_notification;}
const int QtltAlertTypes::performance()     { return libtorrent::alert::performance_warning;}
const int QtltAlertTypes::port_mapping()    { return libtorrent::alert::port_mapping_notification;}
const int QtltAlertTypes::progress()        { return libtorrent::alert::progress_notification;}
const int QtltAlertTypes::stats()           { return libtorrent::alert::stats_notification;}
const int QtltAlertTypes::status()          { return libtorrent::alert::status_notification;}
const int QtltAlertTypes::storage()         { return libtorrent::alert::storage_notification;}
const int QtltAlertTypes::tracker()         { return libtorrent::alert::tracker_notification;}

