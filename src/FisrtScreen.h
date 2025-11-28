#ifndef FISRTSCREEN_H
#define FISRTSCREEN_H

#include <QFrame>

namespace Ui {
class FisrtScreen;
}

class FisrtScreen : public QFrame
{
    Q_OBJECT

public:
    explicit FisrtScreen(QWidget *parent = 0);
    ~FisrtScreen();
signals:
    void signalPushButtonPoroschokClicked();
    void signalPushButtonPoroschokStop();
private:
    Ui::FisrtScreen *ui;
    void updateButtonStyle();
private slots:
    void onPushButtonPoroschokClicked();
    void onBtnUpClicked();
    void onBtnDownClicked();
};

#endif // FISRTSCREEN_H
