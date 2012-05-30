# This is a library (to be ovveridden by eg MSVC specific config)
TEMPLATE = lib

# Requires only core
QT = core

# Name of the target file (lowercase shit to avoid problems)
TARGET = qt-libtorrent

include(../vars.pri)

include(../conf/confversion.pri)

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


DEFINES += QTLIBTORRENT_LIBRARY

INCLUDEPATH += $$PWD

# Share object files for faster compiling
RCC_DIR     = $$PWD/../buildd/temp/rcc
UI_DIR      = $$PWD/../buildd/temp/ui
MOC_DIR     = $$PWD/../buildd/temp/moc
OBJECTS_DIR = $$PWD/../buildd/temp/obj


#CONFIG += debug_and_release build_all

CONFIG(debug, debug|release):   DESTDIR = $$PWD/../buildd/$$PROJECT_NAME-$$PROJECT_VERSION-debug/$$GITVERSION-$$GITCHANGENUMBER
CONFIG(release, debug|release): DESTDIR = $$PWD/../buildd/$$PROJECT_NAME-$$PROJECT_VERSION-release/$$GITVERSION-$$GITCHANGENUMBER

target.path = $$DESTDIR
INSTALLS += target

#win32|mac:!wince*:!win32-msvc:!macx-xcode:CONFIG += debug_and_release build_all
#win32 {
#    DLLDESTDIR = $$[QT_INSTALL_BINS]
#    QMAKE_DISTCLEAN += $$[QT_INSTALL_BINS]\\$${QTSINGLEAPPLICATION_LIBNAME}.dll
#}

DEFINES += BOOST_ASIO_ENABLE_CANCELIO

DEFINES += TORRENT_DISABLE_GEO_IP
#DEFINES += WITH_SHIPPED_GEOPIP_H

macx{
    CONFIG += absolute_library_soname
    INCLUDEPATH +=  /Users/dmp/buildd/deploy.webitup.org/client/Darwin/include
    LIBS += -L/Users/dmp/buildd/deploy.webitup.org/client/Darwin/lib
    LIBS += -ltorrent-rasterbar -lcrypto -lboost_system-mt-roxee -lboost_filesystem-mt-roxee -lboost_thread-mt-roxee

    DEFINES += BOOST_ASIO_DYN_LINK
# Fixes compilation with Boost >= v1.46 where boost
# filesystem v3 is the default.
    DEFINES += BOOST_FILESYSTEM_VERSION=2
}

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
