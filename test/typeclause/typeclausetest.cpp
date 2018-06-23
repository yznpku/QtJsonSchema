#include "typeclausetest.h"
#include "../common.h"

TypeClauseTest::TypeClauseTest(QObject* parent) : QObject(parent)
{

}

void TypeClauseTest::acceptStringSchema_data()
{
  acceptOne_data();

  ADD_ROW << VM({{"type", "null"}}) << V();

  ADD_ROW << VM({{"type", "boolean"}}) << V(false);
  ADD_ROW << VM({{"type", "boolean"}}) << V(true);

  ADD_ROW << VM({{"type", "object"}}) << VM({{"hello", 42}});

  ADD_ROW << VM({{"type", "array"}}) << VL({1, true, "world"});

  ADD_ROW << VM({{"type", "number"}}) << V(0);
  ADD_ROW << VM({{"type", "number"}}) << V(69.5);
  ADD_ROW << VM({{"type", "number"}}) << V(1e300);

  ADD_ROW << VM({{"type", "string"}}) << V("");
  ADD_ROW << VM({{"type", "string"}}) << V("another string");

  ADD_ROW << VM({{"type", "integer"}}) << V(0);
  ADD_ROW << VM({{"type", "integer"}}) << V(-5);
  ADD_ROW << VM({{"type", "integer"}}) << V(1e300);
}

void TypeClauseTest::acceptStringSchema()
{
  acceptOne();
}

void TypeClauseTest::rejectStringSchema_data()
{
  QTest::addColumn<V>("schema");
  QTest::addColumn<V>("instance");

  ADD_ROW << VM({{"type", "null"}}) << V(false);
  ADD_ROW << VM({{"type", "null"}}) << VM({});
  ADD_ROW << VM({{"type", "null"}}) << VL({});
  ADD_ROW << VM({{"type", "null"}}) << V(0);
  ADD_ROW << VM({{"type", "null"}}) << V("");

  ADD_ROW << VM({{"type", "boolean"}}) << V();
  ADD_ROW << VM({{"type", "boolean"}}) << VM({});
  ADD_ROW << VM({{"type", "boolean"}}) << VL({});
  ADD_ROW << VM({{"type", "boolean"}}) << V(0);
  ADD_ROW << VM({{"type", "boolean"}}) << V("");

  ADD_ROW << VM({{"type", "object"}}) << V();
  ADD_ROW << VM({{"type", "object"}}) << V(false);
  ADD_ROW << VM({{"type", "object"}}) << VL({});
  ADD_ROW << VM({{"type", "object"}}) << V(0);
  ADD_ROW << VM({{"type", "object"}}) << V("");

  ADD_ROW << VM({{"type", "array"}}) << V();
  ADD_ROW << VM({{"type", "array"}}) << V(false);
  ADD_ROW << VM({{"type", "array"}}) << VM({});
  ADD_ROW << VM({{"type", "array"}}) << V(0);
  ADD_ROW << VM({{"type", "array"}}) << V("");

  ADD_ROW << VM({{"type", "number"}}) << V();
  ADD_ROW << VM({{"type", "number"}}) << V(false);
  ADD_ROW << VM({{"type", "number"}}) << VM({});
  ADD_ROW << VM({{"type", "number"}}) << VL({});
  ADD_ROW << VM({{"type", "number"}}) << V("");

  ADD_ROW << VM({{"type", "integer"}}) << V();
  ADD_ROW << VM({{"type", "integer"}}) << V(false);
  ADD_ROW << VM({{"type", "integer"}}) << VM({});
  ADD_ROW << VM({{"type", "integer"}}) << VL({});
  ADD_ROW << VM({{"type", "integer"}}) << V("");
  ADD_ROW << VM({{"type", "integer"}}) << V(1e-300);
  ADD_ROW << VM({{"type", "integer"}}) << V(4.5);
}

void TypeClauseTest::rejectStringSchema()
{
  rejectOne();
}

void TypeClauseTest::arraySchema_data()
{
  acceptAndRejectList_data();

  ADD_ROW << VM({{"type", VL({"null", "boolean", "array"})}})
          << VL({V(), false, VL({})})
          << VL({VM({}), 0, ""});
}

void TypeClauseTest::arraySchema()
{
  acceptAndRejectList();
}
