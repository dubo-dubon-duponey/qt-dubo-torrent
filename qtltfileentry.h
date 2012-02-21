#ifndef QTLTFILEENTRY_H
#define QTLTFILEENTRY_H

#include <QObject>
#include <libtorrent/torrent_info.hpp>

class QtLtFileEntry : public QObject
{
    Q_OBJECT
public:
    explicit QtLtFileEntry(libtorrent::file_entry fe, QObject *parent = 0);
    
    Q_PROPERTY(const bool executableAttribute   READ executable_attribute)
    Q_PROPERTY(const qint64 fileBase               READ file_base)
    Q_PROPERTY(const bool hiddenAttribute       READ hidden_attribute)
    Q_PROPERTY(const qint64 mtime                  READ mtime)
    Q_PROPERTY(const qint64 offset                 READ offset)
    Q_PROPERTY(const bool padFile               READ pad_file)
    Q_PROPERTY(const qint64 size                   READ size)
    Q_PROPERTY(const qint64 symlinkAttribute       READ symlink_attribute)

    Q_PROPERTY(const QString path               READ path)
    Q_PROPERTY(const QString symlinkPath        READ symlink_path)

    const bool executable_attribute();
    const qint64 file_base();
    const bool hidden_attribute();
    const qint64 mtime();
    const qint64 offset();
    const bool pad_file();
    const qint64 size();
    const bool symlink_attribute();
    const QString path();
    const QString symlink_path();

signals:
    
public slots:

private:
    libtorrent::file_entry fileentry;
};

#endif // QTLTFILEENTRY_H
