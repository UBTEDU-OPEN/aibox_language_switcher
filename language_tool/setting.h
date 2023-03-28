#ifndef SETTING_H
#define SETTING_H

#include <QWidget>
#include <QTimer>

namespace Ui {
class setting;
}

class setting : public QWidget
{
    Q_OBJECT

public:
    explicit setting( QString language, QWidget *parent = 0);
    ~setting();

    void setResult();
    void showResult();

private:
    Ui::setting *ui;
    QString m_language;
    QTimer* m_timer;

};

#endif // SETTING_H
