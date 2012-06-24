/**
 * Copyright (c) 2012, WebItUp <contact@webitup.fr>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
 *
 * Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
 * Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "coreinstance.h"
#include "session.h"
#include "torrenthandle.h"
#include "alert.h"

#include <libtorrent/bencode.hpp>
#include <libtorrent/torrent_info.hpp>
#include <libtorrent/torrent_handle.hpp>
#include <libtorrent/magnet_uri.hpp>

#include <QtCore/QDateTime>
#include <QtCore/QDebug>
#include <QtCore/QByteArray>

/*! \cond */

using namespace RoxeeTorrent;
namespace RoxeeTorrent{

// XXX maybe let pass the error mask?
Session::Session(const QString & id, const int & major, const int & minor, const int & revision, const int & tag, QObject* parent):
    QObject(parent)
{
    qDebug() << "     +++ [Lib] {Torrent}: constructor";
    _rp_root = 0;
    // Check http://wiki.theory.org/BitTorrentSpecification#peer_id
    // Should be two char long
    // XXX BOGUS
//    const char * identifier = id.toLocal8Bit().constData();
//    std::string identifier = id.toStdString();
    LRTCoreInstance::instance()->setSession( new libtorrent::session(
               libtorrent::fingerprint( id.toLocal8Bit().constData(), major, minor, revision, tag),
                libtorrent::session::start_default_features
                | libtorrent::session::add_default_plugins,
                libtorrent::alert::all_categories));
}

RoxeeTorrent::Root * Session::root()
{
    if(!_rp_root){
        _rp_root = new RoxeeTorrent::Root();
    }
    return _rp_root;
}



void Session::addTorrent(const QString & /*torrentfilepath*/ ){
    // save_path, ti, pointeur vers torrent_info
/*
    // XXX To avoid some exceptions
    // boost::filesystem::path::default_name_check(boost::filesystem::no_check);
    boost::filesystem::path t = boost::filesystem::path(torrentfilepath.toLocal8Bit());
    libtorrent::torrent_info* ti = new libtorrent::torrent_info(t);

    boost::filesystem::path s = boost::filesystem::path("/Users/dmp/Desktop/test");

    //    boost::filesystem::path const& filename

    libtorrent::torrent_handle to = LRTCoreInstance::instance()->getSession()->add_torrent(ti, s);

*/
    //    boost::intrusive_ptr<libtorrent::torrent_info> ti = new libtorrent::torrent_info();
}

// http://code.google.com/p/libtorrent/issues/detail?id=96


//QString Session::addMagnet(const QString & uri, const QString & save_path)
//{
    // XXX DEPRECATED MUST ACCESS TORRENT_PARAM / async_add_torrent
//    qDebug() << " [M] TORRENT: add magnet";
//    libtorrent::torrent_handle to = libtorrent::add_magnet_uri(* LRTCoreInstance::instance()->getSession(),
//        uri.toStdString(), save_path.toStdString());

//    libtorrent::sha1_hash hash = to.info_hash();
//    std::ostringstream o;
//    o << hash;
//    qDebug() << "hooooooooooooooooooooooooooooooooo";
//    qDebug() << o.str().c_str();
//    return QString(o.str().c_str());
//    return 0;


//    libtorrent::async_add_torrent()



    //    boost::filesystem::path t = boost::filesystem::path(path.toLocal8Bit());
    //    boost::filesystem::path s = boost::filesystem::path(save_path.toLocal8Bit());
//        uri.toStdString(), s);


    ////    return QString(o.str().c_str());

