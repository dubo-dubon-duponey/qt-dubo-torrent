#Debug
CONFIG(debug, debug|release): CONFIG += console

win32-g++ {
  include(confwin-mingw.pri)
}
else {
  include(confwin-msvc.pri)
}

CONFIG += dll
#staticlib

DEFINES += TORRENT_USE_WPATH

DEFINES += BOOST_ASIO_SEPARATE_COMPILATION

# Allow old windows versions to behave
DEFINES += BOOST_ASIO_ENABLE_CANCELIO

INCLUDEPATH += C:/roxeelove/src/libtorrent-rasterbar-0.16.0/include
INCLUDEPATH += C:/roxeelove/src/boost_1_49_0
#INCLUDEPATH += C:/roxeelove/src/buildopenssl/include

#LIBS += -LC:/roxeelove/src/boost_1_49_0/stage/lib
LIBS += -LC:/roxeelove/src/libtorrent-rasterbar-0.16.0/bin/msvc-10.0/$${BT}/boost-source/geoip-static/link-static/threading-multi
#LIBS += -LC:/roxeelove/src/buildopenssl/lib



#C:\roxeelove\src\libtorrent-rasterbar-0.15.10\bin\msvc-10.0\release\boost-source\geoip-static\link-static\threading-multi

#    LIBS += -L"../libtorrent-rasterbar-0.15.10/bin/msvc-10.0/debug/boost-source/geoip-static/link-static/openssl-off/threading-multi"
#    LIBS += -L"C:/roxeelove/src/libtorrent-rasterbar-0.15.10/bin/msvc-10.0/debug/boost-source/geoip-static/link-static/openssl-off/threading-multi"
#    LIBS += -llibboost_system-vc100-mt-1_49 -llibboost_filesystem-vc100-mt-1_49 -llibboost_thread-vc100-mt-1_49 -llibtorrent
# -lcrypto

LIBS += -llibtorrent

LIBS += -L../../../src/boost_1_49_0/stage/lib

contains(BT, debug){
    DEFINES += TORRENT_DEBUG
    LIBS += -llibboost_date_time-vc100-mt-gd-1_49
}else{
    LIBS += -llibboost_date_time-vc100-mt-1_49
}


#LIBS += libeay32.lib ssleay32.lib

#contains(BT, debug){
#    LIBS += -llibboost_system-vc100-mt-gd-1_49
#    LIBS += -llibboost_filesystem-vc100-mt-gd-1_49
#    LIBS += -llibboost_thread-vc100-mt-gd-1_49
#}

#contains(BT, release){
#    LIBS += -llibboost_system-vc100-mt-1_49
#    LIBS += -llibboost_filesystem-vc100-mt-1_49
#    LIBS += -llibboost_thread-vc100-mt-1_49
#}


#DEFINES += BOOST_ALL_NO_LIB
DEFINES += BOOST_ASIO_HASH_MAP_BUCKETS=1021
DEFINES += BOOST_EXCEPTION_DISABLE
DEFINES += BOOST_SYSTEM_STATIC_LINK=1
#DEFINES += BOOST_THREAD_USE_LIB
DEFINES += BOOST_THREAD_USE_LIB=1

DEFINES += UNICODE
DEFINES += WIN32
DEFINES += WIN32_LEAN_AND_MEAN
DEFINES += _CRT_SECURE_NO_DEPRECATE
DEFINES += _FILE_OFFSET_BITS=64
DEFINES += _SCL_SECURE_NO_DEPRECATE
DEFINES += _UNICODE
DEFINES += _WIN32
DEFINES += _WIN32_WINNT=0x0500
DEFINES += _WIN32_IE=0x0500
DEFINES += __USE_W32_SOCKETS
