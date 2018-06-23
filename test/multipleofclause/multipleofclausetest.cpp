#include "multipleofclausetest.h"
#include "../common.h"

MultipleOfClauseTest::MultipleOfClauseTest(QObject* parent) : QObject(parent)
{

}

void MultipleOfClauseTest::test_data()
{
  acceptAndRejectList_data();

  ADD_ROW << VM({{"multipleOf", 10}})
          << VL({0, 10, 50, -20})
          << VL({5, 10.5});

  ADD_ROW << VM({{"multipleOf", 2.5}})
          << VL({0, 2.5, 10, -12.5})
          << VL({0.5, 1, 6});
}

void MultipleOfClauseTest::test()
{
  acceptAndRejectList();
}
