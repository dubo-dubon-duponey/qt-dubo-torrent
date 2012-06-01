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

#include "coreinstance.h"
#include "torrenthandle.h"

#include <QtCore/QDebug>

using namespace RoxeeTorrent;

TorrentHandle::TorrentHandle(const QString & hash, QObject *parent) :
    QObject(parent)
{
    m_hash = QString(hash);
//    qDebug() << QString("HAD" + m_hash);

//    // Convert string to ha1
//    std::string str(hash.toAscii().data());
//    std::istringstream i(str);
//    libtorrent::sha1_hash x;
//    i>>x;

//    // Convert ha1 to string
//    std::ostringstream o;
//    o << x;
//    QString ret = QString(o.str().c_str());

//    qDebug("Back to square 1");
//    qDebug() << QString(ret);


}

// ToQString
//    static inline QString toQString(const libtorrent::sha1_hash &hash) {
//      std::ostringstream o;
//      o << hash;
//      return QString(o.str().c_str());
//    }
//    static inline libtorrent::sha1_hash QStringToSha1(const QString& s) {
//      std::string str(s.toAscii().data());
//      std::istringstream i(str);
//      libtorrent::sha1_hash x;
//      i>>x;
//      return x;
//    }


bool TorrentHandle::is_valid()
{
    // Convert string to ha1
    std::string str(m_hash.toAscii().data());
    std::istringstream i(str);
    libtorrent::sha1_hash x;
    i>>x;

    libtorrent::torrent_handle h = LRTCoreInstance::instance()->getSession()->find_torrent(x);
    return h.is_valid();
}


const QString TorrentHandle::info_hash()
{
    return m_hash;
//    // Convert string to ha1
//    std::string str(m_hash.toAscii().data());
//    std::istringstream i(str);
//    libtorrent::sha1_hash x;
//    i>>x;

//    libtorrent::torrent_handle h = LRTCoreInstance::instance()->getSession()->find_torrent(x);
//    if(h.is_valid()){
//        libtorrent::sha1_hash hash = h.info_hash();

//        std::ostringstream o;
//        o << hash;
//        return QString(o.str().c_str());
//    }
//    return 0;
}

const QString TorrentHandle::name()
{
    // Convert string to ha1
    std::string str(m_hash.toAscii().data());
    std::istringstream i(str);
    libtorrent::sha1_hash x;
    i>>x;

    libtorrent::torrent_handle h = LRTCoreInstance::instance()->getSession()->find_torrent(x);
    if(h.is_valid()){
        return h.name().c_str();
    }
    return 0;
}


QString TorrentHandle::filePathAt(const int pos)
{
    // Convert string to ha1
    std::string str(m_hash.toAscii().data());
    std::istringstream i(str);
    libtorrent::sha1_hash x;
    i>>x;

    libtorrent::torrent_handle h = LRTCoreInstance::instance()->getSession()->find_torrent(x);
    if(h.is_valid()){
        libtorrent::file_entry const& fe = h.get_torrent_info().file_at(pos);
        return QString::fromStdString(fe.path);
//        return QString::fromUtf8(fe.path.string().c_str());
    }
    return 0;
}

qint64 TorrentHandle::fileSizeAt(const int pos)
{
    // Convert string to ha1
    std::string str(m_hash.toAscii().data());
    std::istringstream i(str);
    libtorrent::sha1_hash x;
    i>>x;

    libtorrent::torrent_handle h = LRTCoreInstance::instance()->getSession()->find_torrent(x);
    if(h.is_valid()){
        libtorrent::file_entry const& fe = h.get_torrent_info().file_at(pos);
        return fe.size;
    }
    return 0;
}
//Q_INVOKABLE qint64 fileSizeAt(const int pos);
//    file_entry const& file_at(int index) const;
//    struct file_entry
//    {
//            std::string path;
//            size_type offset;
//            size_type size;
//            size_type file_base;
//            time_t mtime;
//            sha1_hash filehash;
//            bool pad_file:1;
//            bool hidden_attribute:1;
//            bool executable_attribute:1;
//            bool symlink_attribute:1;
//    };



bool TorrentHandle::is_sequential_download()
{
    if(!m_hash.length()){
        return 0;
    }
    // Convert string to ha1
    std::string str(m_hash.toAscii().data());
    std::istringstream i(str);
    libtorrent::sha1_hash x;
    i>>x;

    libtorrent::torrent_handle h = LRTCoreInstance::instance()->getSession()->find_torrent(x);
    if(h.is_valid()){
        return h.is_sequential_download();
    }
    return 0;
}

void TorrentHandle::setSequential(bool flag)
{
    if(!m_hash.length()){
        return;
    }
//    // Convert string to ha1
    std::string str(m_hash.toAscii().data());
    std::istringstream i(str);
    libtorrent::sha1_hash x;
    i>>x;

    libtorrent::torrent_handle h = LRTCoreInstance::instance()->getSession()->find_torrent(x);
    if(h.is_valid()){
        h.set_sequential_download(flag);
    }
}

