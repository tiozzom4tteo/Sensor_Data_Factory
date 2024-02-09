#include "GraphView.h"
#include "SensorsViewerManager.h"

GraphView::GraphView(QWidget *parent) : QWidget(parent), series(new QLineSeries()), chart(new QChart()), axisX(new QValueAxis()), axisY(new QValueAxis()),
                                        name(new QLabel("Name")), model(new QLabel("Model")), currentXValue(0), currentIndex(0), maxX(23), maxY(100), minY(-100)
{
}

GraphView::~GraphView()
{
    delete series;
    delete chart;
    delete axisX;
    delete axisY;
    delete name;
    delete model;
}

void GraphView::setManager(SensorsViewerManager *manager)
{
    this->manager = manager;
}

QFrame *GraphView::addGraphView()
{
    std::srand(static_cast<unsigned>(std::time(0)));
    QFrame *mainContainer = new QFrame();
    mainContainer->setStyleSheet("background-color: #f5f5f5;");
    QVBoxLayout *layout = new QVBoxLayout(mainContainer);
    layout->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    name = new QLabel("Name");
    name->setStyleSheet(Style::getLabelStyle());
    name->setAlignment(Qt::AlignCenter);
    model = new QLabel("Model");
    model->setStyleSheet(Style::getLabelStyle());
    model->setAlignment(Qt::AlignCenter);
    QHBoxLayout *buttonLayout = new QHBoxLayout();

    QPushButton *successivo = new QPushButton();
    QPushButton *precedente = new QPushButton();
    QPushButton *Start = new QPushButton();
    QPushButton *Stop = new QPushButton();
    successivo->setStyleSheet(Style::getButton());
    precedente->setStyleSheet(Style::getButton());
    Start->setStyleSheet(Style::getButton());
    Stop->setStyleSheet(Style::getButton());
    successivo->setMinimumSize(0, 30);
    precedente->setMinimumSize(0, 30);
    Start->setMinimumSize(0, 30);
    Stop->setMinimumSize(0, 30);

    successivo->setText("Suc");
    precedente->setText("Prev");
    Start->setText("Start");
    Stop->setText("Stop");

    chart = new QChart();
    chart->setTitle("Grafico delle misurazioni effettuate");

    series = new QLineSeries();
    chart->addSeries(series);
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    axisX->setTitleText("Daily Misurations");
    axisX->setRange(0, maxX);
    chart->setAxisX(axisX, series);
    axisY->setTitleText("Temperature Index");
    axisY->setRange(0, maxY);
    chart->setAxisY(axisY, series);
    connect(Start, SIGNAL(clicked()), manager, SLOT(StartTimer()));
    connect(Stop, SIGNAL(clicked()), manager, SLOT(StopTimer()));
    connect(successivo, SIGNAL(clicked()), manager, SLOT(NextSensor()));
    connect(precedente, SIGNAL(clicked()), manager, SLOT(PreviousSensor()));

    layout->addWidget(name);
    layout->addWidget(model);
    layout->addWidget(chartView);
    buttonLayout->addWidget(precedente);
    buttonLayout->addWidget(Start);
    buttonLayout->addWidget(Stop);
    buttonLayout->addWidget(successivo);
    layout->addLayout(buttonLayout);

    return mainContainer;
}

void GraphView::nextSens(Sensor *sensor)
{
    this->sensor = sensor;
    name->setText(QString::fromStdString(sensor->getName()));
    model->setText(QString::fromStdString(sensor->getModel()));
}

void GraphView::prevSens(Sensor *sensor)
{
    this->sensor = sensor;
    name->setText(QString::fromStdString(sensor->getName()));
    model->setText(QString::fromStdString(sensor->getModel()));
}

void GraphView::setCurrentIndex(const unsigned int &index)
{
    currentIndex = index;
}

unsigned int GraphView::getCurrentIndex() const
{
    return currentIndex;
}

void GraphView::setCurrentType(const std::string &type)
{
    this->type = type;
}

std::string GraphView::getCurrentType() const
{
    return type;
}

void GraphView::setCurrentSensor(Sensor *sensor)
{
    this->sensor = sensor;
    name->setText(QString::fromStdString(sensor->getName()));
    model->setText(QString::fromStdString(sensor->getModel()));
    series->clear();

    if (sensor->getMisurations().size() > 0)
    {
        int i = 0;
        for (int misuration : sensor->getMisurations())
        {
            series->append(i, misuration);
            i++;
        }
        currentXValue = i;
    }
    else
    {
        currentXValue = 0;
    }
    if (dynamic_cast<TermoCouples *>(sensor))
    {
        axisY->setTitleText("Temperature Index");
        axisX->setRange(0, maxX);
        axisY->setRange(minY, this->maxY);
    }
    else
    {
        axisX->setRange(0, maxX);
        axisY->setRange(0, this->maxY);
    }
    if (dynamic_cast<TempSensor *>(sensor))
        axisY->setTitleText("Temperature Index");
    else if (dynamic_cast<GasSensor *>(sensor))
        axisY->setTitleText("Gas Index");
    else if (dynamic_cast<Accellerometer *>(sensor))
        axisY->setTitleText("Acceleration Index");
    else if (dynamic_cast<Giroscope *>(sensor))
        axisY->setTitleText("Euler Index");
    chart->update();
}

