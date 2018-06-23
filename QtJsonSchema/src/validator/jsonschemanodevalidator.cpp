#include "jsonschemanodevalidator.h"
#include <cmath>

JsonSchemaNodeValidator* JsonSchemaNodeValidator::getValidator(JsonSchemaVersion::Version version)
{
  return new JsonSchemaNodeValidator();
}

QList<JsonSchemaValidationError> JsonSchemaNodeValidator::validateNode(const JsonPointer& schemaPtr, const JsonPointer& instancePtr)
{
  const auto& schema = schemaPtr.v;

  if (schema.isBool()) {
    if (schema.toBool())
      return {};
    else
      return {{ schemaPtr, instancePtr, "schema is false" }};
  }

  const auto& o = schema.toObject();
  QList<JsonSchemaValidationError> errors;

  if (o.contains("type"))
    errors.append(typeClause(schemaPtr, instancePtr));

  if (o.contains("const"))
    errors.append(constClause(schemaPtr, instancePtr));

  return errors;
}

QList<JsonSchemaValidationError> JsonSchemaNodeValidator::typeClause(const JsonPointer& schemaPtr, const JsonPointer& instancePtr)
{
  enum Type {
    TYPE_NULL = 1,
    TYPE_BOOLEAN,
    TYPE_OBJECT,
    TYPE_ARRAY,
    TYPE_NUMBER,
    TYPE_STRING,
    TYPE_INTEGER,
  };
  static QHash<QString, Type> typeHash {
    { "null", TYPE_NULL },
    { "boolean", TYPE_BOOLEAN },
    { "object", TYPE_OBJECT },
    { "array", TYPE_ARRAY },
    { "number", TYPE_NUMBER },
    { "string", TYPE_STRING },
    { "integer", TYPE_INTEGER },
  };
  bool acceptType[] = { false, false, false, false, false, false, false, false };

  const auto& schemaValue = schemaPtr.v["type"];
  const auto& instance = instancePtr.v;

  if (schemaValue.isString())
    acceptType[typeHash[schemaValue.toString()]] = true;

  else if (schemaValue.isArray()) {
    const auto& array = schemaValue.toArray();
    for (int i = 0; i < array.size(); i++)
      acceptType[typeHash[array[i].toString()]] = true;
  }

  if (acceptType[TYPE_NULL])
    if (instance.isNull())
      return {};

  if (acceptType[TYPE_BOOLEAN])
    if (instance.isBool())
      return {};

  if (acceptType[TYPE_OBJECT])
    if (instance.isObject())
      return {};

  if (acceptType[TYPE_ARRAY])
    if (instance.isArray())
      return {};

  if (acceptType[TYPE_NUMBER])
    if (instance.isDouble())
      return {};

  if (acceptType[TYPE_STRING])
    if (instance.isString())
      return {};

  if (acceptType[TYPE_INTEGER])
    if (instance.isDouble()) {
      double intpart;
      if (std::modf(instance.toDouble(), &intpart) == 0.0)
        return {};
    }

  return {{ schemaPtr, instancePtr, "type" }};
}

QList<JsonSchemaValidationError> JsonSchemaNodeValidator::constClause(const JsonPointer& schemaPtr, const JsonPointer& instancePtr)
{
  const auto& schemaValue = schemaPtr.v["const"];
  const auto& instance = instancePtr.v;

  if (schemaValue != instance)
    return {{ schemaPtr, instancePtr, "const" }};

  return {};
}
