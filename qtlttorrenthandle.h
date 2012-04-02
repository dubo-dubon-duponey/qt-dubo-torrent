#ifndef QTLTTORRENTHANDLE_H
#define QTLTTORRENTHANDLE_H

#include "qt-libtorrent_global.h"

#include <QObject>


class QTLIBTORRENTSHARED_EXPORT QtLtTorrentHandle : public QObject
{
    Q_OBJECT
public:
    explicit QtLtTorrentHandle(const QString & info_hash, QObject *parent = 0);
    Q_PROPERTY(const QString infoHash READ info_hash)

    const QString info_hash();

signals:

public slots:


private:
    QString m_hash;
};

#endif // QTLTTORRENTHANDLE_H


/*
struct torrent_handle
{
        torrent_handle();

        torrent_status status();
        void file_progress(std::vector<size_type>& fp, int flags = 0);
        void get_download_queue(std::vector<partial_piece_info>& queue) const;
        void get_peer_info(std::vector<peer_info>& v) const;
        torrent_info const& get_torrent_info() const;
        bool is_valid() const;

        std::string name() const;

        void save_resume_data() const;
        void force_reannounce() const;
        void force_dht_announce() const;
        void force_reannounce(boost::posix_time::time_duration) const;
        void scrape_tracker() const;
        void connect_peer(asio::ip::tcp::endpoint const& adr, int source = 0) const;

        void set_tracker_login(std::string const& username
                , std::string const& password) const;

        std::vector<announce_entry> trackers() const;
        void replace_trackers(std::vector<announce_entry> const&);
        void add_tracker(announce_entry const& url);

        void add_url_seed(std::string const& url);
        void remove_url_seed(std::string const& url);
        std::set<std::string> url_seeds() const;

        void add_http_seed(std::string const& url);
        void remove_http_seed(std::string const& url);
        std::set<std::string> http_seeds() const;

        void set_ratio(float ratio) const;
        int max_uploads() const;
        void set_max_uploads(int max_uploads) const;
        void set_max_connections(int max_connections) const;
        int max_connections() const;
        void set_upload_limit(int limit) const;
        int upload_limit() const;
        void set_download_limit(int limit) const;
        int download_limit() const;
        void set_sequential_download(bool sd) const;
        bool is_sequential_download() const;

        void set_peer_upload_limit(asio::ip::tcp::endpoint ip, int limit) const;
        void set_peer_download_limit(asio::ip::tcp::endpoint ip, int limit) const;

        int queue_position() const;
        void queue_position_up() const;
        void queue_position_down() const;
        void queue_position_top() const;
        void queue_position_bottom() const;

        void set_priority(int prio) const;

        void use_interface(char const* net_interface) const;

        void pause() const;
        void resume() const;
        bool is_paused() const;
        bool is_seed() const;
        void force_recheck() const;
        void clear_error() const;
        void set_upload_mode(bool m) const;

        void flush_cache() const;

        void resolve_countries(bool r);
        bool resolve_countries() const;

        enum deadline_flags { alert_when_available = 1 };
        void set_piece_deadline(int index, int deadline, int flags = 0) const;

        void piece_availability(std::vector<int>& avail) const;
        void piece_priority(int index, int priority) const;
        int piece_priority(int index) const;
        void prioritize_pieces(std::vector<int> const& pieces) const;
        std::vector<int> piece_priorities() const;

        void file_priority(int index, int priority) const;
        int file_priority(int index) const;
        void prioritize_files(std::vector<int> const& files) const;
        std::vector<int> file_priorities() const;

        bool is_auto_managed() const;
        void auto_managed(bool m) const;

        bool has_metadata() const;
        bool set_metadata(char const* buf, int size) const;

        boost::filesystem::path save_path() const;
        void move_storage(boost::filesystem::path const& save_path) const;
        void move_storage(boost::filesystem::wpath const& save_path) const;
        void rename_file(int index, boost::filesystem::path) const;
        void rename_file(int index, boost::filesystem::wpath) const;
        storage_interface* get_storage_impl() const;

        bool super_seeding() const;
        void super_seeding(bool on) const;

        enum flags_t { overwrite_existing = 1 };
        void add_piece(int piece, char const* data, int flags = 0) const;
        void read_piece(int piece) const;

        bool operator==(torrent_handle const&) const;
        bool operator!=(torrent_handle const&) const;
        bool operator<(torrent_handle const&) const;
};
  */
