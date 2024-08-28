TEMPLATE = app
TARGET = dialStyles
CONFIG += C++17
QT += core \
    gui \
    widgets
HEADERS += ClassicStyle.h \
    PeppinoStyle.h \
    SkulptureStyle.h \
    dialstyles.h \
    VokiStyle.h
SOURCES += ClassicStyle.cpp \
    PeppinoStyle.cpp \
    SkulptureStyle.cpp \
    dialstyles.cpp \
    VokiStyle.cpp \
    main.cpp
FORMS += dialstyles.ui
