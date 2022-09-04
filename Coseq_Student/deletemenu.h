#ifndef DELETEMENU_H
#define DELETEMENU_H

#include <QMainWindow>

namespace Ui {
class deletemenu;
}

class deletemenu : public QMainWindow
{
    Q_OBJECT

public:
    explicit deletemenu(QWidget *parent = nullptr);
    ~deletemenu();

private:
    Ui::deletemenu *ui;
};

#endif // DELETEMENU_H
