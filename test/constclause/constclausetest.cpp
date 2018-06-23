#include "constclausetest.h"
#include "../common.h"

ConstClauseTest::ConstClauseTest(QObject* parent) : QObject(parent)
{

}

void ConstClauseTest::test_data()
{
  acceptAndRejectList_data();

  ADD_ROW << VM({{"const", V()}})
          << VL({V()})
          << VL({false, VM({}), VL({}), 0, ""});

  ADD_ROW << VM({{"const", true}})
          << VL({true})
          << VL({V(), false, VM({}), VL({}), 0, ""});

  ADD_ROW << VM({{"const", VM({{"hello", 1}, {"world", true}})}})
          << VL({VM({{"hello", 1}, {"world", true}})})
          << VL({V(), false, VM({{"hello", 1}, {"world", false}}), VL({}), 0, ""});

  ADD_ROW << VM({{"const", VL({"hello", true, 42, V()})}})
          << VL({VL({"hello", true, 42, V()})})
          << VL({V(), false, VM({}), VL({"hello", false, 42, V()}), 0, ""});

  ADD_ROW << VM({{"const", 42}})
          << VL({42})
          << VL({V(), false, VM({}), VL({}), 43, ""});

  ADD_ROW << VM({{"const", "hello"}})
          << VL({"hello"})
          << VL({V(), false, VM({}), VL({}), 0, "world"});
}

void ConstClauseTest::test()
{
  acceptAndRejectList();
}
