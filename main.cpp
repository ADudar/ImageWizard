#include "imagewizard.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	setlocale( LC_CTYPE, "RUS" );

	QApplication a(argc, argv);
	ImageWizard w;
	w.show();

	return a.exec();
}
