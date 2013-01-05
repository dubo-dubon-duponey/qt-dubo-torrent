contains(TEMPLATE, lib){
    # Use libtorrent inner crypto
    DEFINES += TORRENT_USE_TOMMATH
    DEFINES += TORRENT_NO_DEPRECATE
    DEFINES += TORRENT_USE_BOOST_DATE_TIME=1
    DEFINES += TORRENT_USE_IPV6=1
    DEFINES += TORRENT_USE_ICONV=1
    # No asserts
    DEFINES += TORRENT_NO_ASSERTS=1
    # Windows only?
    DEFINES += UNICODE _UNICODE

    CONFIG(debug, debug|release){
        DEFINES += TORRENT_DEBUG
    }
    # Fixes things with Boost >= v1.46 where boost filesystem v3 is the default.
    # Using v3 makes for crash on OSX at least
    DEFINES += BOOST_FILESYSTEM_VERSION=2

    contains(ROXEE_DEPEND_LINK, static){
        DEFINES += BOOST_ASIO_SEPARATE_COMPILATION
    }else{
        DEFINES += BOOST_ASIO_DYN_LINK
    }

    LIBS += -lboost_system

    win32{
        #CONFIG += staticlib
        # ROXEE_EXTERNAL should point to that ../../vlc-2.0.1/sdk
        #    LIBS += libvlc.dll.a libvlccore.dll.a

        DEFINES += BOOST_ASIO_ENABLE_CANCELIO
        DEFINES += BOOST_ASIO_HASH_MAP_BUCKETS=1021
        DEFINES += BOOST_EXCEPTION_DISABLE

        # Maybe only msvc???
        #DEFINES += __USE_W32_SOCKETS

        DEFINES += BOOST_ALL_DYN_LINK
        DEFINES += BOOST_ALL_NO_LIB
        DEFINES += BOOST_SYSTEM_STATIC_LINK=1

        DEFINES += __USE_W32_SOCKETS

        # XXX was compiling with WRONG ROXEE_DEPEND_LINK
        !contains(ROXEE_LINK_TYPE, static){
            DEFINES += TORRENT_LINKING_SHARED
        }

        LIBS += -ltorrent

        win32-g++ {
        }

        win32-msvc{
        }
    }else{

        ##### libtorrent general configuration
        # Unicode, iconv yes

        # Use libtorrent bundled geoip source on platforms where it's possible (eg: we control compiling libtorrent)
        mac|win32: DEFINES += WITH_SHIPPED_GEOIP_H

        # ASIO
        DEFINES += BOOST_ASIO_HEADER_ONLY

        mac|win32{
            LIBS += -ltorrent
        }else{
            LIBS += -ltorrent-rasterbar
        }
    }

#    # Mac specific configuration
#    mac{
# Linking dynamically on OSX
#DEFINES += BOOST_ASIO_DYN_LINK

# -lboost_system-mt-roxee
# -lcrypto  -lboost_filesystem-mt-roxee -lboost_thread-mt-roxee
#    }

#    # Unix specific configuration
#    unix:!mac {
#        # Only if static
#        #LIBS += -lvlccore
#    }
}


# Kind of borked, but well

contains(TEMPLATE, app){
    contains(ROXEE_LINK_TYPE, static){
        mac{
            LIBS += -liconv
        }
    }
    INCLUDEPATH +=  $$DESTDIR/../include
}
