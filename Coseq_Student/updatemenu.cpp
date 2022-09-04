#include "updatemenu.h"
#include "ui_updatemenu.h"

updatemenu::updatemenu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::updatemenu)
{
    ui->setupUi(this);
}

updatemenu::~updatemenu()
{
    delete ui;
}
