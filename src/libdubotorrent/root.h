/**
 * Copyright (c) 2018, Dubo Dubon Duponey <dubodubonduponey+github@pm.me>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
 *
 * Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
 * Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*!
\mainpage
This library is primarily meant to be used by the Dubo Webrunner.
Its purpose is to provide a clean, QT-ified, scriptable API that introduces as little extra complexity as possible over
the underyling torrent library, and ideally, be API independent from that library.
Right now though, it only supports (and is meant for) rasterbar libtorrent (http://www.rasterbar.com/products/libtorrent/).

To compile:
- build or install rasterbar libtorrent (http://www.rasterbar.com/products/libtorrent/)
- edit the vars.pri file at the root of the project so that it matches your mileage:
 - DEPDIR=# should point to wherever your lib and include folders reside (under which libtorrent can be found)
 - DESTDIR=# should point to wherever you want the library to be compiled
- qmake, then make

To use it, just create a DuboTorrent::Session object, possibly expose it inside your webkit and learn to swim.

Big fat warning: this pile of code may or may not work for you. If it does, you may send a thank you note :).
If it doesn't, you can probably:
- live with it
- ask me for help

... though neither of these is guaranteed to have any result - of course you may also fix it and possibly ask for a pull request :)


This code is distributed under the terms of the BSD license.
*/

#ifndef DUBOTORRENT_ROOT_H
#define DUBOTORRENT_ROOT_H

#include "global.h"

#include <QObject>

/*! \namespace DuboTorrent
\brief The library namespace.
*/

namespace DuboTorrent
{
/*!
  \brief A dummy object exposing version and name informations.
*/
class LIBDUBOTORRENTSHARED_EXPORT Root: public QObject {
    Q_OBJECT
public:

    /*! \brief The name of the library.*/
    Q_PROPERTY(const QString NAME READ getName CONSTANT)
    /*! \brief The name of the vendor.*/
    Q_PROPERTY(const QString VENDOR READ getVendor CONSTANT)
    /*! \brief The version of the library.*/
    Q_PROPERTY(const QString VERSION READ getVersion CONSTANT)
    /*! \brief The (git) revision of the library.*/
    Q_PROPERTY(const QString REVISION READ getRevision CONSTANT)
    /*! \brief The (git) changeset of the library.*/
    Q_PROPERTY(const QString CHANGESET READ getChangeset CONSTANT)

    /*! \brief The build type (release / debug of the library).*/
    Q_PROPERTY(const QString BUILD READ getBuildType CONSTANT)
    /*! \brief The type of the library (static / dynamic).*/
    Q_PROPERTY(const QString LINK READ getLinkType CONSTANT)
    /*! \brief QT Version used to build.*/
    Q_PROPERTY(const QString QT READ getQt CONSTANT)

    /*! \brief The nameof the underlying player library.*/
    Q_PROPERTY(const QString PLUGIN_NAME READ getLibName CONSTANT)
    /*! \brief The version of the underlying torrent library.*/
    Q_PROPERTY(const QString PLUGIN_VERSION READ getLibVersion CONSTANT)
    /*! \brief The revision of the underlying torrent library.*/
    Q_PROPERTY(const QString PLUGIN_REVISION READ getLibRevision CONSTANT)


    /*! \cond */
    const QString getName();
    const QString getVendor();
    const QString getVersion();
    const QString getRevision();
    const QString getChangeset();

    const QString getBuildType();
    const QString getLinkType();
    const QString getQt();

    const QString getLibName(){ return QString::fromLatin1("libtorrent");}
    const QString getLibVersion();
    const QString getLibRevision();
    /*! \endcond */
};
}

#endif // DUBOTORRENT_ROOT_H
