#include "mainwindow.h"
#include "UI/buttonswidget.h"
#include "UI/cameraviewwidget.h"
#include <QTextStream>
#include <QPushButton>
#include <QVideoWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>



MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    mCameraView = new CameraViewWidget(this);

    createUi();


}

void MainWindow::createUi()
{

    buttonsWidget = new ButtonsWidget;

    QHBoxLayout* mMainLayout = new QHBoxLayout;
    mMainLayout->addWidget(mCameraView, 6);

    mMainLayout->addWidget(buttonsWidget, 1);

    setLayout(mMainLayout);
}

MainWindow::~MainWindow()
{

}

