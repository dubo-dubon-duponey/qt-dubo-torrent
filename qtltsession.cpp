#include "qtltsession.h"

#include <libtorrent/bencode.hpp>
#include <libtorrent/session.hpp>
#include <libtorrent/torrent_info.hpp>
#include <libtorrent/torrent_handle.hpp>
#include <boost/filesystem.hpp>
#include <libtorrent/magnet_uri.hpp>

#include "dirtyhack.h"

#include <QDateTime>
#include <QDebug>
// #include <QArray>
#include <QByteArray>

// XXX maybe let pass the error mask?
QtltSession::QtltSession(const QString & id, const int & major, const int & minor, const int & revision, const int & tag, QObject* parent):
    QObject(parent)
{
    // Check http://wiki.theory.org/BitTorrentSpecification#peer_id
    // Should be two char long
    const char * identifier = id.toLocal8Bit().constData();
    dirtyHack::instance()->setSession( new libtorrent::session(
                libtorrent::fingerprint( identifier, major, minor, revision, tag),
                libtorrent::session::start_default_features
                | libtorrent::session::add_default_plugins,
                libtorrent::alert::all_categories));
}


void QtltSession::addTorrent(const QString & torrentfilepath){
    // save_path, ti, pointeur vers torrent_info
/*
    // XXX To avoid some exceptions
    // boost::filesystem::path::default_name_check(boost::filesystem::no_check);
    boost::filesystem::path t = boost::filesystem::path(torrentfilepath.toLocal8Bit());
    libtorrent::torrent_info* ti = new libtorrent::torrent_info(t);

    boost::filesystem::path s = boost::filesystem::path("/Users/dmp/Desktop/test");

    //    boost::filesystem::path const& filename

    libtorrent::torrent_handle to = dirtyHack::instance()->getSession()->add_torrent(ti, s);

*/
    //    boost::intrusive_ptr<libtorrent::torrent_info> ti = new libtorrent::torrent_info();
}

// http://code.google.com/p/libtorrent/issues/detail?id=96


