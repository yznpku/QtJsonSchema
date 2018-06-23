#ifndef MAXLENGTHCLAUSETEST_H
#define MAXLENGTHCLAUSETEST_H

#include <QObject>

class MaxLengthClauseTest : public QObject
{
  Q_OBJECT

public:
  MaxLengthClauseTest(QObject* parent = nullptr);

private slots:
  void test_data();
  void test();
};

#endif // MAXLENGTHCLAUSETEST_H
