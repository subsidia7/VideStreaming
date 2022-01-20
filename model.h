#ifndef MODEL_H
#define MODEL_H

#include <QObject>
#include <QCameraDevice>
#include "controller.h"

class QCamera;
class QMediaCaptureSession;
class QImageCapture;
class QMediaRecorder;
//class QMediaFormat;


class Model : public QObject
{
    Q_OBJECT
public:
    explicit Model(QObject *parent = nullptr);
    friend class Controller;
private:
    QList<QCameraDevice> mCameraDevices;
    QCamera* mCamera;
    QMediaCaptureSession* mCaptureSession;
    QImageCapture* mImageCapture;
    QMediaRecorder* mRecorder;
    //QMediaFormat* mFormat;
    int mCurrentCameraI;
    QString mCurrentCameraName;

    void changeCameraDevice(const QString&);
};

#endif // MODEL_H
