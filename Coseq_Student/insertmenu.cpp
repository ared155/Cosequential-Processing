#include "insertmenu.h"
#include "ui_insertmenu.h"
#include "insertstudent.h"
#include "insertmarks.h"

insertMenu::insertMenu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::insertMenu)
{
    ui->setupUi(this);
}

insertMenu::~insertMenu()
{
    delete ui;
}

void insertMenu::on_studentData_clicked()
{
    insertStudWindow = new insertstudent(this);
    insertStudWindow->show();
}


void insertMenu::on_marksData_clicked()
{
    insertMarksWindow = new insertmarks(this);
    insertMarksWindow->show();
}

