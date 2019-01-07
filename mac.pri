###############
# Any of the following may be overriden by the environment
###############

# You can choose to link against the third-party provided libraries.
# If so, this should be not null and point to a specific version and subpath
DUBO_INTERNAL_VERSION =
DUBO_INTERNAL_PATH =

# If you rather want to link against your own, specify DUBO_EXTERNAL, a directory that must contain include and lib folders with the necessary dependencies
# Note this will be used BEFORE any other manually specified source
DUBO_EXTERNAL = /Users/dmp/buildd/deploy/client/Darwin/debug/static/
DUBO_EXTERNAL = /Users/dmp/Applications/bin/homebrew/

# Not specifying either means your third-party are already installed system-wide.

# Where to output the final build (will default to buildd/$$platform/$$compiler-$$qtmajorversion-$$linktype-$$buildtype) if left empty
DUBO_DESTDIR =

# Flags to use in order to link to the third-party (lib only)
DUBO_LIBS = -ltorrent-rasterbar -lboost_system
# -lboost_iostreams-mt -liconv -lboost_thread-mt -lboost_system-mt -lboost_chrono-mt # useful only if libtorrent is statically compiled it seems
#   -liconv
# Special include paths (appended to external deps, if any)  (lib only)
DUBO_INC =
