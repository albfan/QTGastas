#include "mainwindow.h"
#include "conexion.h"
#include "qconsultor.h"
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

    QCommandLineOption createDatabaseOption(QStringList() << "c" << "create", QCoreApplication::translate("main", "Crear base de datos."));
    parser.addOption(createDatabaseOption);

    QCommandLineOption databaseFilePathOption(QStringList() << "database-filepath", QCoreApplication::translate("main", "Ruta de base de datos."), QCoreApplication::translate("main", "databaseFilePath"), "baseDatos.sqlite");
    parser.addOption(databaseFilePathOption);

    QCommandLineOption importOption(QStringList() << "i" << "import", QCoreApplication::translate("main", "Importar datos masivamente."), QCoreApplication::translate("main", "filename"));
    parser.addOption(importOption);

    QCommandLineOption typeOption(QStringList() << "t" << "type", QCoreApplication::translate("main", "Tipo de importación: accounts o movements."), QCoreApplication::translate("main", "type"));
    parser.addOption(typeOption);
    parser.process(app);
   
    if (parser.isSet(helpOption)) {
        parser.showHelp(0);
    }

    QString dbFilePath = parser.value(databaseFilePathOption);

    QConsultor* consultor = new QConsultor(dbFilePath);

    if (parser.isSet(createDatabaseOption)) {
        if(!createDataBase(consultor)) {
            return 1;
        }
    }

    if (parser.isSet(demoOption)) {
        if (!insertarDatosPrueba(consultor)) {
           return false;
        }
    }

    if(parser.isSet(importOption)) {
        QString fileName = parser.value(importOption);
        bool isSetTypeOption = parser.isSet(typeOption);
        if(!isSetTypeOption) {
            if(!importarDatos(consultor, fileName)) {
                qDebug() << "error importando movimientos de " << fileName << endl;
                return 1;
            }
        } else {
            QString type = parser.value(typeOption).toLower();
            if ("accounts" == type) {
                if(!importarCuentas(consultor, fileName)) {
                    qDebug() << "error importando cuentas de " << fileName << endl;
                    return 1;
                }
            } else if ("movements" == type) {
                if(!importarDatos(consultor, fileName)) {
                    qDebug() << "error importando movimientos de " << fileName << endl;
                    return 1;
                }
            } else {
                qDebug() << "tipo de importación " << type << " desconocido" << endl;
                return 1;
            }
        }
    }

    MainWindow w(consultor);
    w.show();

    return app.exec();
}
