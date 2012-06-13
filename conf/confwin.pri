#Debug
#CONFIG(debug, debug|release): CONFIG += console

# Target windows XP minimum
DEFINES += _WIN32_WINNT=0x0501





INCLUDEPATH += ../../libtorrent-rasterbar-0.16.0/include
INCLUDEPATH += ../../boost_1_49_0
LIBS += -L../../boost_1_49_0/stage/lib

CONFIG(debug, debug|release){
    BTLT=-gd
}else{
    BTLT=
}

win32-g++ {
    include(confwin-mingw.pri)
    COMPER=mingw46
    COMPIE=gcc-mingw-4.6.2
    ICONT=iconv-on/
    DEFINES += TORRENT_USE_ICONV=1

#    LIBS += -llibboost_system-vc100-mt-gd-1_49
#    LIBS += -llibboost_filesystem-vc100-mt-gd-1_49
#    LIBS += -llibboost_thread-vc100-mt-gd-1_49

}

win32-msvc{
    include(confwin-msvc.pri)
    COMPER=vc100
    ICONT=
    COMPIE=msvc-10.0
}

#LIBS += -llibboost_date_time-$${COMPER}-mt$${BTLT}-1_49
LIBS += -llibboost_system-$${COMPER}-mt$${BTLT}-1_49
LIBS += -L../../libtorrent-rasterbar-0.16.0/bin/$${COMPIE}/$${BT}/asserts-off/boost-source/geoip-static/$${ICONT}link-static/threading-multi

CONFIG += dll

#    "g++"  -ftemplate-depth-128 -O0 -fno-inline -Wall -g -mthreads -Wno-missing-
#braces -fno-strict-aliasing -ftrapv -DBOOST_ALL_NO_LIB -DBOOST_ASIO_ENABLE_CANCE
#LIO -DBOOST_ASIO_HASH_MAP_BUCKETS=1021 -DBOOST_ASIO_SEPARATE_COMPILATION -DBOOST
#_EXCEPTION_DISABLE -DBOOST_FILESYSTEM_VERSION=2 -DBOOST_SYSTEM_STATIC_LINK=1 -DB
#OOST_THREAD_USE_LIB -DTORRENT_DEBUG -DTORRENT_NO_ASSERTS=1 -DTORRENT_USE_ICONV=1
# -DTORRENT_USE_TOMMATH -DUNICODE -DWIN32 -DWIN32_LEAN_AND_MEAN -D_FILE_OFFSET_BI
#TS=64 -D_UNICODE -D_WIN32 -D_WIN32_WINNT=0x0500 -D__USE_W32_SOCKETS  -I"C:\roxee
#love\trees\boost_1_49_0" -I"\usr\sfw\include" -I"C:\roxeelove\trees\boost_1_49_0
#" -I"include" -I"include\libtorrent" -c -o "bin\gcc-mingw-4.6.2\debug\asserts-of
#f\boost-source\geoip-static\iconv-on\link-static\threading-multi\src\assert.o" "
#src\assert.cpp"







#DEFINES += UNICODE
#DEFINES += _UNICODE
#DEFINES += BOOST_ALL_NO_LIB
#DEFINES += BOOST_ASIO_SEPARATE_COMPILATION
#DEFINES += BOOST_SYSTEM_STATIC_LINK=1
#DEFINES += TORRENT_NO_ASSERTS=1
#DEFINES += BOOST_THREAD_USE_LIB
#DEFINES += _WIN32_WINNT=0x0500

DEFINES += BOOST_ASIO_ENABLE_CANCELIO
DEFINES += BOOST_ASIO_HASH_MAP_BUCKETS=1021
DEFINES += BOOST_EXCEPTION_DISABLE

# Windows stuff
DEFINES += WIN32
DEFINES += WIN32_LEAN_AND_MEAN
DEFINES += _FILE_OFFSET_BITS=64
DEFINES += _WIN32
DEFINES += __USE_W32_SOCKETS
DEFINES += _CRT_SECURE_NO_DEPRECATE
DEFINES += _CRT_SECURE_CPP_OVERLOAD_SECURE_NAMES
DEFINES += _CRT_NONSTDC_NO_DEPRECATE









#QMAKE_CFLAGS_RELEASE += -Zi
#QMAKE_LFLAGS_RELEASE += /DEBUG



#DEFINES += BOOST_THREAD_USE_LIB=1
#DEFINES += _CRT_SECURE_NO_DEPRECATE
#DEFINES += _SCL_SECURE_NO_DEPRECATE
#DEFINES += _WIN32_IE=0x0500


#staticlib

#DEFINES += TORRENT_USE_WPATH




#INCLUDEPATH += C:/roxeelove/src/buildopenssl/include

#LIBS += -LC:/roxeelove/src/boost_1_49_0/stage/lib
#LIBS += -LC:/roxeelove/src/buildopenssl/lib



#C:\roxeelove\src\libtorrent-rasterbar-0.15.10\bin\msvc-10.0\release\boost-source\geoip-static\link-static\threading-multi

#    LIBS += -L"../libtorrent-rasterbar-0.15.10/bin/msvc-10.0/debug/boost-source/geoip-static/link-static/openssl-off/threading-multi"
#    LIBS += -L"C:/roxeelove/src/libtorrent-rasterbar-0.15.10/bin/msvc-10.0/debug/boost-source/geoip-static/link-static/openssl-off/threading-multi"
#    LIBS += -llibboost_system-vc100-mt-1_49 -llibboost_filesystem-vc100-mt-1_49 -llibboost_thread-vc100-mt-1_49 -llibtorrent
# -lcrypto



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


