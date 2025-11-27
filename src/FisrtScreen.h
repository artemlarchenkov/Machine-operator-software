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
private slots:
    void onPushButtonPoroschokClicked();
};

#endif // FISRTSCREEN_H
