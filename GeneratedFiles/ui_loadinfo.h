/********************************************************************************
** Form generated from reading UI file 'loadinfo.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOADINFO_H
#define UI_LOADINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_loadInfo
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *objName;
    QComboBox *comboBoxName;
    QHBoxLayout *horizontalLayout_2;
    QLabel *objPose;
    QComboBox *comboBoxPose;
    QHBoxLayout *horizontalLayout_3;
    QLabel *truncated;
    QComboBox *comboBoxTruncated;
    QHBoxLayout *horizontalLayout_4;
    QLabel *difficult;
    QComboBox *comboBoxDifficult;
    QHBoxLayout *horizontalLayout_5;
    QLabel *startPointX;
    QLineEdit *lineEditStartPointX;
    QHBoxLayout *horizontalLayout_6;
    QLabel *startPointY;
    QLineEdit *lineEditStartPointY;
    QHBoxLayout *horizontalLayout_7;
    QLabel *endPointX;
    QLineEdit *lineEditEndPointX;
    QHBoxLayout *horizontalLayout_8;
    QLabel *endPointY;
    QLineEdit *lineEditEndPointY;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *loadInfo)
    {
        if (loadInfo->objectName().isEmpty())
            loadInfo->setObjectName(QStringLiteral("loadInfo"));
        loadInfo->resize(332, 317);
        gridLayout = new QGridLayout(loadInfo);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        groupBox = new QGroupBox(loadInfo);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 22, 221, 220));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        objName = new QLabel(layoutWidget);
        objName->setObjectName(QStringLiteral("objName"));

        horizontalLayout->addWidget(objName);

        comboBoxName = new QComboBox(layoutWidget);
        comboBoxName->setObjectName(QStringLiteral("comboBoxName"));

        horizontalLayout->addWidget(comboBoxName);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        objPose = new QLabel(layoutWidget);
        objPose->setObjectName(QStringLiteral("objPose"));

        horizontalLayout_2->addWidget(objPose);

        comboBoxPose = new QComboBox(layoutWidget);
        comboBoxPose->setObjectName(QStringLiteral("comboBoxPose"));

        horizontalLayout_2->addWidget(comboBoxPose);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        truncated = new QLabel(layoutWidget);
        truncated->setObjectName(QStringLiteral("truncated"));

        horizontalLayout_3->addWidget(truncated);

        comboBoxTruncated = new QComboBox(layoutWidget);
        comboBoxTruncated->setObjectName(QStringLiteral("comboBoxTruncated"));

        horizontalLayout_3->addWidget(comboBoxTruncated);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        difficult = new QLabel(layoutWidget);
        difficult->setObjectName(QStringLiteral("difficult"));

        horizontalLayout_4->addWidget(difficult);

        comboBoxDifficult = new QComboBox(layoutWidget);
        comboBoxDifficult->setObjectName(QStringLiteral("comboBoxDifficult"));

        horizontalLayout_4->addWidget(comboBoxDifficult);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        startPointX = new QLabel(layoutWidget);
        startPointX->setObjectName(QStringLiteral("startPointX"));

        horizontalLayout_5->addWidget(startPointX);

        lineEditStartPointX = new QLineEdit(layoutWidget);
        lineEditStartPointX->setObjectName(QStringLiteral("lineEditStartPointX"));

        horizontalLayout_5->addWidget(lineEditStartPointX);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        startPointY = new QLabel(layoutWidget);
        startPointY->setObjectName(QStringLiteral("startPointY"));

        horizontalLayout_6->addWidget(startPointY);

        lineEditStartPointY = new QLineEdit(layoutWidget);
        lineEditStartPointY->setObjectName(QStringLiteral("lineEditStartPointY"));

        horizontalLayout_6->addWidget(lineEditStartPointY);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        endPointX = new QLabel(layoutWidget);
        endPointX->setObjectName(QStringLiteral("endPointX"));

        horizontalLayout_7->addWidget(endPointX);

        lineEditEndPointX = new QLineEdit(layoutWidget);
        lineEditEndPointX->setObjectName(QStringLiteral("lineEditEndPointX"));

        horizontalLayout_7->addWidget(lineEditEndPointX);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        endPointY = new QLabel(layoutWidget);
        endPointY->setObjectName(QStringLiteral("endPointY"));

        horizontalLayout_8->addWidget(endPointY);

        lineEditEndPointY = new QLineEdit(layoutWidget);
        lineEditEndPointY->setObjectName(QStringLiteral("lineEditEndPointY"));

        horizontalLayout_8->addWidget(lineEditEndPointY);


        verticalLayout->addLayout(horizontalLayout_8);

        buttonBox = new QDialogButtonBox(groupBox);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(60, 260, 231, 23));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(groupBox, 0, 0, 1, 1);

#ifndef QT_NO_SHORTCUT
        objName->setBuddy(comboBoxName);
        objPose->setBuddy(comboBoxPose);
        truncated->setBuddy(comboBoxTruncated);
        difficult->setBuddy(comboBoxDifficult);
        startPointX->setBuddy(lineEditStartPointX);
        startPointY->setBuddy(lineEditStartPointY);
        endPointX->setBuddy(lineEditEndPointX);
        endPointY->setBuddy(lineEditEndPointY);
#endif // QT_NO_SHORTCUT

        retranslateUi(loadInfo);
        QObject::connect(buttonBox, SIGNAL(accepted()), loadInfo, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), loadInfo, SLOT(reject()));

        QMetaObject::connectSlotsByName(loadInfo);
    } // setupUi

    void retranslateUi(QDialog *loadInfo)
    {
        loadInfo->setWindowTitle(QApplication::translate("loadInfo", "Dialog", 0));
        groupBox->setTitle(QApplication::translate("loadInfo", "Object Properties", 0));
        objName->setText(QApplication::translate("loadInfo", "objName:", 0));
        objPose->setText(QApplication::translate("loadInfo", "objPose:", 0));
        truncated->setText(QApplication::translate("loadInfo", "truncated:", 0));
        comboBoxTruncated->clear();
        comboBoxTruncated->insertItems(0, QStringList()
         << QApplication::translate("loadInfo", "0", 0)
         << QApplication::translate("loadInfo", "1", 0)
        );
        difficult->setText(QApplication::translate("loadInfo", "difficult:", 0));
        comboBoxDifficult->clear();
        comboBoxDifficult->insertItems(0, QStringList()
         << QApplication::translate("loadInfo", "0", 0)
         << QApplication::translate("loadInfo", "1", 0)
        );
        startPointX->setText(QApplication::translate("loadInfo", "startPoint x:", 0));
        startPointY->setText(QApplication::translate("loadInfo", "startPoint y:", 0));
        endPointX->setText(QApplication::translate("loadInfo", "endPoint x:", 0));
        endPointY->setText(QApplication::translate("loadInfo", "endPoint y:", 0));
    } // retranslateUi

};

namespace Ui {
    class loadInfo: public Ui_loadInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOADINFO_H
