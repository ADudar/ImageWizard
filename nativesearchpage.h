#ifndef NATIVESEARCHPAGE_H
#define NATIVESEARCHPAGE_H

#include <QWidget>
#include "ui_nativesearchpage.h"

class NativeSearchPage : public QWidget
{
	Q_OBJECT

public:
	NativeSearchPage(QWidget *parent = 0);
	~NativeSearchPage();

private:
	Ui::NativeSearchPage ui;
};

#endif // NATIVESEARCHPAGE_H
