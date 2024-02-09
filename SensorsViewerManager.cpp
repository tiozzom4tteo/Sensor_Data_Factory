#include "SensorsViewerManager.h"
#include "Controller.h"

SensorsViewerManager::SensorsViewerManager(QWidget *parent) : QWidget(parent), home(new SensorsViewer()), sensorView(new SensorView()), createView(new CreateView()), modifyView(new ModifyView()), graphview(new GraphView()), window(new QFrame()), mainLayout(new QStackedLayout()), timer(new QTimer(this))
{
    window->setGeometry(0, 0, 700, 750);
    window->setWindowTitle("Sensori");

    QScreen *screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->availableGeometry();

    int windowWidth = window->width();
    int windowHeight = window->height();
    int x = (screenGeometry.width() - windowWidth) / 2;
    int y = (screenGeometry.height() - windowHeight) / 2;
    window->setGeometry(x, y, windowWidth, windowHeight);

    mainLayout->setAlignment(Qt::AlignHCenter);
    window->setLayout(mainLayout);
    home->setManager(this);
    sensorView->setManager(this);
    createView->setManager(this);
    modifyView->setManager(this);
    graphview->setManager(this);
    mainLayout->addWidget(home->addMenuView());
    mainLayout->addWidget(sensorView->addSensorsView());
    mainLayout->addWidget(createView->addCreateSensorsView());
    mainLayout->addWidget(modifyView->addModifySensorsView());
    mainLayout->addWidget(graphview->addGraphView());
    addMenu();
    showHome();
}

SensorsViewerManager::~SensorsViewerManager()
{
    delete window;
    delete home;
    delete sensorView;
    delete createView;
    delete mainLayout;
    delete timer;
}

void SensorsViewerManager::setController(Controller *controller)
{
    this->controller = controller;
    QAction *action_1 = file->actions().value(2);
    QAction *action_2 = create->actions().value(0);
    QAction *action_3 = menu->actions().value(0);
    QAction *action_4 = menu->actions().value(1);
    QAction *action_5 = menu->actions().value(2);
    QAction *action_6 = menu->actions().value(3);
    QAction *action_7 = menu->actions().value(4);
    QAction *action_8 = file->actions().value(0);
    QAction *action_9 = file->actions().value(1);

    connect(home->getSensorGasButton(), &QPushButton::clicked, this, [=]()
            { controller->getSensors("Gas Sensor"); });
    connect(home->getSensorMovButton(), &QPushButton::clicked, this, [=]()
            { controller->getSensors("Movement Sensor"); });
    connect(home->getSensorTempButton(), &QPushButton::clicked, this, [=]()
            { controller->getSensors("Temperature Sensor"); });
    connect(home->getSensorAllButton(), &QPushButton::clicked, this, [=]()
            { controller->getSensors(""); });

    connect(action_8, &QAction::triggered, this, [=]()
            { controller->load(mainLayout->currentIndex()); });
    connect(action_9, SIGNAL(triggered()), controller, SLOT(save()));
    connect(action_1, SIGNAL(triggered()), this, SLOT(closeApplication()));
    connect(action_2, SIGNAL(triggered()), this, SLOT(showCreateSensorsView()));
    connect(action_3, SIGNAL(triggered()), this, SLOT(showHome()));

    connect(action_4, &QAction::triggered, this, [=]()
            { controller->getSensors("Gas Sensor"); });
    connect(action_5, &QAction::triggered, this, [=]()
            { controller->getSensors("Movement Sensor"); });
    connect(action_6, &QAction::triggered, this, [=]()
            { controller->getSensors("Temperature Sensor"); });
    connect(action_7, &QAction::triggered, this, [=]()
            { controller->getSensors(""); });
    connect(timer, &QTimer::timeout, this, [=]()
            { graphview->setGraph(); });
}

