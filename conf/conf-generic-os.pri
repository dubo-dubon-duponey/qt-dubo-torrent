# Generic QT/OS settings
mac{
    QMAKE_MACOSX_DEPLOYMENT_TARGET = $$ROXEE_MIN_OSX
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


contains(TEMPLATE, lib){
    win32{
        LIBS += $$ROXEE_WIN_LIBS
        win32-g++ {
        }
        else {
            #QMAKE_CFLAGS_RELEASE += -Zi
            # THIS CRAP IS THE ONLY WAY to not have my crappy shitty singleton crash on me
            # QMAKE_LFLAGS_RELEASE += /DEBUG
        }
    }

    # Mac specific configuration
    mac{
        LIBS += $$ROXEE_OSX_LIBS
    }

    # Unix specific configuration
    unix:!mac {
        LIBS += $$ROXEE_NUX_LIBS
    }
}
