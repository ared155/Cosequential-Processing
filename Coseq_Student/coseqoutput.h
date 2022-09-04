#ifndef COSEQOUTPUT_H
#define COSEQOUTPUT_H

#include <QMainWindow>

namespace Ui {
class coseqoutput;
}

class coseqoutput : public QMainWindow
{
    Q_OBJECT

public:
    explicit coseqoutput(QWidget *parent = nullptr);
    ~coseqoutput();

private slots:
    void on_pushButton_clicked();

private:
    Ui::coseqoutput *ui;
};

#endif // COSEQOUTPUT_H
