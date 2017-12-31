/**
 * Copyright (c) 2018, Dubo Dubon Duponey <dubodubonduponey@gmail.com>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
 *
 * Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
 * Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef DUBOTORRENT_ALERTTYPES_H
#define DUBOTORRENT_ALERTTYPES_H

#include "libdubotorrent_global.h"

#include <QtCore/qobject.h>

namespace DuboTorrent
{
/*! \brief Describes types categories used by alerts sent by the library.

  These should be checked against the "category" for any "Alert", or used as an alert mask.

  This is a singleton.
  @see Alert
  @see Session
  */
class LIBDUBOTORRENTSHARED_EXPORT AlertTypes : public QObject
{
    Q_OBJECT
public:

    /*! \brief Singleton */
    static AlertTypes* instance();

    /*! \cond */
    ~AlertTypes();
    /*! \endcond */

    /*! \brief The alert is an error */
    Q_PROPERTY(const int ERROR        READ error)
    /*! \brief Peer alert */
    Q_PROPERTY(const int PEER         READ peer)
    /*! \brief Port mapping alert */
    Q_PROPERTY(const int PORT_MAPPING READ port_mapping)
    /*! \brief Storage alert */
    Q_PROPERTY(const int STORAGE      READ storage)
    /*! \brief Tracker alert */
    Q_PROPERTY(const int TRACKER      READ tracker)
    /*! \brief Debug alert */
    Q_PROPERTY(const int DEBUG        READ debug)
    /*! \brief Status alert */
    Q_PROPERTY(const int STATUS       READ status)
    /*! \brief Progress alert */
    Q_PROPERTY(const int PROGRESS     READ progress)
    /*! \brief IP block alert */
    Q_PROPERTY(const int IP_BLOCK     READ ip_block)
    /*! \brief Performance alert */
    Q_PROPERTY(const int PERFORMANCE  READ performance)
    /*! \brief DHT alert */
    Q_PROPERTY(const int DHT          READ dht)
    /*! \brief Stats alert */
    Q_PROPERTY(const int STATS        READ stats)
    /*! \brief Peer alert */
    Q_PROPERTY(const int ALL          READ all)

    /*! \cond */
    int error();
    int peer();
    int port_mapping();
    int storage();
    int tracker();
    int debug();
    int status();
    int progress();
    int ip_block();
    int performance();
    int dht();
    int stats();
    int all();
    /*! \endcond */

private:
    explicit AlertTypes(){}

    static AlertTypes* m_Instance;

    AlertTypes(const AlertTypes &);
    AlertTypes& operator=(const AlertTypes &);


};
}

#endif // DUBOTORRENT_ALERTTYPES_H

