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

#ifndef ROXEETORRENT_SESSION_H
#define ROXEETORRENT_SESSION_H

#include "libroxeetorrent_global.h"

#include <QtCore/QObject>
#include <QtCore/QVariant>

#include "root.h"

namespace RoxeeTorrent
{
    /*!
      \brief The main instaciable class.
    */
    class LIBROXEETORRENTSHARED_EXPORT Session : public QObject
    {
        Q_OBJECT
    public:
        // XXX maybe let pass the error mask?
        // XXX maybe let expose the constructor to JS
        /*! \brief Session constructor.*/
        explicit Session(const QString & id, const int & major, const int & minor, const int & revision, const int & tag, QObject* parent = 0);
        ~Session();

        /*! \brief Accessor to the Root object */
        RoxeeTorrent::Root * root();

        /*! \brief Allows to restore the previous session state. */
        Q_INVOKABLE void loadState(const QString & e);
        /*! \brief Allows to serialize the current session state. */
        Q_INVOKABLE const QString saveState(const int & flags = 0);

        /*! \brief Pause the session. */
        Q_INVOKABLE void pause();
        /*! \brief Resume the session. */
        Q_INVOKABLE void resume();
        /*! \brief Abort the session. (dmp: wtf?) */
        Q_INVOKABLE void abort();

        /*! \brief Checks wether the session is paused or running. */
        Q_PROPERTY(const bool isPaused READ is_paused)

        /*! \brief Allows to add a torrent file. */
        Q_INVOKABLE void addTorrent(const QString & torrentfilepath);

        //    Q_INVOKABLE void removeTorrent(const QString & torrentfilepath);
    // find_torrent() get_torrents()



        /*! \brief Tells wether dht is enable or not. */
        Q_PROPERTY(const bool isDhtRunning READ is_dht_running)
        /*! \brief Start dht. */
        Q_INVOKABLE void startDht();
        /*! \brief Stop dht. */
        Q_INVOKABLE void stopDht();

        /*! \brief Start lsd. */
        Q_INVOKABLE void startLsd();
        /*! \brief Stop lsd. */
        Q_INVOKABLE void stopLsd();

//        /*! \brief Allow to retrieve and set the upload limit. */
//        Q_PROPERTY(int uploadRateLimit          READ upload_rate_limit          WRITE set_upload_rate_limit)
//        /*! \brief Allow to retrieve and set the download limit. */
//        Q_PROPERTY(int downloadRateLimit        READ download_rate_limit        WRITE set_download_rate_limit)
//        /*! \brief Allow to retrieve and set the local upload limit. */
//        Q_PROPERTY(int localUploadRateLimit     READ local_upload_rate_limit    WRITE set_local_upload_rate_limit)
//        /*! \brief Allow to retrieve and set the local download limit. */
//        Q_PROPERTY(int localDownloadRateLimit   READ local_download_rate_limit  WRITE set_local_download_rate_limit)
//        /*! \brief Allow to retrieve and set the max number of connections. */
//        Q_PROPERTY(int maxConnections           READ max_connections            WRITE set_max_connections)
//        /*! \brief Allow to retrieve and set the max number of uploads. */
//        Q_PROPERTY(int maxUploads               READ max_uploads                WRITE set_max_uploads)
//        /*! \brief Allow to retrieve and set the maxi number of half open connections. */
//        Q_PROPERTY(int maxHalfOpenConnections   READ max_half_open_connections  WRITE set_max_half_open_connections)

//        /*! \brief Allow to retrieve the number of current uploads. */
//        Q_PROPERTY(int numUploads               READ num_uploads)
//        /*! \brief Allow to retrieve the number of current connections. */
//        Q_PROPERTY(int numConnections           READ num_connections)

        /*! \cond */
        const bool is_paused();
        const bool is_dht_running();
        const int upload_rate_limit();
        void set_upload_rate_limit(const int rate);
        const int download_rate_limit();
        void set_download_rate_limit(const int rate);
//        const int local_upload_rate_limit();
//        void set_local_upload_rate_limit(const int rate);
//        const int local_download_rate_limit();
//        void set_local_download_rate_limit(const int rate);
//        const int max_connections();
//        void set_max_connections(const int limit);
//        const int max_half_open_connections();
//        void set_max_half_open_connections(const int limit);
//        const int max_uploads();
//        void set_max_uploads(const int limit);
//        const int num_uploads();
//        const int num_connections();
        /*! \endcond */

        /*! \brief Wether we are listening or not. */
        Q_PROPERTY(bool isListening READ is_listening)
        /*! \brief Gets the listening port. */
        Q_PROPERTY(int  listenPort  READ listen_port)
        /*! \brief Order to listen on the first available port between startPort and endPort. */
        Q_INVOKABLE void listenOn(const int startPort, const int endPort);

        /*! \cond */
        const bool is_listening();
        const int listen_port();
        /*! \endcond */

        /*! \brief Retrieve the last alert. @see Alert */
        Q_INVOKABLE const QVariant popAlert();
        /*! \brief Allows to set an alert mask. */
        Q_INVOKABLE void setAlertMask(int m = 0);

//        Q_INVOKABLE void setAlertQueueSizeLimit(int l);

        /*! \brief Gets the total number of torrents. */
        Q_INVOKABLE const int getTorrentsLength();
        /*! \brief Returns a torrent handle at position "pos". @see TorrentHandle */
        Q_INVOKABLE const QVariant getTorrentAt(int pos);
        /*! \brief Delete torrent at position "pos" (including files). */
        Q_INVOKABLE void removeTorrentAt(int pos);

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

        /*! \brief Adds a new torrent from magnet. */
        Q_INVOKABLE QString addMagnet(const QString & path, const QString & save_path);

    signals:

    public slots:

    private:
        RoxeeTorrent::Root * _rp_root;

    };
}

#endif // ROXEETORRENT_SESSION_H

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
