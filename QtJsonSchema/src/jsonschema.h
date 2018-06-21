#ifndef JSONSCHEMA_H
#define JSONSCHEMA_H

#include <QtCore>

class JsonSchemaPrivate;
class JsonSchema
{

public:
  enum Version { Draft04, Draft06, Draft07 };

public:
  JsonSchema(const JsonSchema& other) noexcept;
  JsonSchema(JsonSchema&& other) noexcept
    : d(other.d) { other.d = nullptr; }
  JsonSchema& operator=(const JsonSchema& other) noexcept;
  JsonSchema& operator=(JsonSchema&& other) noexcept
    { swap(other); return *this; }
  void swap(JsonSchema& other) noexcept
    { qSwap(d, other.d); }
  ~JsonSchema();

  static JsonSchema fromVariant(const QVariant& variant, Version version = Draft07);
  static JsonSchema fromJsonDocument(const QJsonDocument& document, Version version = Draft07);
  static JsonSchema fromJson(const QByteArray& json, Version version = Draft07);
  static JsonSchema metaSchema(Version version);

public:
  bool validate(const QVariant& variant) const;
  bool validate(const QJsonDocument& document) const;
  bool validate(const QByteArray& json) const;
  bool isValid() const;

protected:
  JsonSchema(Version version);
  JsonSchemaPrivate* d;
};

#endif // JSONSCHEMA_H
