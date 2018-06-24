#include "patternclausetest.h"
#include "../common.h"

PatternClauseTest::PatternClauseTest(QObject* parent) : QObject(parent)
{

}

void PatternClauseTest::test_data()
{
  acceptAndRejectList_data();

  ADD_ROW << VM({{"pattern", "^(\\([0-9]{3}\\))?[0-9]{3}-[0-9]{4}$"}})
          << VL({"555-1212", "(888)555-1212"})
          << VL({"(888)555-1212 ext. 532", "(800)FLOWERS"});

  ADD_ROW << VM({{"pattern", "el"}})
          << VL({"el", "elel", "hello"})
          << VL({"le"});
}

void PatternClauseTest::test()
{
  acceptAndRejectList();
}
