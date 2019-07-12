#include "structure.h"
#include <exception>

gds::Structure::Structure(gds::DB *db)
{
    Structure(db, "");
}

gds::Structure::Structure(gds::DB *db, const QString &name)
{
    _parent = db;
    _name = name;
}

void gds::Structure::setName(const QString &name)
{
    _name = name;
}

void gds::Structure::setModifiedAt(const gds::Time &time)
{
    _modifiedAt = time;
}

void gds::Structure::setAccessAt(const gds::Time &time)
{
    _accessAt = time;
}

QString gds::Structure::getName() const
{
    return _name;
}

gds::Time gds::Structure::getModifiedAt() const
{
    return _modifiedAt;
}

gds::Time gds::Structure::getAccessAt() const
{
    return _accessAt;
}






