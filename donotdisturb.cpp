#include "donotdisturb.h"
#include "ui_donotdisturb.h"
#include "mainwindow.h"
DoNotDisturb::DoNotDisturb(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DoNotDisturb)
{
    ui->setupUi(this);
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
