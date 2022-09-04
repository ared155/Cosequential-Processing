#include "insertStud.h"
#include "ui_insert.h"
#include <QTextStream>
#include "student.h"

QString status;

insertStud::insertStud(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::insert)
{
    ui->setupUi(this);
    status = "false";
}

insertStud::~insertStud()
{
    delete ui;
}

void insertStud::on_submit_clicked()
{
    QTextStream out{stdout};
    QString usn = ui->usnEntry->text();
    QString name = ui->nameEntry->text();
    QString branch = ui->branchEntry->text();
    status = status[0];
    ui->label->setText(status);
    Student obj(usn.toStdString(), name.toStdString(), branch.toStdString(), status.toStdString());
    Buffer buff;
    buff.pack(obj);
    buff.write("record.txt");
}


void insertStud::on_paidToggle_clicked()
{
    status = "true";
}


void insertStud::on_notPaidToggle_clicked()
{
    status = "false";
}

