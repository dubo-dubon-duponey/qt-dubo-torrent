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
    qDebug() << " [M] TORRENT: constructor";
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
    qDebug() << " [M] VLC: root getter";
    if(!_rp_root){
        _rp_root = new RoxeeTorrent::Root();
    }
    return _rp_root;
}



void Session::addTorrent(const QString & torrentfilepath){
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


QString Session::addMagnet(const QString & uri, const QString & save_path)
{
    qDebug() << " [M] TORRENT: add magnet";
//    boost::filesystem::path t = boost::filesystem::path(path.toLocal8Bit());
//    boost::filesystem::path s = boost::filesystem::path(save_path.toLocal8Bit());
    libtorrent::torrent_handle to = libtorrent::add_magnet_uri(* LRTCoreInstance::instance()->getSession(),
        uri.toStdString(), save_path.toStdString());
//        uri.toStdString(), s);

    libtorrent::sha1_hash hash = to.info_hash();
    std::ostringstream o;
    o << hash;
    qDebug() << "hooooooooooooooooooooooooooooooooo";
    qDebug() << o.str().c_str();
    return QString(o.str().c_str());
////    return QString(o.str().c_str());

////            ->add_torrent(ti, s);
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
    qDebug() << " [M] TORRENT: destructor";
    LRTCoreInstance::instance()->drop();
}

void Session::loadState(const QString & entry)
{
    const char * in = entry.toLocal8Bit().constData();
    libtorrent::lazy_entry e;
    if (lazy_bdecode(&in[0], &in[0] + sizeof(in), e) == 0) {
      LRTCoreInstance::instance()->getSession()->load_state(e);
    }
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
    QByteArray * q = new QByteArray();
    return QString::fromLocal8Bit(out.data());
}


const bool Session::is_paused(){
    qDebug() << " [M] TORRENT: is paused?";
    LRTCoreInstance * c = LRTCoreInstance::instance();
    return c->getSession()->is_paused();
}

void Session::pause(){
    qDebug() << " [M] TORRENT: pause";
    LRTCoreInstance::instance()->getSession()->pause();
}

void Session::resume(){
    qDebug() << " [M] TORRENT: resume";
    LRTCoreInstance::instance()->getSession()->resume();
}

void Session::abort(){
    qDebug() << " [M] TORRENT: abort";
    LRTCoreInstance::instance()->getSession()->abort();
}

const bool Session::is_dht_running(){
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

const int Session::upload_rate_limit(){
    return LRTCoreInstance::instance()->getSession()->upload_rate_limit();
}
void Session::set_upload_rate_limit(const int rate){
    LRTCoreInstance::instance()->getSession()->set_upload_rate_limit(rate);
}

const int Session::download_rate_limit(){
    return LRTCoreInstance::instance()->getSession()->download_rate_limit();
}
void Session::set_download_rate_limit(const int rate){
    LRTCoreInstance::instance()->getSession()->set_download_rate_limit(rate);
}

const int Session::local_upload_rate_limit(){
    return LRTCoreInstance::instance()->getSession()->local_upload_rate_limit();
}
void Session::set_local_upload_rate_limit(const int rate){
    LRTCoreInstance::instance()->getSession()->set_local_upload_rate_limit(rate);
}

const int Session::local_download_rate_limit(){
    return LRTCoreInstance::instance()->getSession()->local_download_rate_limit();
}
void Session::set_local_download_rate_limit(const int rate){
    LRTCoreInstance::instance()->getSession()->set_local_download_rate_limit(rate);
}

const int Session::max_connections(){
    return LRTCoreInstance::instance()->getSession()->max_connections();
}
void Session::set_max_connections(const int limit){
    LRTCoreInstance::instance()->getSession()->set_max_connections(limit);
}

const int Session::max_half_open_connections(){
    return LRTCoreInstance::instance()->getSession()->max_half_open_connections();
}
void Session::set_max_half_open_connections(const int limit){
    LRTCoreInstance::instance()->getSession()->set_max_half_open_connections(limit);
}

const int Session::max_uploads(){
    return LRTCoreInstance::instance()->getSession()->max_uploads();
}
void Session::set_max_uploads(const int limit){
    LRTCoreInstance::instance()->getSession()->set_max_uploads(limit);
}

const int Session::num_uploads(){
    return LRTCoreInstance::instance()->getSession()->num_uploads();
}
const int Session::num_connections(){
    return LRTCoreInstance::instance()->getSession()->num_connections();
}

const QVariant Session::popAlert(){
    std::auto_ptr<libtorrent::alert> t = LRTCoreInstance::instance()->getSession()->pop_alert();
    if(t.get()){
        Alert* myalert = new Alert(QString::fromLocal8Bit(t->what()),
                                           QString::fromLocal8Bit(t->message().c_str()),
                                           t->category(),
                                           qint64(t->timestamp().time),
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

void Session::setAlertQueueSizeLimit(int l){
    LRTCoreInstance::instance()->getSession()->set_alert_queue_size_limit(l);
}

const bool Session::is_listening(){
    return LRTCoreInstance::instance()->getSession()->is_listening();
}

const int Session::listen_port(){
    return LRTCoreInstance::instance()->getSession()->listen_port();
}

void Session::listenOn(const int startPort, const int endPort){
    // XXX doesn't support interface specific listening
    std::pair<int,int> ports(startPort, endPort);
    libtorrent::error_code ec;
    return LRTCoreInstance::instance()->getSession()->listen_on(ports, ec);
}


const int Session::getTorrentsLength()
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
