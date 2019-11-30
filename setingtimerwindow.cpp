#include "setingtimerwindow.h"
#include "ui_setingtimerwindow.h"
#include <QTimer>
#include <QTime>
#include "mainwindow.h"
SetingTimerWindow::SetingTimerWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SetingTimerWindow)
{
    ui->setupUi(this);
}

void SetingTimerWindow::ready_to_create_element(bool is_timer)
{
    if(is_timer){
        ui->Creation_of_type->setText("Timer");
    }
    else{
        ui->Creation_of_type->setText("Alarm Clock");
        ui->TimeSelection->setTime(QTime::currentTime());
    }
}

SetingTimerWindow::~SetingTimerWindow()
{
    delete ui;
}



void SetingTimerWindow::on_confirm_button_clicked()
{
    QWidget *ParentWidget = parentWidget();
    //emmit(ParentWidget->new_element_created());
    this->hide();
}
