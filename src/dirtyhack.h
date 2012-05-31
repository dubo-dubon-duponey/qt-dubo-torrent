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

#ifndef DIRTYHACK_H
#define DIRTYHACK_H

#include <libtorrent/session.hpp>

#include <QtCore/QMutex>

class dirtyHack
{
public:
    static dirtyHack* instance()
    {
        static QMutex mutex;
        if (!m_Instance){
            mutex.lock();
            if (!m_Instance)
                m_Instance = new dirtyHack;
            mutex.unlock();
        }
        return m_Instance;
    }

    static void drop()
    {
        static QMutex mutex;
        mutex.lock();
        // Destroy the session
        m_Instance->getSession()->~session();
        m_Instance->setSession(0);
        delete m_Instance;
        m_Instance = 0;
        mutex.unlock();
    }

    void setSession (libtorrent::session* val) { _lt_session = val; }
    libtorrent::session* getSession () { return _lt_session; }

private:
    dirtyHack() {}
    dirtyHack(const dirtyHack &); // hide copy constructor
    dirtyHack& operator=(const dirtyHack &); // hide assign op

    static dirtyHack* m_Instance;
    libtorrent::session* _lt_session;
};

#endif // DIRTYHACK_H
