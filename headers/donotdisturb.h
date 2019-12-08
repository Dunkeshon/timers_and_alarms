#ifndef DONOTDISTURB_H
#define DONOTDISTURB_H

#include <QDialog>

namespace Ui {
class DoNotDisturb;
}

class DoNotDisturb : public QDialog
{
    Q_OBJECT

public:
    explicit DoNotDisturb(QWidget *parent = nullptr);
    ~DoNotDisturb();

private slots:
    void on_confirm_disturb_clicked();

    void on_cancel_disturb_clicked();
    void setDisplay_format();

private:
    Ui::DoNotDisturb *ui;
};

#endif // DONOTDISTURB_H
