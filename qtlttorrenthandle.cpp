#include "qtlttorrenthandle.h"
#include "dirtyhack.h"

QtLtTorrentHandle::QtLtTorrentHandle(const QString & hash, QObject *parent) :
    QObject(parent)
{
    dirtyHack::instance()->get_session()->find_torrent(hash.toLocal8Bit());
}

const QString QtLtTorrentHandle::info_hash()
{
    libtorrent::sha1_hash hash = torrentinfo->info_hash();
    std::ostringstream o;
    o << hash;
    return QString(o.str().c_str());
}


