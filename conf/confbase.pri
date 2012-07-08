# QT basic config
CONFIG +=   QT_NO_CAST_FROM_ASCII \
            QT_NO_CAST_TO_ASCII \
            QT_STRICT_ITERATORS \
            QT_USE_FAST_CONCATENATION QT_USE_FAST_OPERATOR_PLUS

# To validate with breakpad
CONFIG += warn_on qt thread exceptions rtti stl

# App or libs use these
VER_MAJ = $$ROXEE_PROJECT_VERSION_MAJOR
VER_MIN = $$ROXEE_PROJECT_VERSION_MINOR
VER_PAT = $$ROXEE_PROJECT_VERSION_BUGFIX
VERSION = $${ROXEE_PROJECT_VERSION_MAJOR}.$${ROXEE_PROJECT_VERSION_MINOR}.$${ROXEE_PROJECT_VERSION_BUGFIX}

# Export these to the root object
DEFINES += PROJECT_NAME=\\\"$${ROXEE_PROJECT_NAME}\\\"
DEFINES += PROJECT_VENDOR=\\\"$${ROXEE_VENDOR_NAME}\\\"
DEFINES += VERSION_FULL=\\\"$${ROXEE_PROJECT_VERSION_MAJOR}.$${ROXEE_PROJECT_VERSION_MINOR}.$${ROXEE_PROJECT_VERSION_BUGFIX}\\\"

# Informations about the git version
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

# Build type
CONFIG(debug, debug|release){
    ROXEE_BUILD_TYPE = debug
}else{
    CONFIG -= debug declarative_debug
    ROXEE_BUILD_TYPE = release
    DEFINES += NDEBUG
}
DEFINES += PROJECT_BUILDTYPE=\\\"$${ROXEE_BUILD_TYPE}\\\"

# Link
FORCE_STATIC{
    ROXEE_LINK_TYPE=static
}

FORCE_DYNAMIC{
    ROXEE_LINK_TYPE=dynamic
}

FORCE_PLUGIN{
    ROXEE_LINK_TYPE=plugin
}

DEFINES += PROJECT_LINKTYPE=\\\"$${ROXEE_LINK_TYPE}\\\"

mac {
    PLT = mac
}

win32 {
    PLT = win
}

!mac:!win32{
    PLT = $$system(uname)-$$system(uname -n)-$$system(arch)
}

# Echo
message( -> Building: $${ROXEE_PROJECT_NAME} $${VERSION} ($${ROXEE_VENDOR_NAME}))
message( -> Git: $${ROXEE_GITVERSION} changeset number $${ROXEE_GITCHANGENUMBER})
message( -> Build type: $${ROXEE_BUILD_TYPE})
message( -> Link: $${ROXEE_LINK_TYPE} version)



# Setting path
TMP_BASE_DIR = $${PWD}/../buildd/$${PLT}-tmp/$${QMAKE_CC}/$${ROXEE_LINK_TYPE}-$${ROXEE_BUILD_TYPE}
RCC_DIR     = $${TMP_BASE_DIR}/rcc
UI_DIR      = $${TMP_BASE_DIR}/ui
MOC_DIR     = $${TMP_BASE_DIR}/moc
OBJECTS_DIR = $${TMP_BASE_DIR}/obj

message( -> Temp build dir: $${TMP_BASE_DIR})


# If we don't have a specific destination directory
isEmpty(ROXEE_DESTDIR){
    DESTDIR = $${PWD}/../buildd/$${PLT}/$${QMAKE_CC}/$${ROXEE_LINK_TYPE}-$${ROXEE_BUILD_TYPE}
}else{
    DESTDIR = $${ROXEE_DESTDIR}
}

message( -> Using build destination dir $${DESTDIR})

# Linking
!isEmpty(ADDITIONAL_DEPENDENCIES_DIR){
    INCLUDEPATH += $${ADDITIONAL_DEPENDENCIES_DIR}/include
    LIBS += -L$${ADDITIONAL_DEPENDENCIES_DIR}/lib
    message( -> Using external lib/include: $${ADDITIONAL_DEPENDENCIES_DIR})
}


# Only relevant for libs: enable dep tracking
contains(TEMPLATE, lib){
    CONFIG += absolute_library_soname
    CONFIG += create_prl
    DESTDIR = $${DESTDIR}/lib
    contains(ROXEE_LINK_TYPE, static){
        CONFIG += static
        CONFIG += staticlib
    }
    contains(ROXEE_LINK_TYPE, plugin){
        CONFIG += plugin
    }
    contains(ROXEE_LINK_TYPE, dynamic){
        CONFIG += shared
        CONFIG += dll
    }
}

# Allow app to read prl, conversely
contains(TEMPLATE, app){
    CONFIG += link_prl
    DESTDIR = $${DESTDIR}/bin
}

mac{
    QMAKE_MACOSX_DEPLOYMENT_TARGET = 10.6
}

win32{
    # Exclude cruft from the SDK
    DEFINES += WIN32_LEAN_AND_MEAN

    # Windows XP
    DEFINES += _WIN32_WINNT=0x0501
    DEFINES += _WIN32_IE=0x0501

    # Disable warnings (older macro)
    #DEFINES += _CRT_SECURE_NO_DEPRECATE
    # Disable warnings (newer macro)
    #DEFINES += _CRT_SECURE_NO_WARNINGS
    # Disable POSIX deprecation warnings
    #DEFINES += _CRT_NONSTDC_NO_DEPRECATE
    # Overload the secure versions so that the signature stays the same
    #DEFINES += _CRT_SECURE_CPP_OVERLOAD_SECURE_NAMES
    # Cygwin requires that stuff when using boost ASIO - but we don't support cygwin
    #DEFINES += __USE_W32_SOCKETS
    # Same shit
#    DEFINES += _SCL_SECURE_NO_DEPRECATE

    # http://stackoverflow.com/questions/662084/whats-the-difference-between-the-win32-and-win32-defines-in-c
    DEFINES += WIN32
    DEFINES += _WIN32

    # Large support
    DEFINES += _FILE_OFFSET_BITS=64

    DEFINES += UNICODE
    DEFINES += _UNICODE
    DEFINES += __USE_W32_SOCKETS

    #QMAKE_CFLAGS_RELEASE += -Zi
    #QMAKE_LFLAGS_RELEASE += /DEBUG

}




#DEFINES += BOOST_ALL_NO_LIB
#DEFINES += BOOST_ASIO_HASH_MAP_BUCKETS=1021
#DEFINES += BOOST_EXCEPTION_DISABLE
#DEFINES += BOOST_SYSTEM_STATIC_LINK=1
#DEFINES += BOOST_THREAD_USE_LIB
#DEFINES += BOOST_THREAD_USE_LIB=1
#DEFINES += UNICODE
#DEFINES += _UNICODE
