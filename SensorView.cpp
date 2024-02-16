#include "SensorView.h"
#include "SensorsViewerManager.h"

SensorView::SensorView(QWidget *parent) : QWidget(parent), mainContainer(new QFrame())

{
}

SensorView::~SensorView()
{
    delete scrollArea;
    delete scrollContent;
    delete scrollLayout;
    delete mainContainer;
    delete findInput;
}

QFrame *SensorView::addSensorsView()
{
    mainContainer->setMinimumSize(650, 500);
    mainContainer->setFrameShape(QFrame::StyledPanel);
    mainContainer->setFrameShadow(QFrame::Plain);
    mainContainer->setFrameStyle(QFrame::NoFrame);
    mainContainer->setStyleSheet("background-color: #f5f5f5;");
    scrollArea = new QScrollArea(mainContainer);
    scrollArea->setWidgetResizable(true);
    scrollContent = new QWidget(scrollArea);
    scrollLayout = new QVBoxLayout(scrollContent);
    scrollLayout->setAlignment(Qt::AlignTop | Qt::AlignHCenter);
    scrollContent->setLayout(scrollLayout);
    scrollArea->setWidget(scrollContent);
    scrollArea->setStyleSheet("background-color: #f5f5f5;");
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    QVBoxLayout *Layout = new QVBoxLayout(mainContainer);

    QVBoxLayout *Layout2 = new QVBoxLayout();
    findInput = new QLineEdit();
    findInput->setPlaceholderText("Find sensor...");
    findInput->setStyleSheet(Style::getLineEditStyle());

    QPushButton *findButton = new QPushButton("Find", mainContainer);
    connect(findButton, SIGNAL(clicked()), this, SLOT(findSensors()));
    findButton->setStyleSheet(Style::getButton());
    findButton->setMinimumSize(0, 20);

    Layout2->addWidget(findInput);
    Layout2->addWidget(findButton);
    Layout->addLayout(Layout2);
    Layout->addWidget(scrollArea);
    return mainContainer;
}

void SensorView::cleanScrollView()
{
    if (scrollLayout)
    {
        while (QLayoutItem *item = scrollLayout->takeAt(0))
        {
            QWidget *widget = item->widget();
            if (widget)
            {
                delete widget;
            }
            delete item;
        }
    }
}

void SensorView::createSensorPerView(Sensor *sensor, const std::string &tipo, const QPixmap &pixmap, const unsigned int &index)
{
    QFrame *frame = new QFrame(mainContainer);
    frame->setMinimumSize(600, 200);
    frame->setFrameShape(QFrame::StyledPanel);
    frame->setFrameShadow(QFrame::Plain);
    QVBoxLayout *verticalLayout = new QVBoxLayout(frame);

    QHBoxLayout *optionsLayer = new QHBoxLayout();
    QPushButton *eliminate = new QPushButton("Eliminate");
    eliminate->setStyleSheet(Style::getButton());
    eliminate->setMinimumSize(0, 20);

    QPushButton *modify = new QPushButton("Modify");
    modify->setStyleSheet(Style::getButton());
    modify->setMinimumSize(0, 20);

    connect(eliminate, &QPushButton::clicked, this, [=](){manager->deleteSensor(frame, index); });

    connect(modify, &QPushButton::clicked, this, [=]()
            {
        manager->getModifyView()->setSensorRef(index);
        manager->showModifySensorView(sensor->getName(), sensor->getModel(), sensor->getDescription()); });

    optionsLayer->addWidget(eliminate);
    optionsLayer->addWidget(modify);

    QHBoxLayout *horizontalLayout = new QHBoxLayout();
    horizontalLayout->setAlignment(Qt::AlignHCenter);

    QLabel *imm = new QLabel("Immagine");
    imm->setGeometry(QRect(7, 5, 401, 141));

    if (tipo == "Gas Sensor" || tipo == "Temperature Sensor" || tipo == "Movement Sensor")
    {
        imm->setPixmap(pixmap);
    }

    QVBoxLayout *data = new QVBoxLayout();
    QHBoxLayout *data2 = new QHBoxLayout();
    QString nome = QString::fromStdString(tipo + "-" + sensor->getName() + "/" + sensor->getModel() + '\n' + sensor->getDescription());
    QLabel *label_2 = new QLabel(QString::fromStdString(tipo));
    label_2->setStyleSheet("color: #333333;");
    QLabel *label_3 = new QLabel(QString::fromStdString(sensor->getName()));
    label_3->setStyleSheet("color: #333333;");
    QLabel *label_4 = new QLabel(QString::fromStdString(sensor->getModel()));
    label_4->setStyleSheet("color: #333333;");
    QLabel *label_5 = new QLabel(QString::fromStdString(sensor->getDescription()));
    label_5->setStyleSheet("color: #333333;");
    data->addWidget(label_2);
    data2->addWidget(label_3);
    data2->addWidget(label_4);
    data->addLayout(data2);
    data->addWidget(label_5);
    label_2->setWordWrap(true);
    label_2->setGeometry(QRect(7, 5, 401, 141));
    horizontalLayout->addWidget(imm);

    horizontalLayout->addSpacerItem(new QSpacerItem(140, 0, QSizePolicy::Fixed, QSizePolicy::Minimum));

    horizontalLayout->addLayout(data);
    horizontalLayout->setAlignment(Qt::AlignHCenter);
    verticalLayout->addLayout(horizontalLayout);
    QPushButton *graph = new QPushButton("Graph View");
    graph->setStyleSheet(Style::getButton());
    graph->setMinimumSize(0, 20);

    connect(graph, &QPushButton::clicked, this, [=]()
            { manager->showGraphSensorView(sensor, index, view); });

    verticalLayout->addWidget(graph);
    scrollLayout->addWidget(frame);
    verticalLayout->addLayout(optionsLayer, Qt::AlignTop | Qt::AlignLeft);
}

