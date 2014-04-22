#ifndef SEARCHPAGE_H
#define SEARCHPAGE_H

#include <string>
#include <Windows.h>

#include <QWidget>
#include <QGridLayout>
#include <QComboBox>
#include <QScrollArea>
#include <QPushButton>
#include <QListWidget>
#include "ui_searchpage.h"

class SearchPage : public QWidget
{
	Q_OBJECT

public:
	SearchPage(QWidget* parent = 0);
	~SearchPage();

	void Init();

public slots:
	void Searching();
	void BoxIndxChanged( int indx );

private:
	Ui::SearchPage ui;

	int m_boxIndx;

	int total;

	QGridLayout* m_mainLayout;
	QComboBox* m_comboBox;
	QPushButton* m_pushButton;
	QScrollArea* m_scrollArea;
	QListWidget* m_listWidget;

	void AddDisks();
	void FindFile(char *path, char *mask);
};

#endif // SEARCHPAGE_H
