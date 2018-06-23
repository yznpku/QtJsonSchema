#include "exclusivemaximumclausetest.h"
#include "../common.h"

ExclusiveMaximumClauseTest::ExclusiveMaximumClauseTest(QObject* parent) : QObject(parent)
{

}

void ExclusiveMaximumClauseTest::test_data()
{
  acceptAndRejectList_data();

  ADD_ROW << VM({{"exclusiveMaximum", 10}})
          << VL({-5, 0, 1.5})
          << VL({10, 10.1, 50});

  ADD_ROW << VM({{"exclusiveMaximum", 0}})
          << VL({-1})
          << VL({0, 1});
}

void ExclusiveMaximumClauseTest::test()
{
  acceptAndRejectList();
}
