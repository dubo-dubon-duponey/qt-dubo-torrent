contains(TEMPLATE, lib){
    message(************************* Building Library *************************)
}

contains(TEMPLATE, app){
    message(************************* Building App *************************)
}

contains(TEMPLATE, subdirs){
    message(************************* Building Subdirectories *************************)
}

# Project vars
include($$PWD/project.pri)

mac {
include($$PWD/mac.pri)
}

win {
include($$PWD/win.pri)
}

!mac:!win32 {
include($$PWD/other.pri)
}


# Generic env setup
include($$PWD/build-system/bs-env.pri)
# QT os-specific setup
include($$PWD/build-system/bs-os.pri)
# QT generic setup
include($$PWD/build-system/bs-qt.pri)


message( -> Building: $${ROXEE_PROJECT_NAME} $${VERSION} ($${ROXEE_VENDOR_NAME}))
message( -> Git: $${ROXEE_GITVERSION} changeset number $${ROXEE_GITCHANGENUMBER})
message( -> Build type: $${ROXEE_BUILD_TYPE})
message( -> Link: $${ROXEE_LINK_TYPE} version)
message( -> Platform: $${ROXEE_PLATFORM})
message( -> Temporary build dir: $${TMP_BASE_DIR})
message( -> Build destination dir $${DESTDIR})
message( -> Additional lib/include: $${ROXEE_EXTERNAL})


defineTest(copyToDestdir) {
    files = $$1
    dest = $$2

    for(FILE, files) {
        DDIR = $$dest

        # Replace slashes in paths with backslashes for Windows
        win32:FILE ~= s,/,\\,g
        win32:DDIR ~= s,/,\\,g

        win32{
            system(mkdir $$quote($$DDIR))
        }else{
            system(mkdir -p $$quote($$DDIR))
        }

        QMAKE_POST_LINK += $$QMAKE_COPY $$quote($$FILE) $$quote($$DDIR) $$escape_expand(\\n\\t)
    }

    export(QMAKE_POST_LINK)
}

defineTest(roxeeLibHelper) {

}
