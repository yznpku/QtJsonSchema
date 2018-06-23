#include "minimumclausetest.h"
#include "../common.h"

MinimumClauseTest::MinimumClauseTest(QObject* parent) : QObject(parent)
{

}

void MinimumClauseTest::test_data()
{
  acceptAndRejectList_data();

  ADD_ROW << VM({{"minimum", 10}})
          << VL({10, 10.1, 50})
          << VL({-5, 0, 1.5});

  ADD_ROW << VM({{"minimum", 0}})
          << VL({0, 1})
          << VL({-1});
}

void MinimumClauseTest::test()
{
  acceptAndRejectList();
}
