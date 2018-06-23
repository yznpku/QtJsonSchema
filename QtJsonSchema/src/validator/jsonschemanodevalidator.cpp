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

  if (o.contains("enum"))
    errors.append(enumClause(schemaPtr, instancePtr));

  if (o.contains("const"))
    errors.append(constClause(schemaPtr, instancePtr));

  if (instancePtr.v.isDouble()) {
    if (o.contains("multipleOf"))
      errors.append(multipleOfClause(schemaPtr, instancePtr));

    if (o.contains("maximum"))
      errors.append(maximumClause(schemaPtr, instancePtr));

    if (o.contains("exclusiveMaximum"))
      errors.append(exclusiveMaximumClause(schemaPtr, instancePtr));

    if (o.contains("minimum"))
      errors.append(minimumClause(schemaPtr, instancePtr));

    if (o.contains("exclusiveMinimum"))
      errors.append(exclusiveMinimumClause(schemaPtr, instancePtr));
  }

  else if (instancePtr.v.isString()) {
    if (o.contains("maxLength"))
      errors.append(maxLengthClause(schemaPtr, instancePtr));

    if (o.contains("minLength"))
      errors.append(minLengthClause(schemaPtr, instancePtr));
  }

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

QList<JsonSchemaValidationError> JsonSchemaNodeValidator::enumClause(const JsonPointer& schemaPtr, const JsonPointer& instancePtr)
{
  const auto& schemaValue = schemaPtr.v["enum"];
  const auto& instance = instancePtr.v;

  if (schemaValue.toArray().contains(instance))
    return {};

  return {{ schemaPtr, instancePtr, "enum" }};
}

QList<JsonSchemaValidationError> JsonSchemaNodeValidator::constClause(const JsonPointer& schemaPtr, const JsonPointer& instancePtr)
{
  const auto& schemaValue = schemaPtr.v["const"];
  const auto& instance = instancePtr.v;

  if (schemaValue == instance)
    return {};

  return {{ schemaPtr, instancePtr, "const" }};
}

QList<JsonSchemaValidationError> JsonSchemaNodeValidator::multipleOfClause(const JsonPointer& schemaPtr, const JsonPointer& instancePtr)
{
  const auto& schemaValue = schemaPtr.v["multipleOf"].toDouble();
  const auto& instance = instancePtr.v.toDouble();

  if (std::fmod(instance, schemaValue) == 0)
    return {};

  return {{ schemaPtr, instancePtr, "multipleOf" }};
}

QList<JsonSchemaValidationError> JsonSchemaNodeValidator::maximumClause(const JsonPointer& schemaPtr, const JsonPointer& instancePtr)
{
  const auto& schemaValue = schemaPtr.v["maximum"].toDouble();
  const auto& instance = instancePtr.v.toDouble();

  if (instance <= schemaValue)
    return {};

  return {{ schemaPtr, instancePtr, "maximum" }};
}

QList<JsonSchemaValidationError> JsonSchemaNodeValidator::exclusiveMaximumClause(const JsonPointer& schemaPtr, const JsonPointer& instancePtr)
{
  const auto& schemaValue = schemaPtr.v["exclusiveMaximum"].toDouble();
  const auto& instance = instancePtr.v.toDouble();

  if (instance < schemaValue)
    return {};

  return {{ schemaPtr, instancePtr, "exclusiveMaximum" }};
}

QList<JsonSchemaValidationError> JsonSchemaNodeValidator::minimumClause(const JsonPointer& schemaPtr, const JsonPointer& instancePtr)
{
  const auto& schemaValue = schemaPtr.v["minimum"].toDouble();
  const auto& instance = instancePtr.v.toDouble();

  if (instance >= schemaValue)
    return {};

  return {{ schemaPtr, instancePtr, "minimum" }};
}

QList<JsonSchemaValidationError> JsonSchemaNodeValidator::exclusiveMinimumClause(const JsonPointer& schemaPtr, const JsonPointer& instancePtr)
{
  const auto& schemaValue = schemaPtr.v["exclusiveMinimum"].toDouble();
  const auto& instance = instancePtr.v.toDouble();

  if (instance > schemaValue)
    return {};

  return {{ schemaPtr, instancePtr, "exclusiveMinimum" }};
}

QList<JsonSchemaValidationError> JsonSchemaNodeValidator::maxLengthClause(const JsonPointer& schemaPtr, const JsonPointer& instancePtr)
{
  const auto& schemaValue = schemaPtr.v["maxLength"].toInt();
  const auto& instance = instancePtr.v.toString();

  if (instance.length() <= schemaValue)
    return {};

  return {{ schemaPtr, instancePtr, "maxLength" }};
}

QList<JsonSchemaValidationError> JsonSchemaNodeValidator::minLengthClause(const JsonPointer& schemaPtr, const JsonPointer& instancePtr)
{
  const auto& schemaValue = schemaPtr.v["minLength"].toInt();
  const auto& instance = instancePtr.v.toString();

  if (instance.length() >= schemaValue)
    return {};

  return {{ schemaPtr, instancePtr, "minLength" }};
}
