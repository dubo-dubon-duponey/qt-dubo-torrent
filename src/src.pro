# Basic consumer variables
include(../vars.pri)

# This is a library (to be ovveridden by eg MSVC specific config)
TEMPLATE = lib

# Requires only core
QT = core
# And be boring
CONFIG +=   QT_NO_CAST_FROM_ASCII \
            QT_NO_CAST_TO_ASCII \
            QT_STRICT_ITERATORS

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
macx{
    message( -> Targetting osx)
    include(../conf/confmacx.pri)
}

# Unix specific configuration
unix:!macx {
    message( -> Targetting linux)
    include(../conf/confunix.pri)
}

# Other files to include in the distributable
#DISTFILES   += ../res/redist/AUTHORS \
#    ../res/redist/ChangeLog \
#    ../res/redist/LICENSE.BSD2 \
#    ../README

INCLUDEPATH += $$PWD

target.path = $$DESTDIR/lib
INSTALLS += target dist


##### libtorrent general configuration
# Fixes things with Boost >= v1.46 where boost filesystem v3 is the default.
# Using v3 makes for crash on OSX at least
DEFINES += BOOST_FILESYSTEM_VERSION=2


#DEFINES += TORRENT_DISABLE_GEO_IP
#DEFINES += WITH_SHIPPED_GEOPIP_H


#win32|mac:!wince*:!win32-msvc:!macx-xcode:CONFIG += debug_and_release build_all
#win32 {
#    DLLDESTDIR = $$[QT_INSTALL_BINS]
#    QMAKE_DISTCLEAN += $$[QT_INSTALL_BINS]\\$${QTSINGLEAPPLICATION_LIBNAME}.dll
#}

# qtlibtorrent.cpp \
SOURCES += \
    dirtyhack.cpp \
    session.cpp \
    alert.cpp \
    torrenthandle.cpp \
    alerttypes.cpp
#    qtltfileentry.cpp \
#    qtlttorrentstatus.cpp \
#    qtlttypessavestates.cpp \
#    qtlttypestorrentstates.cpp \
#    qtltsessionstatus.cpp \
#    qtlttorrentinfo.cpp \

HEADERS += \
    dirtyhack.h \
    libroxeetorrent.h \
    libroxeetorrent_global.h \
    session.h \
    alert.h \
    torrenthandle.h \
    alerttypes.h
#    qtltfileentry.h \
#    qtlttorrentstatus.h \
#    qtlttypessavestates.h \
#    qtlttypestorrentstates.h \
#    qtltsessionstatus.h \
#    qtlttorrentinfo.h \
