#ifndef MINIMUMCLAUSETEST_H
#define MINIMUMCLAUSETEST_H

#include <QObject>

class MinimumClauseTest : public QObject
{
  Q_OBJECT

public:
  MinimumClauseTest(QObject* parent = nullptr);

private slots:
  void test_data();
  void test();
};

#endif // MINIMUMCLAUSETEST_H
