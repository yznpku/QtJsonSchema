#ifndef PATTERNCLAUSETEST_H
#define PATTERNCLAUSETEST_H

#include <QObject>

class PatternClauseTest : public QObject
{
  Q_OBJECT

public:
  PatternClauseTest(QObject* parent = nullptr);

private slots:
  void test_data();
  void test();
};

#endif // PATTERNCLAUSETEST_H
