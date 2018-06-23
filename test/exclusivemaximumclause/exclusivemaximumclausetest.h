#ifndef EXCLUSIVEMAXIMUMCLAUSETEST_H
#define EXCLUSIVEMAXIMUMCLAUSETEST_H

#include <QObject>

class ExclusiveMaximumClauseTest : public QObject
{
  Q_OBJECT

public:
  ExclusiveMaximumClauseTest(QObject* parent = nullptr);

private slots:
  void test_data();
  void test();
};

#endif // EXCLUSIVEMAXIMUMCLAUSETEST_H
