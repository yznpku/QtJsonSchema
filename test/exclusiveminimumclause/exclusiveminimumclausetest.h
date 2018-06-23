#ifndef EXCLUSIVEMINIMUMCLAUSETEST_H
#define EXCLUSIVEMINIMUMCLAUSETEST_H

#include <QObject>

class ExclusiveMinimumClauseTest : public QObject
{
  Q_OBJECT

public:
  ExclusiveMinimumClauseTest(QObject* parent = nullptr);

private slots:
  void test_data();
  void test();
};

#endif // EXCLUSIVEMINIMUMCLAUSETEST_H
