#ifndef GROUPDIALOG_H
#define GROUPDIALOG_H

#include <QDialog>
#include "mainwindow.h"
namespace Ui {
class GroupDialog;
}

class GroupDialog : public QDialog
{
    Q_OBJECT

public:
    explicit GroupDialog(QWidget *parent = nullptr);
    ~GroupDialog();

private slots:
    void on_OK_clicked();

    void on_Cancel_clicked();

private:
    Ui::GroupDialog *ui;
};

#endif // GROUPDIALOG_H
