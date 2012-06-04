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

#ifndef ROXEETORRENT_COREINSTANCE_H
#define ROXEETORRENT_COREINSTANCE_H

#include <libtorrent/session.hpp>

#include <QtCore/QMutex>

/*! \cond */

class LRTCoreInstance
{
public:
    static LRTCoreInstance* instance()
    {
        static QMutex mutex;
        if (!m_Instance){
            mutex.lock();
            if (!m_Instance)
                m_Instance = new LRTCoreInstance;
            mutex.unlock();
        }
        return m_Instance;
    }

    static void drop()
    {
        // Destroy the session
        m_Instance->getSession()->~session();
        m_Instance->setSession(0);

        static QMutex mutex;
        mutex.lock();
        delete m_Instance;
        m_Instance = 0;
        mutex.unlock();
    }

    void setSession (libtorrent::session* val) { _lt_session = val; }
    libtorrent::session* getSession () { return _lt_session; }

private:
    LRTCoreInstance() {}
    LRTCoreInstance(const LRTCoreInstance &); // hide copy constructor
    LRTCoreInstance& operator=(const LRTCoreInstance &); // hide assign op

    static LRTCoreInstance* m_Instance;
    libtorrent::session* _lt_session;
};

/*! \endcond */

#endif // ROXEETORRENT_COREINSTANCE_H
