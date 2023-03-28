#include "content.h"
#include "ui_content.h"
#include <QPainter>
#include <QListView>
#include <QDebug>
#include <QLocale>

content::content(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::content)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
    this->setStyleSheet("background:#FFFFFF;border-bottom-left-radius:10px;border-bottom-right-radius:10px");
    ui->label->setStyleSheet("font:16px; color:#4C545B");
    ui->label_2->setStyleSheet("font:14px; color:#4C545B");
    ui->pushButton->setStyleSheet("background: #389FF1;border-radius: 18px;color:#FFFFFF;");
    ui->comboBox->setView(new QListView());
    ui->comboBox->setStyleSheet("QComboBox{border: 1px solid #9EB2C0;border-radius:5px;background:transparent;}"
                                "QComboBox::drop-down {height:40px;width:40px;background:transparent;border-top-right-radius: 5px;border-bottom-right-radius: 5px; }"
                                "QComboBox::down-arrow {height:12px;width:12px;image: url(:/icon/ic_drop_down.png);}"
                                "QComboBox QAbstractItemView {border: 1px solid #9EB2C0;border-radius:5px;background-color:#FFFFFF;}"
                                "QComboBox QAbstractItemView::item {height: 40px;background:transparent;}"
                                "QComboBox QAbstractItemView::item:selected {color: #FFFFFF;border-radius:4px; background-color:#389FF1;margin:8px 7px 5px 8px}"
                                "QComboBox QAbstractItemView::item:hover {color: #FFFFFF;border-radius:4px;background-color:#389FF1;margin:8px 7px 5px 8px}"
                                "QComboBox::down-arrow:on {image: url(:/icon/ic_drop_down.png);}");

    connect(ui->pushButton, &QPushButton::clicked, this, &content::onStartClicked);
    QLocale locale;
    if (locale.language() == QLocale::Chinese)
    {
        ui->comboBox->setCurrentIndex(0);
    }
    else if(locale.language() == QLocale::English)
    {
        ui->comboBox->setCurrentIndex(1);
    }
}

content::~content()
{
    delete ui;
}

void content::onStartClicked()
{
    emit sigStart(ui->comboBox->currentText().trimmed());
}

void content::paintEvent(QPaintEvent *e)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    QWidget::paintEvent(e);
}
