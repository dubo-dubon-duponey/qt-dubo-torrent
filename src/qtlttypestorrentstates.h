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

#ifndef QTLTTORRENTSTATES_H
#define QTLTTORRENTSTATES_H

#include <QtCore/QObject>
#include <QtCore/QMutex>

class QtLtTorrentStates : public QObject
{
    Q_OBJECT
public:
    static QtLtTorrentStates* instance()
    {
        static QMutex mutex;
        if (!m_Instance){
            mutex.lock();
            if (!m_Instance)
                m_Instance = new QtLtTorrentStates;
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

    Q_PROPERTY(int QUEUED_FOR_CHECKING  READ queued_for_checking)
    Q_PROPERTY(int CHECKING_FILES       READ checking_files)
    Q_PROPERTY(int DOWNLOADING_METADATA READ downloading_metadata)
    Q_PROPERTY(int DOWNLOADING          READ downloading)
    Q_PROPERTY(int FINISHED             READ finished)
    Q_PROPERTY(int SEEDING              READ seeding)
    Q_PROPERTY(int ALLOCATING           READ allocating)
    Q_PROPERTY(int CHECKING_RESUME_DATA READ checking_resume_data)

    const int queued_for_checking();
    const int checking_files();
    const int downloading_metadata();
    const int downloading();
    const int finished();
    const int seeding();
    const int allocating();
    const int checking_resume_data();

signals:
    
public slots:

private:
    QtLtTorrentStates() {}

    QtLtTorrentStates(const QtLtTorrentStates &);
    QtLtTorrentStates& operator=(const QtLtTorrentStates &);

    static QtLtTorrentStates* m_Instance;

};

#endif // QTLTTORRENTSTATES_H
