#OTHER_FILES += \
#    ../res/app.rc.in \
#    ../res/app.rc \
#    ../res/ico/main.ico

#ICON = ../res/ico/main.ico
#RC_FILE = ../res/app.rc

## Lower-case target name to avoid problems on windows
#TARGET = webroxer

#Debug
CONFIG(debug, debug|release): CONFIG += console

win32-g++ {
  include(confwin-mingw.pri)
}
else {
  include(confwin-msvc.pri)
}
