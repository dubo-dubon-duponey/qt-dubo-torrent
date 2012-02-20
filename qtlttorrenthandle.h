#ifndef QTLTTORRENTHANDLE_H
#define QTLTTORRENTHANDLE_H

#include "qt-libtorrent_global.h"

#include <QObject>


class QTLIBTORRENTSHARED_EXPORT qtlttorrenthandle : public QObject
{
    Q_OBJECT
public:
    explicit qtlttorrenthandle(QObject *parent = 0);

signals:

public slots:

};

#endif // QTLTTORRENTHANDLE_H
