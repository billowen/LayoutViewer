#ifndef DB_TEST_H
#define DB_TEST_H
#include "gds.h"
#include "structure.h"
#include <QTest>
#include <memory>

class DbTest : public QObject
{
    Q_OBJECT
private slots:
    void test_create_delete_structure()
    {
        std::unique_ptr<gds::DB> db = std::make_unique<gds::DB>();
        db->createStructure(QString("abc"));
        db->createStructure(QString("cba"));
        QVERIFY(db->getStructure("abc") != nullptr);
        QVERIFY(db->getStructure("cba") != nullptr);
        db->deleteStructure("cba");
        QVERIFY(db->getStructure("cba") == nullptr);

        db->createStructure("s1");
        db->createStructure("s2");
        db->deleteStructures(QVector<QString> {"s1", "s2"});
        QVERIFY(db->getStructure("s1") == nullptr);
        QVERIFY(db->getStructure("s2") == nullptr);
    }

};

#endif // DB_TEST_H
