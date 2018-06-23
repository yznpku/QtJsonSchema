#ifndef COMMON_H
#define COMMON_H

#include <initializer_list>
#include "../QtJsonSchema/src/jsonschema.h"

#define ADD_ROW QTest::addRow("L%d", __LINE__)

using V = QVariant;

QVariant VM(std::initializer_list<std::pair<QString, QVariant>>&& il);
QVariant VL(std::initializer_list<QVariant>&& il);

void acceptOne_data();
void acceptOne();
void rejectOne_data();
void rejectOne();
void acceptList_data();
void acceptList();
void rejectList_data();
void rejectList();
void acceptAndRejectList_data();
void acceptAndRejectList();

#endif // COMMON_H
