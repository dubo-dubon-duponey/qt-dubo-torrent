#ifndef QTLTALERTTYPES_H
#define QTLTALERTTYPES_H

#include "qt-libtorrent_global.h"

#include <QObject>
#include <QMutex>

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

