/********************************************************************************
** Form generated from reading UI file 'drawpicxml.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DRAWPICXML_H
#define UI_DRAWPICXML_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_drawPicXmlClass
{
public:
    QAction *actionOpen;
    QAction *actionExit;
    QAction *actionHelp;
    QAction *actionSourse_code;
    QAction *actionGenerate_XML;
    QAction *actionProcess_pictures;
    QAction *actionShow_Dock;
    QAction *actionOpenFiles;
    QAction *actionChangeListSize;
    QAction *actionIconModel;
    QAction *actionListModel;
    QAction *actionOriginal;
    QAction *actionClearBindingBox;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuHelp;
    QMenu *menuTools;
    QMenu *menuListSize;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QDockWidget *dock;
    QWidget *dockWidgetContents_3;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *labelFolder;
    QComboBox *comboBoxFolder;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labelFileName;
    QLabel *labelFileName_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *labelDataBase;
    QComboBox *comboBoxDataBase;
    QHBoxLayout *horizontalLayout_4;
    QLabel *labelFlickrid;
    QLabel *labelFlickrid_2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *labelOwnerName;
    QLabel *labelOwnerName_2;
    QHBoxLayout *horizontalLayout_6;
    QLabel *labelDepth;
    QLabel *labelDepth_2;
    QHBoxLayout *horizontalLayout_7;
    QLabel *labelWidth;
    QLabel *labelWidth_2;
    QHBoxLayout *horizontalLayout_8;
    QLabel *labelHeight;
    QLabel *labelHeight_2;
    QSpacerItem *verticalSpacer;

    void setupUi(QMainWindow *drawPicXmlClass)
    {
        if (drawPicXmlClass->objectName().isEmpty())
            drawPicXmlClass->setObjectName(QStringLiteral("drawPicXmlClass"));
        drawPicXmlClass->resize(715, 566);
        actionOpen = new QAction(drawPicXmlClass);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionExit = new QAction(drawPicXmlClass);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionHelp = new QAction(drawPicXmlClass);
        actionHelp->setObjectName(QStringLiteral("actionHelp"));
        actionSourse_code = new QAction(drawPicXmlClass);
        actionSourse_code->setObjectName(QStringLiteral("actionSourse_code"));
        actionGenerate_XML = new QAction(drawPicXmlClass);
        actionGenerate_XML->setObjectName(QStringLiteral("actionGenerate_XML"));
        actionProcess_pictures = new QAction(drawPicXmlClass);
        actionProcess_pictures->setObjectName(QStringLiteral("actionProcess_pictures"));
        actionShow_Dock = new QAction(drawPicXmlClass);
        actionShow_Dock->setObjectName(QStringLiteral("actionShow_Dock"));
        actionOpenFiles = new QAction(drawPicXmlClass);
        actionOpenFiles->setObjectName(QStringLiteral("actionOpenFiles"));
        actionChangeListSize = new QAction(drawPicXmlClass);
        actionChangeListSize->setObjectName(QStringLiteral("actionChangeListSize"));
        actionIconModel = new QAction(drawPicXmlClass);
        actionIconModel->setObjectName(QStringLiteral("actionIconModel"));
        actionListModel = new QAction(drawPicXmlClass);
        actionListModel->setObjectName(QStringLiteral("actionListModel"));
        actionOriginal = new QAction(drawPicXmlClass);
        actionOriginal->setObjectName(QStringLiteral("actionOriginal"));
        actionClearBindingBox = new QAction(drawPicXmlClass);
        actionClearBindingBox->setObjectName(QStringLiteral("actionClearBindingBox"));
        centralWidget = new QWidget(drawPicXmlClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        drawPicXmlClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(drawPicXmlClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 715, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        menuTools = new QMenu(menuBar);
        menuTools->setObjectName(QStringLiteral("menuTools"));
        menuListSize = new QMenu(menuTools);
        menuListSize->setObjectName(QStringLiteral("menuListSize"));
        drawPicXmlClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(drawPicXmlClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        drawPicXmlClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(drawPicXmlClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        drawPicXmlClass->setStatusBar(statusBar);
        dock = new QDockWidget(drawPicXmlClass);
        dock->setObjectName(QStringLiteral("dock"));
        dock->setLayoutDirection(Qt::LeftToRight);
        dockWidgetContents_3 = new QWidget();
        dockWidgetContents_3->setObjectName(QStringLiteral("dockWidgetContents_3"));
        verticalLayout = new QVBoxLayout(dockWidgetContents_3);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        labelFolder = new QLabel(dockWidgetContents_3);
        labelFolder->setObjectName(QStringLiteral("labelFolder"));

        horizontalLayout->addWidget(labelFolder);

        comboBoxFolder = new QComboBox(dockWidgetContents_3);
        comboBoxFolder->setObjectName(QStringLiteral("comboBoxFolder"));

        horizontalLayout->addWidget(comboBoxFolder);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        labelFileName = new QLabel(dockWidgetContents_3);
        labelFileName->setObjectName(QStringLiteral("labelFileName"));

        horizontalLayout_2->addWidget(labelFileName);

        labelFileName_2 = new QLabel(dockWidgetContents_3);
        labelFileName_2->setObjectName(QStringLiteral("labelFileName_2"));

        horizontalLayout_2->addWidget(labelFileName_2);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        labelDataBase = new QLabel(dockWidgetContents_3);
        labelDataBase->setObjectName(QStringLiteral("labelDataBase"));

        horizontalLayout_3->addWidget(labelDataBase);

        comboBoxDataBase = new QComboBox(dockWidgetContents_3);
        comboBoxDataBase->setObjectName(QStringLiteral("comboBoxDataBase"));

        horizontalLayout_3->addWidget(comboBoxDataBase);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        labelFlickrid = new QLabel(dockWidgetContents_3);
        labelFlickrid->setObjectName(QStringLiteral("labelFlickrid"));

        horizontalLayout_4->addWidget(labelFlickrid);

        labelFlickrid_2 = new QLabel(dockWidgetContents_3);
        labelFlickrid_2->setObjectName(QStringLiteral("labelFlickrid_2"));

        horizontalLayout_4->addWidget(labelFlickrid_2);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        labelOwnerName = new QLabel(dockWidgetContents_3);
        labelOwnerName->setObjectName(QStringLiteral("labelOwnerName"));

        horizontalLayout_5->addWidget(labelOwnerName);

        labelOwnerName_2 = new QLabel(dockWidgetContents_3);
        labelOwnerName_2->setObjectName(QStringLiteral("labelOwnerName_2"));

        horizontalLayout_5->addWidget(labelOwnerName_2);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        labelDepth = new QLabel(dockWidgetContents_3);
        labelDepth->setObjectName(QStringLiteral("labelDepth"));

        horizontalLayout_6->addWidget(labelDepth);

        labelDepth_2 = new QLabel(dockWidgetContents_3);
        labelDepth_2->setObjectName(QStringLiteral("labelDepth_2"));

        horizontalLayout_6->addWidget(labelDepth_2);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        labelWidth = new QLabel(dockWidgetContents_3);
        labelWidth->setObjectName(QStringLiteral("labelWidth"));

        horizontalLayout_7->addWidget(labelWidth);

        labelWidth_2 = new QLabel(dockWidgetContents_3);
        labelWidth_2->setObjectName(QStringLiteral("labelWidth_2"));

        horizontalLayout_7->addWidget(labelWidth_2);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        labelHeight = new QLabel(dockWidgetContents_3);
        labelHeight->setObjectName(QStringLiteral("labelHeight"));

        horizontalLayout_8->addWidget(labelHeight);

        labelHeight_2 = new QLabel(dockWidgetContents_3);
        labelHeight_2->setObjectName(QStringLiteral("labelHeight_2"));

        horizontalLayout_8->addWidget(labelHeight_2);


        verticalLayout->addLayout(horizontalLayout_8);

        verticalSpacer = new QSpacerItem(20, 240, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        dock->setWidget(dockWidgetContents_3);
        drawPicXmlClass->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dock);
#ifndef QT_NO_SHORTCUT
        labelFolder->setBuddy(comboBoxFolder);
        labelDataBase->setBuddy(comboBoxDataBase);
#endif // QT_NO_SHORTCUT

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuTools->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionOpenFiles);
        menuFile->addAction(actionExit);
        menuHelp->addAction(actionHelp);
        menuHelp->addAction(actionSourse_code);
        menuTools->addAction(actionGenerate_XML);
        menuTools->addAction(actionProcess_pictures);
        menuTools->addAction(actionShow_Dock);
        menuTools->addAction(menuListSize->menuAction());
        menuTools->addAction(actionClearBindingBox);
        menuListSize->addAction(actionIconModel);
        menuListSize->addAction(actionListModel);
        menuListSize->addAction(actionOriginal);

        retranslateUi(drawPicXmlClass);

        QMetaObject::connectSlotsByName(drawPicXmlClass);
    } // setupUi

    void retranslateUi(QMainWindow *drawPicXmlClass)
    {
        drawPicXmlClass->setWindowTitle(QApplication::translate("drawPicXmlClass", "drawPicXml", 0));
        actionOpen->setText(QApplication::translate("drawPicXmlClass", "Open", 0));
        actionExit->setText(QApplication::translate("drawPicXmlClass", "Exit", 0));
        actionExit->setShortcut(QApplication::translate("drawPicXmlClass", "Alt+X", 0));
        actionHelp->setText(QApplication::translate("drawPicXmlClass", "Help", 0));
        actionSourse_code->setText(QApplication::translate("drawPicXmlClass", "Sourse Code", 0));
        actionGenerate_XML->setText(QApplication::translate("drawPicXmlClass", "Generate XML", 0));
        actionGenerate_XML->setShortcut(QApplication::translate("drawPicXmlClass", "Ctrl+G", 0));
        actionProcess_pictures->setText(QApplication::translate("drawPicXmlClass", "Process pictures", 0));
        actionShow_Dock->setText(QApplication::translate("drawPicXmlClass", "Dock", 0));
        actionOpenFiles->setText(QApplication::translate("drawPicXmlClass", "OpenFiles", 0));
        actionOpenFiles->setShortcut(QApplication::translate("drawPicXmlClass", "Ctrl+O", 0));
        actionChangeListSize->setText(QApplication::translate("drawPicXmlClass", "ChangeListSize", 0));
        actionIconModel->setText(QApplication::translate("drawPicXmlClass", "IconModel", 0));
        actionListModel->setText(QApplication::translate("drawPicXmlClass", "ListModel", 0));
        actionOriginal->setText(QApplication::translate("drawPicXmlClass", "Original", 0));
        actionClearBindingBox->setText(QApplication::translate("drawPicXmlClass", "ClearBindingBox", 0));
        menuFile->setTitle(QApplication::translate("drawPicXmlClass", "File", 0));
        menuHelp->setTitle(QApplication::translate("drawPicXmlClass", "Help", 0));
        menuTools->setTitle(QApplication::translate("drawPicXmlClass", "Tools", 0));
        menuListSize->setTitle(QApplication::translate("drawPicXmlClass", "ListSize", 0));
        dock->setWindowTitle(QApplication::translate("drawPicXmlClass", "Properities", 0));
        labelFolder->setText(QApplication::translate("drawPicXmlClass", "folder:", 0));
        comboBoxFolder->clear();
        comboBoxFolder->insertItems(0, QStringList()
         << QApplication::translate("drawPicXmlClass", "VOC2007", 0)
         << QApplication::translate("drawPicXmlClass", "VOC2008", 0)
         << QApplication::translate("drawPicXmlClass", "VOC2009", 0)
         << QApplication::translate("drawPicXmlClass", "VOC2010", 0)
         << QApplication::translate("drawPicXmlClass", "VOC2011", 0)
         << QApplication::translate("drawPicXmlClass", "VOC2012", 0)
        );
        labelFileName->setText(QApplication::translate("drawPicXmlClass", "fileName:", 0));
        labelFileName_2->setText(QString());
        labelDataBase->setText(QApplication::translate("drawPicXmlClass", "dataBase:", 0));
        comboBoxDataBase->clear();
        comboBoxDataBase->insertItems(0, QStringList()
         << QApplication::translate("drawPicXmlClass", "The VOC2007 Database", 0)
         << QApplication::translate("drawPicXmlClass", "The VOC2008 Database", 0)
         << QApplication::translate("drawPicXmlClass", "The VOC2009 Database", 0)
         << QApplication::translate("drawPicXmlClass", "The VOC2010 Database", 0)
         << QApplication::translate("drawPicXmlClass", "The VOC2011 Database", 0)
         << QApplication::translate("drawPicXmlClass", "The VOC2012 Database", 0)
        );
        labelFlickrid->setText(QApplication::translate("drawPicXmlClass", "flickrid:", 0));
        labelFlickrid_2->setText(QString());
        labelOwnerName->setText(QApplication::translate("drawPicXmlClass", "ownerName:", 0));
        labelOwnerName_2->setText(QString());
        labelDepth->setText(QApplication::translate("drawPicXmlClass", "depth:", 0));
        labelDepth_2->setText(QString());
        labelWidth->setText(QApplication::translate("drawPicXmlClass", "width:", 0));
        labelWidth_2->setText(QString());
        labelHeight->setText(QApplication::translate("drawPicXmlClass", "height:", 0));
        labelHeight_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class drawPicXmlClass: public Ui_drawPicXmlClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DRAWPICXML_H
