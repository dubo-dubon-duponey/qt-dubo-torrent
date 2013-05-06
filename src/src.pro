TEMPLATE = lib
QT = core

include($$PWD/../conf/conf.pri)

DEFINES += LIBROXEETORRENT_LIBRARY

contains(ROXEE_LINK_TYPE, static){
    DEFINES += LIBROXEETORRENT_USE_STATIC
}

INCLUDEPATH += $$PWD
INCLUDEPATH += $$PWD/include
target.path = $$DESTDIR
INSTALLS += target



defineTest(copyToDestdir) {
    files = $$1
    dest = $$2

    for(FILE, files) {
        DDIR = $$dest

        # Replace slashes in paths with backslashes for Windows
        win32:FILE ~= s,/,\\,g
        win32:DDIR ~= s,/,\\,g

        win32{
            system(mkdir $$quote($$DDIR))
        }else{
            system(mkdir -p $$quote($$DDIR))
        }
        message(********************************************)
        message($$QMAKE_COPY $$quote($$FILE) $$quote($$DDIR) $$escape_expand(\\n\\t))
        message(********************************************)

        QMAKE_POST_LINK += $$QMAKE_COPY $$quote($$FILE) $$quote($$DDIR) $$escape_expand(\\n\\t)
    }

    export(QMAKE_POST_LINK)
}

copyToDestdir($$PWD/include/libroxeetorrent/*, $$DESTDIR/../include/libroxeetorrent)
copyToDestdir($$PWD/../res/redist/*, $$DESTDIR/../share/libroxeetorrent)

# XXX careful with that - if both directories are the same
#win32{
#    contains(ROXEE_LINK_TYPE, dynamic){
#        copyToDestdir($$SPARK/WinSparkle.dll, $$DESTDIR)
##        copyToDestdir($$ROXEE_EXTERNAL/lib/libvlccore.dll, $$DESTDIR)
#    #    copyToDestdir($$ROXEE_EXTERNAL/lib/plugins/*, $$DESTDIR/plugins)
#    }
#}


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