QString QtltSession::addMagnet(const QString & uri, const QString & save_path)
{
//    boost::filesystem::path t = boost::filesystem::path(path.toLocal8Bit());
//    boost::filesystem::path s = boost::filesystem::path(save_path.toLocal8Bit());
    libtorrent::torrent_handle to = libtorrent::add_magnet_uri(* dirtyHack::instance()->getSession(),
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
QtltSession::~QtltSession()
{
    dirtyHack::instance()->drop();
}

void QtltSession::loadState(const QString & entry)
{
    const char * in = entry.toLocal8Bit().constData();
    libtorrent::lazy_entry e;
    if (lazy_bdecode(&in[0], &in[0] + sizeof(in), e) == 0) {
      dirtyHack::instance()->getSession()->load_state(e);
    }
}

const QString QtltSession::saveState(const int & flags)
{
    libtorrent::entry e;
    if(flags){
        dirtyHack::instance()->getSession()->save_state(e, flags);
    }else{
        dirtyHack::instance()->getSession()->save_state(e);
    }
    std::vector<char> out;
    bencode(std::back_inserter(out), e);
    QByteArray * q = new QByteArray();
    return QString::fromLocal8Bit(out.data());
}


const bool QtltSession::is_paused(){
    return dirtyHack::instance()->getSession()->is_paused();
}

void QtltSession::pause(){
    dirtyHack::instance()->getSession()->pause();
}

void QtltSession::resume(){
    dirtyHack::instance()->getSession()->resume();
}

void QtltSession::abort(){
    dirtyHack::instance()->getSession()->abort();
}

const bool QtltSession::is_dht_running(){
    return dirtyHack::instance()->getSession()->is_dht_running();
}

void QtltSession::startDht(){
    dirtyHack::instance()->getSession()->start_dht();
}

void QtltSession::stopDht(){
    dirtyHack::instance()->getSession()->stop_dht();
}

void QtltSession::startLsd(){
    dirtyHack::instance()->getSession()->start_lsd();
}

void QtltSession::stopLsd(){
    dirtyHack::instance()->getSession()->stop_lsd();
}

/**
 * Limit stuff
 */
const int QtltSession::upload_rate_limit(){
    return dirtyHack::instance()->getSession()->upload_rate_limit();
}
void QtltSession::set_upload_rate_limit(const int rate){
    dirtyHack::instance()->getSession()->set_upload_rate_limit(rate);
}

const int QtltSession::download_rate_limit(){
    return dirtyHack::instance()->getSession()->download_rate_limit();
}
void QtltSession::set_download_rate_limit(const int rate){
    dirtyHack::instance()->getSession()->set_download_rate_limit(rate);
}

const int QtltSession::local_upload_rate_limit(){
    return dirtyHack::instance()->getSession()->local_upload_rate_limit();
}
void QtltSession::set_local_upload_rate_limit(const int rate){
    dirtyHack::instance()->getSession()->set_local_upload_rate_limit(rate);
}

const int QtltSession::local_download_rate_limit(){
    return dirtyHack::instance()->getSession()->local_download_rate_limit();
}
void QtltSession::set_local_download_rate_limit(const int rate){
    dirtyHack::instance()->getSession()->set_local_download_rate_limit(rate);
}

const int QtltSession::max_connections(){
    return dirtyHack::instance()->getSession()->max_connections();
}
void QtltSession::set_max_connections(const int limit){
    dirtyHack::instance()->getSession()->set_max_connections(limit);
}

const int QtltSession::max_half_open_connections(){
    return dirtyHack::instance()->getSession()->max_half_open_connections();
}
void QtltSession::set_max_half_open_connections(const int limit){
    dirtyHack::instance()->getSession()->set_max_half_open_connections(limit);
}

const int QtltSession::max_uploads(){
    return dirtyHack::instance()->getSession()->max_uploads();
}
void QtltSession::set_max_uploads(const int limit){
    dirtyHack::instance()->getSession()->set_max_uploads(limit);
}

const int QtltSession::num_uploads(){
    return dirtyHack::instance()->getSession()->num_uploads();
}
const int QtltSession::num_connections(){
    return dirtyHack::instance()->getSession()->num_connections();
}

/**
 * Alerts
 */
const QVariant QtltSession::popAlert(){
    std::auto_ptr<libtorrent::alert> t = dirtyHack::instance()->getSession()->pop_alert();
    if(t.get()){
        QtltAlert* myalert = new QtltAlert(QString::fromLocal8Bit(t->what()),
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

void QtltSession::setAlertMask(int m){
    dirtyHack::instance()->getSession()->set_alert_mask(m);
}

void QtltSession::setAlertQueueSizeLimit(int l){
    dirtyHack::instance()->getSession()->set_alert_queue_size_limit(l);
}

/**
 * Listening
 */
const bool QtltSession::is_listening(){
    return dirtyHack::instance()->getSession()->is_listening();
}

const int QtltSession::listen_port(){
    return dirtyHack::instance()->getSession()->listen_port();
}

bool QtltSession::listenOn(const int startPort, const int endPort){
    // XXX doesn't support interface specific listening
    std::pair<int,int> ports(startPort, endPort);
    return dirtyHack::instance()->getSession()->listen_on(ports);
}


const int QtltSession::getTorrentsLength()
{
    int num_resume_data = 0;
    std::vector<libtorrent::torrent_handle> handles = dirtyHack::instance()->getSession()->get_torrents();
    for (std::vector<libtorrent::torrent_handle>::iterator i = handles.begin();
            i != handles.end(); ++i)
    {
        ++num_resume_data;
    }
    return num_resume_data;
}

void QtltSession::removeTorrentAt(const int pos)
{
    std::vector<libtorrent::torrent_handle> handles = dirtyHack::instance()->getSession()->get_torrents();
    int num_resume_data = 0;
    for (std::vector<libtorrent::torrent_handle>::iterator i = handles.begin();
            i != handles.end(); ++i)
    {
        if(num_resume_data == pos){
            libtorrent::torrent_handle& h = *i;
            dirtyHack::instance()->getSession()->remove_torrent(h, 1);//libtorrent::session::delete_files);
            return;
        }
        num_resume_data++;
    }
    return;
}

const QVariant QtltSession::getTorrentAt(const int pos)
{
    std::vector<libtorrent::torrent_handle> handles = dirtyHack::instance()->getSession()->get_torrents();
    int num_resume_data = 0;
    for (std::vector<libtorrent::torrent_handle>::iterator i = handles.begin();
            i != handles.end(); ++i)
    {
        if(num_resume_data == pos){
            libtorrent::torrent_handle& h = *i;
            libtorrent::sha1_hash hash = h.info_hash();
            std::ostringstream o;
            o << hash;
            QtLtTorrentHandle * h2 = new QtLtTorrentHandle(QString(o.str().c_str()), this);
            QVariant var(QMetaType::QObjectStar);
            var.setValue((QObject*) h2);
            return var;
//            return QString(h.get_torrent_info().info_hash());
        }
        num_resume_data++;
    }
    return 0;
}
/*
std::auto_ptr<libtorrent::alert> t = dirtyHack::instance()->getSession()->pop_alert();
if(t.get()){
    QtltAlert* myalert = new QtltAlert(QString::fromLocal8Bit(t->what()),
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
