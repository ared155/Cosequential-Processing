#include "deletemenu.h"
#include "ui_deletemenu.h"

deletemenu::deletemenu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::deletemenu)
{
    ui->setupUi(this);
}

deletemenu::~deletemenu()
{
    delete ui;
}
