#ifndef CONEXION
#define CONEXION

#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QApplication>

static bool insertarDatosPrueba(QConsultor* consultor) {
    if (!consultor->AbrirDB()) {
        return false;
    }

    QSqlQuery query;

    //INSERTAR CATEGORIAS
    if(!query.exec("INSERT INTO categorias VALUES(1,0,0,'ropa');"))
        qDebug() <<    query.lastError().text() << endl;

    query.exec("INSERT INTO categorias VALUES(2,0,0,'alimentacion');");
    query.exec("INSERT INTO categorias VALUES(3,0,0,'universidad');");
    query.exec("INSERT INTO categorias VALUES(4,0,0,'ocio');");
    query.exec("INSERT INTO categorias VALUES(5,0,0,'fiestas');");
    query.exec("INSERT INTO categorias VALUES(6,0,0,'coche');");
    query.exec("INSERT INTO categorias VALUES(7,0,0,'casa');");
    query.exec("INSERT INTO categorias VALUES(8,0,0,'viajes');");
    query.exec("INSERT INTO categorias VALUES(9,0,0,'telefono');");
    query.exec("INSERT INTO categorias VALUES(10,0,0,'tecnologia');");
    query.exec("INSERT INTO categorias VALUES(11,0,0,'becas');");
    query.exec("INSERT INTO categorias VALUES(12,0,0,'trabajo');");
    query.exec("INSERT INTO categorias VALUES(13,0,0,'online');");
    query.exec("INSERT INTO categorias VALUES(14,0,0,'ayudas');");
    query.exec("INSERT INTO categorias VALUES(15,0,0,'tecnico');");
    query.exec("INSERT INTO categorias VALUES(16,1,1,'calzado');");
    query.exec("INSERT INTO categorias VALUES(17,1,1,'camisetas');");
    query.exec("INSERT INTO categorias VALUES(18,2,1,'comida');");
    query.exec("INSERT INTO categorias VALUES(19,2,1,'bebida');");
    query.exec("INSERT INTO categorias VALUES(20,16,2,'deportivo');");
    query.exec("INSERT INTO categorias VALUES(21,16,2,'botas');");
    query.exec("INSERT INTO categorias VALUES(22,13,1,'ebay');");
    query.exec("INSERT INTO categorias VALUES(23,13,1,'amazon');");
    query.exec("INSERT INTO categorias VALUES(24,12,1,'pescadero');");
    query.exec("INSERT INTO categorias VALUES(25,12,1,'noche');");

    //SI EXISTE TABLA CUENTAS SE BORRA
    //query.exec("DROP TABLE IF EXISTS cuentas;");

    //SE INSERTAN 3 CUENTAS POR DEFECTO
    query.exec("INSERT INTO cuentas VALUES(1,'banco',3000,1000);");
    query.exec("INSERT INTO cuentas VALUES(2,'tarjeta',300,500);");
    query.exec("INSERT INTO cuentas VALUES(3,'efectivo',1000,1000);");

    //SI LA TABLA DE MOVIMIENTOS EXITE SE BORRA
    // query.exec("DROP TABLE IF EXISTS movimientos;");

    //SE INSERTAN ALGUNOS MOVIMIENTOS
    query.exec("INSERT INTO movimientos VALUES(2,1,'ingreso',12,156.31,'trabajo dia 2','23/05/2015 17:26:09','29/06/2015','Cada mes');");
    query.exec("INSERT INTO movimientos VALUES(3,1,'ingreso',12,300.21,'trabajo dia 3','27/04/2015 17:26:09','28/08/2015','Cada año');");
    query.exec("INSERT INTO movimientos VALUES(4,1,'ingreso',12,54,'trabajo dia 4','23/05/2015 17:26:09','19/07/2015','Cada dos meses');");
    query.exec("INSERT INTO movimientos VALUES(5,1,'ingreso',12,41.31,'trabajo dia 5','23/05/2015 17:26:09',NULL,NULL);");
    query.exec("INSERT INTO movimientos VALUES(6,1,'gasto',1,-123.32,'camiseta roja','25/03/2015 17:26:09',NULL,NULL);");
    query.exec("INSERT INTO movimientos VALUES(7,1,'gasto',1,-123.32,'pantalones azules','16/03/2015 17:26:09',NULL,NULL);");
    query.exec("INSERT INTO movimientos VALUES(8,1,'gasto',1,-123.32,'sudadera','23/05/2015 17:26:10',NULL,NULL);");
    query.exec("INSERT INTO movimientos VALUES(9,1,'gasto',1,-123.32,'guantes futbol','23/04/2015 17:26:10',NULL,NULL);");
    query.exec("INSERT INTO movimientos VALUES(10,1,'gasto',1,-123.32,'chaueta marron','23/05/2015 17:26:10',NULL,NULL);");
    query.exec("INSERT INTO movimientos VALUES(11,2,'ingreso',14,123.32,'ayuda 1','23/05/2015 17:26:10',NULL,NULL);");
    query.exec("INSERT INTO movimientos VALUES(12,2,'ingreso',14,59.2,'ayuda 2','23/05/2015 17:26:10',NULL,NULL);");
    query.exec("INSERT INTO movimientos VALUES(13,2,'ingreso',14,142.21,'ayuda 3','23/02/2015 17:26:10',NULL,NULL);");
    query.exec("INSERT INTO movimientos VALUES(14,2,'ingreso',14,523.23,'ayuda 4','23/05/2015 17:26:10',NULL,NULL);");
    query.exec("INSERT INTO movimientos VALUES(15,2,'ingreso',14,45.2,'ayuda 5','16/04/2015 17:26:10',NULL,NULL);");
    query.exec("INSERT INTO movimientos VALUES(16,2,'gasto',25,-123.32,'salida disco','23/05/2015 17:26:11',NULL,NULL);");
    query.exec("INSERT INTO movimientos VALUES(17,2,'gasto',25,-123.32,'bebidas','23/05/2015 17:26:11',NULL,NULL);");
    query.exec("INSERT INTO movimientos VALUES(18,2,'gasto',6,-123.32,'reparacion chapa','23/05/2015 17:26:11',NULL,NULL);");
    query.exec("INSERT INTO movimientos VALUES(19,2,'gasto',6,-123.32,'cambio aceite','19/04/2015 17:26:11',NULL,NULL);");
    query.exec("INSERT INTO movimientos VALUES(20,2,'gasto',6,-123.32,'arreglar frenos','23/05/2015 17:26:11',NULL,NULL);");
    query.exec("INSERT INTO movimientos VALUES(21,3,'ingreso',15,58.99,'reparar movil','23/05/2015 17:26:11',NULL,NULL);");
    query.exec("INSERT INTO movimientos VALUES(22,3,'ingreso',15,188.31,'reparar lavadora','26/03/2015 17:26:11',NULL,NULL);");
    query.exec("INSERT INTO movimientos VALUES(23,3,'ingreso',15,356.21,'reparar pc','23/05/2015 17:26:12',NULL,NULL);");
    query.exec("INSERT INTO movimientos VALUES(24,3,'ingreso',15,55,'formatear pc amigo','23/05/2015 17:26:12',NULL,NULL);");
    query.exec("INSERT INTO movimientos VALUES(25,3,'ingreso',15,47.22,'reparar pantalla','13/02/2015 17:26:12',NULL,NULL);");
    query.exec("INSERT INTO movimientos VALUES(26,3,'gasto',4,-123.32,'fiesta','23/02/2015 17:26:12',NULL,NULL);");
    query.exec("INSERT INTO movimientos VALUES(27,3,'gasto',4,-123.32,'fiesta','23/05/2014 17:26:12',NULL,NULL);");
    query.exec("INSERT INTO movimientos VALUES(28,3,'gasto',4,-123.32,'fiesta','23/04/2014 17:26:12',NULL,NULL);");
    query.exec("INSERT INTO movimientos VALUES(29,3,'gasto',4,-123.32,'fiesta','23/03/2014 17:26:12',NULL,NULL);");
    query.exec("INSERT INTO movimientos VALUES(30,3,'gasto',4,-123.32,'fiesta','13/04/2014 17:26:12',NULL,NULL);");
    query.exec("INSERT INTO movimientos VALUES(30,3,'ingreso',4,523.32,'venta coche','13/03/2015 21:26:12',NULL,NULL);");

    consultor->CerrarDB();

    return true;
}

