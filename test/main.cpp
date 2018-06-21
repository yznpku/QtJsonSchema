#include <QtCore>
#include <QtDebug>
#include "jsonschema.h"

int main()
{
  auto schema = JsonSchema::metaSchema(JsonSchema::Draft04);
  return 0;
}
