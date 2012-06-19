# Name of the target file (lowercase shit to avoid problems)
INCNAME = lib$${TARGET}

DEFINES += PROJECT_NAME=\\\"$${ROXEE_PROJECT_NAME}\\\"
DEFINES += PROJECT_VENDOR=\\\"$${ROXEE_VENDOR_NAME}\\\"
DEFINES += VERSION_MAJOR=$${ROXEE_PROJECT_VERSION_MAJOR}
DEFINES += VERSION_MINOR=$${ROXEE_PROJECT_VERSION_MINOR}
DEFINES += VERSION_BUGFIX=$${ROXEE_PROJECT_VERSION_BUGFIX}
DEFINES += VERSION_FULL=\\\"$${ROXEE_PROJECT_VERSION_MAJOR}.$${ROXEE_PROJECT_VERSION_MINOR}.$${ROXEE_PROJECT_VERSION_BUGFIX}\\\"

message( -> Building $${ROXEE_PROJECT_NAME} $${ROXEE_PROJECT_VERSION_MAJOR}.$${ROXEE_PROJECT_VERSION_MINOR}.$${ROXEE_PROJECT_VERSION_BUGFIX})

ROXEE_GITVERSION = NOGIT
ROXEE_GITCHANGENUMBER = NOGIT
exists(../.git/HEAD) {
    ROXEE_GITVERSION=$$system(git log -n1 --pretty=format:%h)
    !isEmpty(ROXEE_GITVERSION) {
        ROXEE_GITCHANGENUMBER=$$system(git log --pretty=format:%h | wc -l)
    }else{
        ROXEE_GITVERSION = NOGIT
    }
}
DEFINES += VERSION_GIT=\\\"$${ROXEE_GITVERSION}\\\"
DEFINES += VERSION_CHANGE=\\\"$${ROXEE_GITCHANGENUMBER}\\\"

message( -> Git revision $${ROXEE_GITVERSION} changeset number $${ROXEE_GITCHANGENUMBER})

# Build type
CONFIG(debug, debug|release){
    CONFIG -= release
    ROXEE_BUILD_TYPE = debug
}else{
    CONFIG -= debug declarative_debug
    ROXEE_BUILD_TYPE = release
    DEFINES += NDEBUG
}
DEFINES += PROJECT_BUILDTYPE=\\\"$${ROXEE_BUILD_TYPE}\\\"

message( -> Building a $${ROXEE_BUILD_TYPE} version)

FORCE_STATIC{
    ROXEE_LINK_TYPE=static
}

FORCE_DYNAMIC{
    ROXEE_LINK_TYPE=dynamic
}

contains(ROXEE_LINK_TYPE, static){
    contains(TEMPLATE, lib){
        CONFIG += STATIC
    }
}

DEFINES += PROJECT_LINKTYPE=\\\"$${ROXEE_LINK_TYPE}\\\"

message( -> Building a $${ROXEE_LINK_TYPE} version)

win32-msvc{
    ROXEE_COMPILER=win-msvc
}
win32-g++{
    ROXEE_COMPILER=win-ming
}
macx-g++{
    ROXEE_COMPILER=mac-g++
}
macx-clang{
    ROXEE_COMPILER=mac-clang
}

RCC_DIR     = $${PWD}/../buildd/tmp/$${ROXEE_LINK_TYPE}-$${ROXEE_BUILD_TYPE}-$${ROXEE_COMPILER}/rcc
UI_DIR      = $${PWD}/../buildd/tmp/$${ROXEE_LINK_TYPE}-$${ROXEE_BUILD_TYPE}-$${ROXEE_COMPILER}/ui
MOC_DIR     = $${PWD}/../buildd/tmp/$${ROXEE_LINK_TYPE}-$${ROXEE_BUILD_TYPE}-$${ROXEE_COMPILER}/moc
OBJECTS_DIR = $${PWD}/../buildd/tmp/$${ROXEE_LINK_TYPE}-$${ROXEE_BUILD_TYPE}-$${ROXEE_COMPILER}/obj

message( -> Using temp build dir $${PWD}/../buildd/tmp/$${ROXEE_LINK_TYPE}-$${ROXEE_BUILD_TYPE}-$${ROXEE_COMPILER})

# If we don't have a specific destination directory
isEmpty(ROXEE_DESTDIR){
#    CONFIG += debug_and_release build_all
    DESTDIR = $${PWD}/../buildd/$${TARGET}-$${ROXEE_PROJECT_VERSION_MAJOR}.$${ROXEE_PROJECT_VERSION_MINOR}.$${ROXEE_PROJECT_VERSION_BUGFIX}-$${ROXEE_COMPILER}-$${ROXEE_LINK_TYPE}
}else{
    DESTDIR = $${ROXEE_DESTDIR}
}

message( -> Using build destination dir $${DESTDIR})

# Only relevant for libs: enable dep tracking
CONFIG += create_prl

# Allow app to read prl, conversely
CONFIG += link_prl

# Linking
!isEmpty(ADDITIONAL_DEPENDENCIES_DIR){
    INCLUDEPATH += $${ADDITIONAL_DEPENDENCIES_DIR}/include
    LIBS += -L$${ADDITIONAL_DEPENDENCIES_DIR}/lib
    message( -> Link/inc using $${ADDITIONAL_DEPENDENCIES_DIR})
}

!isEmpty(ROXEE_DEPENDENCIES_DIR){
    INCLUDEPATH += $${ROXEE_DEPENDENCIES_DIR}/$${ROXEE_BUILD_TYPE}/$${ROXEE_LINK_TYPE}/include
    LIBS += -L$${ROXEE_DEPENDENCIES_DIR}/$${ROXEE_BUILD_TYPE}/$${ROXEE_LINK_TYPE}/lib
    message( -> Link/inc using $${ROXEE_DEPENDENCIES_DIR}/$${ROXEE_BUILD_TYPE}/$${ROXEE_LINK_TYPE})
}

# Copying source to install destination
unix{
# XXX Kind of dirty really - only non private headers should go in
    system(rm -fR $${DESTDIR}/include/$${INCNAME})
    system(mkdir -p $${DESTDIR}/include/$${INCNAME})
    system(cp $${PWD}/../src/*.h $${DESTDIR}/include/$${INCNAME})
}

#INSTALLS += src
DESTDIR = $${DESTDIR}/lib

CONFIG(debug, debug|release){
    TARGET = $${TARGET}-d
}
