#include "QtLtTorrentInfo.h"
#include <libtorrent/torrent_info.hpp>
#include <qDebug>
#include "qtltfileentry.h"

QtLtTorrentInfo::QtLtTorrentInfo(const QString & path, QObject *parent):
    QObject(parent)
{
    boost::filesystem::path boostpath = boost::filesystem::path(path.toLocal8Bit());
    torrentinfo = new libtorrent::torrent_info(boostpath);

//    QStringList * files = new QStringList();
////    QObject * toto = new QObject();
////    toto->setProperty("titi", "ytut");
//    for(int i=0; i < ti->num_files(); ++i) {
//        libtorrent::file_entry fentry = ti->file_at(i);
////        const std::string & str = ;
//        QString pip = QString::fromUtf8(fentry.path.string().c_str());// QDir::cleanPath().replace("\\", "/");
//        qDebug() << pip;
//        qDebug() << fentry.offset;
//        qDebug() << fentry.file_base;
//        qDebug() << fentry.pad_file;
//        qDebug() << fentry.hidden_attribute;
//        qDebug() << fentry.executable_attribute;
//    }


//    qDebug() << this->num_files();
//    qDebug() << this->priv();
//    qDebug() << this->total_size();
//    qDebug() << this->piece_length();
//    qDebug() << this->num_pieces();
//    qDebug() << this->info_hash();
//    qDebug() << this->name();
//    qDebug() << this->comment();
//    qDebug() << this->creator();
//    qDebug() << this->creation_date();


}


const int QtLtTorrentInfo::num_files()
{
    return torrentinfo->num_files();
}

const QtLtFileEntry * QtLtTorrentInfo::getFileAt(const int & pos)
{
    libtorrent::file_entry fentry = torrentinfo->file_at(pos);
    QtLtFileEntry * q = new QtLtFileEntry(fentry);
    return q;
}

const bool QtLtTorrentInfo::priv()
{
    return torrentinfo->priv();
}

const qint64 QtLtTorrentInfo::total_size()
{
    return torrentinfo->total_size();
}

const int QtLtTorrentInfo::piece_length()
{
    return torrentinfo->piece_length();
}

const int QtLtTorrentInfo::num_pieces()
{
    return torrentinfo->num_pieces();
}

const QString QtLtTorrentInfo::info_hash()
{
    libtorrent::sha1_hash hash = torrentinfo->info_hash();
    std::ostringstream o;
    o << hash;
    return QString(o.str().c_str());
}

const QString QtLtTorrentInfo::name()
{
    return torrentinfo->name().c_str();
}

const QString QtLtTorrentInfo::comment()
{
    return torrentinfo->comment().c_str();
}

const QString QtLtTorrentInfo::creator()
{
    return torrentinfo->creator().c_str();
}

const qint64 QtLtTorrentInfo::creation_date()
{
    return 0;
//    const boost::optional<boost::posix_time::ptime> boostDate = torrentinfo->creation_date();
//    return boostDate->is_not_a_date_time();
//    if(!boostDate || !boostDate.is_initialized() || boostDate->is_not_a_date_time())
//        return 0;
//    struct std::tm tm;
//    try {
//        tm = boost::posix_time::to_tm(*boostDate);
//    } catch(std::exception e) {
//        return 0;
//    }
//    const time_t t = mktime(&tm);
//    if(t < 0)
//        return 0;
//    const QDateTime dt = QDateTime::fromTime_t(t);
//    if(dt.isNull() || !dt.isValid())
//        return 0;
//    return dt.toString(Qt::DefaultLocaleLongDate);
}

const QString QtLtTorrentInfo::metadata()
{
    return torrentinfo->metadata().get();
}

//    const int metadata_size();


//    boost::optional<boost::posix_time::ptime>
//    creation_date() const;

//    boost::shared_array<char> metadata() const;
//    int metadata_size() const;


//    size_type total_size() const;
//    int piece_length() const;
//    int num_pieces() const;
//    sha1_hash const& info_hash() const;
//    std::string const& name() const;
//    std::string const& comment() const;
//    std::string const& creator() const;


//    static inline QString toQStringU(const std::string &str) {
//      return QString::fromUtf8(str.c_str());

    //#if LIBTORRENT_VERSION_MINOR >= 16
//      QString path = QDir::cleanPath(misc::toQStringU(fentry.path)).replace("\\", "/");
//#else
//#endif


//    qDebug() << ti->file_at(1);


