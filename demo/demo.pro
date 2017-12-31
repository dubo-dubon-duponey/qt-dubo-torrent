TEMPLATE = app
QT = core widgets

PROJECT_ROOT = $$PWD/..
include($$PROJECT_ROOT/config/qmakeitup.pri)

INCLUDEPATH += $$PWD

LIBS += -l$${DUBO_LINK_NAME}

contains(DUBO_LINK_TYPE, static){
    DEFINES += LIBDUBOTORRENT_USE_STATIC
}else{
    win32{
        copyToDestdir($$DUBO_EXTERNAL/libtorrent.dll, $$DESTDIR)
    }
}

SOURCES +=  $$PWD/main.cpp

QMAKE_CXXFLAGS_WARN_OFF += -Wno-unused-parameter
QMAKE_CXXFLAGS_WARN_ON += -Wno-unused-parameter

#    contains(DUBO_LINK_TYPE, static){
#        mac{
#            LIBS += -liconv
#        }
#    }




