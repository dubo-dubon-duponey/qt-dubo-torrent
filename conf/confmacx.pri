QMAKE_MACOSX_DEPLOYMENT_TARGET = 10.6

# Linking dynamically on OSX
DEFINES += BOOST_ASIO_DYN_LINK
CONFIG += absolute_library_soname

# Pointing to include and lib dirs
INCLUDEPATH += $${DEPDIR}/include
LIBS += -L$${DEPDIR}/lib
LIBS += -ltorrent-rasterbar -lboost_system-mt-roxee

# -lcrypto  -lboost_filesystem-mt-roxee -lboost_thread-mt-roxee
