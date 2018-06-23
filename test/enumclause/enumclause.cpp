#include "enumclause.h"
#include "../common.h"

EnumClause::EnumClause(QObject* parent) : QObject(parent)
{

}

void EnumClause::test_data()
{
  acceptAndRejectList_data();

  ADD_ROW << VM({{"enum", VL({V(), true, VM({{"hello", 1}}), VL({"world"}), "string"})}})
          << VL({
                  V(),
                  true,
                  VM({{"hello", 1}}),
                  VL({"world"}),
                  "string"
                })
          << VL({
                  false,
                  VM({{"hello", 2}}),
                  VL({"hello", "world"}),
                  "STRING",
                  3
                });
}

void EnumClause::test()
{
  acceptAndRejectList();
}
