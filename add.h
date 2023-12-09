#ifndef ADDINFO_H
#define ADDINFO_H

#include <QDialog>
#include <mainwindow.h>
namespace Ui {
class AddInfo;
}

class AddInfo : public QDialog
{
    Q_OBJECT

public:
    explicit AddInfo(QWidget *parent = nullptr);
    ~AddInfo();

private slots:
    void on_pushButton_clicked();

private:
    Ui::AddInfo *ui;
};

#endif // ADDINFO_H
