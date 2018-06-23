#ifndef MULTIPLEOFCLAUSETEST_H
#define MULTIPLEOFCLAUSETEST_H

#include <QObject>

class MultipleOfClauseTest : public QObject
{
  Q_OBJECT

public:
  MultipleOfClauseTest(QObject* parent = nullptr);

private slots:
  void test_data();
  void test();
};

#endif // MULTIPLEOFCLAUSETEST_H
