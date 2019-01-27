TEMPLATE = app
QT = core widgets webengine webenginewidgets webchannel

QMAKE_TARGET_BUNDLE_PREFIX=com.dubo-dubon-duponey

PROJECT_ROOT = $$PWD/..
include($$PROJECT_ROOT/config/qmakeitup.pri)

INCLUDEPATH += $$PWD

LIBS += -l$${DUBO_LINK_NAME}

contains(DUBO_LINK_TYPE, static){
    DEFINES += LIBDUBOTORRENT_USE_STATIC
}

SOURCES += $$PWD/main.cpp
RESOURCES += $$PWD/demo.qrc

mac{
    # Add plist, and a nice icon
    OTHER_FILES += $$PWD/Info.plist \
        $$PWD/demo.icns

    QMAKE_INFO_PLIST = $${PWD}/Info.plist
    ICON = $${PWD}/demo.icns
}


# Boost still depends on removed features from C++17
DEFINES += _LIBCPP_ENABLE_CXX17_REMOVED_AUTO_PTR



contains(DUBO_LINK_TYPE, static){
    DEFINES += LIBDUBOTORRENT_USE_STATIC
}else{
    win32{
        copyToDestdir($$DUBO_EXTERNAL/libtorrent.dll, $$DESTDIR)
    }
}


QMAKE_CXXFLAGS_WARN_OFF += -Wno-unused-parameter
QMAKE_CXXFLAGS_WARN_ON += -Wno-unused-parameter

DEFINES += UNICODE _UNICODE

CONFIG(debug, debug|release){
    DEFINES += TORRENT_DEBUG
}

contains(DUBO_LINK_TYPE, static){
    DEFINES += BOOST_ASIO_SEPARATE_COMPILATION
}else{
    DEFINES += BOOST_ASIO_DYN_LINK
}


DEFINES += TORRENT_USE_BOOST_DATE_TIME=1
DEFINES += TORRENT_USE_TOMMATH

#    contains(DUBO_LINK_TYPE, static){
#        mac{
#            LIBS += -liconv
#        }
#    }




