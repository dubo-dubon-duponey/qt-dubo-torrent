#ifndef QTLTSESSION_H
#define QTLTSESSION_H

#include "qt-libtorrent_global.h"

// #include <libtorrent/session.hpp>

#include "qtltalert.h"

#include <QObject>
#include <QVariant>

class QTLIBTORRENTSHARED_EXPORT QtltSession : public QObject
{
    Q_OBJECT
public:
    // XXX maybe let pass the error mask?
    // XXX maybe let expose the constructor to JS
    explicit QtltSession(const QString & id, const int & major, const int & minor, const int & revision, const int & tag, QObject* parent = 0);
    ~QtltSession();

    Q_INVOKABLE const bool isPaused();
    Q_INVOKABLE void pause();
    Q_INVOKABLE void resume();
    Q_INVOKABLE const bool isDhtRunning();
    Q_INVOKABLE void startDht();
    Q_INVOKABLE void stopDht();
    Q_INVOKABLE void startLsd();
    Q_INVOKABLE void stopLsd();

    Q_PROPERTY(int uploadRateLimit          READ upload_rate_limit          WRITE set_upload_rate_limit)
    Q_PROPERTY(int downloadRateLimit        READ download_rate_limit        WRITE set_download_rate_limit)
    Q_PROPERTY(int localUploadRateLimit     READ local_upload_rate_limit    WRITE set_local_upload_rate_limit)
    Q_PROPERTY(int localDownloadRateLimit   READ local_download_rate_limit  WRITE set_local_download_rate_limit)
    Q_PROPERTY(int maxConnections           READ max_connections            WRITE set_max_connections)
    Q_PROPERTY(int maxHalfOpenConnections   READ max_half_open_connections  WRITE set_max_half_open_connections)
    Q_PROPERTY(int maxUploads               READ max_uploads                WRITE set_max_uploads)
    Q_PROPERTY(int numUploads               READ num_uploads)
    Q_PROPERTY(int numConnections           READ num_connections)
    Q_PROPERTY(bool isListening READ is_listening)
    Q_PROPERTY(int  listenPort  READ listen_port)

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
    const bool is_listening();
    const int listen_port();

    Q_INVOKABLE const QVariant popAlert();
    Q_INVOKABLE void setAlertMask(int m);
    Q_INVOKABLE void setAlertQueueSizeLimit(int l);
    Q_INVOKABLE bool listenOn(const int startPort, const int endPort);

    Q_INVOKABLE void addTorrent();

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

// THAT should rather get in
    void load_state(lazy_entry const& e);
    void save_state(entry& e, boost::uint32_t flags) const;

        enum save_state_flags_t
        {
                save_settings = 0x001,
                save_dht_settings = 0x002,
                save_dht_proxy = 0x004,
                save_dht_state = 0x008,
                save_i2p_proxy = 0x010,
                save_encryption_settings = 0x020,
                save_peer_proxy = 0x040,
                save_web_proxy = 0x080,
                save_tracker_proxy = 0x100,
                save_as_map = 0x200,
        };


// should rather be controlled by the app, not by script, which knows bothing about system proxy and so forth...
        // either way, investigate proxy problems more globally
        void set_peer_proxy(proxy_settings const& s);
        void set_web_seed_proxy(proxy_settings const& s);
        void set_tracker_proxy(proxy_settings const& s);

        proxy_settings const& peer_proxy() const;
        proxy_settings const& web_seed_proxy() const;
        proxy_settings const& tracker_proxy() const;


        // Might be interesting in order not to freeze like an ass when closing the session
        session_proxy abort();

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
