#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "insertmenu.h"
#include "coseqoutput.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_exitButton_clicked();

    void on_insertButton_clicked();

    void on_coseqMatching_clicked();


private:
    Ui::MainWindow *ui;
    insertMenu *insertMenuWindow;
    coseqoutput *coseqMenuWindow;
};
#endif // MAINWINDOW_H
