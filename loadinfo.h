#ifndef LOADINFO_H
#define LOADINFO_H

#include <QDialog>
#include <QLineEdit>

namespace Ui {
class loadInfo;
}

class loadInfo : public QDialog
{
    Q_OBJECT

public:
    explicit loadInfo(QWidget *parent = 0);
    ~loadInfo();
   
    void setStartPointX(const QString &startPointX);
    void setStartPointY(const QString &startPointY);
    void setEndPointX(const QString &endPointX);
    void setEndPointY(const QString &endPointY);

    //reset data
    void resetComboBox();

	QString getObjName();
	QString	getObjPose();
	QString	getTruncated();
	QString	getDifficult();
	QString	getStartPointX();
	QString	getStartPointY();
	QString	getEndPointX();
	QString	getEndPointY();
	void initObj();

private:
    Ui::loadInfo *ui;

};

#endif // LOADINFO_H
