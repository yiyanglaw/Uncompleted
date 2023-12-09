#include "tableview.h"
#include "ui_tableview.h"
#include "mainwindow.h"
TableView::TableView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TableView)
{
    ui->setupUi(this);

    MainWindow log;
    log.openconnection();
    QSqlQueryModel * model= new QSqlQueryModel();
    QSqlQuery * qry = new QSqlQuery(log.mydb);
    qry->prepare("select ID,Name,Address,Mobile,price,QTY from Inventory");
    qry->exec();
    model->setQuery(*qry);
    ui->tableView->setModel(model);
    log.closeconnection();
}

TableView::~TableView()
{
    delete ui;
}
