#include "qtlttorrenthandle.h"
#include "dirtyhack.h"

QtLtTorrentHandle::QtLtTorrentHandle(const QString & hash, QObject *parent) :
    QObject(parent)
{
     m_hash = hash;
}

const QString QtLtTorrentHandle::info_hash()
{
/*
    libtorrent::torrent_handle h = dirtyHack::instance()->getSession()->find_torrent(libtorrent::sha1_hash(m_hash.toStdString()));

    libtorrent::sha1_hash hash = h->get_torrent_info()->info_hash();
    std::ostringstream o;
    o << hash;
    return QString(o.str().c_str());
    */
}


