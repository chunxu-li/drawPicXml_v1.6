#include "processimage.h"

#include "ui_processimage.h"
#include <QDir>
#include <QFileDialog>
#include <QDomDocument>
#include <QPainter>
#include "ObjStorage.h"


processimage::processimage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::processimage)
{
    ui->setupUi(this);
	setWindowTitle("Draw Picture");
	setWindowIcon(QIcon(":/icon/title"));
	ui->progressBar->setValue(0);
}

processimage::~processimage()
{
    delete ui;
}

void processimage::on_pushButtonOpen_clicked()
{
    vecReadXml.clear();//Çå¿Õobject
	QDir d;
	d.mkpath("./xmlPic");
	QStringList nameList = QFileDialog::getOpenFileNames(this, "chose pictures", QDir::currentPath());
	ui->progressBar->setRange(0, nameList.count() - 1);

	for (int m = 0; m < nameList.count(); m++)
	{
		QString str = "The number of picture is " + QString::number(nameList.count()) + "\n" + "Now process " + QString::number(m + 1);
		if (m == nameList.count() - 1)
		{
			str += "\nfinished!";
		}
		ui->label->setText(str);
		ui->progressBar->setValue(m);
		ObjStorage readXml;
		QFileInfo fileInfo = QFileInfo(nameList.at(m));
		QString xmlName = "./xmlResult/" + fileInfo.baseName();
		xmlName += ".xml";

		QString newPicName = "./xmlPic/" + fileInfo.baseName() + ".jpg";


		QFile file(xmlName);
		QDomDocument dom;
		dom.setContent(&file);

		QDomElement root = dom.documentElement();
		QDomNodeList nodelist = root.elementsByTagName("object");
		for (int i = 0; i < nodelist.count(); i++)
		{
			QDomNode node = nodelist.item(i);
			QDomNodeList itemlist = node.childNodes();
			for (int j = 0; j < itemlist.count(); j++)
			{
				QDomNode mynode = itemlist.at(j);
				QString s = mynode.nodeName();
				if (mynode.nodeName() == "name")
				{
					QDomNode mynodeChild = mynode.firstChild();
					readXml.setName(mynodeChild.toText().data());
				}
				else if (mynode.nodeName() == "pose")
				{
					QDomNode mynodeChild = mynode.firstChild();
					readXml.setPose(mynodeChild.toText().data());
					
				}
				else if (mynode.nodeName() == "truncated")
				{
					QDomNode mynodeChild = mynode.firstChild();
					readXml.setTruncated(mynodeChild.toText().data());
				}
				else if (mynode.nodeName() == "difficult")
				{
					QDomNode mynodeChild = mynode.firstChild();
					readXml.setDifficult(mynodeChild.toText().data());
				}
				else if (mynode.nodeName() == "bndbox")
				{
					QDomNodeList bndboxNode = mynode.childNodes();

					for (int k = 0; k < bndboxNode.count(); k++)
					{
						QDomNode bndboxItem = bndboxNode.at(k);
						QString s1 = bndboxItem.nodeName();
						QString s2 = bndboxItem.firstChild().toText().data();
						if (bndboxItem.nodeName() == "xmin")
						{
							readXml.setStartPointX(bndboxItem.firstChild().toText().data());
							QString tmp = bndboxItem.firstChild().toText().data();
						}
						else if (bndboxItem.nodeName() == "ymin")
						{
							readXml.setStartPointY(bndboxItem.firstChild().toText().data());
							QString tmp = bndboxItem.firstChild().toText().data();
						}
						else if (bndboxItem.nodeName() == "xmax")
						{
							readXml.setEndPointX(bndboxItem.firstChild().toText().data());
						}
						else if (bndboxItem.nodeName() == "ymax")
						{
							readXml.setEndPointY(bndboxItem.firstChild().toText().data());
						}
					}

				}

			}
			vecReadXml.push_back(readXml);
		}

		QPixmap image;
		image.load(nameList.at(m));
		QPainter painter;
		painter.begin(&image);
		painter.setPen(Qt::red);
		for (int n = 0; n < vecReadXml.count(); n++)
		{
			painter.drawRect(vecReadXml.at(n).getXmin().toInt(), vecReadXml.at(n).getYmin().toInt(), vecReadXml.at(n).getXmax().toInt() - vecReadXml.at(n).getXmin().toInt(), vecReadXml.at(n).getYmax().toInt() - vecReadXml.at(n).getYmin().toInt());
		}
		image.save(newPicName);
		painter.end();
		vecReadXml.clear();
		file.close();
	}


}

void processimage::on_pushButtonExit_clicked()
{
    this->close();
}