int importarCuenta(QString iban, QString description, QString balance) {
    int cuentaId;

    QSqlDatabase::database().transaction();
    QSqlQuery query;

    query.prepare("SELECT idCuenta FROM cuentas WHERE iban = :iban");
    query.bindValue(":iban",iban);
    query.exec();
    cuentaId = 0;
    if(query.next()){
        qDebug() << "la cuenta con iban " << iban << " ya existe" << endl;
        cuentaId = query.value(0).toInt();
    } else {
        if(!query.exec("INSERT INTO cuentas(nombreCuenta, iban, limite, ingresoInicial) VALUES('"
                       + description + "', '" + iban + "',600, " + balance + ");")) {
            qDebug() << query.lastError().text() << endl;
        } else {
            cuentaId = query.lastInsertId().toInt();
        }
    }

    return cuentaId;
}

static bool importarCuentas(QConsultor* consultor, QString fileName) {
    QFile loadFile(fileName);
    bool result = true;

    result = consultor->AbrirDB();

    if (!result) {
        return result;
    }

    if(loadFile.exists() && loadFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QByteArray saveData = loadFile.readAll();
        QJsonDocument jsonDoc(QJsonDocument::fromJson(saveData));

        QJsonObject accountsJson = jsonDoc.object();

        QJsonArray accountsArray = accountsJson["accounts"].toArray();
        for (int accountsIndex = 0; accountsIndex < accountsArray.size(); ++accountsIndex) {
            QJsonObject accountObject = accountsArray[accountsIndex].toObject();

            QString iban = accountObject["iban"].toString();
            QString name = accountObject["name"].toString();

            QString description = accountsJson["description"].toString();
            QString amount = accountObject["amount"].toObject()["fractional"].toString();

            int cuentaId = importarCuenta(iban, description, amount);

            if (cuentaId == 0) {
                qDebug() << "error creando cuenta con iban "+iban << endl;
                result = false;
            }
        }
    }

    consultor->CerrarDB();

    return result;
}

