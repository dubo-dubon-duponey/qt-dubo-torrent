TEMPLATE = app

QT = core widgets

SOURCES +=  $$PWD/main.cpp

include($$PWD/../config/common.pri)

INCLUDEPATH += $$PWD
target.path = $$DESTDIR
INSTALLS += target

LIBS += -l$${ROXEE_LINK_NAME}

contains(ROXEE_LINK_TYPE, static){
    DEFINES += LIBROXEESINAPP_USE_STATIC

    win32{
        DEFINES += LIBROXEETORRENT_USE_STATIC
        copyToDestdir($$ROXEE_EXTERNAL/libtorrent.dll, $$DESTDIR)
    }
}


#    contains(ROXEE_LINK_TYPE, static){
#        mac{
#            LIBS += -liconv
#        }
#    }




