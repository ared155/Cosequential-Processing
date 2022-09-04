#include "coseqdisplay.h"
#include "ui_cosequential.h"

cosequential::cosequential(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::cosequential)
{
    ui->setupUi(this);
}

cosequential::~cosequential()
{
    delete ui;
}
