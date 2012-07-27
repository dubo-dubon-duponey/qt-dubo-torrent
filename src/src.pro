TEMPLATE = lib
QT = core

include($$PWD/../vars.pri)
include($$PWD/../conf/confbase.pri)

# Windows specific configuration
win32{
    message( -> Targetting windows)
    include($$PWD/../conf/confwin.pri)
}

# Mac specific configuration
mac{
    message( -> Targetting osx)
    include($$PWD/../conf/confmacx.pri)
}

# Unix specific configuration
unix:!mac {
    message( -> Targetting *nux)
    include($$PWD/../conf/confunix.pri)
}

DEFINES += LIBROXEETORRENT_LIBRARY

contains(ROXEE_LINK_TYPE, static){
    DEFINES += LIBROXEETORRENT_USE_STATIC
}

INCLUDEPATH += $$PWD
INCLUDEPATH += $$PWD/include
target.path = $$DESTDIR
INSTALLS += target


win32{
    DEFINES += BOOST_ALL_DYN_LINK
    DEFINES += BOOST_ALL_NO_LIB
    DEFINES += BOOST_ASIO_DYN_LINK
    DEFINES += BOOST_ASIO_ENABLE_CANCELIO
    DEFINES += BOOST_ASIO_HASH_MAP_BUCKETS=1021
    DEFINES += BOOST_ASIO_SEPARATE_COMPILATION
    DEFINES += BOOST_EXCEPTION_DISABLE
    DEFINES += BOOST_SYSTEM_STATIC_LINK=1
    DEFINES += BOOST_FILESYSTEM_VERSION=2

    DEFINES += __USE_W32_SOCKETS

    # XXX was compiling with WRONG ROXEE_DEPEND_LINK
    !contains(ROXEE_LINK_TYPE, static){
        DEFINES += TORRENT_LINKING_SHARED
    }

    CONFIG(debug, debug|release){
        DEFINES += TORRENT_DEBUG
    }

    DEFINES += TORRENT_USE_TOMMATH
    DEFINES += TORRENT_NO_DEPRECATE
    DEFINES += TORRENT_USE_BOOST_DATE_TIME=1
    DEFINES += TORRENT_USE_IPV6=1
    DEFINES += TORRENT_NO_ASSERTS=1
    DEFINES += UNICODE _UNICODE
    DEFINES += TORRENT_USE_ICONV=1

    LIBS += -lboost_system
    LIBS += -ltorrent

}else{

    # Fixes things with Boost >= v1.46 where boost filesystem v3 is the default.
    # Using v3 makes for crash on OSX at least
    DEFINES += BOOST_FILESYSTEM_VERSION=2
    # Use libtorrent inner crypto
    DEFINES += TORRENT_USE_TOMMATH
    DEFINES += TORRENT_NO_DEPRECATE
    DEFINES += TORRENT_USE_BOOST_DATE_TIME=1
    DEFINES += TORRENT_USE_IPV6=1
    # No asserts
    DEFINES += TORRENT_NO_ASSERTS=1

    ##### libtorrent general configuration
    # Unicode, iconv yes
    # Windows only?
    DEFINES += UNICODE _UNICODE

    CONFIG(debug, debug|release){
        DEFINES += TORRENT_DEBUG
    }

    # Use libtorrent bundled geoip source on platforms where it's possible (eg: we control compiling libtorrent)
    mac|win32: DEFINES += WITH_SHIPPED_GEOIP_H

    # ASIO
    DEFINES += BOOST_ASIO_HEADER_ONLY
    # Kind of borked, but well
    contains(ROXEE_DEPEND_LINK, static){
        DEFINES += BOOST_ASIO_SEPARATE_COMPILATION
        mac{
            LIBS += -liconv
        }
    }else{
        DEFINES += BOOST_ASIO_DYN_LINK
    }

    DEFINES += TORRENT_USE_ICONV=1

    LIBS += -lboost_system

    mac|win32{
        LIBS += -ltorrent
    }else{
        LIBS += -ltorrent-rasterbar
    }

}





#}

#    DEFINES += BOOST_ALL_DYN_LINK


#mac|win32{
## XXX -mt-d!!!
#    CONFIG(debug, debug|release){
#        LIBS += -lboost_system-mt-d
#    }else{
#        LIBS += -lboost_system-mt
#    }
#}

#unix:!mac{
#    DEFINES += BOOST_ASIO_HEADER_ONLY
#    LIBS += -ltorrent-rasterbar -lboost_system-mt
#}


#contains(ROXEE_LINK_TYPE, static){
#    LIBS += -liconv
#}



# And debug vary as well
#BOOSTIE =

SOURCES += \
    $$PWD/session.cpp \
    $$PWD/alert.cpp \
    $$PWD/torrenthandle.cpp \
    $$PWD/alerttypes.cpp \
    $$PWD/coreinstance.cpp \
    $$PWD/root.cpp

HEADERS += \
    $$PWD/alert.h \
    $$PWD/torrenthandle.h \
    $$PWD/coreinstance.h \
    $$PWD/include/libroxeetorrent/libroxeetorrent_global.h \
    $$PWD/include/libroxeetorrent/session.h \
    $$PWD/include/libroxeetorrent/alerttypes.h \
    $$PWD/include/libroxeetorrent/root.h



#DEFINES += TORRENT_DISABLE_GEO_IP

#win32|mac:!wince*:!win32-msvc:!macx-xcode:CONFIG += debug_and_release build_all
#win32 {
#    DLLDESTDIR = $$[QT_INSTALL_BINS]
#    QMAKE_DISTCLEAN += $$[QT_INSTALL_BINS]\\$${QTSINGLEAPPLICATION_LIBNAME}.dll
#}



# qtlibtorrent.cpp \
#    qtltfileentry.cpp \
#    qtlttorrentstatus.cpp \
#    qtlttypessavestates.cpp \
#    qtlttypestorrentstates.cpp \
#    qtltsessionstatus.cpp \
#    qtlttorrentinfo.cpp \

#    qtltfileentry.h \
#    qtlttorrentstatus.h \
#    qtlttypessavestates.h \
#    qtlttypestorrentstates.h \
#    qtltsessionstatus.h \
#    qtlttorrentinfo.h \
