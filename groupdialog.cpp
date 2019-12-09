#include "groupdialog.h"
#include "ui_groupdialog.h"

GroupDialog::GroupDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GroupDialog)
{
    ui->setupUi(this);
}

GroupDialog::~GroupDialog()
{
    delete ui;
}

void GroupDialog::on_OK_clicked()
{
    MainWindow * temp = qobject_cast <MainWindow *>(parent());
    if(ui->lineEdit->text()!=""){
        temp->current_group = ui->lineEdit->text();
        emit(temp->group_created());
    }

    hide();
}

void GroupDialog::on_Cancel_clicked()
{
    hide();
}
