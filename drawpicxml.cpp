#include "drawpicxml.h"
#include <QFileDialog>
#include <QFileInfo>
#include <QMessageBox>
#include <QDomDocument>
#include <QTextStream>
#include <QtWidgets/QListWidgetItem>
//#include <QDebug>

const int W_ICONSIZE = 96; //图片宽度
const int H_ICONSIZE = 96; //图片高度
const int H_ITEMSIZE = 110; //单元项高度(因为单元项既包括图片又包括文本)


drawPicXml::drawPicXml(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

    setWindowTitle("Draw Picture");
    setWindowIcon(QIcon(":/icon/title"));
	ui.actionOpen->setIcon(QIcon(":/icon/open"));
	ui.actionOpenFiles->setIcon(QIcon(":/icon/open"));
	ui.actionListModel->setIcon(QIcon(":/icon/list2"));
	ui.actionIconModel->setIcon(QIcon(":/icon/listicon"));
	ui.actionOriginal->setIcon(QIcon(":/icon/listicon2"));
	ui.menuListSize->setIcon(QIcon(":/icon/list"));


	ui.actionExit->setIcon(QIcon(":/icon/exit"));
	ui.actionHelp->setIcon(QIcon(":/icon/help"));
	ui.actionGenerate_XML->setIcon(QIcon(":/icon/generate"));
	ui.actionProcess_pictures->setIcon(QIcon(":/icon/process"));
	ui.actionShow_Dock->setIcon(QIcon(":/icon/showdock"));
	ui.actionSourse_code->setIcon(QIcon(":/icon/sourcecode"));
	ui.mainToolBar->addAction(ui.actionOpenFiles);
	//ui.mainToolBar->addAction(ui.actionOpen);
	ui.mainToolBar->addAction(ui.actionGenerate_XML);
	ui.mainToolBar->addAction(ui.actionProcess_pictures);
	ui.mainToolBar->addAction(ui.actionShow_Dock);

	ui.mainToolBar->addAction(ui.actionListModel);
	ui.mainToolBar->addAction(ui.actionIconModel);
	ui.mainToolBar->addAction(ui.actionOriginal);

	ui.mainToolBar->addAction(ui.actionClearBindingBox);
	ui.mainToolBar->addAction(ui.actionExit);
	ui.statusBar->showMessage(tr("Welcome"));
	
	area = new PaintArea;
	ui.statusBar->addPermanentWidget(area->posLabel);
	
    //resize(700,600);
    
    scrollArea= new QScrollArea();
    process=new processimage();


    //dockNameList->fileList
    fileList = new QListWidget;
    fileList->setIconSize(QSize(W_ICONSIZE, H_ICONSIZE));
    fileList->setResizeMode(QListView::Adjust);
    //设置QListWidget的显示模式
    fileList->setViewMode(QListView::IconMode);
    //设置QListWidget中的单元项不可被拖动
    fileList->setMovement(QListView::Static);
    //设置QListWidget中的单元项的间距
    fileList->setSpacing(10);


	dockNameList = new QDockWidget(this);
	dockNameList->setObjectName(QStringLiteral("dockNameList"));
	dockNameList->setWidget(fileList);
	this->addDockWidget(static_cast<Qt::DockWidgetArea>(2), dockNameList);
	dockNameList->setWindowTitle(QApplication::translate("drawPicXmlClass", "FileList", 0));

    scrollArea->setBackgroundRole(QPalette::Dark);
    scrollArea->setWidget(area);
	scrollArea->widget()->setMinimumSize(800, 600);
    setCentralWidget(scrollArea);

    //连接信号槽
    connect(fileList,SIGNAL(itemClicked(QListWidgetItem*)),this,SLOT(Slot_ItemClicked(QListWidgetItem*)));
}

drawPicXml::~drawPicXml()
{

}

