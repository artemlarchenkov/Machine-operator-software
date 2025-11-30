#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    /*!
     * \brief Функция инициализации и передачи настроек подключения
     * \param _app - Указатель на класс для обработки сообщений приложения
     */
    void init(QApplication *_app);
private:
    Ui::MainWindow *ui;

    void loadStyleSheet(const QString& filePath);
};

#endif // MAINWINDOW_H
