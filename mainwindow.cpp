#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    openconnection();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    AddInfo *add= new class AddInfo(this);
    add->setWindowTitle("Add Information");
    add->show();
}

void MainWindow::on_pushButton_retrive_clicked()
{
    retrive *add = new class retrive(this);
    add->setWindowTitle("Search Information");
    add->show();
}

void MainWindow::on_pushButton_2_clicked()
{
    QApplication::quit();
}

void MainWindow::on_pushButton_showAll_clicked()
{
    TableView *tble= new class TableView(this);
    tble->setWindowTitle("List OF INVENTORY");
    tble->show();
}

void MainWindow::on_pushButton_modify_clicked()
{
    Update *upd= new class Update(this);
    upd->setWindowTitle("Update Information...");
    upd->show();
}

void MainWindow::on_pushButton_5_clicked()
{
    Delete *upd= new class Delete(this);
    upd->setWindowTitle("Delete Information...");
    upd->show();
}
