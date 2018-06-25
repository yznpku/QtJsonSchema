#ifndef JSONSCHEMANODEVALIDATOR_H
#define JSONSCHEMANODEVALIDATOR_H

#include <QtCore>
#include "../global.h"
#include "../pointer/jsonpointer.h"
#include "../error/jsonschemavalidationerror.h"

class JsonSchemaNodeValidator
{

public:
  virtual ~JsonSchemaNodeValidator() {}
  static JsonSchemaNodeValidator* getValidator(JsonSchemaVersion::Version version);

  virtual QList<JsonSchemaValidationError> validateNode(const JsonPointer& schemaPtr, const JsonPointer& instancePtr);

protected:
  JsonSchemaNodeValidator() {}

  virtual QList<JsonSchemaValidationError> typeClause(const JsonPointer& schemaPtr, const JsonPointer& instancePtr);
  virtual QList<JsonSchemaValidationError> enumClause(const JsonPointer& schemaPtr, const JsonPointer& instancePtr);
  virtual QList<JsonSchemaValidationError> constClause(const JsonPointer& schemaPtr, const JsonPointer& instancePtr);

  virtual QList<JsonSchemaValidationError> multipleOfClause(const JsonPointer& schemaPtr, const JsonPointer& instancePtr);
  virtual QList<JsonSchemaValidationError> maximumClause(const JsonPointer& schemaPtr, const JsonPointer& instancePtr);
  virtual QList<JsonSchemaValidationError> exclusiveMaximumClause(const JsonPointer& schemaPtr, const JsonPointer& instancePtr);
  virtual QList<JsonSchemaValidationError> minimumClause(const JsonPointer& schemaPtr, const JsonPointer& instancePtr);
  virtual QList<JsonSchemaValidationError> exclusiveMinimumClause(const JsonPointer& schemaPtr, const JsonPointer& instancePtr);

  virtual QList<JsonSchemaValidationError> maxLengthClause(const JsonPointer& schemaPtr, const JsonPointer& instancePtr);
  virtual QList<JsonSchemaValidationError> minLengthClause(const JsonPointer& schemaPtr, const JsonPointer& instancePtr);
  virtual QList<JsonSchemaValidationError> patternClause(const JsonPointer& schemaPtr, const JsonPointer& instancePtr);

  virtual QList<JsonSchemaValidationError> itemsClause(const JsonPointer& schemaPtr, const JsonPointer& instancePtr);
  virtual QList<JsonSchemaValidationError> additionalItemsClause(const JsonPointer& schemaPtr, const JsonPointer& instancePtr);
  virtual QList<JsonSchemaValidationError> maxItemsClause(const JsonPointer& schemaPtr, const JsonPointer& instancePtr);
  virtual QList<JsonSchemaValidationError> minItemsClause(const JsonPointer& schemaPtr, const JsonPointer& instancePtr);
};

#endif // JSONSCHEMANODEVALIDATOR_H
