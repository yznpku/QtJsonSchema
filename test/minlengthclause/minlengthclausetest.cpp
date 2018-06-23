#include "minlengthclausetest.h"
#include "../common.h"

MinLengthClauseTest::MinLengthClauseTest(QObject* parent) : QObject(parent)
{

}

void MinLengthClauseTest::test_data()
{
  acceptAndRejectList_data();

  ADD_ROW << VM({{"minLength", 5}})
          << VL({"hello", "woooooorld"})
          << VL({"", "no"});
}

void MinLengthClauseTest::test()
{
  acceptAndRejectList();
}
