#ifndef BOOLEANSCHEMATEST_H
#define BOOLEANSCHEMATEST_H

#include <QObject>

class BooleanSchemaTest : public QObject
{
  Q_OBJECT

public:
  BooleanSchemaTest(QObject* parent = nullptr);

private slots:
  void trueSchema_data();
  void trueSchema();
  void falseSchema_data();
  void falseSchema();
};

#endif // BOOLEANSCHEMATEST_H
