#include "jsonpointer.h"

JsonPointer::JsonPointer(const QJsonValue& root)
{
  this->root = root;
  this->v = root;
}

JsonPointer::JsonPointer(const QJsonValue& root, const QJsonValue& v, const QStringList& path)
{
  this->root = root;
  this->v = v;
  this->path = path;
}

JsonPointer JsonPointer::operator[](const QString& key) const
{
  if (v.isObject() && v.toObject().contains(key))
    return JsonPointer(root, v[key], path + QStringList {key});

  return JsonPointer();
}

JsonPointer JsonPointer::operator[](int index) const
{
  if (index >= 0 && v.isArray() && index < v.toArray().size())
    return JsonPointer(root, v[index], path + QStringList {QString::number(index)});

  return JsonPointer();
}

bool JsonPointer::isValid() const
{
  return !root.isNull();
}
