#ifndef CLSMAINWINDOW_H
#define CLSMAINWINDOW_H

#include "ui_clsMainWindow.h"
#include <QString>
#include "clsConnectSWBox.h"
class clsMainWindow : public QMainWindow, private Ui::clsMainWindow
{
    Q_OBJECT

public:
    explicit clsMainWindow(QWidget *parent = 0);
    ~clsMainWindow();

private slots:
    void on_btnOpen_clicked();
    void on_btnSend_clicked();
    void on_btnLoop_clicked();
};

#endif // CLSMAINWINDOW_H
