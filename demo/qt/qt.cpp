#include "qt.h"
#include "QString"
#include "QFileDialog"
#include "QDir"
#include "QDateTime"
#include "QFileInfo"
#include "QProgressDialog"

#include <vector>
#include <queue>
#include <fstream>
#include <thread>
#include <atomic>
#include <mutex>              // std::mutex, std::unique_lock
#include <condition_variable> // std::condition_variable

#include "../common/common.h"
#define ScreenWidth 1920
#define ScreenHeight 1080

qt::qt(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	/* 初始化界面 */
	initView();
}

qt::~qt()
{
	delete detector;
	detector = nullptr;
	cleanMenu();
	cleanLayout();
}
/**
* @brief initView - 初始化界面，包括菜单栏、控件布局、连接槽函数
*/
void qt::initView()
{
	/* 菜单 */
	initMenu();
	/* 布局 */
	initLayout();
}

/**
* @brief MainWindow::initMenu - 初始化菜单栏
*/
void qt::initMenu()
{

	/* 打开文件菜单 */
	openFileMenu = new QMenu(SQ("功能模块"));
	openVideoAction = new QAction(SQ("打开摄像头"), this);
	connect(openVideoAction, SIGNAL(triggered()), this, SLOT(openVideoSlot()));
	openFileMenu->addAction(openVideoAction);

	openPictureAction = new QAction(SQ("图片文件"), this);
	connect(openPictureAction, SIGNAL(triggered()), this, SLOT(openPictureSlot()));
	openFileMenu->addAction(openPictureAction);

	
	/* 将菜单添加到菜单栏上 */
	QMenuBar *menuBar = this->menuBar();
	menuBar->addMenu(openFileMenu);

	/* LOGO */
	//this->setWindowIcon(QIcon(":/image/logo.PNG"));
	this->setWindowTitle(SQ("人脸检测系统 "));
}

void qt::cleanMenu()
{
	/* 打开文件菜单 */
	if (openFileMenu)
	{
		delete openFileMenu;
		openFileMenu = NULL;
	}

	if (openVideoAction)
	{
		delete openVideoAction;
		openVideoAction = NULL;
	}

	if (openPictureAction)
	{
		delete openPictureAction;
		openPictureAction = NULL;
	}

}

/**
* @brief MainWindow::initLayout - 初始化控件布局
*/
void qt::initLayout()
{
	/* 图片显示面板 */
	centralWidget = new QWidget(this);
	imageLabel = new  QLabel(centralWidget);
    imageLabel->setScaledContents(true);
	QSize labelSize(ScreenWidth,ScreenHeight);
	imageLabel->setFixedSize(labelSize);
	this->setCentralWidget(centralWidget);
	this->resize(ScreenWidth,ScreenHeight);
	this->show();
}

