/**
 * @alpha1
 */

#ifndef DIRTYHACK_H
#define DIRTYHACK_H

#include <libtorrent/session.hpp>

#include <QMutex>

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
