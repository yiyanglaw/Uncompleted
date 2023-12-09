#ifndef TABLEVIEW_H
#define TABLEVIEW_H

#include <QDialog>

namespace Ui {
class TableView;
}

class TableView : public QDialog
{
    Q_OBJECT

public:
    explicit TableView(QWidget *parent = nullptr);
    ~TableView();

private:
    Ui::TableView *ui;
};

#endif // TABLEVIEW_H
