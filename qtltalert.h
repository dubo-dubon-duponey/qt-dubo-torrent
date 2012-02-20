/**
 * @alpha1
 * XXX timestamp are deadly borked - not too sure why - see session initialization to get it right
 */

#ifndef QTLTALERT_H
#define QTLTALERT_H

#include "qt-libtorrent_global.h"

#include <QObject>

class QTLIBTORRENTSHARED_EXPORT QtltAlert : public QObject
{
    Q_OBJECT
public:
    explicit QtltAlert(const QString &what, const QString &message, const int category, const u_int64_t timestamp, QObject *parent = 0);

    Q_PROPERTY(QString      what        READ what)
    Q_PROPERTY(QString      message     READ message)
    Q_PROPERTY(int          category    READ category)
    Q_PROPERTY(qint64       timestamp   READ timestamp)

    const QString message();
    const QString what();
    const u_int64_t timestamp();
    const int category();

private:
    QString         _message;
    QString         _what;
    int             _category;
    u_int64_t          _timestamp;

};

#endif // QTLTALERT_H
