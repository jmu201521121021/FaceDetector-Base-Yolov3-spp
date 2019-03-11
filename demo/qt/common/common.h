/**
 * @file       common.h
 * @brief      罗普特数据标注工具公共头文件
 * @details    用于统一包含项目所需的头文件
 * @author     xiaochengliu.prc@foxmail.com
 * @date       2018.01.25
 * @version    V0.1
 * @par Copyright (C):
 *			   罗普特(厦门)科技集团有限公司
 * @par History:
 *  - V0.1     xiaochengliu.prc@foxmail.com         2017.12.25 \n
 *             原型开发 \n
 */

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
