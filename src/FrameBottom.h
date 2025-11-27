#ifndef FRAMEBOTTOM_H
#define FRAMEBOTTOM_H

#include <QFrame>

namespace Ui {
class FrameBottom;
}

class FrameBottom : public QFrame
{
    Q_OBJECT

public:
    explicit FrameBottom(QWidget *parent = 0);
    ~FrameBottom();
public slots:
    void showloading();
    void stoploading();
private slots:
    void OnButtomStopMotorsClicked(bool _state);
    void OnButtonDoorClicked(bool _state);
    void OnButtonDoorPerchatkaClicked(bool _state);
    void OnButtonDoorCameraClicked(bool _state);
private:
    Ui::FrameBottom *ui;
};

#endif // FRAMEBOTTOM_H
