#include <QtCore>
#include <QtDebug>
#include "typeclause/typeclausetest.h"

int main()
{
  QTest::qExec(new TypeClauseTest);

  return 0;
}
