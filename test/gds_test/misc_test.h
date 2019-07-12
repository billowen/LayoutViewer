#ifndef MISC_TEST_H
#define MISC_TEST_H

#include <QTest>
#include "misc.h"

class MiscTest : public QObject
{
    Q_OBJECT
private slots:
    void test_Time()
    {
        gds::Time time(2019, 7, 12, 16, 42, 0);
        QVERIFY(time.year == 2019);
        QVERIFY(time.month == 7);
        QVERIFY(time.day == 12);
        QVERIFY(time.hour == 16);
        QVERIFY(time.minute == 42);
        QVERIFY(time.second == 0);
    }
};

#endif // MISC_TEST_H
