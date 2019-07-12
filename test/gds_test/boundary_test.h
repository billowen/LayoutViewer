#ifndef BOUNDARY_TEST_H
#define BOUNDARY_TEST_H

#include <QTest>
#include "boundary.h"

class BoundaryTest : public QObject
{
    Q_OBJECT
private slots:
    void test_boundingRect()
    {
        gds::Boundary polygon(nullptr);

        QVector<QPoint> pts = { QPoint(0, 0), QPoint(5, 0), QPoint(5, 5), QPoint(0, 0)};
        polygon.setPoints(pts);
        QRect box = polygon.boundingRect();
        QVERIFY(polygon.boundingRect() == QRect(QPoint(0, 0), QPoint(5, 5)));
    }
};

#endif // BOUNDARY_TEST_H
