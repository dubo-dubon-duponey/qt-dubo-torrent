ROXEE_PROJECT_NAME = RoxeeTorrent
ROXEE_VENDOR_NAME = WebItUp
ROXEE_PROJECT_VERSION_MAJOR = 0
ROXEE_PROJECT_VERSION_MINOR = 5
ROXEE_PROJECT_VERSION_BUGFIX = 0

# Where to output the final build
ROXEE_DESTDIR =
# Wether to build static, shared, or plugin
#ROXEE_LINK_TYPE = static
#ROXEE_LINK_TYPE = plugin
ROXEE_LINK_TYPE = dynamic

# Where to find additional dependencies (eg: external (win)-sparkle)
# This will take precedence over the provided third-party builds
#ADDITIONAL_DEPENDENCIES_DIR = /Users/dmp/buildd/deploy.webitup.org/client/Darwin/release/$${ROXEE_LINK_TYPE}

# If bundling static libtorrent inside, have to -liconv
ADDITIONAL_DEPENDENCIES_DIR = /Users/dmp/buildd/deploy.webitup.org/client/Darwin/release/static
LIBS += -liconv

TARGET = roxeetorrent
