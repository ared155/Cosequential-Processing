#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "insertStud.h"

//#include "coseq.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_exitButton_clicked()
{
    this->close();
}

void MainWindow::on_insertButton_clicked()
{
//    insertMenu newMenu;
//    newMenu.showFullScreen();

    insertMenuWindow = new insertMenu(this);
    insertMenuWindow->show();
}


void MainWindow::on_coseqMatching_clicked()
{
//    coseq obj;
//    obj.match();
    coseqMenuWindow = new coseqoutput(this);
    coseqMenuWindow->show();
}

