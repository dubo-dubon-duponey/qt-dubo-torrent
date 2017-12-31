###############
# Any of the following may be overriden by the environment
###############

# Wether to build static or shared library
DUBO_LINK_TYPE = static
#DUBO_LINK_TYPE = dynamic

# You can choose to link against the third-party provided libraries.
# If so, this should be not null and point to a specific version and subpath
DUBO_INTERNAL_VERSION =
DUBO_INTERNAL_PATH =

# If you rather want to link against your own, specify DUBO_EXTERNAL, a directory that must contain include and lib folders with the necessary dependencies
# Note this will be used BEFORE any other manually specified source
CONFIG(debug, debug|release){
    contains(QMAKE_CC, cl){
        DUBO_EXTERNAL = C:/dubo/buildd-deploy/msvc/debug/$${DUBO_LINK_TYPE}
    }else{
        DUBO_EXTERNAL = C:/dubo/buildd-deploy/gcc/debug/$${DUBO_LINK_TYPE}
    }
}else{
    contains(QMAKE_CC, cl){
        DUBO_EXTERNAL = C:/dubo/buildd-deploy/msvc/release/$${DUBO_LINK_TYPE}
    }else{
        DUBO_EXTERNAL = C:/dubo/buildd-deploy/gcc/release/$${DUBO_LINK_TYPE}
    }
}


# Not specifying either means your third-party are already installed system-wide.

# Where to output the final build (will default to buildd/$$platform/$$compiler-$$qtmajorversion-$$linktype-$$buildtype) if left empty
DUBO_DESTDIR =

# Flags to use in order to link to the third-party (lib only)
contains(QMAKE_CC, cl){
    CONFIG(debug, debug|release){
        DUBO_LIBS = -llibtorrent -llibboost_system-vc100-mt-gd-1_53
    }else{
        DUBO_LIBS = -llibtorrent -llibboost_system-vc100-mt-1_53
    }
}else{
    CONFIG(debug, debug|release){
# XXX Depends on boost layout... using system for now
#        DUBO_LIBS = -ltorrent -lboost_system-mgw47-mt-d-1_53 -lws2_32 -lwsock32
        DUBO_LIBS = -ltorrent -lboost_system -lws2_32 -lwsock32
    }else{
# Depends on boost layout...
#        DUBO_LIBS = -ltorrent -lboost_system-mgw47-mt-1_53 -lws2_32 -lwsock32
        DUBO_LIBS = -ltorrent -lboost_system -lws2_32 -lwsock32
    }
}

# Special include paths (appended to external deps, if any)  (lib only)
DUBO_INC = include/boost-1_53

