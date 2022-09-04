#ifndef COSEQDISPLAY_H
#define COSEQDISPLAY_H

#include <QMainWindow>

namespace Ui {
class cosequential;
}

class cosequential : public QMainWindow
{
    Q_OBJECT

public:
    explicit cosequential(QWidget *parent = nullptr);
    ~cosequential();

private:
    Ui::cosequential *ui;
};

#endif // COSEQDISPLAY_H
