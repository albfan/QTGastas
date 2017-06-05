#-------------------------------------------------
#
# Project created by QtCreator 2015-05-23T11:42:19
#
#-------------------------------------------------

QT       += core gui sql printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtGastasSignals
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    qconsultor.cpp \
    nuevomovimiento.cpp \
    nuevacuenta.cpp \
    nuevacategoria.cpp \
    editarmovimientos.cpp \
    editarcategorias.cpp

HEADERS  += mainwindow.h \
    qconsultor.h \
    nuevomovimiento.h \
    nuevacuenta.h \
    nuevacategoria.h \
    editarmovimientos.h \
    editarcategorias.h \
    conexion.h

FORMS    += mainwindow.ui \
    qconsultor.ui \
    nuevomovimiento.ui \
    nuevacuenta.ui \
    nuevacategoria.ui \
    editarmovimientos.ui \
    editarcategorias.ui
