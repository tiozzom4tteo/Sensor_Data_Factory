#include "CreateView.h"
#include "SensorsViewerManager.h"

CreateView::CreateView(QWidget *parent) : QWidget(parent)
{
}

CreateView::~CreateView()
{
}

QFrame *CreateView::addCreateSensorsView()
{
    QFrame *sensorsDash = new QFrame();
    sensorsDash->setFrameShape(QFrame::StyledPanel);
    sensorsDash->setFrameShadow(QFrame::Plain);
    sensorsDash->setFrameStyle(QFrame::NoFrame);
    QVBoxLayout *Menu = new QVBoxLayout(sensorsDash);
    Menu->setAlignment(Qt::AlignHCenter);
    sensorsDash->setStyleSheet("background-color: #f5f5f5;");

    QFrame *frame = new QFrame(sensorsDash);
    frame->setMinimumSize(150, 0);
    frame->setFrameShape(QFrame::StyledPanel);
    frame->setFrameShadow(QFrame::Plain);
    frame->setFrameStyle(QFrame::NoFrame);
    QVBoxLayout *verticalLayout_7 = new QVBoxLayout(frame);
    QLabel *nameLabel = new QLabel("Insert name", frame);
    nameLabel->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
    nameLabel->setStyleSheet(Style::getLabelStyle());
    nameLabel->setAlignment(Qt::AlignHCenter);
    nameLabel->setFont(QFont("Arial", 15));

    verticalLayout_7->addWidget(nameLabel);
    QLineEdit *nameInput = new QLineEdit(frame);
    nameInput->setMinimumSize(0, 100);
    nameInput->setStyleSheet(Style::getLineEditStyle());
    verticalLayout_7->addWidget(nameInput);
    Menu->addWidget(frame);

    QFrame *frame_2 = new QFrame(sensorsDash);
    frame_2->setMinimumSize(0, 150);
    frame_2->setFrameShape(QFrame::StyledPanel);
    frame_2->setFrameShadow(QFrame::Plain);
    frame_2->setFrameStyle(QFrame::NoFrame);
    QVBoxLayout *verticalLayout_6 = new QVBoxLayout(frame_2);
    QLabel *modelLabel = new QLabel("Insert model", frame_2);
    modelLabel->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
    modelLabel->setStyleSheet(Style::getLabelStyle());
    modelLabel->setAlignment(Qt::AlignHCenter);
    modelLabel->setFont(QFont("Arial", 15));
    verticalLayout_6->addWidget(modelLabel);
    QLineEdit *modelInput = new QLineEdit(frame_2);
    modelInput->setMinimumSize(0, 100);
    modelInput->setStyleSheet(Style::getLineEditStyle());
    verticalLayout_6->addWidget(modelInput);
    Menu->addWidget(frame_2);

    QFrame *frame_5 = new QFrame(sensorsDash);
    frame_5->setMinimumSize(0, 150);
    frame_5->setFrameShape(QFrame::StyledPanel);
    frame_5->setFrameShadow(QFrame::Plain);
    frame_5->setFrameStyle(QFrame::NoFrame);
    QVBoxLayout *verticalLayout_9 = new QVBoxLayout(frame_5);
    QLabel *DescritpionLabel = new QLabel("Insert descritpion", frame_5);
    DescritpionLabel->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
    DescritpionLabel->setStyleSheet(Style::getLabelStyle());
    DescritpionLabel->setAlignment(Qt::AlignHCenter);
    DescritpionLabel->setFont(QFont("Arial", 15));
    verticalLayout_9->addWidget(DescritpionLabel);
    QLineEdit *descritpionInput = new QLineEdit(frame_5);
    descritpionInput->setMinimumSize(0, 100);
    descritpionInput->setStyleSheet(Style::getLineEditStyle());
    verticalLayout_9->addWidget(descritpionInput);
    Menu->addWidget(frame_5);

    QFrame *frame_3 = new QFrame(sensorsDash);
    frame_3->setMinimumSize(0, 150);
    frame_3->setFrameShape(QFrame::StyledPanel);
    frame_3->setFrameShadow(QFrame::Plain);
    frame_3->setFrameStyle(QFrame::NoFrame);
    QVBoxLayout *verticalLayout_3 = new QVBoxLayout(frame_3);
    QLabel *sensorTypeLabel = new QLabel("Choose sensor type", frame_3);
    sensorTypeLabel->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
    sensorTypeLabel->setStyleSheet(Style::getLabelStyle());
    sensorTypeLabel->setAlignment(Qt::AlignHCenter);
    sensorTypeLabel->setFont(QFont("Arial", 15));
    verticalLayout_3->addWidget(sensorTypeLabel);
    QComboBox *sensorTypeSelect = new QComboBox(frame_3);
    sensorTypeSelect->addItem("Accellerometer");
    sensorTypeSelect->addItem("Elettrometer");
    sensorTypeSelect->addItem("Giroscope");
    sensorTypeSelect->addItem("Semiconductors");
    sensorTypeSelect->addItem("Termoresistance");
    sensorTypeSelect->addItem("Termocouples");
    sensorTypeSelect->setStyleSheet(Style::getComboBoxStyle());
    verticalLayout_3->addWidget(sensorTypeSelect);
    Menu->addWidget(frame_3);
    QFrame *frame_4 = new QFrame(sensorsDash);
    frame_4->setFrameShape(QFrame::StyledPanel);
    frame_4->setFrameShadow(QFrame::Plain);
    frame_4->setFrameStyle(QFrame::NoFrame);
    QVBoxLayout *verticalLayout_2 = new QVBoxLayout(frame_4);
    QPushButton *createSensorButton = new QPushButton("Create sensor", frame_4);
    createSensorButton->setMinimumSize(150, 30);
    createSensorButton->setStyleSheet(Style::getButton());

    verticalLayout_2->addWidget(createSensorButton);
    verticalLayout_2->setAlignment(Qt::AlignHCenter);
    Menu->addWidget(frame_4);

    connect(createSensorButton, &QPushButton::clicked, this, [=]()
            { manager->createSensor(sensorTypeSelect->currentIndex(), nameInput->text().toStdString(), modelInput->text().toStdString(), descritpionInput->text().toStdString()); });

    return sensorsDash;
}
void CreateView::setManager(SensorsViewerManager *manager)
{
    this->manager = manager;
}
