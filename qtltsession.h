#ifndef QTLTSESSION_H
#define QTLTSESSION_H

#include "qt-libtorrent_global.h"

// #include <libtorrent/session.hpp>

#include "qtltalert.h"
#include "qtlttorrenthandle.h"

#include <QObject>
#include <QVariant>
// #include <QArray>

class QTLIBTORRENTSHARED_EXPORT QtltSession : public QObject
{
    Q_OBJECT
public:
    // XXX maybe let pass the error mask?
    // XXX maybe let expose the constructor to JS
    explicit QtltSession(const QString & id, const int & major, const int & minor, const int & revision, const int & tag, QObject* parent = 0);
    ~QtltSession();

    Q_INVOKABLE void loadState(const QString & e);
    Q_INVOKABLE const QString saveState(const int & flags = 0);

    Q_INVOKABLE void pause();
    Q_INVOKABLE void resume();
    Q_INVOKABLE void abort();

    Q_PROPERTY(const bool isPaused READ is_paused)
    const bool is_paused();

    Q_INVOKABLE void addTorrent(const QString & torrentfilepath);

    //    Q_INVOKABLE void removeTorrent(const QString & torrentfilepath);
// find_torrent() get_torrents()



    Q_PROPERTY(const bool isDhtRunning READ is_dht_running)
    const bool is_dht_running();
    Q_INVOKABLE void startDht();
    Q_INVOKABLE void stopDht();

    Q_INVOKABLE void startLsd();
    Q_INVOKABLE void stopLsd();

    Q_PROPERTY(int uploadRateLimit          READ upload_rate_limit          WRITE set_upload_rate_limit)
    Q_PROPERTY(int downloadRateLimit        READ download_rate_limit        WRITE set_download_rate_limit)
    Q_PROPERTY(int localUploadRateLimit     READ local_upload_rate_limit    WRITE set_local_upload_rate_limit)
    Q_PROPERTY(int localDownloadRateLimit   READ local_download_rate_limit  WRITE set_local_download_rate_limit)
    Q_PROPERTY(int maxConnections           READ max_connections            WRITE set_max_connections)
    Q_PROPERTY(int maxUploads               READ max_uploads                WRITE set_max_uploads)
    Q_PROPERTY(int maxHalfOpenConnections   READ max_half_open_connections  WRITE set_max_half_open_connections)

    Q_PROPERTY(int numUploads               READ num_uploads)
    Q_PROPERTY(int numConnections           READ num_connections)

    const int upload_rate_limit();
    void set_upload_rate_limit(const int rate);
    const int download_rate_limit();
    void set_download_rate_limit(const int rate);
    const int local_upload_rate_limit();
    void set_local_upload_rate_limit(const int rate);
    const int local_download_rate_limit();
    void set_local_download_rate_limit(const int rate);
    const int max_connections();
    void set_max_connections(const int limit);
    const int max_half_open_connections();
    void set_max_half_open_connections(const int limit);
    const int max_uploads();
    void set_max_uploads(const int limit);
    const int num_uploads();
    const int num_connections();

    Q_PROPERTY(bool isListening READ is_listening)
    Q_PROPERTY(int  listenPort  READ listen_port)
    Q_INVOKABLE bool listenOn(const int startPort, const int endPort);

    const bool is_listening();
    const int listen_port();

    Q_INVOKABLE const QVariant popAlert();
    Q_INVOKABLE void setAlertMask(int m = 0);
    Q_INVOKABLE void setAlertQueueSizeLimit(int l);

    Q_INVOKABLE const int getTorrentsLength();
    Q_INVOKABLE const QVariant getTorrentAt(int pos);

    //    Q_INVOKABLE const QVariant waitForAlert();
    // load_asnum_db() load_country_db() as_for_ip() set_ip_filter get_ip_filter
    // add_extension
    // set_settings() set_pe_settings() set_proxy() proxy()
    // http://doc.qt.nokia.com/4.8-snapshot/qnetworkproxyfactory.html#systemProxyForQuery

//    status()
//    session_status status() const;
//    status() returns session wide-statistics and status. The session_status struct has the following members:
    // set_dht_settings() dht_state()
    // add_dht_node() add_dht_router()
    // start_upnp() stop_upnp()
    // start_natpmp() stop_natpmp()

    Q_INVOKABLE void addMagnet(const QString & path, const QString & save_path);

signals:

public slots:

private:

};

#endif // QTLTSESSION_H

/*
  // XXX implement me

// Implement or not...
// Extensions being by default activated would be nice, but not sure it should be script controlled
        void add_extension(boost::function<
                boost::shared_ptr<torrent_plugin>(torrent*)> ext);


// should rather be controlled by the app, not by script, which knows bothing about system proxy and so forth...
        // either way, investigate proxy problems more globally
        void set_peer_proxy(proxy_settings const& s);
        void set_web_seed_proxy(proxy_settings const& s);
        void set_tracker_proxy(proxy_settings const& s);

        proxy_settings const& peer_proxy() const;
        proxy_settings const& web_seed_proxy() const;
        proxy_settings const& tracker_proxy() const;


        // Might be interesting in order not to freeze like an ass when closing the session

// Settings stuff
    void set_settings(session_settings const& settings);
    void set_pe_settings(pe_settings const& settings);
        void set_dht_settings(
                dht_settings const& settings);



// GEOIP Stuff: investigate worthiness later
        bool load_asnum_db(char const* file);
        bool load_asnum_db(wchar_t const* file);
        bool load_country_db(char const* file);
        bool load_country_db(wchar_t const* file);
        int as_for_ip(address const& adr);

        void set_ip_filter(ip_filter const& f);
        ip_filter const& get_ip_filter() const;


        // Info reporting stuff
        session_status status() const;
        cache_status get_cache_status() const;

// Routing stuff
        upnp* start_upnp();
        void stop_upnp();

        natpmp* start_natpmp();
        void stop_natpmp();

// Not too sure the practical use yet
        alert const* wait_for_alert(time_duration max_wait);

// DHT related stuff
// DHT state might be interesting to save
        entry dht_state() const;
        void add_dht_node(std::pair<std::string
                , int> const& node);
        void add_dht_router(std::pair<std::string
                , int> const& node);

  */

/*
    libtorrent::alert* t = dynamic_cast<libtorrent::alert*>(lt_alert.get());


        enum options_t
        {
                none = 0,
                delete_files = 1
        };

        enum session_flags_t
        {
                add_default_plugins = 1,
                start_default_features = 2
        };





  */
