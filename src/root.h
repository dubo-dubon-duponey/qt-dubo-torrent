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

#ifndef ROXEETORRENT_ROOT_H
#define ROXEETORRENT_ROOT_H

#include "libroxeetorrent_global.h"
#include <QtCore/QObject>


namespace RoxeeTorrent
{

    class LIBROXEETORRENTSHARED_EXPORT Root: public QObject {
        Q_OBJECT
    public:
//        explicit Root(QObject *parent);

        Q_PROPERTY(const QString name READ getName)
        Q_PROPERTY(const QString ROXEE_VERSION READ getVersion)
        Q_PROPERTY(const QString ROXEE_REVISION READ getRevision)
        Q_PROPERTY(const QString ROXEE_CHANGESET READ getChangeset)

        Q_PROPERTY(const QString PLUGIN_VERSION READ getLibVersion)
        Q_PROPERTY(const QString PLUGIN_REVISION READ getLibRevision)

        const QString getName();
        const QString getVersion();
        const QString getRevision();
        const QString getChangeset();

        const QString getLibVersion();
        const QString getLibRevision();
    };
}

#endif // ROXEETORRENT_ROOT_H
