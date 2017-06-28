QT += core gui sql printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtGastas
TEMPLATE = app
target.path = $${PREFIX}/bin
INSTALLS = target

SOURCES += src/main.cpp\
    src/mainwindow.cpp \
    src/qconsultor.cpp \
    src/nuevomovimiento.cpp \
    src/nuevacuenta.cpp \
    src/nuevacategoria.cpp \
    src/editarmovimientos.cpp \
    src/editarcategorias.cpp

HEADERS += src/mainwindow.h \
    src/qconsultor.h \
    src/nuevomovimiento.h \
    src/nuevacuenta.h \
    src/nuevacategoria.h \
    src/editarmovimientos.h \
    src/editarcategorias.h \
    src/conexion.h

FORMS += src/mainwindow.ui \
    src/qconsultor.ui \
    src/nuevomovimiento.ui \
    src/nuevacuenta.ui \
    src/nuevacategoria.ui \
    src/editarmovimientos.ui \
    src/editarcategorias.ui

