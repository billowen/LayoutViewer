#include "gds.h"
#include "structure.h"
#include <algorithm>

void gds::DB::setVersion(short version)
{
    _version = version;
}

void gds::DB::setModifiedAt(const gds::Time &time)
{
    _modifiedAt = time;
}

void gds::DB::setAccessAt(const gds::Time &time)
{
    _accessAt = time;
}

void gds::DB::setLibName(const QString &libName)
{
    _libName = libName;
}

void gds::DB::setDbUnitInMeter(double dbUnitInMeter)
{
    _dbUnitInMeter = dbUnitInMeter;
}

void gds::DB::setDbUnitInUserUnit(double dbUnitInUserUnit)
{
    _dbUnitInUserUnit = dbUnitInUserUnit;
}

short gds::DB::getVersion() const
{
    return _version;
}

gds::Time gds::DB::getModifiedAt() const
{
    return _modifiedAt;
}

gds::Time gds::DB::getAccessAt() const
{
    return _accessAt;
}

QString gds::DB::getLibName() const
{
    return _libName;
}

double gds::DB::getDbUnitInMeter() const
{
    return _dbUnitInMeter;
}

double gds::DB::getDbUnitInUserUnit() const
{
    return _dbUnitInUserUnit;
}

QList<QString> gds::DB::getStructureNames() const
{
    return _structuresIdx.keys();
}

gds::Structure *gds::DB::getStructure(const QString &name) const
{
    if (!_structuresIdx.contains(name)) {
        return nullptr;
    }

    return _structures[_structuresIdx[name]];
}

gds::Structure *gds::DB::createStructure()
{
    return createStructure("");
}

gds::Structure *gds::DB::createStructure(const QString &name)
{
    if (_structuresIdx.contains(name)) {
        throw std::runtime_error("The structure name has been used.");
    }

    Structure *ptr = new Structure(this, name);
    _structures.push_back(ptr);
    _structuresIdx.insert(name, _structures.size() - 1);
    return ptr;
}

void gds::DB::deleteStructure(const QString &name)
{
    if (_structuresIdx.contains(name)) {
        _structures.remove(_structuresIdx[name]);
        rebuildStructureIdx();
    }
}

void gds::DB::deleteStructures(const QVector<QString> &names)
{
    QVector<int> idxList;
    for (auto name : names) {
        if (_structuresIdx.contains(name)) {
            idxList.push_back(_structuresIdx[name]);
        }
    }
    if (idxList.size() > 0) {
        std::sort(idxList.begin(), idxList.end());
        for (auto i = idxList.size() - 1; i >= 0; i--) {
            _structures.remove(idxList[i]);
        }
        rebuildStructureIdx();
    }
}

void gds::DB::rebuildStructureIdx()
{
    _structuresIdx.clear();
    for (auto i = 0; i < _structures.size(); i++) {
        _structuresIdx.insert(_structures[i]->getName(), i);
    }
}

