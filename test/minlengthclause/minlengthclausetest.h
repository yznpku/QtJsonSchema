#ifndef MINLENGTHCLAUSETEST_H
#define MINLENGTHCLAUSETEST_H

#include <QObject>

class MinLengthClauseTest : public QObject
{
  Q_OBJECT

public:
  MinLengthClauseTest(QObject* parent = nullptr);

private slots:
  void test_data();
  void test();
};

#endif // MINLENGTHCLAUSETEST_H
