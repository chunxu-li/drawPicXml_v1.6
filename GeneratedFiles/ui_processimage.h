/********************************************************************************
** Form generated from reading UI file 'processimage.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROCESSIMAGE_H
#define UI_PROCESSIMAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_processimage
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QGridLayout *gridLayout;
    QProgressBar *progressBar;
    QPushButton *pushButtonOpen;
    QPushButton *pushButtonExit;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *processimage)
    {
        if (processimage->objectName().isEmpty())
            processimage->setObjectName(QStringLiteral("processimage"));
        processimage->resize(413, 394);
        centralwidget = new QWidget(processimage);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(60, 30, 281, 271));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        progressBar = new QProgressBar(widget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(24);
        progressBar->setTextVisible(false);

        gridLayout->addWidget(progressBar, 3, 0, 1, 1);

        pushButtonOpen = new QPushButton(widget);
        pushButtonOpen->setObjectName(QStringLiteral("pushButtonOpen"));

        gridLayout->addWidget(pushButtonOpen, 0, 0, 1, 1);

        pushButtonExit = new QPushButton(widget);
        pushButtonExit->setObjectName(QStringLiteral("pushButtonExit"));

        gridLayout->addWidget(pushButtonExit, 4, 0, 1, 1);

        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        processimage->setCentralWidget(centralwidget);
        menubar = new QMenuBar(processimage);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 413, 23));
        processimage->setMenuBar(menubar);
        statusbar = new QStatusBar(processimage);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        processimage->setStatusBar(statusbar);

        retranslateUi(processimage);

        QMetaObject::connectSlotsByName(processimage);
    } // setupUi

    void retranslateUi(QMainWindow *processimage)
    {
        processimage->setWindowTitle(QApplication::translate("processimage", "MainWindow", 0));
        pushButtonOpen->setText(QApplication::translate("processimage", "Open", 0));
        pushButtonExit->setText(QApplication::translate("processimage", "Exit", 0));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class processimage: public Ui_processimage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROCESSIMAGE_H
