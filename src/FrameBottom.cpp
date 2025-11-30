#include "FrameBottom.h"
#include "ui_FrameBottom.h"
#include <QMessageBox>
#include "CustomDialog.h"

FrameBottom::FrameBottom(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::FrameBottom)
{
    ui->setupUi(this);

    connect(ui->button_stop_motors, &QPushButton::clicked,
            this, &FrameBottom::OnButtomStopMotorsClicked);

    connect(ui->door_camera, &QPushButton::clicked,
            this, &FrameBottom::OnButtonDoorClicked);

    connect(ui->door_perchatka, &QPushButton::clicked,
            this, &FrameBottom::OnButtonDoorPerchatkaClicked);

    connect(ui->camera_light, &QPushButton::clicked,
            this, &FrameBottom::OnButtonDoorCameraClicked);
}

FrameBottom::~FrameBottom()
{
    delete ui;
}

void FrameBottom::OnButtomStopMotorsClicked(bool _state)
{
    Q_UNUSED(_state)

    CustomDialog dlg("Движение остановлено",
                     "Движение моторов осей перемещения остановлены вручную");
    dlg.exec();
}

void FrameBottom::OnButtonDoorClicked(bool _state)
{
    Q_UNUSED(_state)

    CustomDialog dlg("Дверь камеры",
                     "Дверь камеры открыта/закрыта");
    dlg.exec();
}

void FrameBottom::OnButtonDoorPerchatkaClicked(bool _state)
{
    Q_UNUSED(_state)

    CustomDialog dlg("Дверь перчатки",
                     "Дверь перчатки открыта/закрыта");
    dlg.exec();
}

void FrameBottom::OnButtonDoorCameraClicked(bool _state)
{
    Q_UNUSED(_state)

    CustomDialog dlg("Освещение камеры",
                     "Освещение камеры включено/выключено");
    dlg.exec();
}

