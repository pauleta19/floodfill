#include "program.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	
	QApplication a(argc, argv);
	program w;
	w.show();
	w.setFixedHeight(600);
	w.setFixedWidth(600);
	return a.exec();
}
