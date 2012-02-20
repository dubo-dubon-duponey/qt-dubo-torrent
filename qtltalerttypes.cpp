/**
 * @alpha1
 */

#include "qtltalerttypes.h"

#include <libtorrent/alert_types.hpp>

QtltAlertTypes* QtltAlertTypes::m_Instance = 0;

const int QtltAlertTypes::none()            { return 0;}
const int QtltAlertTypes::error()           { return libtorrent::alert::error_notification;}
const int QtltAlertTypes::peer()            { return libtorrent::alert::peer_notification;}
const int QtltAlertTypes::port_mapping()    { return libtorrent::alert::port_mapping_notification;}
const int QtltAlertTypes::storage()         { return libtorrent::alert::storage_notification;}
const int QtltAlertTypes::tracker()         { return libtorrent::alert::tracker_notification;}
const int QtltAlertTypes::debug()           { return libtorrent::alert::debug_notification;}
const int QtltAlertTypes::status()          { return libtorrent::alert::status_notification;}
const int QtltAlertTypes::progress()        { return libtorrent::alert::progress_notification;}
const int QtltAlertTypes::ip_block()        { return libtorrent::alert::ip_block_notification;}
const int QtltAlertTypes::performance()     { return libtorrent::alert::performance_warning;}
const int QtltAlertTypes::dht()             { return libtorrent::alert::dht_notification;}
const int QtltAlertTypes::stats()           { return libtorrent::alert::stats_notification;}
const int QtltAlertTypes::all()             { return libtorrent::alert::all_categories;}