void drawPicXml::on_actionOpen_triggered()//打开
{
	QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), QDir::currentPath(), tr("Image Files(*.jpg;*.png;*.bmp;*jpeg)"));
	if (!fileName.isEmpty())
	{
		area->image.load(fileName);
		if (area->image.isNull())
		{
			QMessageBox::information(this, tr("Image Viewer"), tr("Cannot load %1.").arg(fileName));
			return;
		}
		QFileInfo fileInfo = QFileInfo(fileName);
		ui.labelFileName_2->setText(fileInfo.fileName());
		ui.labelFlickrid_2->setText("autox4u");
		ui.labelOwnerName_2->setText("Perry Aidelbaum");
		ui.labelDepth_2->setText("3");
		ui.labelWidth_2->setText(QString::number(area->image.width()));
		ui.labelHeight_2->setText(QString::number((area->image.height())));
		scrollArea->widget()->setMinimumSize(area->image.width(), area->image.height());
		area->clearVec();
	}
}

void drawPicXml::on_actionClearBindingBox_triggered()
{
    QString fileName = ui.labelFileName_2->text ();
    fileName = fileName.split (".").at (0);
	fileName = "./xmlResult/" + fileName;
    fileName += ".xml";
    QFile file(fileName);
    if (file.exists())
    {
        //设置背景为红色
        fileList->currentItem ()->setBackgroundColor (QColor(Qt::white));
		area->clearAllBox();		
        file.remove ();
    }
}

void drawPicXml::on_actionOpenFiles_triggered()
{
    
	fileNames = QFileDialog::getOpenFileNames(this, tr("Open Files"), QDir::currentPath(), tr("Image Files(*.jpg;*.png;*.bmp;*.jpeg)"));
    //fileList->addItems(fileNames);
	if (fileNames.count()>0)
	{
		fileList->clear();
		for (int index = 0; index < fileNames.count(); index++)
		{
			//获得图片路径
			QString strPath = fileNames.at(index);
			//生成图像objPixmap
			QPixmap objPixmap(strPath);

			QFileInfo fi = QFileInfo(strPath);

			//生成QListWidgetItem对象(注意：其Icon图像进行了伸缩[96*96])---scaled函数
			QListWidgetItem *pItem = new QListWidgetItem(QIcon(objPixmap.scaled(QSize(W_ICONSIZE, H_ICONSIZE))), fi.baseName());
			//设置单元项的宽度和高度
			pItem->setSizeHint(QSize(W_ICONSIZE, H_ITEMSIZE));
			fileList->insertItem(index, pItem);

			QString xmlName = "./xmlResult/" + fi.baseName();
			xmlName += ".xml";

			QFile file(xmlName);
			if (file.exists())
			{
				//设置背景为红色
				pItem->setBackgroundColor(QColor(Qt::red));
			}

		}
	}
    
}
void drawPicXml::Slot_ItemClicked(QListWidgetItem *item)
{
//    QRgb backColor=qRgb(255,255,255);//画布背景颜色用白色
//    area->image.fill(backColor);
    int nRowIndex = fileList->row(item);
    if(!item)
    {
        return;
    }

	area->openImage(fileNames.at(nRowIndex));
	scrollArea->widget()->resize(area->getImageSize());//获得图片的大小，然后更改 scrollArea 的大小
	
    if (area->image.isNull())
    {
        QMessageBox::information(this, tr("Image Viewer"), tr("Cannot load %1.").arg(fileNames.at(nRowIndex)));
        return;
    }

    QFileInfo fileInfo = QFileInfo(fileNames.at(nRowIndex));
    ui.labelFileName_2->setText(fileInfo.fileName());
    ui.labelFlickrid_2->setText("autox4u");
    ui.labelOwnerName_2->setText("Perry Aidelbaum");
    ui.labelDepth_2->setText("3");
    ui.labelWidth_2->setText(QString::number(area->image.width()));
    ui.labelHeight_2->setText(QString::number((area->image.height())));
    scrollArea->widget()->setMinimumSize(area->image.width(), area->image.height());
    area->clearVec();


    if (item->background() == QColor(Qt::red))
    {

        /*QMessageBox msgBox;
        msgBox.setText("The xml has already been generated!");
        msgBox.setInformativeText("Click Ok to check or Discard to remark?");
        msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Discard);
        msgBox.setDefaultButton(QMessageBox::Ok);
        int ret = msgBox.exec();*/
		//默认返回值为QMessageBox::Ok
		int ret = QMessageBox::Ok;
        switch (ret) {
        case QMessageBox::Ok:
        {
            // Save was clicked
            QVector<ObjStorage>vecReadXml;//存储从xml中读出的信息
            vecReadXml.clear();//清空object
            ObjStorage readXml;

            QString xmlName = "./xmlResult/" + fileInfo.baseName();
            xmlName += ".xml";


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
             file.close();

            QPainter painter;
            painter.begin(&area->image);
            painter.setPen(Qt::red);
            for (int n = 0; n < vecReadXml.count(); n++)
            {
                painter.drawRect(vecReadXml.at(n).getXmin().toInt(), vecReadXml.at(n).getYmin().toInt(), vecReadXml.at(n).getXmax().toInt() - vecReadXml.at(n).getXmin().toInt(), vecReadXml.at(n).getYmax().toInt() - vecReadXml.at(n).getYmin().toInt());
            }
            painter.end();
            vecReadXml.clear();
            update();
           break;
        }

        case QMessageBox::Discard:
            // Don't Save was clicked
            break;
        default:
            // should never be reached
            break;
        }

    }



}

