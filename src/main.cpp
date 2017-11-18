#include "mainwindow.h"
#include "conexion.h"
#include <QApplication>

int main(int argc, char *argv[])
{

    QApplication app(argc, argv);
    QApplication::setApplicationName("qtcash");
    QApplication::setApplicationVersion("1.0.0");

    QCommandLineParser parser;
    parser.setApplicationDescription(QCoreApplication::translate("main", "Control de ingresos y gastos"));
    QCommandLineOption helpOption = parser.addHelpOption();
    parser.addVersionOption();

    QCommandLineOption demoOption(QStringList() << "d" << "demo", QCoreApplication::translate("main", "Añadir datos de prueba."));
    parser.addOption(demoOption);
    QCommandLineOption importOption(QStringList() << "i" << "import", QCoreApplication::translate("main", "Importar datos masivamente."), QCoreApplication::translate("main", "filename"));
    parser.addOption(importOption);

    parser.process(app);
   
    if (parser.isSet(helpOption))
           parser.showHelp(0);

    if(!createConnection(parser.isSet(demoOption)))
        return 1;

    if(parser.isSet(importOption)) {
        if(!importarDatos(parser.value(importOption))) {
            return 1;
        }
    }

    MainWindow w;
    w.show();

    return app.exec();
}
