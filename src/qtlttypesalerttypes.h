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

#ifndef QTLTALERTTYPES_H
#define QTLTALERTTYPES_H

#include "qt-libtorrent_global.h"

#include <QtCore/QObject>
#include <QtCore/QMutex>

class QTLIBTORRENTSHARED_EXPORT QtltAlertTypes : public QObject
{
    Q_OBJECT
public:
    static QtltAlertTypes* instance()
    {
        static QMutex mutex;
        if (!m_Instance){
            mutex.lock();
            if (!m_Instance)
                m_Instance = new QtltAlertTypes;
            mutex.unlock();
        }
        return m_Instance;
    }

    static void drop()
    {
        static QMutex mutex;
        mutex.lock();
        delete m_Instance;
        m_Instance = 0;
        mutex.unlock();
    }

    Q_PROPERTY(const int ERROR        READ error)
    Q_PROPERTY(int PEER         READ peer)
    Q_PROPERTY(int PORT_MAPPING READ port_mapping)
    Q_PROPERTY(int STORAGE      READ storage)
    Q_PROPERTY(int TRACKER      READ tracker)
    Q_PROPERTY(int DEBUG        READ debug)
    Q_PROPERTY(int STATUS       READ status)
    Q_PROPERTY(int PROGRESS     READ progress)
    Q_PROPERTY(int IP_BLOCK     READ ip_block)
    Q_PROPERTY(int PERFORMANCE  READ performance)
    Q_PROPERTY(int DHT          READ dht)
    Q_PROPERTY(int STATS        READ stats)
    Q_PROPERTY(int ALL          READ all)

    const int error();
    const int peer();
    const int port_mapping();
    const int storage();
    const int tracker();
    const int debug();
    const int status();
    const int progress();
    const int ip_block();
    const int performance();
    const int dht();
    const int stats();
    const int all();

private:
    QtltAlertTypes() {}

    QtltAlertTypes(const QtltAlertTypes &);
    QtltAlertTypes& operator=(const QtltAlertTypes &);

    static QtltAlertTypes* m_Instance;

};

#endif // QTLTALERTTYPES_H

