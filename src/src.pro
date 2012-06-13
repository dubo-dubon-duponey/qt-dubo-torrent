# Basic consumer variables
include(../vars.pri)

# This is a library (to be ovveridden by eg MSVC specific config)
TEMPLATE = lib

# Requires only core
QT = core

# And be boring
CONFIG +=   QT_NO_CAST_FROM_ASCII \
            QT_NO_CAST_TO_ASCII \
            QT_STRICT_ITERATORS \
            QT_USE_FAST_CONCATENATION QT_USE_FAST_OPERATOR_PLUS

# Yes, this will build a lib
DEFINES += LIBROXEETORRENT_LIBRARY

# Basic stuff (version and build/path magic)
include(../conf/confbase.pri)

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
    message( -> Targetting linux)
    include(../conf/confunix.pri)
}

INCLUDEPATH += $$PWD
target.path = $$DESTDIR
INSTALLS += target

LIBS += -ltorrent -lboost_system-mt

CONFIG += absolute_library_soname

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
# Use libtorrent bundled geoip source
DEFINES += WITH_SHIPPED_GEOIP_H

# Torrent linking to boost depend as well
contains(ROXEE_LINK_TYPE, static){
    DEFINES += BOOST_ALL_NO_LIB
    DEFINES += BOOST_ASIO_SEPARATE_COMPILATION
}else{
    DEFINES += BOOST_ALL_DYN_LINK
    DEFINES += BOOST_ASIO_DYN_LINK
}

# And debug vary as well
#BOOSTIE =
CONFIG(debug, debug|release){
    DEFINES += TORRENT_DEBUG
#    BOOSTIE = -d
}

SOURCES += \
    session.cpp \
    alert.cpp \
    torrenthandle.cpp \
    alerttypes.cpp \
    coreinstance.cpp \
    root.cpp

HEADERS += \
    libroxeetorrent_global.h \
    session.h \
    alert.h \
    torrenthandle.h \
    alerttypes.h \
    coreinstance.h \
    root.h



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
