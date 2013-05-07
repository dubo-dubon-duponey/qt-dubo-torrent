TEMPLATE = lib
QT = core

include($$PWD/../config/common.pri)

DEFINES += LIBROXEETORRENT_LIBRARY

contains(ROXEE_LINK_TYPE, static){
    DEFINES += LIBROXEETORRENT_USE_STATIC
}

INCLUDEPATH += $$PWD
INCLUDEPATH += $$PWD/include
target.path = $$DESTDIR
INSTALLS += target


copyToDestdir($$PWD/include/libroxeetorrent/*, $$DESTDIR/../include/libroxeetorrent)
copyToDestdir($$PWD/../res/redist/*, $$DESTDIR/../share/libroxeetorrent)


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


# Windows only?
DEFINES += UNICODE _UNICODE

CONFIG(debug, debug|release){
    DEFINES += TORRENT_DEBUG
}

contains(ROXEE_LINK_TYPE, static){
    DEFINES += BOOST_ASIO_SEPARATE_COMPILATION
}else{
    DEFINES += BOOST_ASIO_DYN_LINK
}

DEFINES += TORRENT_USE_BOOST_DATE_TIME=1
DEFINES += TORRENT_USE_TOMMATH

# Working: msvc static debug
# Working: msvc static release
win32{
    # XXX is this necessary?
    DEFINES += _CRT_SECURE_NO_DEPRECATE
    DEFINES += _CRT_SECURE_CPP_OVERLOAD_SECURE_NAMES
    DEFINES += _CRT_NONSTDC_NO_DEPRECATE

    DEFINES += BOOST_ASIO_ENABLE_CANCELIO
    DEFINES += BOOST_ASIO_HASH_MAP_BUCKETS=1021
    DEFINES += BOOST_EXCEPTION_DISABLE

#    DEFINES += BOOST_ALL_NO_LIB
}


#DEFINES += BOOST_ASIO_HEADER_ONLY

# Use libtorrent inner crypto
#DEFINES += TORRENT_NO_DEPRECATE
#DEFINES += TORRENT_USE_IPV6=1
#DEFINES += TORRENT_USE_ICONV=1

## No asserts
#DEFINES += TORRENT_NO_ASSERTS=1


## Fixes things with Boost >= v1.46 where boost filesystem v3 is the default.
## Using v3 makes for crash on OSX at least
#DEFINES += BOOST_FILESYSTEM_VERSION=2


#mac|win32{
#    DEFINES += WITH_SHIPPED_GEOIP_H
#}



#    # Maybe only msvc???
#    #DEFINES += __USE_W32_SOCKETS

#    DEFINES += BOOST_ALL_DYN_LINK
#    DEFINES += BOOST_SYSTEM_STATIC_LINK=1

#    # XXX was compiling with WRONG ROXEE_DEPEND_LINK
#    !contains(ROXEE_LINK_TYPE, static){
#        DEFINES += TORRENT_LINKING_SHARED
#    }

#}else{

#    ##### libtorrent general configuration
#    # Unicode, iconv yes

#    # Use libtorrent bundled geoip source on platforms where it's possible (eg: we control compiling libtorrent)

#    # ASIO
#    DEFINES += BOOST_ASIO_HEADER_ONLY

#}

#    # Mac specific configuration
#    mac{
# Linking dynamically on OSX
#DEFINES += BOOST_ASIO_DYN_LINK

# -lboost_system-mt-roxee
# -lcrypto  -lboost_filesystem-mt-roxee -lboost_thread-mt-roxee
#    }


















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
