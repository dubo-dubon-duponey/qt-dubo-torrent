# Entry point project file

# Enforce recent QT
lessThan(QT_VERSION, 4.8) {
    error("QTLibTorrent is tested only with Qt 4.8 or greater")
}

# Explore subdirs in order
TEMPLATE = subdirs
CONFIG = ordered
SUBDIRS = src
# res
#OTHER_FILES += ../vars.pri.in
