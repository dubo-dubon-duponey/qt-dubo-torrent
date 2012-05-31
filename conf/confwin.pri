#Debug
CONFIG(debug, debug|release): CONFIG += console

# Allow old windows versions to behave
DEFINES += BOOST_ASIO_ENABLE_CANCELIO

win32-g++ {
  include(confwin-mingw.pri)
}
else {
  include(confwin-msvc.pri)
}
