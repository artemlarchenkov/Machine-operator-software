#include "FrameBottom.h"
#include "ui_FrameBottom.h"
#include <QMessageBox>
#include "CustomDialog.h"
#include <QTimer>

FrameBottom::FrameBottom(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::FrameBottom)
{
    ui->setupUi(this);

    ui->icon_loading->hide();

    toDefaultButttons();
    ui->button_stop_motors->setProperty("hover", false);
    ui->button_stop_motors->setStyleSheet("");

    ui->door_camera->setProperty("hover", false);
    ui->door_camera->setStyleSheet("");
    ui->door_camera->setIcon(QIcon(":/lock.png"));

    ui->door_perchatka->setProperty("hover", false);
    ui->door_perchatka->setStyleSheet("");
    ui->door_perchatka->setIcon(QIcon(":/lock.png"));

    ui->camera_light->setProperty("hover", false);
    ui->camera_light->setStyleSheet("");

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

void FrameBottom::showloading()
{
    ui->icon_loading->show();
}

void FrameBottom::stoploading()
{
    ui->icon_loading->hide();
}

void FrameBottom::OnButtomStopMotorsClicked(bool _state)
{
    Q_UNUSED(_state)

    ui->button_stop_motors->setProperty("hover", true);
    ui->button_stop_motors->setStyleSheet("");

    QTimer::singleShot(5000, this, [this](){
        auto dlg = new CustomDialog("Движение остановлено",
                                    "Движение моторов осей перемещения остановлены вручную");

        connect(dlg, &CustomDialog::onpushButton_understandClicked,
                this, [this](){
            ui->button_stop_motors->setProperty("hover", false);
            ui->button_stop_motors->setStyleSheet("");
        });
                dlg->exec();
                dlg->deleteLater();

    });
}

void FrameBottom::OnButtonDoorClicked(bool _state)
{
    Q_UNUSED(_state)

    ui->door_camera->setProperty("hover", true);
    ui->door_camera->setStyleSheet("");
    ui->door_camera->setIcon(QIcon(":/icon_lock_pressed.png"));

    QTimer::singleShot(5000,this,[this](){
        auto dlg = new CustomDialog("Дверь камеры",
                         "Дверь камеры открыта/закрыта");
        connect(dlg, &CustomDialog::onpushButton_understandClicked,
                this, [this](){
            ui->door_camera->setProperty("hover", false);
            ui->door_camera->setStyleSheet("");
        });
        dlg->exec();
        dlg->deleteLater();

    });
}

void FrameBottom::OnButtonDoorPerchatkaClicked(bool _state)
{
    Q_UNUSED(_state)
    ui->door_perchatka->setProperty("hover", true);
    ui->door_perchatka->setStyleSheet("");
    ui->door_perchatka->setIcon(QIcon(":/icon_lock_pressed.png"));

    QTimer::singleShot(5000,this, [this](){
        auto dlg = new CustomDialog("Дверь перчатки",
                         "Дверь перчатки открыта/закрыта");
        connect(dlg, &CustomDialog::onpushButton_understandClicked,
                this, [this](){
            ui->door_perchatka->setProperty("hover", false);
            ui->door_perchatka->setStyleSheet("");
        });
        dlg->exec();
        dlg->deleteLater();

    });
}

void FrameBottom::OnButtonDoorCameraClicked(bool _state)
{
    Q_UNUSED(_state)

    ui->camera_light->setProperty("hover", true);
    ui->camera_light->setStyleSheet("");

    QTimer::singleShot(5000, this, [this](){
        auto dlg = new CustomDialog("Освещение камеры",
                         "Освещение камеры включено/выключено");

        connect(dlg, &CustomDialog::onpushButton_understandClicked,
                this, [this](){
            ui->camera_light->setProperty("hover", false);
            ui->camera_light->setStyleSheet("");
        });

        dlg->exec();
        dlg->deleteLater();
    });
}

void FrameBottom::toDefaultButttons()
{
    ui->door_camera->setProperty("hover", false);
    ui->door_camera->setStyleSheet("");

    ui->door_perchatka->setProperty("hover", false);
    ui->door_perchatka->setStyleSheet("");

    ui->door_camera->setProperty("hover", false);
    ui->door_camera->setStyleSheet("");

    ui->button_stop_motors->setProperty("hover", false);
    ui->button_stop_motors->setStyleSheet("");
}

