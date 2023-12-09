#ifndef DELETE_H
#define DELETE_H

#include <QDialog>

namespace Ui {
class Delete;
}

class Delete : public QDialog
{
    Q_OBJECT

public:
    explicit Delete(QWidget *parent = nullptr);
    ~Delete();

private slots:
    void on_getdata_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Delete *ui;
};

#endif // DELETE_H
