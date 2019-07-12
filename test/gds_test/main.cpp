#include <QtTest>
#include "misc_test.h"
#include "db_test.h"

int main(int argc, char *argv[])
{
    MiscTest miscTest;
    QTest::qExec(&miscTest, argc, argv);

    DbTest dbTest;
    QTest::qExec(&dbTest, argc, argv);
}

//#include "tst_gdstest.moc"