void drawPicXml::on_actionExit_triggered()//退出
{
	this->close();
}

void drawPicXml::on_actionProcess_pictures_triggered()//批量处理图片
{
	process->show();
}

void drawPicXml::on_actionGenerate_XML_triggered()//生成XML
{
	//creater root
	QDomDocument doc;
	QDomElement root = doc.createElement(QString("annotation"));
	doc.appendChild(root);


	//folder
	QDomElement folder = doc.createElement("folder");
	root.appendChild(folder);

	QDomText folderText = doc.createTextNode(ui.comboBoxFolder->currentText());
	folder.appendChild(folderText);


	//filename
	QDomElement filename = doc.createElement("filename");
	root.appendChild(filename);
	QDomText filenameText = doc.createTextNode(ui.labelFileName_2->text());
	filename.appendChild(filenameText);


	//source
	QDomElement source = doc.createElement("source");
	root.appendChild(source);


	//source.database
	QDomElement database = doc.createElement("database");
	source.appendChild(database);
	QDomText databaseText = doc.createTextNode(ui.comboBoxDataBase->currentText());
	database.appendChild(databaseText);


	//source.annotation
	QDomElement annotation = doc.createElement("annotation");
	source.appendChild(annotation);
	QDomText annotationText = doc.createTextNode("PASCAL" + ui.comboBoxFolder->currentText());
	annotation.appendChild(annotationText);


	//source.image
	QDomElement image = doc.createElement("image");
	source.appendChild(image);
	QDomText imageText = doc.createTextNode("flickr");
	image.appendChild(imageText);


	//source.flickrid
	QDomElement sourceFlickrid = doc.createElement("flickrid");
	source.appendChild(sourceFlickrid);
	QDomText sourceFlickridText = doc.createTextNode("325443404");
	sourceFlickrid.appendChild(sourceFlickridText);

	//owner
	QDomElement owner = doc.createElement("owner");
	root.appendChild(owner);

	//owner.flickrid
	QDomElement ownerFlickrid = doc.createElement("flickrid");
	QDomText ownerFlickridText = doc.createTextNode(ui.labelFlickrid_2->text());
	ownerFlickrid.appendChild(ownerFlickridText);
	owner.appendChild(ownerFlickrid);

	//owner.name
	QDomElement ownerName = doc.createElement("name");
	QDomText ownerNameText = doc.createTextNode(ui.labelOwnerName_2->text());
	owner.appendChild(ownerName);
	ownerName.appendChild(ownerNameText);

	//size
	QDomElement size = doc.createElement("size");
	root.appendChild(size);

	//size.width
	QDomElement sizeWidth = doc.createElement("width");
	QDomText sizeWidthText = doc.createTextNode(ui.labelWidth_2->text());
	sizeWidth.appendChild(sizeWidthText);
	size.appendChild(sizeWidth);

	//size.height
	QDomElement sizeHeight = doc.createElement("height");
	QDomText sizeHeightText = doc.createTextNode(ui.labelHeight_2->text());
	sizeHeight.appendChild(sizeHeightText);
	size.appendChild(sizeHeight);

	//size.depth
	QDomElement sizeDepth = doc.createElement("depth");
	QDomText sizeDepthText = doc.createTextNode(ui.labelDepth_2->text());
	sizeDepth.appendChild(sizeDepthText);
	size.appendChild(sizeDepth);

	//segmented
	QDomElement segmented = doc.createElement("segmented");
	QDomText segmentedText = doc.createTextNode("0");
	segmented.appendChild(segmentedText);
	root.appendChild(segmented);


    QVector<ObjStorage> tmpVecObj=area->getVecObj();
    for (size_t i = 0; i < tmpVecObj.count(); i++)
	{
		//object1
		QDomElement object1 = doc.createElement("object");
		root.appendChild(object1);

		//object1.name
		QDomElement object1Name = doc.createElement("name");
		QDomText object1NameText = doc.createTextNode(tmpVecObj.at(i).getName());
		object1Name.appendChild(object1NameText);
		object1.appendChild(object1Name);

		//objecdt1.pose
		QDomElement object1Pose = doc.createElement("pose");
        QDomText object1PoseText = doc.createTextNode(tmpVecObj.at(i).getPose());
		object1Pose.appendChild(object1PoseText);
		object1.appendChild(object1Pose);

		//object1.truncated
		QDomElement object1Truncated = doc.createElement("truncated");
        QDomText object1TruncatedText = doc.createTextNode(tmpVecObj.at(i).getTruncated());
		object1.appendChild(object1Truncated);
		object1Truncated.appendChild(object1TruncatedText);

		//object1.difficult
		QDomElement object1Difficult = doc.createElement("difficult");
        QDomText object1DifficultText = doc.createTextNode(area->getVecObj().at(i).getDifficult());
		object1.appendChild(object1Difficult);
		object1Difficult.appendChild(object1DifficultText);

		//object1.bndbox
		QDomElement object1Bndbox = doc.createElement("bndbox");
		object1.appendChild(object1Bndbox);

		//object1.bndbox.xmin
		QDomElement object1BndboxXmin = doc.createElement("xmin");
        QDomText object1BndboxXminText = doc.createTextNode(tmpVecObj.at(i).getXmin());
		object1Bndbox.appendChild(object1BndboxXmin);
		object1BndboxXmin.appendChild(object1BndboxXminText);

		//object1.bndbox.ymin
		QDomElement object1BndboxYmin = doc.createElement("ymin");
        QDomText object1BndboxYminText = doc.createTextNode(tmpVecObj.at(i).getYmin());
		object1Bndbox.appendChild(object1BndboxYmin);
		object1BndboxYmin.appendChild(object1BndboxYminText);

		//object1.bndbox.xmax
		QDomElement object1BndboxXmax = doc.createElement("xmax");
        QDomText object1BndboxXmaxText = doc.createTextNode(tmpVecObj.at(i).getXmax());
		object1Bndbox.appendChild(object1BndboxXmax);
		object1BndboxXmax.appendChild(object1BndboxXmaxText);

		//object1.bndbox.ymax
		QDomElement object1BndboxYmax = doc.createElement("ymax");
        QDomText object1BndboxYmaxText = doc.createTextNode(tmpVecObj.at(i).getYmax());
		object1Bndbox.appendChild(object1BndboxYmax);
		object1BndboxYmax.appendChild(object1BndboxYmaxText);
	}
	QDir d;
	d.mkpath("./xmlResult");
	QString saveName = ui.labelFileName_2->text().split(".")[0] + ".xml";
	QFile file("./xmlResult/" + saveName);
	if (!file.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text))
		return;
	QTextStream out(&file);
	out.setCodec("UTF-8");
	doc.save(out, 4, QDomNode::EncodingFromTextStream);//void QDomNode::save(QTextStream & stream, int indent, EncodingPolicy encodingPolicy = QDomNode::EncodingFromDocument) const
	file.close();
	QMessageBox msgBox;
	msgBox.setText("The xml has been modified.");
	msgBox.exec();
	area->clearVec();
    fileList->currentItem()->setBackgroundColor(QColor(Qt::red));//设置背景为红色

}

