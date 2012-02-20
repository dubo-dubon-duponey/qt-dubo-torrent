#ifndef QTLTTORRENTINFO_H
#define QTLTTORRENTINFO_H

#include "qt-libtorrent_global.h"

#include <QObject>
#include <QVariant>
#include <QVariantList>

class QTLIBTORRENTSHARED_EXPORT qtlttorrentinfo : public QObject
{
    Q_OBJECT
public:
    explicit qtlttorrentinfo(QObject *parent = 0);


//    void add_tracker(QString const& url, int tier = 0);
//    void add_tracker(std::string const& url, int tier = 0);

//    QVariantList<QVariant> const& trackers() const;
//    std::vector<announce_entry> const& trackers() const;

signals:

public slots:

};

/*
struct announce_entry
{
        announce_entry(std::string const& url);
        std::string url;

        int next_announce_in() const;
        int min_announce_in() const;

        boost::uint8_t tier;
        boost::uint8_t fail_limit;
        boost::uint8_t fails;

        enum tracker_source
        {
                source_torrent = 1,
                source_client = 2,
                source_magnet_link = 4,
                source_tex = 8
        };
        boost::uint8_t source;

        bool verified:1;
        bool updating:1;
        bool start_sent:1;
        bool complete_sent:1;
};
*/

#endif // QTLTTORRENTINFO_H

/*
class torrent_info
{
public:

        // these constructors throws exceptions on error
        torrent_info(sha1_hash const& info_hash);
        torrent_info(lazy_entry const& torrent_file);
        torrent_info(char const* buffer, int size);
        torrent_info(boost::filesystem::path const& filename);
        torrent_info(boost::filesystem::wpath const& filename);

        // these constructors sets the error code on error
        torrent_info(sha1_hash const& info_hash, error_code& ec);
        torrent_info(lazy_entry const& torrent_file, error_code& ec);
        torrent_info(char const* buffer, int size, error_code& ec);
        torrent_info(fs::path const& filename, error_code& ec);
        torrent_info(fs::wpath const& filename, error_code& ec);


        file_storage const& files() const;
        file_storage const& orig_files() const;

        void remap_files(file_storage const& f);

        void rename_file(int index, std::string const& new_filename);
        void rename_file(int index, std::wstring const& new_filename);

        typedef file_storage::iterator file_iterator;
        typedef file_storage::reverse_iterator reverse_file_iterator;

        file_iterator begin_files() const;
        file_iterator end_files() const;
        reverse_file_iterator rbegin_files() const;
        reverse_file_iterator rend_files() const;

        int num_files() const;
        file_entry const& file_at(int index) const;

        std::vector<file_slice> map_block(int piece, size_type offset
                , int size) const;
        peer_request map_file(int file_index, size_type file_offset
                , int size) const;

        bool priv() const;

        std::vector<std::string> const& url_seeds() const;
        void add_url_seed(std::string const& url);
        std::vector<std::string> const& http_seeds() const;
        void add_http_seed(std::string const& url);

        size_type total_size() const;
        int piece_length() const;
        int num_pieces() const;
        sha1_hash const& info_hash() const;
        std::string const& name() const;
        std::string const& comment() const;
        std::string const& creator() const;

        std::vector<std::pair<std::string, int> > const& nodes() const;
        void add_node(std::pair<std::string, int> const& node);

        boost::optional<boost::posix_time::ptime>
        creation_date() const;

        int piece_size(unsigned int index) const;
        sha1_hash const& hash_for_piece(unsigned int index) const;
        char const* hash_for_piece_ptr(unsigned int index) const;

        boost::shared_array<char> metadata() const;
        int metadata_size() const;
};
  */