void SensorsViewerManager::addMenu()
{
    QMenuBar *menubar = new QMenuBar(this);
    file = new QMenu("File", menubar);
    menubar->addMenu(file);

    QAction *loadAction = new QAction("Load", file);
    QShortcut *loadSC = new QShortcut(QKeySequence(Qt::CTRL | Qt::Key_L), this);
    loadAction->setShortcut(loadSC->key());
    file->addAction(loadAction);

    QAction *saveAction = new QAction("Save", file);
    QShortcut *saveSC = new QShortcut(QKeySequence(Qt::CTRL | Qt::Key_S), this);
    saveAction->setShortcut(saveSC->key());
    file->addAction(saveAction);

    QAction *closeAction = new QAction("Close", file);
    QShortcut *closeSC = new QShortcut(QKeySequence(Qt::CTRL | Qt::Key_E), this);
    closeAction->setShortcut(closeSC->key());
    file->addAction(closeAction);

    create = new QMenu("Create", menubar);
    menubar->addMenu(create);
    QAction *createSensAction = new QAction("Create Sensor", create);
    QShortcut *createSC = new QShortcut(QKeySequence(Qt::CTRL | Qt::Key_N), this);
    createSensAction->setShortcut(createSC->key());
    create->addAction(createSensAction);

    menu = new QMenu("Menu", menubar);
    menubar->addMenu(menu);
    QAction *HomeAction = new QAction("Home", menu);
    QShortcut *homeSC = new QShortcut(QKeySequence(Qt::CTRL | Qt::Key_B), this);
    HomeAction->setShortcut(homeSC->key());
    menu->addAction(HomeAction);

    QAction *GasAction = new QAction("Gas Sensors", menu);
    QShortcut *gasSC = new QShortcut(QKeySequence(Qt::CTRL | Qt::Key_G), this);
    GasAction->setShortcut(gasSC->key());
    menu->addAction(GasAction);

    QAction *MovAction = new QAction("Movement Sensors", menu);
    QShortcut *movSC = new QShortcut(QKeySequence(Qt::CTRL | Qt::Key_M), this);
    MovAction->setShortcut(movSC->key());
    menu->addAction(MovAction);

    QAction *TempAction = new QAction("Temperature Sensors", menu);
    QShortcut *tempSC = new QShortcut(QKeySequence(Qt::CTRL | Qt::Key_T), this);
    TempAction->setShortcut(tempSC->key());
    menu->addAction(TempAction);

    QAction *AllAction = new QAction("All Sensors", menu);
    QShortcut *allSC = new QShortcut(QKeySequence(Qt::CTRL | Qt::Key_K), this);
    AllAction->setShortcut(allSC->key());
    menu->addAction(AllAction);
    mainLayout->setMenuBar(menubar);
}

SensorsViewer *SensorsViewerManager::getHomeView() const
{
    return home;
}

SensorView *SensorsViewerManager::getSensorView() const
{
    return sensorView;
}

CreateView *SensorsViewerManager::getCreateView() const
{
    return createView;
}

ModifyView *SensorsViewerManager::getModifyView() const
{
    return modifyView;
}

GraphView *SensorsViewerManager::getGraphView() const
{
    return graphview;
}

void SensorsViewerManager::showHome() const
{
    timer->stop();
    mainLayout->setCurrentIndex(0);
}

void SensorsViewerManager::showSensorsView(const std::vector<Sensor *> &sensors)
{
    timer->stop();
    sensorView->addSensorToView(sensors);
    mainLayout->setCurrentIndex(1);
}

void SensorsViewerManager::showCreateSensorsView() const
{
    timer->stop();
    mainLayout->setCurrentIndex(2);
}

void SensorsViewerManager::showModifySensorView(const std::string &name, const std::string &model, const std::string &description)
{
    timer->stop();
    modifyView->setName(name);
    modifyView->setModel(model);
    modifyView->setDescription(description);
    mainLayout->setCurrentIndex(3);
}

void SensorsViewerManager::showGraphSensorView(Sensor *sensor, const unsigned int &index, const std::string &type) const
{
    graphview->setCurrentSensor(sensor);
    graphview->setCurrentIndex(index);
    graphview->setCurrentType(type);
    mainLayout->setCurrentIndex(4);
}

void SensorsViewerManager::closeApplication() const
{
    timer->stop();
    QCoreApplication::quit();
}

void SensorsViewerManager::show() const
{
    window->show();
}

void SensorsViewerManager::deleteSensor(QFrame *frame, const unsigned int &index)
{
    delete frame;
    controller->removeSensor(index);
}

void SensorsViewerManager::modifySensor(const std::string &name, const std::string &model, const std::string &description)
{
    controller->modifySensor(name, model, description);
}

void SensorsViewerManager::StartTimer() const
{
    timer->start(1000);
}

void SensorsViewerManager::StopTimer() const
{
    timer->stop();
}

void SensorsViewerManager::NextSensor() const
{
    timer->stop();
    controller->next();
}

void SensorsViewerManager::PreviousSensor() const
{
    timer->stop();
    controller->previous();
}

void SensorsViewerManager::createSensor(const unsigned int &index, const std::string &name, const std::string &model, const std::string &description) const
{
    controller->createSensors(index, name, model, description);
}
