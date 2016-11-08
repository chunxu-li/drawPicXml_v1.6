#ifndef PROCESSIMAGE_H
#define PROCESSIMAGE_H

#include <QMainWindow>
#include "ObjStorage.h"

namespace Ui {
class processimage;
}

class processimage : public QMainWindow
{
    Q_OBJECT

public:
    explicit processimage(QWidget *parent = 0);
    ~processimage();

private slots:
    void on_pushButtonOpen_clicked();

    void on_pushButtonExit_clicked();

private:
    Ui::processimage *ui;
	QVector<ObjStorage>vecReadXml;//�洢��xml�ж�������Ϣ
};

#endif // PROCESSIMAGE_H
