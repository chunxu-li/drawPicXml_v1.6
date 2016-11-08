#ifndef PAINTAREA_H
#define PAINTAREA_H

#include <QWidget>
#include <QImage>
#include <QPaintEvent>
#include <QMouseEvent>
#include <QPainter>
#include <QRgb>
#include <QVector>
#include <QLabel>
#include <QContextMenuEvent>
#include "ObjStorage.h"
#include "loadinfo.h"

class PaintArea : public QWidget
{
	Q_OBJECT
public:
	PaintArea();
	QVector<ObjStorage> getVecObj();
	void clearVec();
	bool openImage(const QString &fileName);
	void setImageSize(int width, int height);
	void reDrawView();
	QSize getImageSize();
	void clearAllBox();


protected:
	void paintEvent(QPaintEvent *event);//重绘
	void mousePressEvent(QMouseEvent* event);
	void mouseReleaseEvent(QMouseEvent* event);
	void mouseMoveEvent(QMouseEvent* event);
	void contextMenuEvent(QContextMenuEvent *event);
	void paint(QImage &image);


public:
	QImage image;//QImage类对象，用于在其上画图
	QImage tmpImage;//临时绘图
	QImage refreshImage;
	bool isDrawing;
	QRgb backColor;//QRgb颜色对象，存储image的背景色
	QPoint startPoint;
	QPoint endPoint;
	QVector<QPoint> vecPoint;

	loadInfo* info;
	QLabel* posLabel;
private:
	ObjStorage tmpObj;
	QVector<ObjStorage> vecObj;
	QAction *actionDelete;	
	QPoint currentPos;
	QAction *actionClearAll;


signals:
	void sigDeleteItem(QPoint cur);
	private slots :
	void emitDelete();
	void deleteItem(QPoint cur);
	void clearAll();

};

#endif // PAINTAREA_H
