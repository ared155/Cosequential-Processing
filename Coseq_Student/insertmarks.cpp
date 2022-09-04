#include "insertmarks.h"
#include "ui_insertmarks.h"
#include "marksrecord.h"

insertmarks::insertmarks(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::insertmarks)
{
    ui->setupUi(this);
}

insertmarks::~insertmarks()
{
    delete ui;
}

void insertmarks::on_submit_clicked()
{
    QString usn = ui->usnEntry->text();
    MarksRecord obj(usn.toStdString());
    BufferMarks buff;

    int flag = buff.add(obj);

    if(flag==0)
    {
        ui->errorFlag->setText("Duplicate Entry Found!");
    }
    else
    {
        ui->errorFlag->setText("Entry Successfully Done!");
    }

    //reseting fields
    ui->usnEntry->setText("");
}