void drawPicXml::on_actionSourse_code_triggered()//源代码
{
    QMessageBox msgBox;
        msgBox.setText("Based on Qt 5.5.0 (MSVC 2013, 32 bit) ver1.3(opensource)\nBuilt on Sep 10 2015 01:56:58 ");
        msgBox.setInformativeText("chunxuxiao@gmail.com");
        msgBox.exec();
}

void drawPicXml::on_actionHelp_triggered()//帮助说明
{
    QMessageBox msgBox;
    msgBox.setText("There are still so many bugs,but i don't want to debug anymore! ");
    msgBox.setInformativeText("May be FangHao can help you!");
    msgBox.exec();
}

void drawPicXml::on_actionShow_Dock_triggered()//显示daock
{
    
    if (ui.dock->isVisible()||dockNameList->isVisible())
	{
		ui.dock->setVisible(false);
        dockNameList->setVisible(false);
	}
	else
	{
		ui.dock->setVisible(true);
        dockNameList->setVisible(true);

	}
	

}


void drawPicXml::on_actionChangeListSize_triggered()
{
    fileList->setViewMode(QListView::ListMode);
    fileList->setIconSize(QSize(W_ICONSIZE*0.3, H_ICONSIZE*0.3));
    fileList->setSpacing(1);
    for(int index = 0; index < fileList->count(); index++)
    {
        fileList->item(index)->setSizeHint(QSize(W_ICONSIZE*0.3,H_ITEMSIZE*0.3));
        update();

    }
}

