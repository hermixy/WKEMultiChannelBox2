#include "clsMainWindow.h"
#include <QDebug>
#include <math.h>
#include <QTime>
clsMainWindow::clsMainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    setupUi(this);

    btnOpen->setEnabled(true);
    btnLoop->setEnabled(false);
    btnSend->setEnabled(false);
}

clsMainWindow::~clsMainWindow()
{
}

void clsMainWindow::on_btnOpen_clicked()
{
    bool isInit = clsConnectSWBox::Instance()->initSerialPort();

    btnOpen->setEnabled(!isInit);
    btnLoop->setEnabled(isInit);
    btnSend->setEnabled(isInit);
}


void clsMainWindow::on_btnSend_clicked()
{
    btnLoop->setChecked(false);
    qApp->processEvents();
    qDebug()<< clsConnectSWBox::Instance()->sendCommand(txtSend->text());
}

void clsMainWindow::on_btnLoop_clicked()
{
    QStringList commands;
    QString tmp;

    for(int i=0; i<16; i++)
    {
        int value=  pow(2,i);
        tmp = QString("4,%1,0").arg(QString::number(value));
        commands<<tmp;
    }

    for(int i=1; i<5; i++)
    {
        int value=  pow(2,i-1);
        tmp = QString("4,0,%1").arg(QString::number(value));
        commands<<tmp;
    }

    int i=0;
    int count=0;
    QTime time=QTime::currentTime();
    while(btnLoop->isChecked())
    {
        qApp->processEvents();
        clsConnectSWBox::Instance()->sendCommand(commands.at(i));
        i=i+1;
        i=i%20;

        if(i==0)
        {
            count++;
            qDebug()<<"Use time: "<<count<<" : "<< QTime::currentTime().msecsTo(time);
        }
        qApp->processEvents();
    }
}
