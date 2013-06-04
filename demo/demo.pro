TEMPLATE = app

QT = core widgets

SOURCES +=  $$PWD/main.cpp

QMAKE_CXXFLAGS_WARN_OFF += -Wno-unused-parameter
QMAKE_CXXFLAGS_WARN_ON += -Wno-unused-parameter

include($$PWD/../config/common.pri)

INCLUDEPATH += $$PWD
target.path = $$DESTDIR
INSTALLS += target

LIBS += -l$${ROXEE_LINK_NAME}

contains(ROXEE_LINK_TYPE, static){
    DEFINES += LIBROXEETORRENT_USE_STATIC

}else{
    win32{
        copyToDestdir($$ROXEE_EXTERNAL/libtorrent.dll, $$DESTDIR)
    }
}


#    contains(ROXEE_LINK_TYPE, static){
#        mac{
#            LIBS += -liconv
#        }
#    }




