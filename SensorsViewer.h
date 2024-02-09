#ifndef SENSORSVIEWER_H
#define SENSORSVIEWER_H

#include "Sensor.h"
#include "Style.h"
#include <QWidget>
#include <QFrame>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPlainTextEdit>
#include <QTextBrowser>
#include <QTextEdit>

class SensorsViewerManager;

class SensorsViewer : public QWidget
{
    Q_OBJECT

private:
    SensorsViewerManager *manager;
    QVBoxLayout *mainLayout;
    QPushButton *SensorGasButton;
    QPushButton *SensorMovButton;
    QPushButton *SensorTempButton;
    QPushButton *SensorAllButton;

public:
    explicit SensorsViewer(QWidget *parent = nullptr);
    ~SensorsViewer();
    void setManager(SensorsViewerManager *);
    QFrame *addMenuView();
    QPushButton *getSensorGasButton();
    QPushButton *getSensorMovButton();
    QPushButton *getSensorTempButton();
    QPushButton *getSensorAllButton();

signals:
};

#endif // SENSORSVIEWER_H
