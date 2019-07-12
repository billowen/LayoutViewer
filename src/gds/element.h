#ifndef GDS_ELEMENT_H
#define GDS_ELEMENT_H
#include <QString>
#include <QRect>

namespace gds {
class Structure;

class Element
{
public:
    enum Type {
        UNKOWN = 0,
        BOUNDARY,
        PATH,
        AREF,
        SREF,
        TEXT,
    };


    Element(Structure* parent, Type type);
    virtual ~Element();

    virtual QRect boundingRect() const = 0;
protected:
    Type _type;
    Structure* _parent;
};

}




#endif // ELEMENT_H
