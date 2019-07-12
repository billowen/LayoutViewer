#ifndef GDS_BOUNDARY_H
#define GDS_BOUNDARY_H
#include "element.h"
#include <QRect>
#include <QVector>
#include <QPoint>

namespace gds {

class Structure;

class Boundary : public Element
{
public:
    Boundary(Structure* parent);
    virtual ~Boundary();

    void setEflags(short eflags);
    void setLayer(short layerNum, short dt);
    void setPoints(const QVector<QPoint> &pts);

    short getEflags() const;
    short getLayerNum() const;
    short getDt() const;
    QVector<QPoint> getPoints() const;

    virtual QRect boundingRect() const;
private:
    short _eflags;
    short _layerNum, _dt;
    QVector<QPoint> _pts;
};

}




#endif // BOUNDARY_H
