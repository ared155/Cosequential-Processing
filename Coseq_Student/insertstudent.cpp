#include "insertstudent.h"
#include "ui_insertstudent.h"
#include "student.h"
#include <QTextStream>

QString status;

insertstudent::insertstudent(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::insertstudent)
{
    ui->setupUi(this);
    status = "f";
}

insertstudent::~insertstudent()
{
    delete ui;
}

void insertstudent::on_submit_clicked()
{
    QTextStream out{stdout};
    //Fetching Data
    QString usn = ui->usnEntry->text();
    QString name = ui->nameEntry->text();
    QString branch = ui->branchEntry->text();

    Student obj(usn.toStdString(), name.toStdString(), branch.toStdString(), status.toStdString());
    Buffer buff;

    int flag = buff.add(obj);
    out<<"\nFlag : "<<flag;

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
    ui->nameEntry->setText("");
    ui->branchEntry->setText("");
    status = "f";
}


void insertstudent::on_paidToggle_clicked()
{
    status = "t";
}


void insertstudent::on_notPaidToggle_clicked()
{
    status = "f";
}
