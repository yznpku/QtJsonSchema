#include "booleanschematest.h"
#include "../common.h"

BooleanSchemaTest::BooleanSchemaTest(QObject* parent) : QObject(parent)
{

}

void BooleanSchemaTest::trueSchema_data()
{
  acceptList_data();

  ADD_ROW << V(true)
          << VL({
                  V(),
                  true,
                  VM({{"hello", 1}}),
                  VL({"world"}),
                  42,
                  "string"
                });
}

void BooleanSchemaTest::trueSchema()
{
  acceptList();
}

void BooleanSchemaTest::falseSchema_data()
{
  rejectList_data();

  ADD_ROW << V(false)
          << VL({
                  V(),
                  true,
                  VM({{"hello", 1}}),
                  VL({"world"}),
                  42,
                  "string"
                });
}

void BooleanSchemaTest::falseSchema()
{
  rejectList();
}
