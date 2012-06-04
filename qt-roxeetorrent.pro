# Entry point project file

# Enforce recent QT
lessThan(QT_VERSION, 4.8) {
    error("RoxeeTorrent is tested only with Qt 4.8 or greater")
}

# Explore subdirs in order
TEMPLATE = subdirs
CONFIG = ordered
SUBDIRS = src

OTHER_FILES += vars.pri.in \
    res/doxygen.tpl \
    res/redist/AUTHORS \
    res/redist/ChangeLog \
    res/redist/LICENSE.BSD2 \
    README
