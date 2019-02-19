TEMPLATE = lib
QT = core

PROJECT_ROOT = $$PWD/..
include($$PROJECT_ROOT/config/qmakeitup.pri)

INCLUDEPATH += $$PWD

HEADERS += \
    $$PWD/alert.h \
    $$PWD/torrenthandle.h \
    $$PWD/coreinstance.h \
    $$PWD/lib$${TARGET}/global.h \
    $$PWD/lib$${TARGET}/session.h \
    $$PWD/lib$${TARGET}/alerttypes.h \
    $$PWD/lib$${TARGET}/root.h

SOURCES += \
    $$PWD/session.cpp \
    $$PWD/alert.cpp \
    $$PWD/torrenthandle.cpp \
    $$PWD/alerttypes.cpp \
    $$PWD/coreinstance.cpp \
    $$PWD/root.cpp

# XXX do this ASAP
# DEFINES += TORRENT_NO_DEPRECATE

# Boost still depends on removed features from C++17, and so does libtorrent (eg: BOOST_NO_AUTO_PTR will break)
DEFINES += _LIBCPP_ENABLE_CXX17_REMOVED_AUTO_PTR




# Working: msvc static debug
# Working: msvc static release
win32{
    DEFINES += UNICODE _UNICODE

    # XXX is this necessary?
#    DEFINES += _CRT_SECURE_NO_DEPRECATE
#    DEFINES += _CRT_SECURE_CPP_OVERLOAD_SECURE_NAMES
#    DEFINES += _CRT_NONSTDC_NO_DEPRECATE

    DEFINES += BOOST_ASIO_ENABLE_CANCELIO
    DEFINES += BOOST_ASIO_HASH_MAP_BUCKETS=1021
    DEFINES += BOOST_EXCEPTION_DISABLE

#    DEFINES += BOOST_ALL_NO_LIB
}


#win32|mac:!wince*:!win32-msvc:!macx-xcode:CONFIG += debug_and_release build_all
#win32 {
#    DLLDESTDIR = $$[QT_INSTALL_BINS]
#    QMAKE_DISTCLEAN += $$[QT_INSTALL_BINS]\\$${QTSINGLEAPPLICATION_LIBNAME}.dll
#}

