QT += core gui

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

RESOURCES += \
    risorse.qrc \

SOURCES += \
    CreateView.cpp \
    CreatorSensors.cpp \
    GraphView.cpp \
    Model.cpp \
    ModifyView.cpp \
    SensorView.cpp \
    SensorsDashboard.cpp \
    SemiConductors.cpp \
    Sensor.cpp \
    GasSensor.cpp \
    main.cpp \
    MovSens.cpp \
    SensorsViewer.cpp \
    SensorsViewerManager.cpp \
    Style.cpp \
    TempSensor.cpp \
    Controller.cpp \
    ElettroSensor.cpp \
    TermoResistance.cpp \
    TermoCouples.cpp \
    Accellerometer.cpp \
    Giroscope.cpp \


HEADERS += \
    CreateView.h \
    CreatorSensors.h \
    GraphView.h \
    Model.h \
    ModifyView.h \
    SensorView.h \
    SensorsDashboard.h \
    SemiConductors.h \
    Sensor.h \
    GasSensor.h \
    MovSens.h \
    SensorsViewer.h \
    SensorsViewerManager.h \
    Style.h \
    TempSensor.h \
    ElettroSensor.h \
    TermoResistance.h \
    TermoCouples.h \
    Accellerometer.h \
    Giroscope.h \
    Controller.h \

QT += widgets
QT += charts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
salvataggio.json

FORMS += \

