######################################################################
# Automatically generated by qmake (2.01a) Sal Eki 21 18:51:08 2008
######################################################################

TEMPLATE = app
TARGET = 
DEPENDPATH += .
INCLUDEPATH += .

# Input
HEADERS += AnaPencere.h burn.h client.h pencereclient.h
SOURCES += AnaPencere.cpp main.cpp pencereclient.cpp
RESOURCES += simgeler.qrc
TRANSLATIONS += olric_en.ts

 # install
target.path = $$[QT_INSTALL_EXAMPLES]/meltem/olric sources.files = $$SOURCES *.pro
sources.path = $$[QT_INSTALL_EXAMPLES]/meltem/olric
INSTALLS += target sources
