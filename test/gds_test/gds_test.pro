QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  \
    main.cpp

HEADERS += \
    boundary_test.h \
    db_test.h \
    misc_test.h

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../src/gds/release/ -lgds
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../src/gds/debug/ -lgds
else:unix: LIBS += -L$$OUT_PWD/../../src/gds/ -lgds

INCLUDEPATH += $$PWD/../../src/gds
DEPENDPATH += $$PWD/../../src/gds

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../src/gds/release/libgds.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../src/gds/debug/libgds.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../src/gds/release/gds.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../src/gds/debug/gds.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../../src/gds/libgds.a
