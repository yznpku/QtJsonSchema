#include "exclusiveminimumclausetest.h"
#include "../common.h"

ExclusiveMinimumClauseTest::ExclusiveMinimumClauseTest(QObject* parent) : QObject(parent)
{

}

void ExclusiveMinimumClauseTest::test_data()
{
  acceptAndRejectList_data();

  ADD_ROW << VM({{"exclusiveMinimum", 10}})
          << VL({10.1, 50})
          << VL({-5, 0, 1.5, 10});

  ADD_ROW << VM({{"exclusiveMinimum", 0}})
          << VL({1})
          << VL({-1, 0});
}

void ExclusiveMinimumClauseTest::test()
{
  acceptAndRejectList();
}
