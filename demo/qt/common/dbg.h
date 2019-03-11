#ifndef __DBG_H__
#define __DBG_H__

#if _MSC_VER
#define snprintf _snprintf
#endif

#include <stdio.h>
#include <stdarg.h>
#include <assert.h>
#include <opencv2/opencv.hpp>
#include <QPixmap>
#include <QLabel>

enum DbgLevel {
    DbgLevelVerbose,
    DbgLevelInfo,
    DbgLevelWarn,
    DbgLevelError,
    DbgLevelNone
};

void dbg(DbgLevel level, const char *file, int line, const char *fmt, ...);

#define dbgVerbose(fmt, ...)    dbg(DbgLevelVerbose, __FILE__, __LINE__, fmt, ##__VA_ARGS__)
#define dbgInfo(fmt, ...)       dbg(DbgLevelInfo, __FILE__, __LINE__, fmt, ##__VA_ARGS__)
#define dbgWarn(fmt, ...)       dbg(DbgLevelWarn, __FILE__, __LINE__, fmt, ##__VA_ARGS__)
#define dbgError(fmt, ...)      dbg(DbgLevelError, __FILE__, __LINE__, fmt, ##__VA_ARGS__)

void imdbgShow(const std::string &name, const cv::Mat &img);
void imdbgWrite(const std::string &name, const cv::Mat &img);

void drawPoints(cv::Mat &image, const std::vector<cv::Point2f> &points, const cv::Scalar &color = cv::Scalar::all(255));
void drawBox(cv::Mat &image, const cv::Rect &box, const cv::Scalar &color = cv::Scalar::all(255), int thick = 1);
/**
 * @brief setImage2Label    在label上显示图片
 * @param image             图片
 * @param qLabel            label
 */
void setImage2Label(const cv::Mat &image, QLabel *qLabel);
#endif // DBG_H
