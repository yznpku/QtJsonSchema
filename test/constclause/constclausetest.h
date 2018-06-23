#ifndef CONSTCLAUSETEST_H
#define CONSTCLAUSETEST_H

#include <QObject>

class ConstClauseTest : public QObject
{
  Q_OBJECT

public:
  ConstClauseTest(QObject* parent = nullptr);

private slots:
  void test_data();
  void test();
};

#endif // CONSTCLAUSETEST_H
