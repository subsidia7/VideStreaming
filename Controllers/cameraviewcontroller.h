#ifndef CAMERAVIEWCONTROLLER_H
#define CAMERAVIEWCONTROLLER_H

#include <QObject>

class CameraViewController : public QObject
{
    Q_OBJECT
public:
    explicit CameraViewController(QObject *parent = nullptr);

signals:

};

#endif // CAMERAVIEWCONTROLLER_H
