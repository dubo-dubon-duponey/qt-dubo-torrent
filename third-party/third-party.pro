TEMPLATE = subdirs

OTHER_FILES +=  $$PWD/README \
                $$PWD/bootstrap.sh

PROJECT_ROOT = $$PWD/..
include($$PROJECT_ROOT/config/qmakeitup.pri)

# Only mac has deps for now
mac{
    !isEmpty(DUBO_INTERNAL){
        message( -> Using internal third-party $${DUBO_INTERNAL_VERSION})
        system($$PWD/bootstrap.sh $$DUBO_INTERNAL_VERSION)
    }
}

# https://dl.bintray.com/boostorg/release/1.66.0/source/boost_1_66_0.tar.bz2
# https://github.com/arvidn/libtorrent/blob/master/docs/building.rst
