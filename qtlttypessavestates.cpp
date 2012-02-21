#include "qtlttypessavestates.h"
#include <libtorrent/session.hpp>

QtLtSaveStates* QtLtSaveStates::m_Instance = 0;

const int QtLtSaveStates::save_settings()               { return libtorrent::session::save_settings;}
const int QtLtSaveStates::save_dht_settings()           { return libtorrent::session::save_dht_settings;}
const int QtLtSaveStates::save_dht_state()              { return libtorrent::session::save_dht_state;}
const int QtLtSaveStates::save_i2p_proxy()              { return libtorrent::session::save_i2p_proxy;}
const int QtLtSaveStates::save_encryption_settings()    { return libtorrent::session::save_encryption_settings;}
const int QtLtSaveStates::save_as_map()                 { return libtorrent::session::save_as_map;}
const int QtLtSaveStates::save_proxy()                  { return libtorrent::session::save_proxy;}
