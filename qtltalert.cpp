/**
 * @alpha1
 * XXX timestamp are deadly borked - not too sure why - see session initialization to get it right
 */

#include "qtltalert.h"
#include <qDebug>

QtltAlert::QtltAlert(const QString &what, const QString &message, const int category, const u_int64_t timestamp, QObject *parent):
    QObject(parent)
{
    _message    = message;
    _what       = what;
    _timestamp  = timestamp;
    _category   = category;
}

const QString QtltAlert::message()    {
    return _message;
}

const QString QtltAlert::what()      {
    return _what;
}

const u_int64_t QtltAlert::timestamp()
{
    return _timestamp;
}

// To be compared against an error type
const int QtltAlert::category()       {
    return _category;
}
