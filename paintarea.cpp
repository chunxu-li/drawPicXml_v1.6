#include "paintarea.h"
#include <QToolTip>
#include <QDebug>
#include <QMessageBox>
#include <QMenu>

PaintArea::PaintArea()
{
	//image=QImage(500,500,QImage::Format_RGB32);//画布的初始大小设置
	//backColor=qRgb(255,255,255);//画布背景颜色用白色
	//image.fill(backColor);
	isDrawing = false;
	tmpImage = image;
	info = new loadInfo;
	info->initObj();
	posLabel = new QLabel(this);


	actionDelete = new QAction("Delete", this);
	actionClearAll = new QAction("ClearAll", this);
	actionDelete->setIcon(QIcon(":/icon/delete"));
	actionClearAll->setIcon(QIcon(":/icon/clearall"));

	QObject::connect(this, SIGNAL(sigDeleteItem(QPoint)), this, SLOT(deleteItem(QPoint)));//槽函数没有执行
}

void PaintArea::contextMenuEvent(QContextMenuEvent *event)
{
	currentPos = event->pos();
	QMenu *menu = new QMenu(this);
	menu->addAction(actionDelete);
	menu->addAction(actionClearAll);
	QObject::connect(actionDelete, SIGNAL(triggered()), this, SLOT(emitDelete()));//槽函数没有执行
	connect(actionClearAll, SIGNAL(triggered()), this, SLOT(clearAll()));
	menu->move(cursor().pos());
	menu->show();
}

QVector<ObjStorage> PaintArea::getVecObj()
{
	return this->vecObj;
}

void PaintArea::clearVec()
{
	this->vecObj.clear();
}

bool PaintArea::openImage(const QString &fileName)
{
	QImage loadedImage;
	if (!loadedImage.load(fileName))
		return false;
	QSize newSize = loadedImage.size();
	setImageSize(newSize.width(), newSize.height());
	image = loadedImage;
	refreshImage = loadedImage;
	update();
	return true;
}

void PaintArea::setImageSize(int width, int height)
{
	QImage newImage(width, height, QImage::Format_RGB32);
	image = newImage;
	update();
}

void PaintArea::reDrawView()
{
	image = refreshImage;
	for (int indexRedraw = 0; indexRedraw < vecObj.count(); indexRedraw++)
	{

		QPainter pp(&image);
		pp.setPen(Qt::red);
		int x1 = vecObj.at(indexRedraw).getXmin().toInt();
		int y1 = vecObj.at(indexRedraw).getYmin().toInt();
		int x2 = vecObj.at(indexRedraw).getXmax().toInt();
		int y2 = vecObj.at(indexRedraw).getYmax().toInt();
		pp.drawRect(x1, y1, x2 - x1, y2 - y1);
		update();
	}
}

QSize PaintArea::getImageSize()
{
	return image.size();
}
void PaintArea::clearAllBox()
{
	emit(clearAll());
}
void PaintArea::paintEvent(QPaintEvent*event)
{

	QPainter painter(this);
	painter.drawImage(0, 0, image);
	if (isDrawing == true)
	{

		painter.drawImage(0, 0, tmpImage);
	}

}

void PaintArea::mouseMoveEvent(QMouseEvent* event)
{
	QString str = "(X:" + QString::number(event->pos().x()) + ",Y:" + QString::number(event->pos().y()) + ")";
	posLabel->setText(str);
	QToolTip::showText(mapToGlobal(event->pos()), str);//显示鼠标位置

	if (event->buttons()&Qt::LeftButton)//如果鼠标左键按着的同时移动鼠标
	{
		tmpImage = image;
		endPoint = event->pos();//获得鼠标指针的当前坐标作为终点坐标
		vecPoint.push_back(endPoint);
		paint(tmpImage);//绘制图形
	}

}

void PaintArea::mousePressEvent(QMouseEvent* event)
{

	if (event->button() == Qt::LeftButton)
	{
		isDrawing = true;
		startPoint = event->pos();

		vecPoint.push_back(startPoint);
	}

}

void PaintArea::mouseReleaseEvent(QMouseEvent* event)
{
	if (event->button() == Qt::LeftButton)//如果鼠标左键释放
	{

		endPoint = event->pos();
		if (event->pos().x() > image.width())
		{
			endPoint.setX(image.width() - 1);//-1的目的是为了看清画出框的轮廓
		}
		if (event->pos().y() > image.height())
		{
			endPoint.setY(image.height() - 1);
		}
		vecPoint.push_back(endPoint);

		paint(tmpImage);//先画在tmpImage上面确定之后再画在image上面

		if (vecPoint.front() != vecPoint.back() && vecPoint.front().x() < vecPoint.back().x() && vecPoint.front().y() < vecPoint.back().y() && vecPoint.front().x() < image.width() && vecPoint.front().y() < image.height())
		{
			info->setStartPointX(QString::number(vecPoint.front().x()));
			info->setStartPointY(QString::number(vecPoint.front().y()));
			info->setEndPointX(QString::number(vecPoint.back().x()));
			info->setEndPointY(QString::number(vecPoint.back().y()));
			info->resetComboBox();
			int rec = info->exec();

			//判断如果鼠标不在图像上点击则不弹出对话框

			if (rec == QDialog::Accepted)
			{
				tmpObj.setName(info->getObjName());
				tmpObj.setPose(info->getObjPose());
				tmpObj.setTruncated(info->getTruncated());
				tmpObj.setDifficult(info->getDifficult());
				tmpObj.setStartPointX(info->getStartPointX());
				tmpObj.setStartPointY(info->getStartPointY());
				tmpObj.setEndPointX(info->getEndPointX());
				tmpObj.setEndPointY(info->getEndPointY());
				vecObj.push_back(tmpObj);

				paint(image);
				isDrawing = false;

			}
			else//reject
			{
				QMessageBox msgBox;
				msgBox.setText("The change will not be modified!");
				msgBox.exec();

				isDrawing = false;
			}

		}

		vecPoint.clear();
	}
}

