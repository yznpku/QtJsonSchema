#include <QtCore>
#include <QtDebug>
#include "typeclause/typeclausetest.h"
#include "constclause/constclausetest.h"

int main()
{
  QTest::qExec(new TypeClauseTest);
  QTest::qExec(new ConstClauseTest);

  return 0;
}
