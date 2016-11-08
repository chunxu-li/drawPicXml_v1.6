#pragma once
#include <QString>
class ObjStorage
{
public:
	ObjStorage();
    QString getName()const;
	QString getPose()const;
	QString getTruncated()const;
	QString getDifficult()const;
	QString getXmin()const;
	QString getYmin()const;
	QString getXmax()const;
	QString getYmax()const;

	void setName(const QString &name);
	void setPose(const QString &pose);
	void setTruncated(const QString &truncated);
	void setDifficult(const QString &difficult);
	void setStartPointX(const QString &startPointX);
	void setStartPointY(const QString &startPointY);
	void setEndPointX(const QString &endPointX);
	void setEndPointY(const QString &endPointY);
	bool operator==(const ObjStorage &rhl);
	/*bool operator==(const ObjStorage &rhl)
	{
		return this->xmin == rhl.xmin&&this->xmax == rhl.xmax&&this->ymin == rhl.ymin&&this->ymax == rhl.ymax;

	}*/
	~ObjStorage();
private:
    QString name;
    QString pose;
    QString truncated;
    QString difficult;
    QString xmin;
    QString ymin;
    QString xmax;
    QString ymax;


};

