#ifndef ENUMCLAUSE_H
#define ENUMCLAUSE_H

#include <QObject>

class EnumClause : public QObject
{
  Q_OBJECT

public:
  EnumClause(QObject* parent = nullptr);

private slots:
  void test_data();
  void test();
};

#endif // ENUMCLAUSE_H
