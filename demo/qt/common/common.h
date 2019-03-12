
#ifndef __COMMON_H__
#define __COMMON_H__

#include "dbg.h"

#include <string>
#include <qstring.h>

#define SQ(str) str2qstr(str)
#define QS(qstr) std::string(qstr2str(QString(qstr)))

// 解决中文乱码的问题
inline QString str2qstr(const std::string& str)
{
    return QString::fromLocal8Bit(str.data());
}

inline std::string qstr2str(const QString& qstr)
{
    QByteArray cdata = qstr.toLocal8Bit();
    return std::string(cdata);
}

#endif
