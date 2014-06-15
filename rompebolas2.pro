TEMPLATE = app

QT += qml quick widgets

SOURCES += main.cpp \
    lib/motor/automata.cpp \
    lib/motor/estadojuego.cpp \
    lib/motor/motor.cpp \
    lib/board/board.cpp

RESOURCES += qml.qrc \
    img/res.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH = /home/leandro/dev/qt/rompebolas2/

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    lib/motor/automata.h \
    lib/motor/estadojuego.h \
    lib/motor/motor.h \
    lib/board/board.h
