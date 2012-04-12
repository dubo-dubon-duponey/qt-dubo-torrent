#include "qtlttorrenthandle.h"
#include "dirtyhack.h"
#include <QDebug>

QtLtTorrentHandle::QtLtTorrentHandle(const QString & hash, QObject *parent) :
    QObject(parent)
{
    m_hash = QString(hash);
    qDebug() << QString("HAD" + m_hash);

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


bool QtLtTorrentHandle::is_valid()
{
    // Convert string to ha1
    std::string str(m_hash.toAscii().data());
    std::istringstream i(str);
    libtorrent::sha1_hash x;
    i>>x;

    libtorrent::torrent_handle h = dirtyHack::instance()->getSession()->find_torrent(x);
    return h.is_valid();
}


const QString QtLtTorrentHandle::info_hash()
{
//    return m_hash;
    // Convert string to ha1
    std::string str(m_hash.toAscii().data());
    std::istringstream i(str);
    libtorrent::sha1_hash x;
    i>>x;

    libtorrent::torrent_handle h = dirtyHack::instance()->getSession()->find_torrent(x);
    if(h.is_valid()){
        libtorrent::sha1_hash hash = h.info_hash();

        std::ostringstream o;
        o << hash;
        return QString(o.str().c_str());
    }
    return 0;
}

const QString QtLtTorrentHandle::name()
{
    // Convert string to ha1
    std::string str(m_hash.toAscii().data());
    std::istringstream i(str);
    libtorrent::sha1_hash x;
    i>>x;

    libtorrent::torrent_handle h = dirtyHack::instance()->getSession()->find_torrent(x);
    if(h.is_valid()){
        return h.name().c_str();
    }
    return 0;
}


QString QtLtTorrentHandle::filePathAt(const int pos)
{
    // Convert string to ha1
    std::string str(m_hash.toAscii().data());
    std::istringstream i(str);
    libtorrent::sha1_hash x;
    i>>x;

    libtorrent::torrent_handle h = dirtyHack::instance()->getSession()->find_torrent(x);
    if(h.is_valid()){
        libtorrent::file_entry const& fe = h.get_torrent_info().file_at(pos);
        return QString::fromUtf8(fe.path.string().c_str());
    }
    return 0;
}

qint64 QtLtTorrentHandle::fileSizeAt(const int pos)
{
    // Convert string to ha1
    std::string str(m_hash.toAscii().data());
    std::istringstream i(str);
    libtorrent::sha1_hash x;
    i>>x;

    libtorrent::torrent_handle h = dirtyHack::instance()->getSession()->find_torrent(x);
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



bool QtLtTorrentHandle::is_sequential_download()
{
    if(!m_hash.length()){
        return 0;
    }
    // Convert string to ha1
    std::string str(m_hash.toAscii().data());
    std::istringstream i(str);
    libtorrent::sha1_hash x;
    i>>x;

    libtorrent::torrent_handle h = dirtyHack::instance()->getSession()->find_torrent(x);
    if(h.is_valid()){
        return h.is_sequential_download();
    }
    return 0;
}

void QtLtTorrentHandle::setSequential(bool flag)
{
    if(!m_hash.length()){
        return;
    }
//    // Convert string to ha1
    std::string str(m_hash.toAscii().data());
    std::istringstream i(str);
    libtorrent::sha1_hash x;
    i>>x;

    libtorrent::torrent_handle h = dirtyHack::instance()->getSession()->find_torrent(x);
    if(h.is_valid()){
        h.set_sequential_download(flag);
    }
}

//QVariant QtLtTorrentHandle::getInfo()
//{
//    // Convert string to ha1
//    std::string str(m_hash.toAscii().data());
//    std::istringstream i(str);
//    libtorrent::sha1_hash x;
//    i>>x;

//    libtorrent::torrent_handle h = dirtyHack::instance()->getSession()->find_torrent(x);

//    if(h.is_valid()){
//        libtorrent::torrent_info inf = h.get_torrent_info();
//        QtLtTorrentInfo v = new QtLtTorrentInfo(inf, this);
//        QVariant var(QMetaType::QObjectStar);
//        var.setValue((QObject*) v);
//        return var;
//    }
//    return 0;
//}



const int QtLtTorrentHandle::num_files()
{
    // Convert string to ha1
    std::string str(m_hash.toAscii().data());
    std::istringstream i(str);
    libtorrent::sha1_hash x;
    i>>x;

    libtorrent::torrent_handle h = dirtyHack::instance()->getSession()->find_torrent(x);
    if(h.is_valid() && h.has_metadata()){
        return h.get_torrent_info().num_files();
    }
    return 0;
}

//const QtLtFileEntry * QtLtTorrentHandle::getFileAt(const int & pos)
//{
//    libtorrent::file_entry fentry = torrentinfo->file_at(pos);
//    QtLtFileEntry * q = new QtLtFileEntry(fentry);
//    return q;
//}

const bool QtLtTorrentHandle::priv()
{
    // Convert string to ha1
    std::string str(m_hash.toAscii().data());
    std::istringstream i(str);
    libtorrent::sha1_hash x;
    i>>x;

    libtorrent::torrent_handle h = dirtyHack::instance()->getSession()->find_torrent(x);
    if(h.is_valid() && h.has_metadata()){
        return h.get_torrent_info().priv();
    }
    return 0;
}

const qint64 QtLtTorrentHandle::total_size()
{
//    if(!m_hash.length()){
//        return;
//    }
    // Convert string to ha1
    std::string str(m_hash.toAscii().data());
    std::istringstream i(str);
    libtorrent::sha1_hash x;
    i>>x;

    libtorrent::torrent_handle h = dirtyHack::instance()->getSession()->find_torrent(x);
    if(h.is_valid() && h.has_metadata()){
        libtorrent::torrent_info toto = h.get_torrent_info();
        return toto.total_size();
    }
    return 0;
}

const int QtLtTorrentHandle::num_pieces()
{
    // Convert string to ha1
    std::string str(m_hash.toAscii().data());
    std::istringstream i(str);
    libtorrent::sha1_hash x;
    i>>x;

    libtorrent::torrent_handle h = dirtyHack::instance()->getSession()->find_torrent(x);
    if(h.is_valid() && h.has_metadata()){
        return h.get_torrent_info().num_pieces();
    }
    return 0;
}

const int QtLtTorrentHandle::piece_length()
{
    // Convert string to ha1
    std::string str(m_hash.toAscii().data());
    std::istringstream i(str);
    libtorrent::sha1_hash x;
    i>>x;

    libtorrent::torrent_handle h = dirtyHack::instance()->getSession()->find_torrent(x);
    if(h.is_valid() && h.has_metadata()){
        return h.get_torrent_info().piece_length();
    }
    return 0;
}


const QString QtLtTorrentHandle::comment()
{
    // Convert string to ha1
    std::string str(m_hash.toAscii().data());
    std::istringstream i(str);
    libtorrent::sha1_hash x;
    i>>x;

    libtorrent::torrent_handle h = dirtyHack::instance()->getSession()->find_torrent(x);
    if(h.is_valid() && h.has_metadata()){
        return h.get_torrent_info().comment().c_str();
    }
    return 0;
}

const QString QtLtTorrentHandle::creator()
{
    // Convert string to ha1
    std::string str(m_hash.toAscii().data());
    std::istringstream i(str);
    libtorrent::sha1_hash x;
    i>>x;

    libtorrent::torrent_handle h = dirtyHack::instance()->getSession()->find_torrent(x);
    if(h.is_valid() && h.has_metadata()){
        return h.get_torrent_info().creator().c_str();
    }
    return 0;
}

const QString QtLtTorrentHandle::metadata()
{
    // Convert string to ha1
    std::string str(m_hash.toAscii().data());
    std::istringstream i(str);
    libtorrent::sha1_hash x;
    i>>x;

    libtorrent::torrent_handle h = dirtyHack::instance()->getSession()->find_torrent(x);
    if(h.is_valid() && h.has_metadata()){
        return h.get_torrent_info().metadata().get();// c_str();
    }
    return 0;
}

const qint64 QtLtTorrentHandle::all_time_download()
{
    // Convert string to ha1
    std::string str(m_hash.toAscii().data());
    std::istringstream i(str);
    libtorrent::sha1_hash x;
    i>>x;

    libtorrent::torrent_handle h = dirtyHack::instance()->getSession()->find_torrent(x);
    if(h.is_valid()){
        return h.status().all_time_download;// c_str();
    }
    return 0;
}

