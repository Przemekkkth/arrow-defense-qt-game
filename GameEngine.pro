greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
    src/arrow.cpp \
    src/fontmanager.cpp \
    src/gamemanager.cpp \
    src/gamescene.cpp \
    src/main.cpp \
    src/pixmapmanager.cpp \
    src/sprite.cpp \
    src/view.cpp

HEADERS += \
    src/arrow.h \
    src/arrowshape.h \
    src/fontmanager.h \
    src/gamemanager.h \
    src/gamescene.h \
    src/pixmapmanager.h \
    src/resourceholder.h \
    src/sprite.h \
    src/utils.h \
    src/view.h

RESOURCES += \
    resource.qrc
