#ifndef INSERTSTUDENT_H
#define INSERTSTUDENT_H

#include <QMainWindow>

namespace Ui {
class insertstudent;
}

class insertstudent : public QMainWindow
{
    Q_OBJECT

public:
    explicit insertstudent(QWidget *parent = nullptr);
    ~insertstudent();

private slots:
    void on_submit_clicked();

    void on_paidToggle_clicked();

    void on_notPaidToggle_clicked();

private:
    Ui::insertstudent *ui;
};

#endif // INSERTSTUDENT_H
