/**
 * Copyright (c) 2012, WebItUp <contact@webitup.fr>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
 *
 * Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
 * Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

// * XXX timestamp are deadly borked - not too sure why - see session initialization to get it right

#ifndef ROXEETORRENT_ALERT_H
#define ROXEETORRENT_ALERT_H

#include "libroxeetorrent_global.h"

#include <QtCore/qobject.h>

namespace RoxeeTorrent
{
    /*! \brief Every alert message implements this.

      An alert consist of a "what", or subject, a "message", a "timestamp" and a category to be compared with AlertTypes.
      @see AlertTypes
     */
    class Alert : public QObject
    {
        Q_OBJECT
    public:
        /*! Constructor. Test. */
        explicit Alert(const QString &what, const QString &message, const int category, const qint64 timestamp, QObject *parent = 0);
        ~Alert();

        /*! Title or subject of the alert*/
        Q_PROPERTY(QString      what        READ what)
        /*! Detailed message of the alert*/
        Q_PROPERTY(QString      message     READ message)
        /*! Category of the alert, to becompared with alerttypes*/
        Q_PROPERTY(int          category    READ category)
        /*! "Time" of the alert*/
        Q_PROPERTY(qint64       timestamp   READ timestamp)

        /*! \cond */
        const QString message();
        const QString what();
        const qint64 timestamp();
        const int category();
        /*! \endcond */

    private:
        QString         _message;
        QString         _what;
        int             _category;
        qint64       _timestamp;

    };
}

#endif // ROXEETORRENT_ALERT_H