void qt::cleanLayout()
{
	if (centralWidget)
	{
		delete centralWidget;
		centralWidget = NULL;
	}

}
void draw_boxes(cv::Mat mat_img, std::vector<bbox_t> result_vec, std::vector<std::string> obj_names, double spendTime, int current_det_fps = -1, int current_cap_fps = -1)
{
	int const colors[6][3] = { { 1,0,1 },{ 0,0,1 },{ 0,1,1 },{ 0,1,0 },{ 1,1,0 },{ 1,0,0 } };

	for (auto &i : result_vec) {
		cv::Scalar color(0, 255, 0);
		cv::rectangle(mat_img, cv::Rect(i.x, i.y, i.w, i.h), color, 2);
		std::string obj_name = "face";
		cv::Size const text_size = getTextSize(obj_name, cv::FONT_HERSHEY_COMPLEX_SMALL, 1.2, 2, 0);
		int const max_width = (text_size.width > i.w + 2) ? text_size.width-5 : (i.w + 2);
		cv::rectangle(mat_img, cv::Point2f(std::max((int)i.x - 1, 0), std::max((int)i.y - 30, 0)),
			cv::Point2f(std::min((int)i.x + max_width, mat_img.cols - 1), std::min((int)i.y, mat_img.rows - 1)),
			color, CV_FILLED, 8, 0);
		putText(mat_img, obj_name, cv::Point2f(i.x, i.y - 10), cv::FONT_HERSHEY_COMPLEX_SMALL, 1.2, cv::Scalar(0, 0, 0), 2);
	}
	std::string  spend = QS(QString::number(spendTime, 10,4));
	putText(mat_img, "time:"+spend+"s", cv::Point2f(0, 30), cv::FONT_HERSHEY_COMPLEX_SMALL, 1.2, cv::Scalar(0, 0, 0), 2);
	if (current_det_fps >= 0 && current_cap_fps >= 0) {
		std::string fps_str = "FPS detection: " + std::to_string(current_det_fps) + "   FPS capture: " + std::to_string(current_cap_fps);
		putText(mat_img, fps_str, cv::Point2f(10, 20), cv::FONT_HERSHEY_COMPLEX_SMALL, 1.2, cv::Scalar(50, 255, 0), 2);
	}
}
void qt::openVideoSlot() {
	if (openVideoAction->text() == SQ("打开摄像头"))
	{
		selectModel = 0;
		if (!capture.open(2))
		{
			if (!capture.open(1)) {
			     capture.open(0);
		     }
			qDebug()<< "open video false 1";

		}
		openFlag = true;
		openVideoAction->setText(SQ("关闭摄像头"));
		
	}
	else
	{
		openVideoAction->setText(SQ("打开摄像头"));
		capture.release();
		openFlag = false;
	}
	// this->update();
}

void qt::paintEvent(QPaintEvent *e)
{
	
	if (openFlag && selectModel == 0)
	{

		capture >> imgSrc;

		auto start = std::chrono::steady_clock::now();
		std::vector<bbox_t> result_vec = detector->detect(imgSrc);
		auto end = std::chrono::steady_clock::now();
		std::chrono::duration<double> spent = end - start;
		qDebug() << " Time: " << spent.count() << " sec \n";

		// result_vec = detector->tracking_id(result_vec);    // comment it - if track_id is not required
		draw_boxes(imgSrc, result_vec, obj_names,spent.count());
		setImage2Label(imgSrc, imageLabel);
	}
	else if(!openFlag && selectModel == 0 )
	{
		imageLabel->clear();
	}
}
void qt::openPictureSlot() {
	selectModel = 1;
	QString imageFilePath;
	imageFilePath = QFileDialog::getOpenFileName(
		this,
		SQ("打开图片文件"),
		QDir::currentPath(),
		"All files(*.jpg *.jpeg *.png *.gif)");																						
	if (QS(imageFilePath).empty())
	{
		dbgError("The imageFilePath is empty!\n");
		return;
	}
	imgSrc = cv::imread(QS(imageFilePath));
	auto start = std::chrono::steady_clock::now();
	std::vector<bbox_t> result_vec = detector->detect(imgSrc);
	auto end = std::chrono::steady_clock::now();
	std::chrono::duration<double> spent = end - start;
	qDebug() << " Time: " << spent.count() << " sec \n";

	// result_vec = detector->tracking_id(result_vec);    // comment it - if track_id is not required
	draw_boxes(imgSrc, result_vec, obj_names,spent.count());
	setImage2Label(imgSrc, imageLabel);
}
std::vector<std::string> qt::objects_names_from_file(std::string const filename) {
	std::ifstream file(filename);
	std::vector<std::string> file_lines;
	if (!file.is_open()) return file_lines;
	for (std::string line; getline(file, line);) file_lines.push_back(line);
	std::cout << "object names loaded \n";
	return file_lines;
}

cv::Scalar qt::obj_id_to_color(int obj_id) {
	int const colors[6][3] = { { 1,0,1 },{ 0,0,1 },{ 0,1,1 },{ 0,1,0 },{ 1,1,0 },{ 1,0,0 } };
	int const offset = obj_id * 123457 % 6;
	int const color_scale = 150 + (obj_id * 123457) % 100;
	cv::Scalar color(colors[offset][0], colors[offset][1], colors[offset][2]);
	color *= color_scale;
	return color;
}