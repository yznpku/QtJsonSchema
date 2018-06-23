#include "maximumclausetest.h"
#include "../common.h"

MaximumClauseTest::MaximumClauseTest(QObject *parent) : QObject(parent)
{

}

void MaximumClauseTest::test_data()
{
  acceptAndRejectList_data();

  ADD_ROW << VM({{"maximum", 10}})
          << VL({-5, 0, 1.5, 10})
          << VL({10.1, 50});

  ADD_ROW << VM({{"maximum", 0}})
          << VL({-1, 0})
          << VL({1});
}

void MaximumClauseTest::test()
{
  acceptAndRejectList();
}
