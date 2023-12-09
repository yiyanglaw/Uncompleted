#include "addinfo.h"
#include "ui_addinfo.h"

AddInfo::AddInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddInfo)
{
    ui->setupUi(this);
}

AddInfo::~AddInfo()
{

    delete ui;
}

void AddInfo::on_pushButton_clicked()
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
    qry.prepare("insert into Inventory(ID,Name,QTY,price,Mobile,Address) values ('"+id+"','"+name+"','"+QTY+"','"+price+"','"+mobile+"','"+address+"')");
    if(qry.exec()){
        QMessageBox::information(this,"saved...","information suQTYesfully saved...");
    }else{
        QMessageBox::critical(this,"error",qry.lastError().text());
    }
    log.closeconnection();
}
