#include <QtCore>
#include <QtTest>
#include "typeclause/typeclausetest.h"
#include "constclause/constclausetest.h"
#include "enumclause/enumclause.h"
#include "multipleofclause/multipleofclausetest.h"
#include "maximumclause/maximumclausetest.h"
#include "exclusivemaximumclause/exclusivemaximumclausetest.h"
#include "minimumclause/minimumclausetest.h"
#include "exclusiveminimumclause/exclusiveminimumclausetest.h"
#include "maxlengthclause/maxlengthclausetest.h"
#include "minlengthclause/minlengthclausetest.h"

int main()
{
  QTest::qExec(new TypeClauseTest);
  QTest::qExec(new ConstClauseTest);
  QTest::qExec(new EnumClause);

  QTest::qExec(new MultipleOfClauseTest);
  QTest::qExec(new MaximumClauseTest);
  QTest::qExec(new ExclusiveMaximumClauseTest);
  QTest::qExec(new MinimumClauseTest);
  QTest::qExec(new ExclusiveMinimumClauseTest);

  QTest::qExec(new MaxLengthClauseTest);
  QTest::qExec(new MinLengthClauseTest);

  return 0;
}
