#include "jsonschema.h"
#include "jsonschema_p.h"

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

JsonSchema JsonSchema::fromVariant(const QVariant& variant, JsonSchema::Version version)
{
  JsonSchema schema(version);
  schema.d->root = variant;

  const auto& meta = JsonSchema::metaSchema(version);
  if (!meta.validate(variant))
    return JsonSchema(version);

  return schema;
}

JsonSchema JsonSchema::fromJsonDocument(const QJsonDocument& document, JsonSchema::Version version)
{
  return fromVariant(document.toVariant(), version);
}

JsonSchema JsonSchema::fromJson(const QByteArray& json, JsonSchema::Version version)
{
  return fromJsonDocument(QJsonDocument::fromJson(json), version);
}

JsonSchema JsonSchema::metaSchema(JsonSchema::Version version)
{
  JsonSchema schema(version);

  return schema;
}

bool JsonSchema::validate(const QVariant& variant) const
{
  return true;
}

bool JsonSchema::validate(const QJsonDocument& document) const
{
  return validate(document.toVariant());
}

bool JsonSchema::validate(const QByteArray& json) const
{
  return validate(QJsonDocument::fromJson(json));
}

bool JsonSchema::isValid() const
{
  return true;
}

JsonSchema::JsonSchema(Version version)
  : d(new JsonSchemaPrivate(version))
{
}

JsonSchemaPrivate::JsonSchemaPrivate(JsonSchema::Version version)
{
  this->version = version;
}
