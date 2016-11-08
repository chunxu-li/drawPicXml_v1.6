#include "ObjStorage.h"


ObjStorage::ObjStorage()
{
}


ObjStorage::~ObjStorage()
{
}


QString ObjStorage::getName()const
{
    return name;
}
QString ObjStorage::getPose()const
{
    return pose;
}
QString ObjStorage::getTruncated()const
{
    return truncated;
}
QString ObjStorage::getDifficult()const
{
    return difficult;
}
QString ObjStorage::getXmin()const
{
    return xmin;
}
QString ObjStorage::getYmin()const
{
    return ymin;
}
QString ObjStorage::getXmax()const
{
    return xmax;
}
QString ObjStorage::getYmax()const
{
    return ymax;
}




void ObjStorage::setName(const QString &name)
{
	this->name = name;
}
void ObjStorage::setPose(const QString &pose)
{
	this->pose = pose;
}
void ObjStorage::setTruncated(const QString &truncated)
{
	this->truncated = truncated;
}
void ObjStorage::setDifficult(const QString &difficult)
{
	this->difficult = difficult;
}
void ObjStorage::setStartPointX(const QString &startPointX)
{
	this->xmin = startPointX;
}
void ObjStorage::setStartPointY(const QString &startPointY)
{
	this->ymin = startPointY;
}
void ObjStorage::setEndPointX(const QString &endPointX)
{
	this->xmax = endPointX;
}
void ObjStorage::setEndPointY(const QString &endPointY)
{
	this->ymax = endPointY;
}

bool ObjStorage::operator==(const ObjStorage &rhl)
{
	return this->xmin.toInt() == rhl.xmin.toInt()&&this->xmax.toInt() == rhl.xmax.toInt()&&this->ymin.toInt() == rhl.ymin.toInt()&&this->ymax.toInt() == rhl.ymax.toInt();
}
