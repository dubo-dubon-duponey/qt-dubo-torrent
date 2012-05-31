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

#ifndef QTLTFILEENTRY_H
#define QTLTFILEENTRY_H

#include <QtCore/QObject>
#include <libtorrent/torrent_info.hpp>

namespace RoxeeTorrent
{
    class QtLtFileEntry : public QObject
    {
        Q_OBJECT
    public:
        explicit QtLtFileEntry(libtorrent::file_entry fe, QObject *parent = 0);

        Q_PROPERTY(const bool executableAttribute   READ executable_attribute)
        Q_PROPERTY(const qint64 fileBase               READ file_base)
        Q_PROPERTY(const bool hiddenAttribute       READ hidden_attribute)
        Q_PROPERTY(const qint64 mtime                  READ mtime)
        Q_PROPERTY(const qint64 offset                 READ offset)
        Q_PROPERTY(const bool padFile               READ pad_file)
        Q_PROPERTY(const qint64 size                   READ size)
        Q_PROPERTY(const qint64 symlinkAttribute       READ symlink_attribute)

        Q_PROPERTY(const QString path               READ path)
        Q_PROPERTY(const QString symlinkPath        READ symlink_path)

        const bool executable_attribute();
        const qint64 file_base();
        const bool hidden_attribute();
        const qint64 mtime();
        const qint64 offset();
        const bool pad_file();
        const qint64 size();
        const bool symlink_attribute();
        const QString path();
        const QString symlink_path();

    signals:

    public slots:

    private:
        libtorrent::file_entry fileentry;
    };
}

#endif // QTLTFILEENTRY_H
