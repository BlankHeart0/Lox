#ifndef __VALUE_H__
#define __VALUE_H__

#include "common.h"

typedef double Value;

typedef struct{
    int capacity;
    int count;
    Value* values;
}ValueArray;

void InitValueArray(ValueArray* array);
void WriteValueArray(ValueArray* array, Value value);
void FreeValueArray(ValueArray* array);

void PrintValue(Value value);

#endif