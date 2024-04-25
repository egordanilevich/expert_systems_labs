#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent, question *in_head)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    head = in_head;
    ptr = head;
    ui->textBrowser->append(ptr->text);
    if(!ptr->answ){
        ui->textBrowser->append(ptr->ans1_t);
        ui->textBrowser->append(ptr->ans2_t);
    }
    ui->textBrowser->append("");
    ui->textBrowser->append("");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_restart_clicked()
{
    ptr = head;
    ui->textBrowser->clear();
    ui->textBrowser->append(ptr->text);
    if(!ptr->answ){
        ui->textBrowser->append(ptr->ans1_t);
        ui->textBrowser->append(ptr->ans2_t);
    }
    ui->textBrowser->append("");
    ui->textBrowser->append("");
}


void MainWindow::on_pushButton_1_clicked()
{
    if(ptr->ans1 == nullptr){
        return;
    }
    ptr = ptr->ans1;
    ui->textBrowser->append(ptr->text);
    if(!ptr->answ){
        ui->textBrowser->append(ptr->ans1_t);
        ui->textBrowser->append(ptr->ans2_t);
    }
    ui->textBrowser->append("");
    ui->textBrowser->append("");
}


void MainWindow::on_pushButton_2_clicked()
{
    if(ptr->ans2 == nullptr){
        return;
    }
    ptr = ptr->ans2;
    ui->textBrowser->append(ptr->text);
    if(!ptr->answ){
        ui->textBrowser->append(ptr->ans1_t);
        ui->textBrowser->append(ptr->ans2_t);
    }
    ui->textBrowser->append("");
    ui->textBrowser->append("");
}