//QVariant TorrentHandle::getInfo()
//{
//    // Convert string to ha1
//    std::string str(m_hash.toAscii().data());
//    std::istringstream i(str);
//    libtorrent::sha1_hash x;
//    i>>x;

//    libtorrent::torrent_handle h = LRTCoreInstance::instance()->getSession()->find_torrent(x);

//    if(h.is_valid()){
//        libtorrent::torrent_info inf = h.get_torrent_info();
//        QtLtTorrentInfo v = new QtLtTorrentInfo(inf, this);
//        QVariant var(QMetaType::QObjectStar);
//        var.setValue((QObject*) v);
//        return var;
//    }
//    return 0;
//}



const int TorrentHandle::num_files()
{
    // Convert string to ha1
    std::string str(m_hash.toAscii().data());
    std::istringstream i(str);
    libtorrent::sha1_hash x;
    i>>x;

    libtorrent::torrent_handle h = LRTCoreInstance::instance()->getSession()->find_torrent(x);
    if(h.is_valid() && h.has_metadata()){
        return h.get_torrent_info().num_files();
    }
    return 0;
}

//const QtLtFileEntry * TorrentHandle::getFileAt(const int & pos)
//{
//    libtorrent::file_entry fentry = torrentinfo->file_at(pos);
//    QtLtFileEntry * q = new QtLtFileEntry(fentry);
//    return q;
//}

const bool TorrentHandle::priv()
{
    // Convert string to ha1
    std::string str(m_hash.toAscii().data());
    std::istringstream i(str);
    libtorrent::sha1_hash x;
    i>>x;

    libtorrent::torrent_handle h = LRTCoreInstance::instance()->getSession()->find_torrent(x);
    if(h.is_valid() && h.has_metadata()){
        return h.get_torrent_info().priv();
    }
    return 0;
}

const qint64 TorrentHandle::total_size()
{
//    if(!m_hash.length()){
//        return;
//    }
    // Convert string to ha1
    std::string str(m_hash.toAscii().data());
    std::istringstream i(str);
    libtorrent::sha1_hash x;
    i>>x;

    libtorrent::torrent_handle h = LRTCoreInstance::instance()->getSession()->find_torrent(x);
    if(h.is_valid() && h.has_metadata()){
        libtorrent::torrent_info toto = h.get_torrent_info();
        return toto.total_size();
    }
    return 0;
}

const int TorrentHandle::num_pieces()
{
    // Convert string to ha1
    std::string str(m_hash.toAscii().data());
    std::istringstream i(str);
    libtorrent::sha1_hash x;
    i>>x;

    libtorrent::torrent_handle h = LRTCoreInstance::instance()->getSession()->find_torrent(x);
    if(h.is_valid() && h.has_metadata()){
        return h.get_torrent_info().num_pieces();
    }
    return 0;
}

const int TorrentHandle::piece_length()
{
    // Convert string to ha1
    std::string str(m_hash.toAscii().data());
    std::istringstream i(str);
    libtorrent::sha1_hash x;
    i>>x;

    libtorrent::torrent_handle h = LRTCoreInstance::instance()->getSession()->find_torrent(x);
    if(h.is_valid() && h.has_metadata()){
        return h.get_torrent_info().piece_length();
    }
    return 0;
}


const QString TorrentHandle::comment()
{
    // Convert string to ha1
    std::string str(m_hash.toAscii().data());
    std::istringstream i(str);
    libtorrent::sha1_hash x;
    i>>x;

    libtorrent::torrent_handle h = LRTCoreInstance::instance()->getSession()->find_torrent(x);
    if(h.is_valid() && h.has_metadata()){
        return h.get_torrent_info().comment().c_str();
    }
    return 0;
}

const QString TorrentHandle::creator()
{
    // Convert string to ha1
    std::string str(m_hash.toAscii().data());
    std::istringstream i(str);
    libtorrent::sha1_hash x;
    i>>x;

    libtorrent::torrent_handle h = LRTCoreInstance::instance()->getSession()->find_torrent(x);
    if(h.is_valid() && h.has_metadata()){
        return h.get_torrent_info().creator().c_str();
    }
    return 0;
}

const QString TorrentHandle::metadata()
{
    // Convert string to ha1
    std::string str(m_hash.toAscii().data());
    std::istringstream i(str);
    libtorrent::sha1_hash x;
    i>>x;

    libtorrent::torrent_handle h = LRTCoreInstance::instance()->getSession()->find_torrent(x);
    if(h.is_valid() && h.has_metadata()){
        return h.get_torrent_info().metadata().get();// c_str();
    }
    return 0;
}

const qint64 TorrentHandle::all_time_download()
{
    // Convert string to ha1
    std::string str(m_hash.toAscii().data());
    std::istringstream i(str);
    libtorrent::sha1_hash x;
    i>>x;

    libtorrent::torrent_handle h = LRTCoreInstance::instance()->getSession()->find_torrent(x);
    if(h.is_valid()){
        return h.status().all_time_download;// c_str();
    }
    return 0;
}

