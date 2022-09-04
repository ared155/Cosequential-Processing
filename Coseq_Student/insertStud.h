#ifndef INSERTSTUD_H
#define INSERTSTUD_H

#include <QDialog>

namespace Ui {
class insertStud;
}

class insertStud : public QDialog
{
    Q_OBJECT

public:
    explicit insertStud(QWidget *parent = nullptr);
    ~insertStud();

private slots:
    void on_submit_clicked();

    void on_paidToggle_clicked();

    void on_notPaidToggle_clicked();

private:
    Ui::insertStud *ui;
};

#endif // INSERTSTUD_H
