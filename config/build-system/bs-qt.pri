lessThan(QT_VERSION, $$ROXEE_MINIMUM_QT) {
    error("$$ROXEE_PROJECT_NAME works only with Qt $$ROXEE_MINIMUM_QT or greater (you have $$QT_VERSION)")
}

# QT4/5 modules add fix
lessThan(QT_VERSION, 5.0.0) {
    contains(QT, widgets){
        QT += gui
        QT -= widgets
    }
    contains(QT, webkitwidgets){
        QT += webkit
        QT -= webkitwidgets
    }
}

# QT basic config
CONFIG +=   QT_NO_CAST_FROM_ASCII \
            QT_NO_CAST_TO_ASCII \
            QT_STRICT_ITERATORS \
            QT_USE_FAST_CONCATENATION \
            QT_USE_FAST_OPERATOR_PLUS

# To validate with breakpad
CONFIG += warn_on qt thread exceptions rtti stl

# Version for app or library
VER_MAJ = $$ROXEE_PROJECT_VERSION_MAJOR
VER_MIN = $$ROXEE_PROJECT_VERSION_MINOR
VER_PAT = $$ROXEE_PROJECT_VERSION_BUGFIX
VERSION = $${ROXEE_PROJECT_VERSION_MAJOR}.$${ROXEE_PROJECT_VERSION_MINOR}.$${ROXEE_PROJECT_VERSION_BUGFIX}

# No debug
!CONFIG(debug, debug|release){
    CONFIG -= debug declarative_debug
    DEFINES += NDEBUG
}

# Setting path
VARIED_DIR = $${QMAKE_CC}-$${QT_MAJOR_VERSION}-$${ROXEE_LINK_TYPE}-$${ROXEE_BUILD_TYPE}
TMP_BASE_DIR = $${PWD}/../../buildd/$${ROXEE_PLATFORM}-tmp/$${VARIED_DIR}
RCC_DIR     = $${TMP_BASE_DIR}/rcc
UI_DIR      = $${TMP_BASE_DIR}/ui
MOC_DIR     = $${TMP_BASE_DIR}/moc
OBJECTS_DIR = $${TMP_BASE_DIR}/obj


# If we don't have a specific destination directory
isEmpty(ROXEE_DESTDIR){
    DESTDIR = $${PWD}/../../buildd/$${ROXEE_PLATFORM}/$${VARIED_DIR}
}else{
    DESTDIR = $${ROXEE_DESTDIR}
}

# Only relevant for libs: enable dep tracking
contains(TEMPLATE, lib){
    CONFIG += absolute_library_soname

    # Linking against third-party libs if any
    !isEmpty(ROXEE_EXTERNAL){
        INCLUDEPATH += $${ROXEE_EXTERNAL}/include
        LIBS += -L$${ROXEE_EXTERNAL}/lib
        mac{
            QMAKE_LFLAGS += -F$${ROXEE_EXTERNAL}/Frameworks
        }
        !isEmpty(ROXEE_INC){
            INCLUDEPATH += $${ROXEE_EXTERNAL}/$${ROXEE_INC}
        }
    }

    # Add custom flags to link against third-party, if any necessary
    LIBS += $$ROXEE_LIBS

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

    INCLUDEPATH +=  $$DESTDIR/include
    LIBS += -L$$DESTDIR/lib

    DESTDIR = $${DESTDIR}/bin
}
