#ifndef IMAGEWIZARD_H
#define IMAGEWIZARD_H

#include <QtWidgets/QMainWindow>
#include "ui_imagewizard.h"

class ImageWizard : public QMainWindow
{
	Q_OBJECT

public:
	ImageWizard(QWidget *parent = 0);
	~ImageWizard();

private:
	Ui::ImageWizardClass ui;
};

#endif // IMAGEWIZARD_H
