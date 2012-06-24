/**
 * Copyright (c) 2012, WebItUp <contact@webitup.fr>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
 *
 * Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
 * Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "alerttypes.h"

#include <libtorrent/alert_types.hpp>

#include <QtCore/QMutex>

/*! \cond */

namespace RoxeeTorrent{
AlertTypes* AlertTypes::m_Instance = 0;

AlertTypes* AlertTypes::instance()
{
    static QMutex mutex;
    if (!m_Instance){
        mutex.lock();
        if (!m_Instance)
            m_Instance = new AlertTypes;
        mutex.unlock();
    }
    return m_Instance;
}

/*! \cond */
AlertTypes::~AlertTypes()
{
    static QMutex mutex;
    mutex.lock();
    delete m_Instance;
    m_Instance = 0;
    mutex.unlock();
}


int AlertTypes::all()             { return libtorrent::alert::all_categories;}
int AlertTypes::debug()           { return libtorrent::alert::debug_notification;}
int AlertTypes::dht()             { return libtorrent::alert::dht_notification;}
int AlertTypes::error()           { return libtorrent::alert::error_notification;}
int AlertTypes::ip_block()        { return libtorrent::alert::ip_block_notification;}
int AlertTypes::peer()            { return libtorrent::alert::peer_notification;}
int AlertTypes::performance()     { return libtorrent::alert::performance_warning;}
int AlertTypes::port_mapping()    { return libtorrent::alert::port_mapping_notification;}
int AlertTypes::progress()        { return libtorrent::alert::progress_notification;}
int AlertTypes::stats()           { return libtorrent::alert::stats_notification;}
int AlertTypes::status()          { return libtorrent::alert::status_notification;}
int AlertTypes::storage()         { return libtorrent::alert::storage_notification;}
int AlertTypes::tracker()         { return libtorrent::alert::tracker_notification;}

}

/*! \endcond */
