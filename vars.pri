ROXEE_PROJECT_NAME = RoxeeTorrent
ROXEE_VENDOR_NAME = WebItUp
ROXEE_PROJECT_VERSION_MAJOR = 0
ROXEE_PROJECT_VERSION_MINOR = 6
ROXEE_PROJECT_VERSION_BUGFIX = 0

# Where to output the final build
ROXEE_DESTDIR =
# Wether to build static, shared, or plugin
ROXEE_LINK_TYPE = static
#ROXEE_LINK_TYPE = dynamic
#ROXEE_LINK_TYPE = plugin
# Wether to link to dependency statically or dynamically
#ROXEE_DEPEND_LINK = static
ROXEE_DEPEND_LINK = dynamic

CONFIG(debug, debug|release){
    mac{
        ADDITIONAL_DEPENDENCIES_DIR = /Users/dmp/buildd/deploy.webitup.org/client/Darwin/debug/$${ROXEE_DEPEND_LINK}
    }
    win32{
        ADDITIONAL_DEPENDENCIES_DIR = C:/roxeelove/buildd-deploy/msvc/debug/$${ROXEE_DEPEND_LINK}
    }
}else{
    mac{
        ADDITIONAL_DEPENDENCIES_DIR = /Users/dmp/buildd/deploy.webitup.org/client/Darwin/release/$${ROXEE_DEPEND_LINK}
    }
    win32{
        ADDITIONAL_DEPENDENCIES_DIR = C:/roxeelove/buildd-deploy/msvc/release/$${ROXEE_DEPEND_LINK}
    }
}

TARGET = roxeetorrent

#INCLUDEPATH += C:\\roxeelove\\buildd-deploy\\msvc\\release\\static\\include
