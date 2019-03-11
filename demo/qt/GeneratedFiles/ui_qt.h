/********************************************************************************
** Form generated from reading UI file 'qt.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QT_H
#define UI_QT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_qtClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *qtClass)
    {
        if (qtClass->objectName().isEmpty())
            qtClass->setObjectName(QStringLiteral("qtClass"));
        qtClass->resize(600, 400);
        menuBar = new QMenuBar(qtClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        qtClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(qtClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        qtClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(qtClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        qtClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(qtClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        qtClass->setStatusBar(statusBar);

        retranslateUi(qtClass);

        QMetaObject::connectSlotsByName(qtClass);
    } // setupUi

    void retranslateUi(QMainWindow *qtClass)
    {
        qtClass->setWindowTitle(QApplication::translate("qtClass", "qt", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class qtClass: public Ui_qtClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QT_H
