#ifndef INSERTMENU_H
#define INSERTMENU_H

#include <QMainWindow>
#include "insertstudent.h"
#include "insertmarks.h"

namespace Ui {
class insertMenu;
}

class insertMenu : public QMainWindow
{
    Q_OBJECT

public:
    explicit insertMenu(QWidget *parent = nullptr);
    ~insertMenu();

private slots:
    void on_studentData_clicked();

    void on_marksData_clicked();

private:
    Ui::insertMenu *ui;
    insertstudent *insertStudWindow;
    insertmarks *insertMarksWindow;
};

#endif // INSERTMENU_H
