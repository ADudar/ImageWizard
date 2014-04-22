#ifndef IMAGEWIZARD_H
#define IMAGEWIZARD_H

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QMenu>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QLayout.h>
#include "searchpage.h"
#include "nativesearchpage.h"
#include "ui_imagewizard.h"

class ImageWizard : public QMainWindow
{
	Q_OBJECT

public:
	ImageWizard(QWidget* parent = 0);
	~ImageWizard();

public slots:
    void SetPageSearch();
    void SetPageNativeSearch();


private:
	Ui::ImageWizardClass ui;

	const int m_height;
	const int m_width;

	QMenuBar* m_menuBar;
	QToolBar* m_toolBar;

	QStackedWidget* m_stactk;
	SearchPage* m_searchPage;
	NativeSearchPage* m_nativeSearchPage;

	void Init();
};

#endif // IMAGEWIZARD_H
