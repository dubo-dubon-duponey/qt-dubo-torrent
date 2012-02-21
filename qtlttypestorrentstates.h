#ifndef QTLTTORRENTSTATES_H
#define QTLTTORRENTSTATES_H

#include <QObject>
#include <QMutex>

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
