#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include "controller.h"


class ButtonsWidget;
class CameraViewWidget;

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    friend class Controller;

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:

    void createUi();

    CameraViewWidget* mCameraView;
    ButtonsWidget* buttonsWidget;

};
#endif // MAINWINDOW_H
