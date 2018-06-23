#ifndef COMMON_H
#define COMMON_H

#include <initializer_list>
#include "../QtJsonSchema/src/jsonschema.h"

#define ADD_ROW QTest::addRow("L%d", __LINE__)

using V = QVariant;

QVariant VM(std::initializer_list<std::pair<QString, QVariant>>&& il) {
  return QVariant(QVariantMap(std::forward<std::initializer_list<std::pair<QString, QVariant>>>(il)));
}

QVariant VL(std::initializer_list<QVariant>&& il) {
  return QVariant(QVariantList(std::forward<std::initializer_list<QVariant>>(il)));
}

#endif // COMMON_H
