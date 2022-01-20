#ifndef CAMERAVIEWWIDGET_H
#define CAMERAVIEWWIDGET_H

#include <QVideoWidget>

class CameraViewWidget : public QVideoWidget
{
public:
    CameraViewWidget(QWidget* parent = nullptr);
};

#endif // CAMERAVIEWWIDGET_H
