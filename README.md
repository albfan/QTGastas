# QTGastas

Aplicación para gestionar los ingresos y gastos de un usuario.

## Compilar

requiere Qt5

    $ cd repo
    $ mkdir build
    $ cd build
    $ qmake PREFIX=/usr/local ..
    $ make
    $ sudo make install

## Ejecutar

    $ QtGastas

## Opciones

    $ QtGastas --help

- demo: Se creará una base de datos de prueba. Los pdf se crearán en el directorio de ejecución.

## Gastos periodicos:

Para probar la inserción de datos programados, insertar un movimiento programado con el dia actual, mes, año y ponerle una PERIOCIDAD y volver a ejecutar la aplicacion.
