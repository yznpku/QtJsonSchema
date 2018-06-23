#include <QtCore>
#include <QtTest>
#include "typeclause/typeclausetest.h"
#include "constclause/constclausetest.h"
#include "enumclause/enumclause.h"

int main()
{
  QTest::qExec(new TypeClauseTest);
  QTest::qExec(new ConstClauseTest);
  QTest::qExec(new EnumClause);

  return 0;
}
