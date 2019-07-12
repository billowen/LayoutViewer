#include "boundary.h"
#include "structure.h"


gds::Boundary::Boundary(gds::Structure *parent)
    : Element (parent, BOUNDARY)
{
    _layerNum = -1;
    _dt = -1;
    _eflags = 0;
}

gds::Boundary::~Boundary()
{

}

void gds::Boundary::setEflags(short eflags)
{
    _eflags = eflags;
}

void gds::Boundary::setLayer(short layerNum, short dt)
{
    _layerNum = layerNum;
    _dt = dt;
}

void gds::Boundary::setPoints(const QVector<QPoint> &pts)
{
    if (pts.size() < 4) {
        throw std::runtime_error("Boundary should have a minimum of 4 coordinates.");
    }
    if (pts[0].x() != pts.back().x() || pts[0].y() != pts.back().y()) {
        throw std::runtime_error("The first and last coordinates of a boundary must coincide.");
    }
    _pts.clear();
    _pts = pts;
}

short gds::Boundary::getEflags() const
{
    return _eflags;
}

short gds::Boundary::getLayerNum() const
{
    return _layerNum;
}

short gds::Boundary::getDt() const
{
    return _dt;
}

QRect gds::Boundary::boundingRect() const
{
    if (_pts.size() < 4) {
        return QRect(0, 0, 0, 0);
    }
    int x1 = _pts[0].x();
    int y1 = _pts[0].y();
    int x2 = _pts[0].x();
    int y2 = _pts[0].y();

    for (auto p : _pts) {
        x1 = x1 < p.x() ? x1 : p.x();
        y1 = y1 < p.y() ? y1 : p.y();
        x2 = x2 > p.x() ? x2 : p.x();
        y2 = y2 > p.y() ? y2 : p.y();
    }

    return QRect(QPoint(x1, y1), QPoint(x2, y2));
}




