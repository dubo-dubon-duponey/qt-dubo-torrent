TEMPLATE = app

## Basic consumer variables
QT = core widgets

SOURCES +=  $$PWD/main.cpp

# You don't "need" any "magic" of the following - just link against the produced library if you are doing it your own way
include($$PWD/../conf/conf.pri)

INCLUDEPATH += $$PWD
target.path = $$DESTDIR
INSTALLS += target