void PaintArea::paint(QImage &image)
{
	QPainter pp(&image);
	pp.setPen(Qt::red);
	pp.drawRect(vecPoint.front().x(), vecPoint.front().y(), vecPoint.back().x() - vecPoint.front().x(), vecPoint.back().y() - vecPoint.front().y());
	update();


}


void PaintArea::emitDelete()
{
	emit sigDeleteItem(currentPos);
	currentPos = QPoint(0, 0);
}

void PaintArea::deleteItem(QPoint cur)
{

	QVector<ObjStorage> selectedObj;
	selectedObj.clear();
	for (int index = 0; index < vecObj.count(); index++)
	{
		int x1 = vecObj.at(index).getXmin().toInt();
		int y1 = vecObj.at(index).getYmin().toInt();
		int x2 = vecObj.at(index).getXmax().toInt();
		int y2 = vecObj.at(index).getYmax().toInt();

		if (cur.x() >= x1&&cur.x() <= x2&&cur.y() >= y1&&cur.y() <= y2)
		{
			selectedObj.push_back(vecObj.at(index));
		}
	}


	if (selectedObj.size() == 1)
	{
		QPainter pp;
		pp.begin(&image);
		pp.setPen(Qt::black);
		int x1 = selectedObj.at(0).getXmin().toInt();
		int y1 = selectedObj.at(0).getYmin().toInt();
		int x2 = selectedObj.at(0).getXmax().toInt();
		int y2 = selectedObj.at(0).getYmax().toInt();
		pp.drawRect(x1, y1, x2 - x1, y2 - y1);
		pp.end();
		update();

		/*QMessageBox msg;
		msg.setText("Delete info.");
		msg.setInformativeText("Delete or not?");
		msg.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
		msg.setDefaultButton(QMessageBox::No);
		int ret = msg.exec();*/
		//如果只有一个则直接删除
		int ret = QMessageBox::Yes;
		switch (ret) {
		case QMessageBox::Yes:
		{
				// Yes was clicked					
				QVector<ObjStorage>::Iterator it = vecObj.begin();
				while (it != vecObj.end())
				{
					if ((*it).getXmin() == selectedObj.at(0).getXmin() && (*it).getYmin() == selectedObj.at(0).getYmin() && (*it).getXmax() == selectedObj.at(0).getXmax() && (*it).getYmax() == selectedObj.at(0).getYmax()) {
						it = vecObj.erase(it);
					}
					else {
						++it;
					}
				}
				selectedObj.clear();
				reDrawView();

				break;

		}
		case QMessageBox::No:
			// No was clicked
			selectedObj.clear();
			reDrawView();
			break;
		default:
			// should never be reached
			break;
		}

	}
	else
	{
		for (int itmp = 0; itmp < selectedObj.count(); itmp++)
		{
			QPainter pp;
			pp.begin(&image);
			pp.setPen(Qt::black);
			int x1 = selectedObj.at(itmp).getXmin().toInt();
			int y1 = selectedObj.at(itmp).getYmin().toInt();
			int x2 = selectedObj.at(itmp).getXmax().toInt();
			int y2 = selectedObj.at(itmp).getYmax().toInt();
			pp.drawRect(x1, y1, x2 - x1, y2 - y1);
			pp.end();
			update();

			QMessageBox msg;
			msg.setText("Delete info.");
			msg.setInformativeText("Delete or not?");
			msg.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
			msg.setDefaultButton(QMessageBox::No);
			int ret = msg.exec();
			switch (ret) {
			case QMessageBox::Yes:
			{
									 // Yes was clicked					
									 QVector<ObjStorage>::Iterator it = vecObj.begin();
									 while (it != vecObj.end())
									 {
										 if ((*it).getXmin() == selectedObj.at(itmp).getXmin() && (*it).getYmin() == selectedObj.at(itmp).getYmin() && (*it).getXmax() == selectedObj.at(itmp).getXmax() && (*it).getYmax() == selectedObj.at(itmp).getYmax()) {
											 it = vecObj.erase(it);
										 }
										 else {
											 ++it;
										 }
									 }
									 reDrawView();
									 break;

			}
			case QMessageBox::No:
				// No was clicked
				//selectedObj.removeAt(itmp);
				reDrawView();
				break;
			default:
				// should never be reached
				break;
			}

		}
	}


}

void PaintArea::clearAll()
{
	vecObj.clear();
	reDrawView();
	update();
}
