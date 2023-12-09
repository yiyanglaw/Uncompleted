#include "update.h"
#include "ui_update.h"
#include "mainwindow.h"
Update::Update(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Update)
{
    ui->setupUi(this);
}

Update::~Update()
{
    delete ui;
}

void Update::on_getdata__clicked()
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
            ui->lineEdit_name->setText(qry.value(1).toString());
            ui->lineEdit_QTY->setText(qry.value(2).toString());
            ui->lineEdit_price->setText(qry.value(3).toString());
            ui->lineEdit_mobile->setText(qry.value(4).toString());
            ui->lineEdit_address->setText(qry.value(5).toString());
        }
        if(flag){
            ui->lineEdit_name->setText(qry.value(1).toString());
            ui->lineEdit_QTY->setText(qry.value(2).toString());
            ui->lineEdit_price->setText(qry.value(3).toString());
            ui->lineEdit_mobile->setText(qry.value(4).toString());
            ui->lineEdit_address->setText(qry.value(5).toString());
            QMessageBox::information(this,"NO RECORD FOUND","NO Such Record Found");
        }
    }else
        QMessageBox::critical(this,"Error",qry.lastError().text());

    log.closeconnection();
}

void Update::on_pushButton_2_clicked()
{
    QString id,name,address,mobile,price,QTY;
    id= ui->lineEdit_id->text();
    name= ui->lineEdit_name->text();
    address= ui->lineEdit_address->text();
    mobile= ui->lineEdit_mobile->text();
    price= ui->lineEdit_price->text();
    QTY= ui->lineEdit_QTY->text();
    MainWindow  log;
    if(!log.openconnection())QMessageBox::critical(this,"error","Failed to open database");

    QSqlQuery qry;
    qry.prepare("update Inventory set Name='"+name+"',QTY='"+QTY+"',price='"+price+"',Mobile='"+mobile+"',Address='"+address+"' where ID='"+id+"' ");
    if(qry.exec()){
        QMessageBox::information(this,"Updated...","information suQTYesfully Updated...");
    }else{
        QMessageBox::critical(this,"error",qry.lastError().text());
    }
    log.closeconnection();
}
