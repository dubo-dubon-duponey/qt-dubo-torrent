PROJECT_NAME = RoxeeTorrent
# Name of the target file (lowercase shit to avoid problems)
TARGET = roxeetorrent

DEFINES += NAME=$${PROJECT_NAME}
DEFINES += VERSION_MAJOR=$${PROJECT_VERSION_MAJOR}
DEFINES += VERSION_MINOR=$${PROJECT_VERSION_MINOR}
DEFINES += VERSION_BUGFIX=$${PROJECT_VERSION_BUGFIX}
DEFINES += VERSION_FULL=\\\"$${PROJECT_VERSION_MAJOR}.$${PROJECT_VERSION_MINOR}.$${PROJECT_VERSION_BUGFIX}\\\"

exists(../.git/HEAD) {
    GITVERSION=$$system(git log -n1 --pretty=format:%h)
    !isEmpty(GITVERSION) {
        GITCHANGENUMBER=$$system(git log --pretty=format:%h | wc -l)
        DEFINES += VERSION_GIT=\\\"$$GITVERSION\\\"
        DEFINES += VERSION_CHANGE=\\\"$$GITCHANGENUMBER\\\"
    }
}

# Append name if compiling for debug / release
CONFIG(release, debug|release){
    BT = release
    message( -> Release build)
}
CONFIG(debug, debug|release){
    BT = debug
    message( -> Debug build)
}

# Share object files for faster compiling
RCC_DIR     = $$PWD/../buildd-$$BT/temp/rcc
UI_DIR      = $$PWD/../buildd-$$BT/temp/ui
MOC_DIR     = $$PWD/../buildd-$$BT/temp/moc
OBJECTS_DIR = $$PWD/../buildd-$$BT/temp/obj

message( -> Using temp build dir $$PWD/../buildd-$$BT)

isEmpty(DESTDIR){
    CONFIG += debug_and_release build_all
    DESTDIR = $$PWD/../buildd-$$BT/$$PROJECT_NAME-$${PROJECT_VERSION_MAJOR}.$${PROJECT_VERSION_MINOR}.$${PROJECT_VERSION_BUGFIX}-$${GITVERSION}-$${GITCHANGENUMBER}
}

message( -> Using output dir $${DESTDIR})
