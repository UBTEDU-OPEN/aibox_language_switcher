#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDesktopWidget>
#include <QMouseEvent>
#include <QBitmap>
#include <QPainter>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowFlags(Qt::FramelessWindowHint);
    this->setStyleSheet("MainWindow{background-color:#9EB2C0;}");
    //屏幕居中
    this->setGeometry(QStyle::alignedRect(Qt::LeftToRight,Qt::AlignCenter,this->size(),qApp->desktop()->availableGeometry()));
    //圆角
    QBitmap bmp(this->size());
    bmp.fill();
    QPainter painter(&bmp);
    painter.setPen(Qt::NoPen);
    painter.setBrush(Qt::black);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.drawRoundedRect(bmp.rect(), 10, 10);
    setMask(bmp);

    m_titlebar = new titlebar();
    m_content = new content();
    m_dialog = new dialog();
    ui->verticalLayout->addWidget(m_titlebar);
    ui->verticalLayout->addWidget(m_content);

    connect(m_titlebar, &titlebar::SigMin, this, &MainWindow::showMinimized);
    connect(m_titlebar, &titlebar::SigClose, this, &MainWindow::close);
    connect(m_content, &content::sigStart, this, &MainWindow::showDialog);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showDialog(QString language)
{

    m_dialog->setParent(this);
    m_dialog->setLanguage(language);
    m_dialog->show();
}


void MainWindow::mousePressEvent(QMouseEvent *e)
{
    if(e->button() == Qt::LeftButton)
    {
        m_ptPre = e->globalPos();
        m_bLeftDown = true;
    }
    else
    {
        m_bLeftDown = false;
    }
    return QWidget::mousePressEvent(e);
}

void MainWindow::mouseMoveEvent(QMouseEvent *e)
{
    if(!(windowState() & Qt::WindowMaximized))
    {
        if(m_bLeftDown && m_titlebar->rect().contains(mapFromGlobal(m_ptPre))) //暂时不支持拉伸
        {
            QPoint nowPt = e->globalPos();
            QPoint moveTo = mapToParent(nowPt - m_ptPre);
            move(moveTo);
            m_ptPre = nowPt;
        }
    }
    QWidget::mouseMoveEvent(e);
}

void MainWindow::mouseReleaseEvent(QMouseEvent *e)
{

    m_bLeftDown = false;
    QWidget::mouseReleaseEvent(e);
}
