#include "donotdisturb.h"
#include "ui_donotdisturb.h"
#include "mainwindow.h"
DoNotDisturb::DoNotDisturb(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DoNotDisturb)
{
    ui->setupUi(this);
    setDisplay_format();
}

DoNotDisturb::~DoNotDisturb()
{
    delete ui;
}

void DoNotDisturb::on_confirm_disturb_clicked()
{
   MainWindow * temp = qobject_cast <MainWindow *>(parent());

   temp->do_not_distorb_from = ui->disturb_from->time().msecsSinceStartOfDay();
   temp->do_not_distorb_to = ui->disturb_to->time().msecsSinceStartOfDay();
   emit(temp->do_not_disturb_changed());
   hide();
}


void DoNotDisturb::on_cancel_disturb_clicked()
{
    hide();
}

void DoNotDisturb::setDisplay_format()
{
    MainWindow * temp = qobject_cast <MainWindow *>(parent());
    ui->disturb_to->setDisplayFormat(temp->display_format);
    ui->disturb_from->setDisplayFormat(temp->display_format);
}
