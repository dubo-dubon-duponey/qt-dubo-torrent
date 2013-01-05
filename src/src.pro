TEMPLATE = lib
QT = core

include($$PWD/../conf/conf.pri)
#include($$PWD/../conf/confbase.pri)

## Windows specific configuration
#win32{
#    message( -> Targetting windows)
#    include($$PWD/../conf/confwin.pri)
#}

## Mac specific configuration
#mac{
#    message( -> Targetting osx)
#    include($$PWD/../conf/confmacx.pri)
#}

## Unix specific configuration
#unix:!mac {
#    message( -> Targetting *nux)
#    include($$PWD/../conf/confunix.pri)
#}

DEFINES += LIBROXEETORRENT_LIBRARY

contains(ROXEE_LINK_TYPE, static){
    DEFINES += LIBROXEETORRENT_USE_STATIC
}

INCLUDEPATH += $$PWD
INCLUDEPATH += $$PWD/include
target.path = $$DESTDIR
INSTALLS += target

# Copy headers to destination
system(rm -Rf "$$DESTDIR/../include")
system(mkdir -p "$$DESTDIR/../")
system(cp -R "$$PWD/include" "$$DESTDIR/../")
message(cp -R "$$PWD/include" "$$DESTDIR/../")
system(rm -Rf "$$DESTDIR/../share")
system(mkdir -p "$$DESTDIR/../share/libroxeetorrent")
system(cp "$$PWD/../res/redist/*" "$$DESTDIR/../share/libroxeetorrent")


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
