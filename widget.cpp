#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->pbCoffee->setEnabled(false);    //Coffee button off
    ui->pbTea->setEnabled(false);       //Tea button off
    ui->pbIcetea->setEnabled(false);    //Icetea button off
    ui->pbMilk->setEnabled(false);      //Milk button off
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeMoney(int diff)
{
    if(diff>0){
        money += diff;
        ui->lcdNumber->display(money);
    }
    else{
        if(money>=-diff){    //have money > drinking money
            money += diff;
            ui->lcdNumber->display(money);
        }
        else{   //have money < drinking money
        }
    }
    changeButton(money);
}


void Widget::changeButton(int money)
{
    if(money<10){
        ui->pbMilk->setEnabled(false);
        ui->pbTea->setEnabled(false);
        ui->pbIcetea->setEnabled(false);
        ui->pbCoffee->setEnabled(false);
    }
    else if(money>=10&&money<50){
        ui->pbMilk->setEnabled(true);
        ui->pbTea->setEnabled(false);
        ui->pbIcetea->setEnabled(false);
        ui->pbCoffee->setEnabled(false);
    }
    else if(money>=50&&money<100){
        ui->pbTea->setEnabled(true);
        ui->pbIcetea->setEnabled(true);
        ui->pbMilk->setEnabled(true);
        ui->pbCoffee->setEnabled(false);
    }
    else if(money>=100){
        ui->pbMilk->setEnabled(true);
        ui->pbCoffee->setEnabled(true);
        ui->pbTea->setEnabled(true);
        ui->pbIcetea->setEnabled(true);
    }
}


void Widget::on_pbCoin10_clicked()
{
    changeMoney(10);
}


void Widget::on_pbCoin50_clicked()
{
    changeMoney(50);
}


void Widget::on_pbCoin100_clicked()
{
    changeMoney(100);
}


void Widget::on_pbCoin500_clicked()
{
    changeMoney(500);
}


void Widget::on_pbCoffee_clicked()
{
    changeMoney(-100);
}


void Widget::on_pbTea_clicked()
{
    changeMoney(-50);
}


void Widget::on_pbIcetea_clicked()
{
    changeMoney(-50);
}


void Widget::on_pbMilk_clicked()
{
    changeMoney(-10);
}



void Widget::on_pbReset_clicked()
{
    arr[0] = money/500;
    arr[1] = (money - 500*arr[0])/100;
    arr[2] = (money - 500*arr[0] - 100*arr[1])/50;
    arr[3] = (money - 500*arr[0] - 100*arr[1] - 50*arr[2])/10;

    QMessageBox mb;
    mb.information(this, "payback", "your money \r\r500won : " + QString::number(arr[0]) +
                                                 "\r100won : " + QString::number(arr[1]) +
                                                 "\r50won : " + QString::number(arr[2]) +
                                                 "\r10won : " + QString::number(arr[3]), "ok");
}