Sensor *GraphView::getCurrentSensor() const
{
    return sensor;
}

void GraphView::setGraph()
{
    int resetValue = maxX;

    if (currentXValue > resetValue)
    {
        currentXValue = 0;
        series->clear();
        sensor->clear();
        axisX->setRange(0, resetValue);
    }

    int *maxY = &this->maxY;
    int *minY = &this->minY;
    auto clamp = [maxY, minY](double val, double max) -> double
    { return (val < *minY) ? *minY : (*maxY * val) / max; };

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::mt19937 generator(seed);
    std::uniform_int_distribution<int> distribution(1, 5);
    std::uniform_int_distribution<int> distribution2(-5, 5);

    if (dynamic_cast<SemiConductors *>(sensor))
    {
        GasSensor *sen1 = dynamic_cast<GasSensor *>(sensor);
        sen1->setPresence(true);
        sen1->setResistence(distribution(generator));
        SemiConductors *sen2 = dynamic_cast<SemiConductors *>(sensor);
        sen2->setCoeffCalibr(distribution(generator));
        sen2->setDensity(distribution(generator));
        sensor->addMisuration(clamp);
        double mis = sensor->getLastMisurations();
        series->append(currentXValue, mis);
        axisX->setRange(0, maxX);
        axisY->setRange(0, this->maxY);
    }
    else if (dynamic_cast<ElettroSensor *>(sensor))
    {
        GasSensor *sen1 = dynamic_cast<GasSensor *>(sensor);
        sen1->setPresence(true);
        sen1->setResistence(distribution(generator));
        ElettroSensor *elettro = dynamic_cast<ElettroSensor *>(sensor);
        elettro->setConcElem(distribution(generator));
        elettro->setIntensity(distribution(generator));
        elettro->setVoltage(distribution(generator));
        sensor->addMisuration(clamp);
        double mis = sensor->getLastMisurations();
        series->append(currentXValue, mis);
        axisX->setRange(0, maxX);
        axisY->setRange(0, this->maxY);
    }
    else if (dynamic_cast<TermoResistance *>(sensor))
    {
        TempSensor *temp = dynamic_cast<TempSensor *>(sensor);
        temp->setResistence(distribution(generator));
        temp->setTemperature(distribution2(generator));
        TermoResistance *tempres = dynamic_cast<TermoResistance *>(sensor);
        tempres->setTemperature(distribution2(generator));
        sensor->addMisuration(clamp);
        double mis = sensor->getLastMisurations();
        series->append(currentXValue, mis);
        axisX->setRange(0, maxX);
        axisY->setRange(0, this->maxY);
    }
    else if (dynamic_cast<TermoCouples *>(sensor))
    {
        TempSensor *temp = dynamic_cast<TempSensor *>(sensor);
        temp->setResistence(distribution(generator));
        temp->setTemperature(distribution2(generator));
        TermoCouples *tempres = dynamic_cast<TermoCouples *>(sensor);
        tempres->setSeebeck(distribution(generator));
        tempres->setTemperature(distribution2(generator));
        sensor->addMisuration(clamp);
        double mis = sensor->getLastMisurations();
        series->append(currentXValue, mis);
        axisX->setRange(0, maxX);
        axisY->setRange(this->minY, this->maxY);
    }
    else if (dynamic_cast<Accellerometer *>(sensor))
    {
        MovSens *mov = dynamic_cast<MovSens *>(sensor);
        double y = distribution(generator);
        mov->setPosition1(y);
        mov->setPosition2(y + distribution(generator));
        mov->setVariation(distribution(generator));
        Accellerometer *acc = dynamic_cast<Accellerometer *>(sensor);
        acc->setVelocity(distribution(generator));
        sensor->addMisuration(clamp);
        double mis = sensor->getLastMisurations();
        series->append(currentXValue, mis);
        axisX->setRange(0, maxX);
        axisY->setRange(0, this->maxY);
    }
    else if (dynamic_cast<Giroscope *>(sensor))
    {
        double y1 = distribution(generator);
        MovSens *mov = dynamic_cast<MovSens *>(sensor);
        mov->setPosition1(distribution(generator));
        mov->setPosition2(y1);
        mov->setVariation(distribution(generator));
        Giroscope *giro = dynamic_cast<Giroscope *>(sensor);
        giro->setSecPos(y1 + distribution(generator));
        double y2 = distribution(generator);
        giro->setTempo1(y2);
        giro->setTempo2(y2 + distribution(generator));
        sensor->addMisuration(clamp);
        double mis = sensor->getLastMisurations();
        series->append(currentXValue, mis);
        axisX->setRange(0, maxX);
        axisY->setRange(0, this->maxY);
    }
    currentXValue += 1;
    chart->update();
}
