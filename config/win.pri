###############
# Any of the following may be overriden by the environment
###############

# Wether to build static, plugin or shared library
ROXEE_LINK_TYPE = static
#ROXEE_LINK_TYPE = dynamic
# XXX unlikely to work presently ROXEE_LINK_TYPE = plugin

# You can choose to link against the third-party provided libraries.
# If so, this should be not null and point to a specific version and subpath
ROXEE_INTERNAL_VERSION =
ROXEE_INTERNAL_PATH =

# If you rather want to link against your own, specify ROXEE_EXTERNAL, a directory that must contain include and lib folders with the necessary dependencies
# Note this will be used BEFORE any other manually specified source
CONFIG(debug, debug|release){
    ROXEE_EXTERNAL = C:/roxeelove/buildd-deploy/msvc/debug/static
}else{
    ROXEE_EXTERNAL = C:/roxeelove/buildd-deploy/msvc/release/static
}

# Not specifying either means your third-party are already installed system-wide.

# Where to output the final build (will default to buildd/$$platform/$$compiler-$$qtmajorversion-$$linktype-$$buildtype) if left empty
ROXEE_DESTDIR =

# Flags to use in order to link to the third-party (lib only)
ROXEE_LIBS = -lboost_system -ltorrent
# Special include paths (appended to external deps, if any)  (lib only)
ROXEE_INC =
