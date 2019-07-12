#include "element.h"
#include "structure.h"

gds::Element::Element(gds::Structure *parent, gds::Element::Type type)
{
    _parent = parent;
    _type = type;
}

gds::Element::~Element()
{

}