void drawPicXml::on_actionListModel_triggered()
{
    fileList->setViewMode(QListView::ListMode);
    fileList->setIconSize(QSize(W_ICONSIZE*0.3, H_ICONSIZE*0.3));
    fileList->setSpacing(1);
    for(int index = 0; index < fileList->count(); index++)
    {
        fileList->item(index)->setSizeHint(QSize(W_ICONSIZE*0.3,H_ITEMSIZE*0.3));
        update();

    }

}

void drawPicXml::on_actionIconModel_triggered()
{
    fileList->setViewMode(QListView::ListMode);
    fileList->setIconSize(QSize(W_ICONSIZE, H_ICONSIZE));
    fileList->setSpacing(3);
    for(int index = 0; index < fileList->count(); index++)
    {
        fileList->item(index)->setSizeHint(QSize(W_ICONSIZE,H_ITEMSIZE));
        update();

    }

}

void drawPicXml::on_actionOriginal_triggered()
{
    fileList->setViewMode(QListView::IconMode);
    fileList->setIconSize(QSize(W_ICONSIZE, H_ICONSIZE));
    fileList->setSpacing(10);
    for(int index = 0; index < fileList->count(); index++)
    {
        fileList->item(index)->setSizeHint(QSize(W_ICONSIZE,H_ITEMSIZE));
        update();

    }

}
