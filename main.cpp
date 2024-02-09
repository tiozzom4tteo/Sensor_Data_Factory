#include <QApplication>
#include <QStyleFactory>
#include "SensorsViewerManager.h"
#include "Controller.h"
#include "Model.h"
#include "Style.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Style s;
    SensorsViewerManager w;
    Controller c;
    Model m;
    c.setModel(&m);
    c.setViewer(&w);
    w.setController(&c);
    w.show();
    return a.exec();
}
