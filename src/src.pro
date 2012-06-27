# Basic consumer variables
include(../vars.pri)

# Requires only core
QT = core

# Build a lib
TEMPLATE = lib
DEFINES += LIBROXEETORRENT_LIBRARY

# Basic stuff (version and build/path magic)
include(../conf/confbase.pri)

# Third-party stuff
include(../third-party/bootstrap.pri)

# Windows specific configuration
win32{
    message( -> Targetting windows)
    include(../conf/confwin.pri)
}

# Mac specific configuration
mac{
    message( -> Targetting osx)
    include(../conf/confmacx.pri)
}

# Unix specific configuration
unix:!mac {
    message( -> Targetting *nux)
    include(../conf/confunix.pri)
}

INCLUDEPATH += $$PWD
INCLUDEPATH += $$PWD/include/libroxeetorrent
target.path = $$DESTDIR
INSTALLS += target


##### libtorrent general configuration

# Fixes things with Boost >= v1.46 where boost filesystem v3 is the default.
# Using v3 makes for crash on OSX at least
DEFINES += BOOST_FILESYSTEM_VERSION=2
# Use libtorrent inner crypto
DEFINES += TORRENT_USE_TOMMATH
# Unicode, iconv yes
DEFINES += UNICODE _UNICODE TORRENT_USE_ICONV=1
# No deprecated functions
DEFINES += TORRENT_NO_DEPRECATE

DEFINES += TORRENT_USE_BOOST_DATE_TIME=1
DEFINES += TORRENT_USE_IPV6=1
# No asserts
DEFINES += TORRENT_NO_ASSERTS=1

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
}else{
    DEFINES += BOOST_ASIO_DYN_LINK
}

mac|win32{
    LIBS += -ltorrent
    contains(ROXEE_DEPEND_LINK, static){
        LIBS += -liconv
    }
}else{
    LIBS += -ltorrent-rasterbar
}

LIBS += -lboost_system


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
    session.cpp \
    alert.cpp \
    torrenthandle.cpp \
    alerttypes.cpp \
    coreinstance.cpp \
    root.cpp

HEADERS += \
    alert.h \
    torrenthandle.h \
    coreinstance.h \
    include/libroxeetorrent/libroxeetorrent_global.h \
    include/libroxeetorrent/session.h \
    include/libroxeetorrent/alerttypes.h \
    include/libroxeetorrent/root.h



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
