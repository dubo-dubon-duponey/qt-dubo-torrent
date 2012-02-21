#ifndef QTLTSAVESTATES_H
#define QTLTSAVESTATES_H

#include <QObject>
#include <QMutex>

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
