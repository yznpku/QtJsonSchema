#ifndef MAXIMUMCLAUSETEST_H
#define MAXIMUMCLAUSETEST_H

#include <QObject>

class MaximumClauseTest : public QObject
{
  Q_OBJECT

public:
  MaximumClauseTest(QObject* parent = nullptr);

private slots:
  void test_data();
  void test();
};

#endif // MAXIMUMCLAUSETEST_H
