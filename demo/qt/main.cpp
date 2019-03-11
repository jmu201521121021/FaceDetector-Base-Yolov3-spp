#include "qt.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	qt w;
	w.show();
	return a.exec();
}
