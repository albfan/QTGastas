#include "mainwindow.h"
#include "conexion.h"
#include <QApplication>

int main(int argc, char *argv[])
{

    QApplication app(argc, argv);
    //QCoreApplication app(argc, argv);
    //QCoreApplication::setApplicationName("QtGastas");
    //QCoreApplication::setApplicationVersion("1.0.0");

    QCommandLineParser parser;
    parser.setApplicationDescription(QCoreApplication::translate("main", "Control de ingresos y gastos"));
    QCommandLineOption helpOption = parser.addHelpOption();
    parser.addVersionOption();

    QCommandLineOption demoOption(QStringList() << "d" << "demo", QCoreApplication::translate("main", "Añadir datos de prueba."));
    parser.addOption(demoOption);

    parser.process(app);
   
    if (parser.isSet(helpOption))
           parser.showHelp(0);

    if(!createConnection(parser.isSet(demoOption)))
        return 1;

    MainWindow w;
    w.show();

    return app.exec();
}
