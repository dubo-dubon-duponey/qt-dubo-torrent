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

#ifndef QTLTSAVESTATES_H
#define QTLTSAVESTATES_H

#include <QtCore/QObject>
#include <QtCore/QMutex>

class QtLtSaveStates : public QObject
{
    Q_OBJECT
public:
    static QtLtSaveStates* instance()
    {
        static QMutex mutex;
        if (!m_Instance){
            mutex.lock();
            if (!m_Instance)
                m_Instance = new QtLtSaveStates;
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

    Q_PROPERTY(int SETTINGS     READ save_settings)
    Q_PROPERTY(int DHT_SETTINGS READ save_dht_settings)
    Q_PROPERTY(int DHT_STATE    READ save_dht_state)
    Q_PROPERTY(int I2P_PROXY    READ save_i2p_proxy)
    Q_PROPERTY(int ENCRYPTION_SETTINGS  READ save_encryption_settings)
    Q_PROPERTY(int AS_MAP       READ save_as_map)
    Q_PROPERTY(int PROXY        READ save_proxy)

    const int save_settings();
    const int save_dht_settings();
    const int save_dht_state();
    const int save_i2p_proxy();
    const int save_encryption_settings();
    const int save_as_map();
    const int save_proxy();

private:
    QtLtSaveStates() {}

    QtLtSaveStates(const QtLtSaveStates &);
    QtLtSaveStates& operator=(const QtLtSaveStates &);

    static QtLtSaveStates* m_Instance;
    
};

#endif // QTLTSAVESTATES_H
