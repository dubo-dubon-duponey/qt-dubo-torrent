/**
 * Copyright (c) 2019, Dubo Dubon Duponey <dubodubonduponey+github@pm.me>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
 *
 * Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
 * Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef DUBOTORRENT_TORRENTHANDLE_H
#define DUBOTORRENT_TORRENTHANDLE_H

#include "libdubotorrent/global.h"

#include <QObject>
#include <QVariant>


namespace DuboTorrent
{
    /*!
      \brief A torrent object, as returned by the session object.
    */
    class TorrentHandle : public QObject
    {
        Q_OBJECT
    public:
        /*! \cond */
        explicit TorrentHandle(const QString & info_hash, QObject * parent = nullptr);
        /*! \endcond */

        ~TorrentHandle();

        /*! \brief Reads the torrent infohash. */
        Q_PROPERTY(const QString infoHash READ info_hash)
        /*! \brief Reads the torrent name. */
        Q_PROPERTY(const QString name READ name)
        /*! \brief Tells wether the torrent is valid or not. */
        Q_PROPERTY(bool isValid READ is_valid)
        /*! \brief Tells wether the torrent is downloading sequentially. */
        Q_PROPERTY(bool isSequential READ is_sequential_download)

        /*! \brief Allows to make the torrent download (un)sequentially. */
        Q_INVOKABLE void setSequential(bool flag);

    //    Q_INVOKABLE QVariant getInfo();



        /*! \brief Reads the number of files in the torrent. */
        Q_PROPERTY(const int numFiles READ num_files)
        /*! \brief Reads wether the torrent is private or not. */
        Q_PROPERTY(const int priv READ priv)

        /*! \brief Reads the total size of the torrent. */
        Q_PROPERTY(const qint64 totalSize READ total_size)
        /*! \brief Reads the torrent piece length. */
        Q_PROPERTY(const qint64 pieceLength READ piece_length)
        /*! \brief Reads the torrent number of pieces. */
        Q_PROPERTY(const qint64 numPieces READ num_pieces)

        /*! \brief Reads the torrent allTimeDownload. */
        Q_PROPERTY(const qint64 allTimeDownload READ all_time_download)


    //    Q_PROPERTY(const QString infoHash READ info_hash)

    //    Q_PROPERTY(const QString name READ name)
        /*! \brief Reads the torrent comment. */
        Q_PROPERTY(const QString comment READ comment)
        /*! \brief Reads the torrent creator. */
        Q_PROPERTY(const QString creator READ creator)

    //    Q_PROPERTY(const qint64 creationDate READ creation_date)
        /*! \brief Reads the torrent metadata. */
        Q_PROPERTY(const QString metadata READ metadata)

        /*! \brief Gets the file path of file at position pos in the list of files. */
        Q_INVOKABLE QString filePathAt(const int pos);
        /*! \brief Reads the file size of file at position pos in the list of files. */
        Q_INVOKABLE qint64 fileSizeAt(const int pos);
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

        //    Q_INVOKABLE const QtLtFileEntry * getFileAt(const int & pos);

        /*! \cond */
        const QString info_hash();
        const QString name();
        bool is_sequential_download();
        bool is_valid();

        int num_files();
        bool priv();
        qint64 total_size();
        qint64 all_time_download();
        int piece_length();
        int num_pieces();
    //    const QString info_hash();

    //    const QString name();
        const QString comment();
        const QString creator();

    //    const qint64 creation_date();
        const QString metadata();
        /*! \endcond */

    signals:

    public slots:


    private:
        QString m_hash;
    };
}

#endif // DUBOTORRENT_TORRENTHANDLE_H


/*
        std::string name() const;
        sha1_hash info_hash() const;
        bool is_sequential_download() const;
        void set_sequential_download(bool sd) const;
        torrent_info const& get_torrent_info() const;
        bool is_valid() const;

        void file_progress(std::vector<size_type>& fp, int flags = 0);


        torrent_status status();
        void get_download_queue(std::vector<partial_piece_info>& queue) const;
        void get_peer_info(std::vector<peer_info>& v) const;

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
}
  */