void SensorView::addSensorToView(const std::vector<Sensor *> &sensors)
{
    cleanScrollView();
    QPixmap pixmap;
    unsigned int index = 0;
    for (auto sensor : sensors)
    {
        std::string tipo;
        if (view == "Gas Sensor" && dynamic_cast<GasSensor *>(sensor))
        {
            tipo = "Gas Sensor";
            pixmap.load(":/assets/Gas.png");
            createSensorPerView(sensor, tipo, pixmap, index);
        }
        else if (view == "Movement Sensor" && dynamic_cast<MovSens *>(sensor))
        {
            tipo = "Movement Sensor";
            pixmap.load(":/assets/Mov.png");
            createSensorPerView(sensor, tipo, pixmap, index);
        }
        else if (view == "Temperature Sensor" && dynamic_cast<TempSensor *>(sensor))
        {
            tipo = "Temperature Sensor";
            pixmap.load(":/assets/Temp.png");
            createSensorPerView(sensor, tipo, pixmap, index);
        }
        else if (view == "")
        {
            if (dynamic_cast<TempSensor *>(sensor))
            {
                tipo = "Temperature Sensor";
                pixmap.load(":/assets/Temp.png");
                createSensorPerView(sensor, tipo, pixmap, index);
            }
            else if (dynamic_cast<GasSensor *>(sensor))
            {
                tipo = "Gas Sensor";
                pixmap.load(":/assets/Gas.png");
                createSensorPerView(sensor, tipo, pixmap, index);
            }
            else
            {
                tipo = "Movement Sensor";
                pixmap.load(":/assets/Mov.png");
                createSensorPerView(sensor, tipo, pixmap, index);
            }
        }
        index += 1;
    }
}

void SensorView::setManager(SensorsViewerManager *manager)
{
    this->manager = manager;
}

void SensorView::setView(const std::string &view)
{
    this->view = view;
}

void SensorView::findSensors() const
{

    for (QObject *sensor : scrollContent->children())
    {
        if (QFrame *frameSensor = qobject_cast<QFrame *>(sensor))
        {
            QString datas;
            for (QObject *wid : sensor->children())
            {
                if (QLabel *label = qobject_cast<QLabel *>(wid))
                {
                    if (label->text().toStdString() != "IMMAGINE")
                    {
                        datas += label->text();
                    }
                }
            }
            if (datas.toStdString().find(findInput->text().toStdString()) != std::string::npos)
            {
                frameSensor->setVisible(true);
            }
            else
            {
                frameSensor->hide();
            }
        }
    }
}
