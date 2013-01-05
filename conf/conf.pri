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
include($$PWD/../vars.pri)
# Generic env setup
include($$PWD/conf-generic-env.pri)
# QT generic setup
include($$PWD/conf-generic-qt.pri)
# QT os-specific setup
include($$PWD/conf-generic-os.pri)

# Project specific configuration / os specific
include($$PWD/conf-project.pri)


message( -> Building: $${ROXEE_PROJECT_NAME} $${VERSION} ($${ROXEE_VENDOR_NAME}))
message( -> Git: $${ROXEE_GITVERSION} changeset number $${ROXEE_GITCHANGENUMBER})
message( -> Build type: $${ROXEE_BUILD_TYPE})
message( -> Link: $${ROXEE_LINK_TYPE} version)
message( -> Platform: $${ROXEE_PLATFORM})
message( -> Temporary build dir: $${TMP_BASE_DIR})
message( -> Build destination dir $${DESTDIR})
message( -> Additional lib/include: $${ROXEE_EXTERNAL})
