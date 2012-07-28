ROXEE_PROJECT_NAME = RoxeeTorrent
ROXEE_VENDOR_NAME = WebItUp
ROXEE_PROJECT_VERSION_MAJOR = 0
ROXEE_PROJECT_VERSION_MINOR = 6
ROXEE_PROJECT_VERSION_BUGFIX = 0
ROXEE_MINIMUM_QT = 4.8
ROXEE_MIN_OSX = 10.6

# Name of the target
TARGET = roxeetorrent

# Any of the following may also be specified using environment variables
# Note that environment variables will OVERRIDE these

# Wether to build static, plugin or shared library
#ROXEE_LINK_TYPE = plugin
#ROXEE_LINK_TYPE = static
ROXEE_LINK_TYPE = dynamic

# internal means we will use and build bundled third-party scripts/libs
# any other value means you have to provide the given libs and includes (for eg inside ROXEE_EXTERNAL)
ROXEE_THIRD_PARTY = internal

# Where to output the final build (will default to buildd/platform/compiler-linktype-production)
ROXEE_DESTDIR =

# Where to find additional dependencies (include and libs)
# Note this will be used BEFORE any other manually specified source, so, careful with that
ROXEE_EXTERNAL =




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
