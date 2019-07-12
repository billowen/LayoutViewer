#ifndef GDS_STRUCTURE_H
#define GDS_STRUCTURE_H
#include <QString>
#include "misc.h"

namespace gds {
class DB;

class Structure
{
public:
    Structure(DB* db);
    Structure(DB* db, const QString &name);
    ~Structure() {}

    void setName(const QString &name);
    void setModifiedAt(const Time &time);
    void setAccessAt(const Time &time);

    QString getName() const;
    Time getModifiedAt() const;
    Time getAccessAt() const;

private:

    DB* _parent;        // 拥有当前Structure所有权的db
    QString _name;
    Time _modifiedAt;
    Time _accessAt;
};

}




#endif // STRUCTURE_H
