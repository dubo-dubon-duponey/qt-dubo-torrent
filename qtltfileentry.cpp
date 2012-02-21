#include "qtltfileentry.h"

QtLtFileEntry::QtLtFileEntry(libtorrent::file_entry fe, QObject *parent) :
    QObject(parent)
{
    fileentry = fe;
}

const bool QtLtFileEntry::executable_attribute()
{
    return fileentry.executable_attribute;
}

const qint64 QtLtFileEntry::file_base()
{
    return fileentry.file_base;
}

const bool QtLtFileEntry::hidden_attribute()
{
    return fileentry.hidden_attribute;
}

const qint64 QtLtFileEntry::mtime()
{
    return fileentry.mtime;
}

const qint64 QtLtFileEntry::offset()
{
    return fileentry.offset;
}

const bool QtLtFileEntry::pad_file()
{
    return fileentry.pad_file;
}

const qint64 QtLtFileEntry::size()
{
    return fileentry.size;
}

const bool QtLtFileEntry::symlink_attribute()
{
    return fileentry.symlink_attribute;
}

const QString QtLtFileEntry::path()
{
    return QString::fromUtf8(fileentry.path.string().c_str());
}

const QString QtLtFileEntry::symlink_path()
{
    return QString::fromUtf8(fileentry.symlink_path.string().c_str());
}
