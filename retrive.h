#ifndef RETRIVE_H
#define RETRIVE_H

#include <QDialog>

namespace Ui {
class retrive;
}

class retrive : public QDialog
{
    Q_OBJECT

public:
    explicit retrive(QWidget *parent = nullptr);
    ~retrive();

private slots:
    void on_getdata_3_clicked();



private:
    Ui::retrive *ui;
};

#endif // RETRIVE_H
