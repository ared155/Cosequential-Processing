#ifndef INSERTMARKS_H
#define INSERTMARKS_H

#include <QMainWindow>

namespace Ui {
class insertmarks;
}

class insertmarks : public QMainWindow
{
    Q_OBJECT

public:
    explicit insertmarks(QWidget *parent = nullptr);
    ~insertmarks();

private slots:
    void on_submit_clicked();

private:
    Ui::insertmarks *ui;
};

#endif // INSERTMARKS_H
