#include "common.h"
#include <QtTest>

QVariant VM(std::initializer_list<std::pair<QString, QVariant> >&& il)
{
  return QVariant(QVariantMap(std::forward<std::initializer_list<std::pair<QString, QVariant>>>(il)));
}

QVariant VL(std::initializer_list<QVariant>&& il)
{
  return QVariant(QVariantList(std::forward<std::initializer_list<QVariant>>(il)));
}

void acceptOne_data()
{
  QTest::addColumn<V>("schema");
  QTest::addColumn<V>("instance");
}

void acceptOne()
{
  QFETCH(V, schema);
  QFETCH(V, instance);

  const auto& s = JsonSchema::fromVariant(schema);
  QVERIFY(s.validate(instance));
}

void rejectOne_data()
{
  QTest::addColumn<V>("schema");
  QTest::addColumn<V>("instance");
}

void rejectOne()
{
  QFETCH(V, schema);
  QFETCH(V, instance);

  const auto& s = JsonSchema::fromVariant(schema);
  QVERIFY(!s.validate(instance));
}

void acceptList_data()
{
  QTest::addColumn<V>("schema");
  QTest::addColumn<V>("instanceList");
}

void acceptList()
{
  QFETCH(V, schema);
  QFETCH(V, instanceList);

  const auto& s = JsonSchema::fromVariant(schema);

  foreach (const auto& instance, instanceList.toList())
    QVERIFY(s.validate(instance));
}

void rejectList_data()
{
  QTest::addColumn<V>("schema");
  QTest::addColumn<V>("instanceList");
}

void rejectList()
{
  QFETCH(V, schema);
  QFETCH(V, instanceList);

  const auto& s = JsonSchema::fromVariant(schema);

  foreach (const auto& instance, instanceList.toList())
    QVERIFY(!s.validate(instance));
}

void acceptAndRejectList_data()
{
  QTest::addColumn<V>("schema");
  QTest::addColumn<V>("acceptInstanceList");
  QTest::addColumn<V>("rejectInstanceList");
}

void acceptAndRejectList()
{
  QFETCH(V, schema);
  QFETCH(V, acceptInstanceList);
  QFETCH(V, rejectInstanceList);

  const auto& s = JsonSchema::fromVariant(schema);

  foreach (const auto& instance, acceptInstanceList.toList())
    QVERIFY(s.validate(instance));

  foreach (const auto& instance, rejectInstanceList.toList())
    QVERIFY(!s.validate(instance));
}
