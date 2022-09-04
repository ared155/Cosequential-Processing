#ifndef UPDATEMENU_H
#define UPDATEMENU_H

#include <QMainWindow>

namespace Ui {
class updatemenu;
}

class updatemenu : public QMainWindow
{
    Q_OBJECT

public:
    explicit updatemenu(QWidget *parent = nullptr);
    ~updatemenu();

private:
    Ui::updatemenu *ui;
};

#endif // UPDATEMENU_H
