#-------------------------------------------------
#
# Project created by QtCreator 2012-02-20T01:56:15
#
#-------------------------------------------------

QT       -= gui

TARGET = qt-libtorrent
TEMPLATE = lib

DEFINES += QTLIBTORRENT_LIBRARY

INCLUDEPATH += $$PWD

mac:CONFIG += absolute_library_soname
win32|mac:!wince*:!win32-msvc:!macx-xcode:CONFIG += debug_and_release build_all
DESTDIR = $$PWD/lib
#win32 {
#    DLLDESTDIR = $$[QT_INSTALL_BINS]
#    QMAKE_DISTCLEAN += $$[QT_INSTALL_BINS]\\$${QTSINGLEAPPLICATION_LIBNAME}.dll
#}
target.path = $$DESTDIR
INSTALLS += target


macx{
    INCLUDEPATH +=  /Users/dmp/buildd/deploy.webitup.org/client/Darwin/include
    LIBS += -L/Users/dmp/buildd/deploy.webitup.org/client/Darwin/lib
    LIBS += -ltorrent-rasterbar -lcrypto -lboost_system-mt -lboost_filesystem-mt -lboost_thread-mt
}

# Fixes compilation with Boost >= v1.46 where boost
# filesystem v3 is the default.
DEFINES += BOOST_FILESYSTEM_VERSION=2
DEFINES += BOOST_ASIO_ENABLE_CANCELIO
DEFINES += WITH_SHIPPED_GEOPIP_H

SOURCES += qtlibtorrent.cpp \
    qtltalert.cpp \
    qtltsession.cpp \
    dirtyhack.cpp \
    qtlttorrenthandle.cpp \
    qtltfileentry.cpp \
    qtlttorrentstatus.cpp \
    qtlttypessavestates.cpp \
    qtlttypesalerttypes.cpp \
    qtlttypestorrentstates.cpp \
    qtltsessionstatus.cpp
#    qtlttorrentinfo.cpp \

HEADERS += qtlibtorrent.h \
        qt-libtorrent_global.h \
    qtltalert.h \
    qtltsession.h \
    dirtyhack.h \
    qtlttorrenthandle.h \
    qtltfileentry.h \
    qtlttorrentstatus.h \
    qtlttypessavestates.h \
    qtlttypesalerttypes.h \
    qtlttypestorrentstates.h \
    qtltsessionstatus.h
#    qtlttorrentinfo.h \
