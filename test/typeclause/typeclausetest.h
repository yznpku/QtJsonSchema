#ifndef TYPECLAUSETEST_H
#define TYPECLAUSETEST_H

#include <QtTest>

class TypeClauseTest : public QObject
{
  Q_OBJECT

public:
  TypeClauseTest(QObject* parent = nullptr);

private slots:
  void acceptStringSchema_data();
  void acceptStringSchema();
  void rejectStringSchema_data();
  void rejectStringSchema();
  void arraySchema_data();
  void arraySchema();
};

#endif // TYPECLAUSETEST_H
