#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->pbCof100->setEnabled(false);
    ui->pbTea150->setEnabled(false);
    ui->pbMil200->setEnabled(false);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeMoney(int diff){
    money+=diff;
    ui->lcdNumber->display(money);
}

void Widget::checkMenu(){
    if(money>=100){
        ui->pbCof100->setEnabled(true);
    }
    else ui->pbCof100->setEnabled(false);

    if(money>=150){
        ui->pbTea150->setEnabled(true);
    }
    else ui->pbTea150->setEnabled(false);

    if(money>=200){
        ui->pbMil200->setEnabled(true);
    }
    else ui->pbMil200->setEnabled(false);
}

void Widget::on_pbCoin10_clicked(){
    changeMoney(10);
    checkMenu();
}

void Widget::on_pbCoin50_clicked(){
    changeMoney(50);
    checkMenu();
}

void Widget::on_pbCoin100_clicked(){
    changeMoney(100);
    checkMenu();
}

void Widget::on_pbCoin500_clicked(){
    changeMoney(500);
    checkMenu();
}

void Widget::on_pbCof100_clicked()
{
    changeMoney(-100);
    checkMenu();
}


void Widget::on_pbTea150_clicked()
{
    changeMoney(-150);
    checkMenu();
}


void Widget::on_pbMil200_clicked()
{
    changeMoney(-200);
    checkMenu();
}


void Widget::on_pbReset_clicked()
{
    QMessageBox mb;
    int tmp = 0;
    int count1 = 0;
    int count2 = 0;
    int count3 = 0;
    int count4 = 0;
    char buffer[100];
    tmp = money;
    while(true){
        if(tmp>=500){
            tmp = tmp - 500;
            count1 += 1;
        }
        else if(tmp>=100){
            tmp = tmp - 100;
            count2 += 1;
        }
        else if(tmp>=50){
            tmp = tmp - 50;
            count3 += 1;
        }
        else if(tmp>=10){
            tmp = tmp - 10;
            count4 += 1;
        }
        else break;
    }
    sprintf(buffer,"500won: %d, 100won: %d, 50won: %d, 10won: %d", count1, count2, count3, count4);

    mb.information(this, "Change", buffer);
}

