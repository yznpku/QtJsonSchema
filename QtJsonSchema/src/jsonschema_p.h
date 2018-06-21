#ifndef JSONSCHEMA_P_H
#define JSONSCHEMA_P_H

#include "jsonschema.h"

class JsonSchemaPrivate
{
public:
  QAtomicInt ref;

  JsonSchema::Version version;
  QVariant root;
  bool valid {false};

public:
  JsonSchemaPrivate(JsonSchema::Version version);
};

#endif // JSONSCHEMA_P_H
