#ifndef GDS_H
#define GDS_H
#include <QString>
#include <QMap>
#include <QVector>
#include "misc.h"

namespace gds {

class Structure;


class DB
{
public:
    DB() {}
    ~DB() {}

    void setVersion(short version);
    void setModifiedAt(const Time &time);
    void setAccessAt(const Time &time);
    void setLibName(const QString &libName);
    void setDbUnitInMeter(double dbUnitInMeter);
    void setDbUnitInUserUnit(double dbUnitInUserUnit);

    short getVersion() const;
    Time getModifiedAt() const;
    Time getAccessAt() const;
    QString getLibName() const;
    double getDbUnitInMeter() const;
    double getDbUnitInUserUnit() const;
    QList<QString> getStructureNames() const;
    Structure* getStructure(const QString &name) const;

    /**
     * @brief 在当前db中添加一个新的structure.
     * @return 新structure的指针.
     */
    Structure *createStructure();
    /**
     * @brief 在当前db中添加一个指定名字的新的structure.
     * @param name structure名字.
     * @return 新structure的指针.
     */
    Structure* createStructure(const QString &name);
    /**
     * @brief 删除一个structure.
     * @param name 需要删除的structure名字.
     */
    void deleteStructure(const QString &name);
    /**
     * @brief 删除一组structure.
     * @param names 需要删除的structure的名字列表.
     */
    void deleteStructures(const QVector<QString> &names);

private:
    /**
     * @brief 重新构建structure索引缓存
     */
    void rebuildStructureIdx();

    short _version;
    Time _modifiedAt;
    Time _accessAt;
    QString _libName;
    double _dbUnitInMeter;
    double _dbUnitInUserUnit;

    QMap<QString, int> _structuresIdx;  // structure名字索引缓存
    QVector<Structure*> _structures;


};

}

#endif // GDS_H
