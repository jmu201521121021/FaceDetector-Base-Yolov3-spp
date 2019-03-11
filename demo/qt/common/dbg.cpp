
#include <chrono>
#include <mutex>
#include <fstream>
#include <sstream>
#include "QSize"

#include "dbg.h"

using namespace std::chrono;

static const int LogBufSize = 256;

DbgLevel gDbgLevel = DbgLevelInfo;

bool gImageDbgShowOn = true;
bool gImageDbgWriteOn = true;
bool gDrawDbgOn = false;
bool gRecordLog = false;

static char gLogBuf[LogBufSize];
static std::mutex gLogMutex;
static std::ofstream gRecordFile;

void dbg(DbgLevel level, const char *file, int line, const char *fmt, ...)
{
    if (level >= gDbgLevel) {
        gLogMutex.lock();

        int len = snprintf(gLogBuf, LogBufSize, "<%s, %d>: ", file, line);
        va_list ap;
        va_start(ap, fmt);
        len += vsnprintf(gLogBuf + len, LogBufSize - len, fmt, ap);
        va_end(ap);

        printf("%s", gLogBuf);
        if (gRecordLog) {
            if (!gRecordFile.is_open()) {
                time_t time = system_clock::to_time_t(system_clock::now());
                std::stringstream ss;
                ss << "log_" << time << ".txt";
                gRecordFile.open(ss.str());
            }

            gRecordFile.write(gLogBuf, len);
            gRecordFile.flush();
        }

        gLogMutex.unlock();
    }
}

void imdbgShow(const std::string &name, const cv::Mat &img)
{
    if (gImageDbgShowOn) {
        cv::imshow(name, img);
    }
}

void imdbgWrite(const std::string &name, const cv::Mat &img)
{
    if (gImageDbgWriteOn) {
        cv::imwrite(name, img);
    }
}

void drawPoints(cv::Mat &image, const std::vector<cv::Point2f> &points, const cv::Scalar &color)
{
    if (gDrawDbgOn) {
        for (std::vector<cv::Point2f>::const_iterator i = points.begin(), ie = points.end(); i != ie; ++i) {
            circle(image, *i, 1, color, 1);
        }
    }
}

void drawBox(cv::Mat &image, const cv::Rect &box, const cv::Scalar &color, int thick)
{
    if (gDrawDbgOn) {
        rectangle(image, cv::Point(box.x, box.y), cv::Point(box.x + box.width, box.y + box.height), color, thick);
    }
}
/**
 * @brief setImage2Label    在label上显示图片
 * @param image             图片
 * @param qLabel            label
 */
void setImage2Label(const cv::Mat &image, QLabel *qLabel)
{
	cv::Mat showImg;
	cv::cvtColor(image, showImg, CV_BGR2RGB); //因为Mat的图像数据是BGR,所以要先将img转化位RGB
	QImage qImg = QImage((const uchar *)(showImg.data),
						showImg.cols, showImg.rows,
						showImg.cols * showImg.channels(),
						QImage::Format_RGB888);
	qLabel->clear();                                //清空控件label
	qLabel->setPixmap(QPixmap::fromImage(qImg));    //label赋值
	qLabel->show();
  qLabel->update();
}
