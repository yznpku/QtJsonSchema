#include "jsonschema.h"
#include "jsonschema_p.h"
#include "validator/jsonschemanodevalidator.h"

JsonSchema::JsonSchema(const JsonSchema& other) noexcept
  : d(other.d)
{
  if (d)
    d->ref.ref();
}

JsonSchema& JsonSchema::operator=(const JsonSchema& other) noexcept
{
  if (other.d)
    other.d->ref.ref();
  if (d && !d->ref.deref())
    delete d;
  d = other.d;
  return *this;
}

JsonSchema::~JsonSchema()
{
  if (d && !d->ref.deref())
    delete d;
}

JsonSchema JsonSchema::fromJson(const QJsonValue& json, JsonSchemaVersion::Version version)
{
  JsonSchema schema(version);
  auto d = schema.d;

  const auto& meta = JsonSchema::metaSchema(version);
  if (!meta.validate(json))
    return JsonSchema(version);

  d->setSchema(json);
  return schema;
}

JsonSchema JsonSchema::fromVariant(const QVariant& variant, JsonSchemaVersion::Version version)
{
  return fromJson(QJsonValue::fromVariant(variant), version);
}

JsonSchema JsonSchema::fromJsonDocument(const QJsonDocument& document, JsonSchemaVersion::Version version)
{
  return fromVariant(document.toVariant(), version);
}

JsonSchema JsonSchema::fromJsonString(const QByteArray& json, JsonSchemaVersion::Version version)
{
  return fromJsonDocument(QJsonDocument::fromJson(json), version);
}

JsonSchema JsonSchema::metaSchema(JsonSchemaVersion::Version version)
{
  JsonSchema schema(version);
  schema.d->setSchema(QJsonValue(QJsonValue::Object));
  return schema;
}

bool JsonSchema::validate(const QJsonValue& instance) const
{
  const auto& errors = d->validator->validate(JsonPointer(instance));
  return errors.isEmpty();
}

bool JsonSchema::validate(const QVariant& instance) const
{
  return validate(QJsonValue::fromVariant(instance));
}

bool JsonSchema::validate(const QJsonDocument& instance) const
{
  return validate(instance.toVariant());
}

bool JsonSchema::validate(const QByteArray& instance) const
{
  return validate(QJsonDocument::fromJson(instance));
}

bool JsonSchema::isValid() const
{
  return true;
}

JsonSchema::JsonSchema(JsonSchemaVersion::Version version)
  : d(new JsonSchemaPrivate(version))
{
}

JsonSchemaPrivate::JsonSchemaPrivate(JsonSchemaVersion::Version version)
{
  this->version = version;
  validator.reset(JsonSchemaNodeValidator::getValidator(version));
}

void JsonSchemaPrivate::setSchema(const QJsonValue& schema)
{
  validator->setSchema(schema);
}
