#include "SensorsViewer.h"
#include "SensorsViewerManager.h"
#include "Style.h"
#include <vector>

SensorsViewer::SensorsViewer(QWidget *parent) : QWidget(parent), /*manager(new SensorsViewerManager()),*/ mainLayout(new QVBoxLayout()), SensorGasButton(new QPushButton()), SensorMovButton(new QPushButton()), SensorTempButton(new QPushButton())
{
}

SensorsViewer::~SensorsViewer()
{
    delete mainLayout;
    delete SensorGasButton;
    delete SensorMovButton;
    delete SensorTempButton;
}

void SensorsViewer::setManager(SensorsViewerManager *manager)
{
    this->manager = manager;
}

QFrame *SensorsViewer::addMenuView()
{
    QFrame *mainContainer = new QFrame();
    mainContainer->setMinimumSize(650, 650);
    mainContainer->setFrameShape(QFrame::StyledPanel);
    mainContainer->setFrameShadow(QFrame::Plain);
    mainContainer->setFrameStyle(QFrame::NoFrame);
    mainContainer->setStyleSheet("background-color: #f5f5f5;");

    QVBoxLayout *Menu = new QVBoxLayout(mainContainer);
    Menu->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    for (int i = 4; i >= 1; --i)
    {
        QFrame *frame = new QFrame(mainContainer);
        frame->setMinimumSize(300, 100);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Plain);
        frame->setFrameStyle(QFrame::NoFrame);
        frame->setStyleSheet("background-color: #f5f5f5;");

        QHBoxLayout *horizontalLayout = new QHBoxLayout(frame);

        Style::setButtonStyle();

        switch (i)
        {
        case 1:
            SensorTempButton = new QPushButton(frame);
            SensorTempButton->setText("View temperature sensors");
            SensorTempButton->setMinimumSize(200, 50);
            SensorTempButton->setStyleSheet(Style::getButton());
            horizontalLayout->addWidget(SensorTempButton);
            break;
        case 2:
            SensorMovButton = new QPushButton(frame);
            SensorMovButton->setText("View movement sensors");
            SensorMovButton->setMinimumSize(200, 50);
            SensorMovButton->setStyleSheet(Style::getButton());
            horizontalLayout->addWidget(SensorMovButton);
            break;
        case 3:
            SensorGasButton = new QPushButton(frame);
            SensorGasButton->setText("View gas sensors");
            SensorGasButton->setMinimumSize(200, 50);
            SensorGasButton->setStyleSheet(Style::getButton());
            horizontalLayout->addWidget(SensorGasButton);
            break;
        case 4:
            SensorAllButton = new QPushButton(frame);
            SensorAllButton->setText("View all sensors");
            SensorAllButton->setMinimumSize(200, 50);
            SensorAllButton->setStyleSheet(Style::getButton());
            horizontalLayout->addWidget(SensorAllButton);
            break;
        }

        Menu->addWidget(frame);
    }

    return mainContainer;
}

QPushButton *SensorsViewer::getSensorGasButton() const
{
    return SensorGasButton;
}

QPushButton *SensorsViewer::getSensorMovButton() const
{
    return SensorMovButton;
}

QPushButton *SensorsViewer::getSensorTempButton() const
{
    return SensorTempButton;
}

QPushButton *SensorsViewer::getSensorAllButton() const
{
    return SensorAllButton;
}
