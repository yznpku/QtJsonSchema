#include <QtCore>
#include <QtTest>

#include "schemavalidationtest.h"

int main()
{
  QTest::qExec(new SchemaValidationTest({
    ":/generic/boolean-schema.json",

    ":/generic/type-clause.json",
    ":/generic/const-clause.json",
    ":/generic/enum-clause.json",

    ":/numeric/multipleOf-clause.json",
    ":/numeric/maximum-clause.json",
    ":/numeric/exclusiveMaximum-clause.json",
    ":/numeric/minimum-clause.json",
    ":/numeric/exclusiveMinimum-clause.json",

    ":/string/maxLength-clause.json",
    ":/string/minLength-clause.json",
    ":/string/pattern-clause.json",

    ":/array/items-clause-group.json",
    ":/array/maxItems-clause.json",
    ":/array/minItems-clause.json",
    ":/array/uniqueItems-clause.json",
    ":/array/contains-clause.json",

    ":/object/maxProperties-clause.json",
    ":/object/minProperties-clause.json",
    ":/object/required-clause.json",
  }));

  return 0;
}