    ////            ->add_torrent(ti, s);
//}




QString Session::addMagnet(const QString & uri, const QString & save_path)
{

    // Actually add the torrent
//    add_torrent_params p = initializeAddTorrentParams(hash);
//    p.ti = t;

//    // Get fast resume data if existing
//    bool fastResume = false;
//    std::vector<char> buf; // Needs to stay in the function scope
//    if (resumed) {
//      if (loadFastResumeData(hash, buf)) {
//        fastResume = true;
//        p.resume_data = &buf;
//        qDebug("Successfully loaded fast resume data");
//      }
//    }

//    QString savePath;
//    if (!from_url.isEmpty() && savepathLabel_fromurl.contains(QUrl::fromEncoded(from_url.toUtf8()))) {
//      // Enforcing the save path defined before URL download (from RSS for example)
//      QPair<QString, QString> savePath_label = savepathLabel_fromurl.take(QUrl::fromEncoded(from_url.toUtf8()));
//      if (savePath_label.first.isEmpty())
//        savePath = getSavePath(hash, fromScanDir, path);
//      else
//        savePath = savePath_label.first;
//      // Remember label
//      TorrentTempData::setLabel(hash, savePath_label.second);
//    } else {
//      savePath = getSavePath(hash, fromScanDir, path);
//    }
//    if (!defaultTempPath.isEmpty() && !TorrentPersistentData::isSeed(hash) && resumed) {
//      qDebug("addTorrent::Temp folder is enabled.");
//      QString torrent_tmp_path = defaultTempPath.replace("\\", "/");
//      p.save_path = torrent_tmp_path.toUtf8().constData();
//      // Check if save path exists, creating it otherwise
//      if (!QDir(torrent_tmp_path).exists()) QDir().mkpath(torrent_tmp_path);
//      qDebug("addTorrent: using save_path: %s", qPrintable(torrent_tmp_path));
//    } else {
//      p.save_path = savePath.toUtf8().constData();
//      // Check if save path exists, creating it otherwise
//      if (!QDir(savePath).exists()) QDir().mkpath(savePath);
//      qDebug("addTorrent: using save_path: %s", qPrintable(savePath));
//    }

//    // Adding torrent to Bittorrent session
//    try {
//      h =  QTorrentHandle(s->add_torrent(p);
//    }catch(std::exception e) {
//      qDebug("Error: %s", e.what());
//    }


    libtorrent::add_torrent_params p;
    p.save_path = save_path.toStdString();

#if LIBTORRENT_VERSION_MINOR >= 16
//    p.seed_mode = false;
//    p.auto_managed = true;
    p.url = uri.toStdString();
    libtorrent::torrent_handle to = LRTCoreInstance::instance()->getSession()->add_torrent(p);

    libtorrent::sha1_hash hash = to.info_hash();
    std::ostringstream o;
    o << hash;
    qDebug() << "hooooooooooooooooooooooooooooooooo";
    qDebug() << o.str().c_str();
    return QString(o.str().c_str());
#else
	// XXX dirty temporary hack to have the shit compile
	libtorrent::add_magnet_uri(* LRTCoreInstance::instance()->getSession(),
		uri.toStdString(), p);
	return 0;
#endif

//    typedef boost::function<storage_interface*(file_storage const&
//            , file_storage const*, std::string const&, file_pool&
//            , std::vector<boost::uint8_t> const&) storage_constructor_type;

//    struct add_torrent_params
//    {
//            add_torrent_params(storage_constructor_type s);

//            enum flags_t
//            {
//                    flag_seed_mode = 0x001,
//                    flag_override_resume_data = 0x002,
//                    flag_upload_mode = 0x004,
//                    flag_share_mode = 0x008,
//                    flag_apply_ip_filter = 0x010,
//                    flag_paused = 0x020,
//                    flag_auto_managed = 0x040.
//                    flag_duplicate_is_error = 0x080,
//                    flag_merge_resume_trackers = 0x100,
//                    flag_update_subscribe = 0x200
//            };

//            int version;
//            boost::intrusive_ptr<torrent_info> ti;
//            std::vector<std::string> trackers;
//            std::vector<std::pair<std::string, int> > dht_nodes;
//            sha1_hash info_hash;
//            std::string name;
//            std::string save_path;
//            std::vector<char>* resume_data;
//            storage_mode_t storage_mode;
//            storage_constructor_type storage;
//            void* userdata;
//            std::vector<boost::uint8_t> const* file_priorities;
//            std::string trackerid;
//            std::string url;
//            std::string uuid;
//            std::string source_feed_url;
//            boost::uint64_t flags;
//    };

//    torrent_handle add_torrent(add_torrent_params const& params);
//    torrent_handle add_torrent(add_torrent_params const& params
//            , error_code& ec);
//    void async_add_torrent(add_torrent_params const& params);

}











//add_magnet_uri()
//torrent_handle add_magnet_uri(session& ses, std::string const& uri
//        add_torrent_params p);
//torrent_handle add_magnet_uri(session& ses, std::string const& uri
//        add_torrent_params p, error_code& ec);
//This function parses the magnet URI (uri) as a bittorrent magnet link, and adds the torrent to the specified session (ses). It returns the handle to the newly added torrent, or an invalid handle in case parsing failed. To control some initial settings of the torrent, sepcify those in the add_torrent_params, p. See add_torrent().

//The overload that does not take an error_code throws an exception on error and is not available when building without exception support.

//For more information about magnet links, see magnet links.



// XXX will block until all trackers are notified - might or might not be what we want
Session::~Session()
{
    qDebug() << "     --- [Lib] {Torrent}: destructor";
    LRTCoreInstance::instance()->drop();
}

void Session::loadState(const QString & entry)
{
    const char * in = entry.toLocal8Bit().constData();
    libtorrent::lazy_entry e;
    libtorrent::error_code c;
#if LIBTORRENT_VERSION_MINOR >= 16
    if (lazy_bdecode(&in[0], &in[0] + sizeof(in), e, c) == 0) {
      LRTCoreInstance::instance()->getSession()->load_state(e);
    }
#else
	lazy_bdecode(&in[0], &in[0] + sizeof(in), e);
	LRTCoreInstance::instance()->getSession()->load_state(e);
#endif
}

const QString Session::saveState(const int & flags)
{
    libtorrent::entry e;
    if(flags){
        LRTCoreInstance::instance()->getSession()->save_state(e, flags);
    }else{
        LRTCoreInstance::instance()->getSession()->save_state(e);
    }
    std::vector<char> out;
    bencode(std::back_inserter(out), e);
//    QByteArray * q = new QByteArray();
    return QString::fromLocal8Bit(out.data());
}


bool Session::is_paused(){
    qDebug() << "     *** [Lib] {Torrent}: is paused?";
    LRTCoreInstance * c = LRTCoreInstance::instance();
    return c->getSession()->is_paused();
}

void Session::pause(){
    qDebug() << "     *** [Lib] {Torrent}: pause";
    LRTCoreInstance::instance()->getSession()->pause();
}

void Session::resume(){
    qDebug() << "     *** [Lib] {Torrent}: resume";
    LRTCoreInstance::instance()->getSession()->resume();
}

void Session::abort(){
    qDebug() << "     *** [Lib] {Torrent}: abort";
    LRTCoreInstance::instance()->getSession()->abort();
}

bool Session::is_dht_running(){
    return LRTCoreInstance::instance()->getSession()->is_dht_running();
}

void Session::startDht(){
    LRTCoreInstance::instance()->getSession()->start_dht();
}

void Session::stopDht(){
    LRTCoreInstance::instance()->getSession()->stop_dht();
}

void Session::startLsd(){
    LRTCoreInstance::instance()->getSession()->start_lsd();
}

void Session::stopLsd(){
    LRTCoreInstance::instance()->getSession()->stop_lsd();
}

int Session::upload_rate_limit(){
#if LIBTORRENT_VERSION_MINOR >= 16
    return LRTCoreInstance::instance()->getSession()->settings().upload_rate_limit;
#else
	return 0;
#endif
}
void Session::set_upload_rate_limit(const int rate){
    // XXX Is this even working???
#if LIBTORRENT_VERSION_MINOR >= 16
    LRTCoreInstance::instance()->getSession()->settings().upload_rate_limit = rate;
#else
	qDebug() << "Cant set rate! Too old libtorrent";
	qDebug() << rate;
#endif
//    LRTCoreInstance::instance()->getSession()->set_upload_rate_limit(rate);
}

int Session::download_rate_limit(){
#if LIBTORRENT_VERSION_MINOR >= 16
    return LRTCoreInstance::instance()->getSession()->settings().download_rate_limit;
#else
	return 0;
#endif
}
void Session::set_download_rate_limit(const int rate){
#if LIBTORRENT_VERSION_MINOR >= 16
    LRTCoreInstance::instance()->getSession()->settings().download_rate_limit = rate;
#else
	qDebug() << "Cant set rate! Too old libtorrent";
	qDebug() << rate;
#endif
//    LRTCoreInstance::instance()->getSession()->set_download_rate_limit(rate);
}

//const int Session::local_upload_rate_limit(){
//    return 0; // LRTCoreInstance::instance()->getSession()->local_upload_rate_limit();
//}
//void Session::set_local_upload_rate_limit(const int rate){
////    LRTCoreInstance::instance()->getSession()->set_local_upload_rate_limit(rate);
//}

//const int Session::local_download_rate_limit(){
//    return 0; // LRTCoreInstance::instance()->getSession()->local_download_rate_limit();
//}
//void Session::set_local_download_rate_limit(const int rate){
////    LRTCoreInstance::instance()->getSession()->set_local_download_rate_limit(rate);
//}

//const int Session::max_connections(){
//    return 0;//LRTCoreInstance::instance()->getSession()->max_connections();
//}
//void Session::set_max_connections(const int limit){
//    // LRTCoreInstance::instance()->getSession()->set_max_connections(limit);
//}

//const int Session::max_half_open_connections(){
//    return 0;//LRTCoreInstance::instance()->getSession()->max_half_open_connections();
//}
//void Session::set_max_half_open_connections(const int limit){
//    // LRTCoreInstance::instance()->getSession()->set_max_half_open_connections(limit);
//}

//const int Session::max_uploads(){
//    return 0; // LRTCoreInstance::instance()->getSession()->max_uploads();
//}
//void Session::set_max_uploads(const int limit){
////    LRTCoreInstance::instance()->getSession()->set_max_uploads(limit);
//}

//const int Session::num_uploads(){
//    return 0; // LRTCoreInstance::instance()->getSession()->num_uploads();
//}
//const int Session::num_connections(){
//    return 0; // LRTCoreInstance::instance()->getSession()->num_connections();
//}

const QVariant Session::popAlert(){
    std::auto_ptr<libtorrent::alert> t = LRTCoreInstance::instance()->getSession()->pop_alert();
    if(t.get()){
        libtorrent::ptime boostDate =  t->timestamp();

        // Previously was boostDate.time
        struct std::tm tm;
        tm = boost::posix_time::to_tm(boostDate);
        const time_t ft = mktime(&tm);

        Alert* myalert = new Alert(QString::fromLocal8Bit(t->what()),
                                           QString::fromLocal8Bit(t->message().c_str()),
                                           t->category(),
                                           qint64(ft),
                                           this);
        QVariant var(QMetaType::QObjectStar);
        var.setValue((QObject*) myalert);
        return var;
    }
    return 0;
}

void Session::setAlertMask(int m){
    LRTCoreInstance::instance()->getSession()->set_alert_mask(m);
}

//void Session::setAlertQueueSizeLimit(int l){
//    // LRTCoreInstance::instance()->getSession()->set_alert_queue_size_limit(l);
//}

bool Session::is_listening(){
    return LRTCoreInstance::instance()->getSession()->is_listening();
}

int Session::listen_port(){
    return LRTCoreInstance::instance()->getSession()->listen_port();
}

void Session::listenOn(const int startPort, const int endPort){
    // XXX doesn't support interface specific listening
    std::pair<int,int> ports(startPort, endPort);
    libtorrent::error_code ec;
#if LIBTORRENT_VERSION_MINOR >= 16
    LRTCoreInstance::instance()->getSession()->listen_on(ports, ec);
#else
    LRTCoreInstance::instance()->getSession()->listen_on(ports);
#endif
}


int Session::getTorrentsLength()
{
    int num_resume_data = 0;
    std::vector<libtorrent::torrent_handle> handles = LRTCoreInstance::instance()->getSession()->get_torrents();
    for (std::vector<libtorrent::torrent_handle>::iterator i = handles.begin();
            i != handles.end(); ++i)
    {
        ++num_resume_data;
    }
    return num_resume_data;
}

void Session::removeTorrentAt(const int pos)
{
    std::vector<libtorrent::torrent_handle> handles = LRTCoreInstance::instance()->getSession()->get_torrents();
    int num_resume_data = 0;
    for (std::vector<libtorrent::torrent_handle>::iterator i = handles.begin();
            i != handles.end(); ++i)
    {
        if(num_resume_data == pos){
            libtorrent::torrent_handle& h = *i;
            LRTCoreInstance::instance()->getSession()->remove_torrent(h, 1);//libtorrent::session::delete_files);
            return;
        }
        num_resume_data++;
    }
    return;
}

const QVariant Session::getTorrentAt(const int pos)
{
    std::vector<libtorrent::torrent_handle> handles = LRTCoreInstance::instance()->getSession()->get_torrents();
    int num_resume_data = 0;
    for (std::vector<libtorrent::torrent_handle>::iterator i = handles.begin();
            i != handles.end(); ++i)
    {
        if(num_resume_data == pos){
            libtorrent::torrent_handle& h = *i;
            libtorrent::sha1_hash hash = h.info_hash();
            std::ostringstream o;
            o << hash;
            TorrentHandle * h2 = new TorrentHandle(QString(o.str().c_str()), this);
            QVariant var(QMetaType::QObjectStar);
            var.setValue((QObject*) h2);
            return var;
//            return QString(h.get_torrent_info().info_hash());
        }
        num_resume_data++;
    }
    return 0;
}

}
/*
std::auto_ptr<libtorrent::alert> t = LRTCoreInstance::instance()->getSession()->pop_alert();
if(t.get()){
    Alert* myalert = new Alert(QString::fromLocal8Bit(t->what()),
                                       QString::fromLocal8Bit(t->message().c_str()),
                                       t->category(),
                                       t->timestamp().time,
                                       this);
    QVariant var(QMetaType::QObjectStar);
    var.setValue((QObject*) myalert);
    return var;
}
return 0;
*/

/*







      boost::intrusive_ptr<torrent_info> ti;

        torrent_handle add_torrent(
                add_torrent_params const& params);
        torrent_handle add_torrent(
                add_torrent_params const& params
                , error_code& ec);

        void remove_torrent(torrent_handle const& h
                , int options = none);
        torrent_handle find_torrent(sha_hash const& ih);
        std::vector<torrent_handle> get_torrents() const;


         make_torrent
         save_resume_data


typedef storage_interface* (&storage_constructor_type)(
        file_storage const&, file_storage const*, fs::path const&, file_pool&);

struct add_torrent_params
{
        add_torrent_params(storage_constructor_type s);

        boost::intrusive_ptr<torrent_info> ti;
        char const* tracker_url;
        sha1_hash info_hash;
        char const* name;
        fs::path save_path;
        std::vector<char>* resume_data;
        storage_mode_t storage_mode;
        bool paused;
        bool auto_managed;
        bool duplicate_is_error;
        storage_constructor_type storage;
        void* userdata;
        bool seed_mode;
        bool override_resume_data;
        bool upload_mode;
};

torrent_handle add_torrent(add_torrent_params const& params);
torrent_handle add_torrent(add_torrent_params const& params
        , error_code& ec);



  */
/*! \endcond */
