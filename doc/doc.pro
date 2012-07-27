TEMPLATE = subdirs
OTHER_FILES +=  $$PWD/doc.sh \
                $$PWD/doxygen.tpl

!win32{
    system(./doc.sh)
}
