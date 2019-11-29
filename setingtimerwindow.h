#ifndef SETINGTIMERWINDOW_H
#define SETINGTIMERWINDOW_H

#include <QDialog>

namespace Ui {
class SetingTimerWindow;
}

class SetingTimerWindow : public QDialog
{
    Q_OBJECT

public:

    explicit SetingTimerWindow(QWidget *parent = nullptr);
    void ready_to_create_element(bool is_timer);
    ~SetingTimerWindow();

private:
    Ui::SetingTimerWindow *ui;
};

#endif // SETINGTIMERWINDOW_H
