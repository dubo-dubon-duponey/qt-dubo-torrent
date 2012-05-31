/**
 * Copyright (c) 2012, WebItUp
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
 *
 * Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
 * Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "qtltfileentry.h"

using namespace RoxeeTorrent;

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
    return QString::fromStdString(fileentry.path);// .string().c_str());
}

const QString QtLtFileEntry::symlink_path()
{
    return QString::fromStdString(fileentry.symlink_path);//.string().c_str());
}
