#include "qtlttypestorrentstates.h"
#include <libtorrent/torrent.hpp>

QtLtTorrentStates* QtLtTorrentStates::m_Instance = 0;

const int QtLtTorrentStates::queued_for_checking()  { return libtorrent::torrent_status::queued_for_checking; }
const int QtLtTorrentStates::checking_files()       { return libtorrent::torrent_status::checking_files; }
const int QtLtTorrentStates::downloading_metadata() { return libtorrent::torrent_status::downloading_metadata; }
const int QtLtTorrentStates::downloading()          { return libtorrent::torrent_status::downloading; }
const int QtLtTorrentStates::finished()             { return libtorrent::torrent_status::finished; }
const int QtLtTorrentStates::seeding()              { return libtorrent::torrent_status::seeding; }
const int QtLtTorrentStates::allocating()           { return libtorrent::torrent_status::allocating; }
const int QtLtTorrentStates::checking_resume_data() { return libtorrent::torrent_status::checking_resume_data; }
