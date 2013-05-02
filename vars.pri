ROXEE_PROJECT_NAME = RoxeeTorrent
ROXEE_VENDOR_NAME = WebItUp
ROXEE_PROJECT_VERSION_MAJOR = 0
ROXEE_PROJECT_VERSION_MINOR = 7
ROXEE_PROJECT_VERSION_BUGFIX = 0
ROXEE_MINIMUM_QT = 4.6
ROXEE_MIN_OSX = 10.6

# Name of the target
TARGET = roxeetorrent

# Any of the following may also be specified using environment variables

# Wether to build static, plugin or shared library
#ROXEE_LINK_TYPE = static
ROXEE_LINK_TYPE = dynamic

# XXX unlikely to work presently ROXEE_LINK_TYPE = plugin


# If you want to use the provided mechanism to fetch and link third-party dependencies, specify which version you want here
# Otherwise, you must specify ROXEE_EXTERNAL (below)
ROXEE_INTERNAL_VERSION =
ROXEE_INTERNAL_PATH =

# Where to find additional dependencies (include and libs)
# Note this will be used BEFORE any other manually specified source, so, careful with that
ROXEE_EXTERNAL =

# Where to output the final build (will default to buildd/platform/compiler-qtmajorversion-linktype-debug)
ROXEE_DESTDIR =

ROXEE_WIN_LIBS =
ROXEE_NUX_LIBS =
ROXEE_OSX_LIBS =









renvlt=$$(ROXEE_LINK_TYPE)
isEmpty(renvlt){
    renvlt=$$ROXEE_LINK_TYPE
}

# XXX private stuff - to be enhanced
isEmpty(ROXEE_EXTERNAL){
    CONFIG(debug, debug|release){
        mac{
            ROXEE_EXTERNAL = /Users/dmp/buildd/deploy.webitup.org/client/Darwin/debug/$${renvlt}
        }
        win32{
            ROXEE_EXTERNAL = C:/roxeelove/buildd-deploy/msvc/debug/$${renvlt}
        }
    }else{
        mac{
            ROXEE_EXTERNAL = /Users/dmp/buildd/deploy.webitup.org/client/Darwin/release/$${renvlt}
        }
        win32{
            ROXEE_EXTERNAL = C:/roxeelove/buildd-deploy/msvc/release/$${renvlt}
        }
    }
}
