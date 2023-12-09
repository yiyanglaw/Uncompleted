#include "retrive.h"
#include "ui_retrive.h"
#include "mainwindow.h"
retrive::retrive(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::retrive)
{
    ui->setupUi(this);
}

retrive::~retrive()
{
    delete ui;
}

void retrive::on_getdata_3_clicked()
{
    QString id=ui->lineEdit_id->text();

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
            ui->lineEdit_name_2->setText(qry.value(1).toString());
            ui->lineEdit_QTY_2->setText(qry.value(2).toString());
            ui->lineEdit_price_2->setText(qry.value(3).toString());
            ui->lineEdit_mobile_2->setText(qry.value(4).toString());
            ui->lineEdit_address_2->setText(qry.value(5).toString());
            QMessageBox::information(this,"NO RECORD FOUND","NO Such Record Found");
        }
    }else
        QMessageBox::critical(this,"Error",qry.lastError().text());

    log.closeconnection();
}