static bool importarDatos(QConsultor* consultor, QString fileName) {
    QFile loadFile(fileName);
    int cuentaId;
    int categId;

    if (!consultor->AbrirDB()) {
        return false;
    }

    if(loadFile.exists() && loadFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QByteArray saveData = loadFile.readAll();
        QJsonDocument jsonDoc(QJsonDocument::fromJson(saveData));

        QJsonObject transactionJson = jsonDoc.object();
        QString iban = transactionJson["account"].toObject()["iban"].toString();
        QString description = transactionJson["account"].toObject()["description"].toString();

        //TODO: Obtener de account
        QString balance("0");

        cuentaId = importarCuenta(iban, description, balance);

        if (cuentaId == 0) {
            qDebug() << "error creando cuenta con iban "+iban << endl;
            return false;
        }

        categId = 0;
        QString categoriaDesc = "importación";

        QSqlDatabase::database().transaction();
        QSqlQuery query;

        query.prepare("SELECT categId FROM categorias WHERE nombreCateg = :descripcion");
        query.bindValue(":descripcion", categoriaDesc);
        query.exec();
        if(query.next()){
            categId = query.value(0).toInt();
        } else {
            query.prepare("INSERT INTO categorias(idCategPadre, nivel, nombreCateg) VALUES(0,0,:categoriaDesc);");
            query.bindValue(":categoriaDesc", categoriaDesc);
            if(!query.exec()) {
                qDebug() << query.lastError().text() << endl;
            } else {
                categId = query.lastInsertId().toInt();
            }
        }

        if (categId == 0) {
            qDebug() << "error creando categoría "+categoriaDesc << endl;
            return false;
        }

        QJsonArray transactionArray = transactionJson["transactions"].toArray();
        for (int transactionIndex = 0; transactionIndex < transactionArray.size(); ++transactionIndex) {
            QJsonObject transactionObject = transactionArray[transactionIndex].toObject();
            QString date = transactionObject["date"].toString();
            QString description = transactionObject["description"].toString();
            QString amount = transactionObject["amount"].toObject()["fractional"].toString();
            amount.remove(amount.length() - 2, 2);
            amount.insert(amount.length() - 2, ".");
            query.prepare("INSERT INTO movimientos (cuentaId,tipoMov,categId,importe,descripcion,data) VALUES(:cuentaId,:tipoMov,:categId,:importe,:desc,:fecha)");

            QString tipoMov(amount.startsWith("-")? "gasto": "ingreso");
            query.bindValue(":cuentaId", cuentaId);
            query.bindValue(":tipoMov", tipoMov);
            query.bindValue(":categId", categId);
            query.bindValue(":importe", amount);
            query.bindValue(":desc", description);
            query.bindValue(":fecha", date + " 12:00:00");
            if (!query.exec()) {
                qDebug() << query.lastError().text() << endl;
                return false;
            }
        }

        QSqlDatabase::database().commit();
        return true;
    } else {
        return false;
    }

    consultor->CerrarDB();
}

