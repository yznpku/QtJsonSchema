#ifndef SCHEMAVALIDATIONTEST_H
#define SCHEMAVALIDATIONTEST_H

#include <QtCore>

class SchemaValidationTest : public QObject
{
  Q_OBJECT

  QStringList files;

public:
  SchemaValidationTest(const QStringList& testDataFiles);

private slots:
  void test_data();
  void test();
};

#endif // SCHEMAVALIDATIONTEST_H
