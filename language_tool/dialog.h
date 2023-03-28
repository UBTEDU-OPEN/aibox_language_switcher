#ifndef DIALOG_H
#define DIALOG_H

#include <QWidget>
#include "setting.h"
#include "ui_setting.h"

namespace Ui {
class dialog;
}

class dialog : public QWidget
{
    Q_OBJECT

public:
    explicit dialog(QWidget *parent = 0);
    ~dialog();

    void setLanguage(QString language);

    Ui::dialog *ui;

private slots:
    void onOKClicked();

private:

    QString m_warning;
    int m_step = 1; //表示确认阶段的第1/2个环节
    bool m_save = false;
    setting *m_setting;
    QString m_language;
};

#endif // DIALOG_H
