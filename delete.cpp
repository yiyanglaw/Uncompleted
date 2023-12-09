#include "delete.h"
#include "ui_delete.h"
#include "mainwindow.h"
Delete::Delete(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Delete)
{
    ui->setupUi(this);
}

Delete::~Delete()
{
    delete ui;
}

void Delete::on_getdata_2_clicked()
{
    QString id=ui->lineEdit_id_2->text();

    MainWindow  log;
    bool ok=log.openconnection();
    if(!ok)QMessageBox::critical(this,"error","Failed to open database");

    QSqlQuery qry;
    int flag=1;
    qry.prepare("select * from Inventory where ID='"+id+"'");
    if(qry.exec()){
        while(qry.next()){
            flag=0;
            ui->lineEdit_name_2->setText(qry.value(1).toString());
            ui->lineEdit_QTY_2->setText(qry.value(2).toString());
            ui->lineEdit_price_2->setText(qry.value(3).toString());
            ui->lineEdit_mobile_2->setText(qry.value(4).toString());
            ui->lineEdit_address_2->setText(qry.value(5).toString());
        }
        if(flag){
            ui->lineEdit_name_2->setText(" ");
            ui->lineEdit_QTY_2->setText(" ");
            ui->lineEdit_price_2->setText(" ");
            ui->lineEdit_mobile_2->setText(" ");
            ui->lineEdit_address_2->setText(" ");
            QMessageBox::information(this,"NO RECORD FOUND","NO Such Record Found");
        }
    }else
        QMessageBox::critical(this,"Error",qry.lastError().text());

    log.closeconnection();
}

void Delete::on_pushButton_3_clicked()
{
    QString id=ui->lineEdit_id_2->text();
    MainWindow  log;
    bool ok=log.openconnection();
    if(!ok)QMessageBox::critical(this,"error","Failed to open database");

    QSqlQuery qry;
    qry.prepare("Delete from Inventory where ID='"+id+"'");
    if(qry.exec()){
        QMessageBox::information(this,"Delete","Information Deleted");
    }else
        QMessageBox::critical(this,"Error",qry.lastError().text());
    log.closeconnection();
}
