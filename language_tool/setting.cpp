#include "setting.h"
#include "ui_setting.h"
#include <QTimer>
#include <iostream>
#include <QFile>
#include <QLocale>
#include <QTextStream>

setting::setting(QString language, QWidget *parent ) :
    QWidget(parent),
    ui(new Ui::setting),
    m_language(language)
{
    ui->setupUi(this);

    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_StyledBackground);

    this->setGeometry(1,51,618,448);
    this->setStyleSheet("#setting{background-color:rgba(23,26,45,74%)}");
    ui->widget->setStyleSheet("background:#FFFFFF;border-radius:10px;");
    ui->pushButton->setStyleSheet("background: #389FF1;border-radius: 5px;color:#FFFFFF");
    ui->label->setStyleSheet("font-family: PingFangSC-Medium;font-size: 20px;color: #4C545B;line-height: 24px;");

    ui->pushButton->hide();
    connect(ui->pushButton, &QPushButton::clicked, this, &setting::close);

    m_timer = new QTimer();
    connect(m_timer, &QTimer::timeout, this, &setting::setResult);
    m_timer->setSingleShot(true);
}

setting::~setting()
{
    delete ui;
}

void setting::showResult()
{
    this->show();
    m_timer->start(1000);
}

//使用popen函数执行命令行指令
char* runPopen(const char* command)
{
    FILE *fp = NULL;
    char cmd[1024];
    char buf[1024];
    static char result[1024*1024];
    memset(result,'\0',sizeof(result));
    sprintf(cmd, command);
    if( (fp = popen(cmd, "r")) != NULL)
    {
        while(fgets(buf, 1024, fp) != NULL)
        {
            strcat(result, buf);
        }
        pclose(fp);
        fp = NULL;
        return result;
    }
    else
    {
        perror("fail to popen");
        return NULL;
    }
}

void setting::setResult()
{
    std::string result = runPopen("/usr/local/UBTTools/language -r");
    if (result[result.length()-1] == '\n')
    {
        result = result.substr(0, result.length()-1);
    }
    if (m_language == "中文")
    {
        if (result == "LANG=zh_CN.UTF-8")
        {
            system("update-locale LANG=zh_CN.UTF-8 "
                   "LANGUAGE=zh_CN.UTF-8 LC_NUMERIC=zh_CN.UTF-8 "
                   "LC_TIME=zh_CN.UTF-8 LC_MONETARY=zh_CN.UTF-8 "
                   "LC_PAPER=zh_CN.UTF-8 LC_NAME=zh_CN.UTF-8 "
                   "LC_ADDRESS=zh_CN.UTF-8 LC_TELEPHONE=zh_CN.UTF-8 "
                   "LC_MEASUREMENT=zh_CN.UTF-8 LC_IDENTIFICATION=zh_CN.UTF-8 "
                   "LC_ALL=zh_CN.UTF-8");
            system("reboot");
        }
        else
        {
            ui->label->setText(tr("设置失败，请重试"));
            ui->pushButton->show();
        }
    }
    else if (m_language == "English")
    {
        if (result == "LANG=en_US.UTF-8")
        {
            system("update-locale LANG=en_US.UTF-8 "
                   "LANGUAGE=en_US.UTF-8 LC_NUMERIC=en_US.UTF-8 "
                   "LC_TIME=en_US.UTF-8 LC_MONETARY=en_US.UTF-8 "
                   "LC_PAPER=en_US.UTF-8 LC_NAME=en_US.UTF-8 "
                   "LC_ADDRESS=en_US.UTF-8 LC_TELEPHONE=en_US.UTF-8 "
                   "LC_MEASUREMENT=en_US.UTF-8 LC_IDENTIFICATION=en_US.UTF-8 "
                   "LC_ALL=en_US.UTF-8");
            system("reboot");
        }
        else
        {
            ui->label->setText(tr("设置失败，请重试"));
            ui->pushButton->show();
        }
    }
}


