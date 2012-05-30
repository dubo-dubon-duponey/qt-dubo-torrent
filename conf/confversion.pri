OTHER_FILES += ../conf/confversion.pri.in

DEFINES += VERSION=\\\"v$${PROJECT_VERSION}\\\"

DEFINES += VERSION_MAJOR=0
DEFINES += VERSION_MINOR=2
DEFINES += VERSION_BUGFIX=0

exists(../.git/HEAD) {
    GITVERSION=$$system(git log -n1 --pretty=format:%h)
    !isEmpty(GITVERSION) {
        GITCHANGENUMBER=$$system(git log --pretty=format:%h | wc -l)
        DEFINES += GITVERSION=\"\\\"$$GITVERSION\\\"\"
        DEFINES += GITCHANGENUMBER=\"\\\"$$GITCHANGENUMBER\\\"\"
    }
}
