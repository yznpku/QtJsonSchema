#include <QtCore>
#include <QtDebug>
#include "jsonschema.h"

int main()
{
  auto schema = JsonSchema::fromVariant(QVariantMap {{"type", "string"}});
  auto instance1 = QVariant("hello");
  auto instance2 = QVariant(42);

  qDebug() << schema.validate(instance1);
  qDebug() << schema.validate(instance2);

  return 0;
}
