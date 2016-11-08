
#ifndef DRAWPICXML_H
#define DRAWPICXML_H

#include <QtWidgets/QMainWindow>
#include "ui_drawpicxml.h"
#include "paintarea.h"
#include "processimage.h"
#include <QScrollArea>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QDockWidget>
#include <QPaintEvent>


class drawPicXml : public QMainWindow
{
	Q_OBJECT

public:
	drawPicXml(QWidget *parent = 0);

	~drawPicXml();

private:
	Ui::drawPicXmlClass ui;
    PaintArea* area;
    QScrollArea* scrollArea;
    processimage *process;
	QListWidget *fileList;
	QDockWidget *dockNameList;

    QStringList fileNames;//´æ´¢Í¼Æ¬Ãû



protected:

private slots:
    void on_actionOpen_triggered();
    void on_actionExit_triggered();
    void on_actionProcess_pictures_triggered();
    void on_actionGenerate_XML_triggered();
    void on_actionSourse_code_triggered();
    void on_actionHelp_triggered();
    void on_actionShow_Dock_triggered();
    void on_actionOpenFiles_triggered();
	void on_actionClearBindingBox_triggered();

    void Slot_ItemClicked(QListWidgetItem * item);

    void on_actionChangeListSize_triggered();
    void on_actionListModel_triggered();
    void on_actionIconModel_triggered();
    void on_actionOriginal_triggered();
	
};

#endif // DRAWPICXML_H
