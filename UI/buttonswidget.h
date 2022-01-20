#ifndef BUTTONSWIDGET_H
#define BUTTONSWIDGET_H

#include <QWidget>

class QPushButton;
class QComboBox;

class ButtonsWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ButtonsWidget(QWidget *parent = nullptr);
    QPushButton* mStartCameraBut;
    QPushButton* mPhotoBut;
    QPushButton* mStartRecBut;
    QPushButton* mStopRecBut;
    QPushButton* mStopCameraBut;
    QComboBox* cameraChooseBox;
    QComboBox* microphoneChooseBox;

    void fillCameraChooseBox(const QStringList&);
    void fillMicrophoneChooseBox(const QStringList&);
private:

};

#endif // BUTTONSWIDGET_H
