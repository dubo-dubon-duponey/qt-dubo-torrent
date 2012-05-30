DEFINES += NAME=$${PROJECT_NAME}
DEFINES += VERSION_MAJOR=$${PROJECT_VERSION_MAJOR}
DEFINES += VERSION_MINOR=$${PROJECT_VERSION_MINOR}
DEFINES += VERSION_BUGFIX=$${PROJECT_VERSION_BUGFIX}
DEFINES += VERSION_FULL=\\\"$${PROJECT_VERSION_MAJOR}.$${PROJECT_VERSION_MINOR}.$${PROJECT_VERSION_BUGFIX}\\\"

exists(../.git/HEAD) {
    GITVERSION=$$system(git log -n1 --pretty=format:%h)
    !isEmpty(GITVERSION) {
        GITCHANGENUMBER=$$system(git log --pretty=format:%h | wc -l)
        DEFINES += VERSION_GIT=\"\\\"$$GITVERSION\\\"\"
        DEFINES += VERSION_CHANGE=\"\\\"$$GITCHANGENUMBER\\\"\"
    }
}


CONFIG(release, debug|release): message( -> Release build)
CONFIG(debug, debug|release): message( -> Debug build)

isEmpty(DESTDIR){
    CONFIG(release, debug|release): BT = release
    CONFIG(debug, debug|release): BT = debug
    DESTDIR = $$PWD/../buildd/$$PROJECT_NAME-$${PROJECT_VERSION_MAJOR}.$${PROJECT_VERSION_MINOR}.$${PROJECT_VERSION_BUGFIX}-$$BT-$${GITVERSION}-$${GITCHANGENUMBER}
}

message( -> Using output dir $${DESTDIR})
