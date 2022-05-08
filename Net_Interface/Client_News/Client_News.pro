QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += "C:\Users\Tudor\Desktop\Facultate\anul 2\sem2\P_POO\Net_Interface\Net_Interface"
SOURCES += \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    mainwindow.h
    
HEADERS +=
    net_client.h

HEADERS +=
    net_common.h

HEADERS +=
    net_connection.h

HEADERS +=
    net_message.h

HEADERS +=
    net_server.h

HEADERS +=
    net_tsqueue.h

HEADERS +=
    olc_net.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
