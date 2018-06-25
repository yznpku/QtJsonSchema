#include "schemavalidationtest.h"
#include "common.h"

SchemaValidationTest::SchemaValidationTest(const QStringList& testDataFiles)
{
  this->files = testDataFiles;
}

void SchemaValidationTest::test_data()
{
  QTest::addColumn<QJsonValue>("schema");
  QTest::addColumn<QJsonValue>("accept");
  QTest::addColumn<QJsonValue>("reject");

  foreach (const auto& fileName, files) {
    QFile file(fileName);
    file.open(QIODevice::ReadOnly);
    const auto& json = QJsonDocument::fromJson(file.readAll()).object();
    const auto& testCases = json["testCases"].toArray();

    for (int i = 0; i < testCases.size(); i++) {
      const auto& testCase = testCases[i].toObject();
      QTest::addRow("%s[%d]", fileName.toLocal8Bit().constData(), i) << testCase["schema"] << testCase["accept"] << testCase["reject"];
    }
  }
}

void SchemaValidationTest::test()
{
  QFETCH(QJsonValue, schema);
  QFETCH(QJsonValue, accept);
  QFETCH(QJsonValue, reject);

  const auto& s = JsonSchema::fromJson(schema);

  foreach (const auto& instance, accept.toArray())
    QVERIFY(s.validate(instance));

  foreach (const auto& instance, reject.toArray())
    QVERIFY(!s.validate(instance));
}
