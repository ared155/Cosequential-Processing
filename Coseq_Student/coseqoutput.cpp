#include "coseqoutput.h"
#include "ui_coseqoutput.h"
#include "coseq.h"

#include "sstream"
#include "fstream"
#include "QTableWidgetItem"

coseqoutput::coseqoutput(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::coseqoutput)
{
    ui->setupUi(this);
}

coseqoutput::~coseqoutput()
{
    delete ui;
}

void coseqoutput::on_pushButton_clicked()
{
    int count=0;

    coseq obj;
    obj.match();

    char objInfo[100][150];

    std::fstream f("eligible.txt", std::ios::in);
    char buff[150];
    while(!f.eof()){
        f.getline(buff,150,'\n');
        printf("\nBuff : %s\n", buff);
        strcpy(objInfo[count],buff);
        count++;
    }
    count--;

    ui->tableWidget->setRowCount(count);
    ui->tableWidget->setColumnCount(3);
    for (auto r=0; r<count; r++){
        char usn[15], name[50], branch[50];
        std::stringstream is(objInfo[r]);
        is.getline(usn,15,'|');
        is.getline(name,50,'|');
        is.getline(branch,50,'|');
        ui->tableWidget->setItem( r, 0, new QTableWidgetItem(usn));
        ui->tableWidget->setItem( r, 2, new QTableWidgetItem(name));
        ui->tableWidget->setItem( r, 1, new QTableWidgetItem(branch));
    }
}
