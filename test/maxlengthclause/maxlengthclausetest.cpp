#include "maxlengthclausetest.h"
#include "../common.h"

MaxLengthClauseTest::MaxLengthClauseTest(QObject* parent) : QObject(parent)
{

}

void MaxLengthClauseTest::test_data()
{
  acceptAndRejectList_data();

  ADD_ROW << VM({{"maxLength", 5}})
          << VL({"", "a", "hello"})
          << VL({"failed", "looooool"});
}

void MaxLengthClauseTest::test()
{
  acceptAndRejectList();
}
