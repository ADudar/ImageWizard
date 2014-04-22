/********************************************************************************
** Form generated from reading UI file 'imagewizard.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGEWIZARD_H
#define UI_IMAGEWIZARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ImageWizardClass
{
public:
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ImageWizardClass)
    {
        if (ImageWizardClass->objectName().isEmpty())
            ImageWizardClass->setObjectName(QStringLiteral("ImageWizardClass"));
        ImageWizardClass->resize(600, 400);
        centralWidget = new QWidget(ImageWizardClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        ImageWizardClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ImageWizardClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 21));
        ImageWizardClass->setMenuBar(menuBar);
        statusBar = new QStatusBar(ImageWizardClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        ImageWizardClass->setStatusBar(statusBar);

        retranslateUi(ImageWizardClass);

        QMetaObject::connectSlotsByName(ImageWizardClass);
    } // setupUi

    void retranslateUi(QMainWindow *ImageWizardClass)
    {
        ImageWizardClass->setWindowTitle(QApplication::translate("ImageWizardClass", "ImageWizard", 0));
    } // retranslateUi

};

namespace Ui {
    class ImageWizardClass: public Ui_ImageWizardClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGEWIZARD_H
