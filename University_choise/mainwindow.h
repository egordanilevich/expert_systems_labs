#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "question.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr,question *in_head=nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_restart_clicked();

    void on_pushButton_1_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    question *head,*ptr;
};
#endif // MAINWINDOW_H
