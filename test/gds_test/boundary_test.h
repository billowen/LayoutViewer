#ifndef BOUNDARY_TEST_H
#define BOUNDARY_TEST_H

#include <QTest>
#include "boundary.h"

class BoundaryTest : public QObject
{
    Q_OBJECT
private slots:
    void test_boundary()
    {
        gds::Boundary polygon(nullptr);

        polygon.setEflags(2);
        QVERIFY(polygon.getEflags() == 2);

        polygon.setLayer(1, 0);
        QVERIFY(polygon.getLayerNum() == 1);
        QVERIFY(polygon.getDt() == 0);


        QVector<QPoint> pts = { QPoint(0, 0), QPoint(5, 0), QPoint(5, 5), QPoint(0, 0)};
        polygon.setPoints(pts);
        QVERIFY(polygon.boundingRect() == QRect(QPoint(0, 0), QPoint(5, 5)));
    }
};

#endif // BOUNDARY_TEST_H
