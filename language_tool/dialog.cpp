#include "dialog.h"
#include "ui_dialog.h"
#include <pthread.h>
#include <iostream>
#include <QFile>
#include <QTextStream>
#include <QTextCodec>
#include <QDebug>
#include <stdlib.h>
#include <QTimer>

void* checkPower(void* param);
dialog *g_pDialog = nullptr;

dialog::dialog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::dialog)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_StyledBackground);

    m_setting = new setting("中文");

    this->setGeometry(1,51,618,448);
    this->setStyleSheet("#dialog{background-color:rgba(23,26,45,74%)}");
    ui->widget_5->setStyleSheet("background:#FFFFFF;border-radius:10px;");
    ui->label->setStyleSheet("border-image: url(:/icon/ic_warning_red.png)");
    ui->pbcancel->setStyleSheet("background: #9EB2C0;border-radius: 5px;color:#FFFFFF");
    ui->pbok->setStyleSheet("background: #389FF1;border-radius: 5px;color:#FFFFFF");
    ui->label_2->setStyleSheet("font-family: PingFangSC-Medium;font-size: 14px;color: #4C545B;line-height: 24px;");

    connect(ui->pbcancel, &QPushButton::clicked, this, &dialog::close);
    connect(ui->pbok, &QPushButton::clicked, this, &dialog::onOKClicked);
    this->hide();


}

dialog::~dialog()
{
    delete ui;
}


void dialog::onOKClicked()
{

    if(m_language == "English")
    {
        system("/usr/local/UBTTools/language -w LANG=en_US.UTF-8");
    }
    else if(m_language == "中文")
    {
        system("/usr/local/UBTTools/language -w LANG=zh_CN.UTF-8");
    }

    m_setting = new setting(m_language);
    m_setting->setParent(this->parentWidget());
    m_setting->showResult();

}

void dialog::setLanguage(QString language)
{
    m_language = language;
}


