# Informations about the git version
ROXEE_GITVERSION = NOGIT
ROXEE_GITCHANGENUMBER = NOGIT
exists(../../.git/HEAD) {
    ROXEE_GITVERSION=$$system(git log -n1 --pretty=format:%h)
    !isEmpty(ROXEE_GITVERSION) {
        # No wc on windows
        !win32{
             ROXEE_GITCHANGENUMBER=$$system(git log --pretty=format:%h | wc -l)
        }
    }else{
        ROXEE_GITVERSION = NOGIT
    }
}

# Environment overrides
renv=$$(ROXEE_LINK_TYPE)
!isEmpty(renv){
    message(Link type overriden by environment)
    ROXEE_LINK_TYPE = $$renv
}

renv=$$(ROXEE_INTERNAL_VERSION)
!isEmpty(renv){
    message(Third-party version overriden by environment)
    ROXEE_INTERNAL_VERSION = $$renv
}

renv=$$(ROXEE_DESTDIR)
!isEmpty(renv){
    message(Destdir overriden by environment)
    ROXEE_DESTDIR = $$renv
}

renv=$$(ROXEE_EXTERNAL)
!isEmpty(renv){
    message(External deps specified by environment)
    ROXEE_EXTERNAL = $$renv
}

isEmpty(ROXEE_EXTERNAL){
    ROXEE_INTERNAL = true
    !isEmpty(ROXEE_INTERNAL_VERSION){
        ROXEE_EXTERNAL= $$PWD/../../third-party/$$ROXEE_INTERNAL_PATH
    }
}

mac|win32{
    isEmpty(ROXEE_EXTERNAL){
        error(You have to specify either a ROXEE_INTERNAL_VERSION or ROXEE_EXTERNAL where to find dependencies on windows and mac)
    }
}

# Build type
CONFIG(debug, debug|release){
    ROXEE_BUILD_TYPE = debug
}else{
    ROXEE_BUILD_TYPE = release
}

mac {
    ROXEE_PLATFORM = mac
}

win32 {
    ROXEE_PLATFORM = win
}

!mac:!win32{
    ROXEE_PLATFORM = $$system(uname)-$$system(uname -n)-$$system(arch)
}

ROXEE_LINK_NAME = $${TARGET}
win32{
    contains(ROXEE_LINK_TYPE, dynamic){
        ROXEE_LINK_NAME = $${TARGET}$${VER_MAJ}
    }
}
# Export these to the root object
DEFINES += PROJECT_NAME=\\\"$${ROXEE_PROJECT_NAME}\\\"
DEFINES += PROJECT_VENDOR=\\\"$${ROXEE_VENDOR_NAME}\\\"
DEFINES += VERSION_FULL=\\\"$${ROXEE_PROJECT_VERSION_MAJOR}.$${ROXEE_PROJECT_VERSION_MINOR}.$${ROXEE_PROJECT_VERSION_BUGFIX}\\\"
DEFINES += VERSION_GIT=\\\"$${ROXEE_GITVERSION}\\\"
DEFINES += VERSION_CHANGE=\\\"$${ROXEE_GITCHANGENUMBER}\\\"
DEFINES += PROJECT_BUILDTYPE=\\\"$${ROXEE_BUILD_TYPE}\\\"
DEFINES += PROJECT_LINKTYPE=\\\"$${ROXEE_LINK_TYPE}\\\"
