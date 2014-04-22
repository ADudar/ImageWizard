/********************************************************************************
** Form generated from reading UI file 'nativesearchpage.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NATIVESEARCHPAGE_H
#define UI_NATIVESEARCHPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NativeSearchPage
{
public:

    void setupUi(QWidget *NativeSearchPage)
    {
        if (NativeSearchPage->objectName().isEmpty())
            NativeSearchPage->setObjectName(QStringLiteral("NativeSearchPage"));
        NativeSearchPage->resize(400, 300);

        retranslateUi(NativeSearchPage);

        QMetaObject::connectSlotsByName(NativeSearchPage);
    } // setupUi

    void retranslateUi(QWidget *NativeSearchPage)
    {
        NativeSearchPage->setWindowTitle(QApplication::translate("NativeSearchPage", "NativeSearchPage", 0));
    } // retranslateUi

};

namespace Ui {
    class NativeSearchPage: public Ui_NativeSearchPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NATIVESEARCHPAGE_H