static bool createDataBase(QConsultor* consultor) {

    if (!consultor->AbrirDB()) {
        return false;
    }

    QSqlQuery query;

    //para que se activen las claves ajenas
    if(!query.exec("PRAGMA foreign_keys = ON;")) {
        qDebug() << query.lastError().text() << endl;
    }

    //TABLE DE CATEGORIAS
    if(!query.exec("CREATE TABLE categorias(idCateg INTEGER PRIMARY KEY,idCategPadre INTEGER,nivel INT,nombreCateg TEXT);")) {
        qDebug() << query.lastError().text() << endl;
    }

    //SE CREA LA TABLA DE CUENTAS
    if(!query.exec("CREATE TABLE cuentas(idCuenta INTEGER PRIMARY KEY,nombreCuenta TEXT, iban TEXT, limite REAL,ingresoInicial REAL);")) {
        qDebug() << query.lastError().text() << endl;
    }

    //CREA LA TABLA DE MOVIMIENTOS
    if(!query.exec("CREATE TABLE movimientos(idMov INTEGER,cuentaId INTEGER,tipoMov TEXT,"
                   "categId INTEGER,importe REAL,descripcion TEXT,data TEXT, dataProgramada TEXT, "
                   "periocidad TEXT,PRIMARY KEY (idMov),FOREIGN KEY(cuentaId) REFERENCES cuentas(idCuenta), "
                   "FOREIGN KEY(categId) REFERENCES categorias(idCateg));")) {
        qDebug() << query.lastError().text() << endl;
    }

    if(!query.exec("CREATE VIEW VistaCategorias AS "
                   "select idCateg as ID, nombreCateg as NOMBRE,"
                   "idCategPadre as PADRE from categorias where nivel = 0;")) {
        qDebug() << query.lastError().text() << endl;
    }

    if(!query.exec("CREATE VIEW VistaSubCateg AS select idCateg,nombreCateg, "
                   "idCategPadre from categorias where nivel = 1; ")) {
        qDebug() << query.lastError().text() << endl;
    }

    if(!query.exec("CREATE VIEW VistaSubSubCateg AS    select idCateg,nombreCateg,"
                   " idCategPadre from categorias where nivel = 2;")) {
        qDebug() << query.lastError().text() << endl;
    }

    if(!query.exec("CREATE VIEW VistaFinalSub AS  "
                   " select idCateg as ID, nombreCateg as NOMBRE, NOMBRE as PADRE "
                   " from VistaSubCateg as VS  inner join VistaCategorias as VC "
                   " on VS.idCategPadre = VC.ID;")) {
        qDebug() << query.lastError().text() << endl;
    }

    if(!query.exec("CREATE VIEW VistaFinalSubSub AS "
                   " select VSS.idCateg as ID, VSS.nombreCateg as NOMBRE, VS.nombreCateg as PADRE"
                   " from VistaSubSubCateg as VSS inner join VistaSubCateg as VS "
                   " on VSS.idCategPadre = VS.idCateg;")) {
        qDebug() << query.lastError().text() << endl;
    }

    if(!query.exec("CREATE VIEW VistaMovimientos AS "
                   " select descripcion as DESCRIPCION, tipoMov as TIPO, importe as IMPORTE,"
                   " nombreCateg as CATEGORIA, nombreCuenta as CUENTA, data as FECHA, dataProgramada as FECHAPROG, periocidad as PERIOCIDAD"
                   " from movimientos as MOV "
                   " inner join categorias as CAT on  MOV.categId = CAT.idCateg"
                   " inner join cuentas as CUE on MOV.cuentaID = CUE.idCuenta"
                   " where PERIOCIDAD is null;")) {
        qDebug() << query.lastError().text() << endl;
    }

    if(!query.exec("CREATE VIEW VistaProgramada AS "
                   " select descripcion as DESCRIPCION, tipoMov as TIPO, importe as IMPORTE,"
                   " nombreCateg as CATEGORIA, nombreCuenta as CUENTA, data as FECHA, dataProgramada as FECHAPROG, periocidad as PERIOCIDAD"
                   " from movimientos as MOV "
                   " inner join categorias as CAT on  MOV.categId = CAT.idCateg"
                   " inner join cuentas as CUE on MOV.cuentaID = CUE.idCuenta"
                   " where PERIOCIDAD is not null;")) {

        qDebug() << query.lastError().text() << endl;
    }

    consultor->CerrarDB();

    return true;
}
#endif // CONEXION

