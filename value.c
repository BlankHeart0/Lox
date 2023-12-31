#include <stdio.h>

#include "memory.h"
#include "value.h"

void InitValueArray(ValueArray* array)
{
    array->capacity=0;
    array->count=0;
    array->values=NULL;
}

void WriteValueArray(ValueArray* array, Value value)
{
    if(array->capacity<array->count+1)
    {
        int old_capacity=array->capacity;
        array->capacity=GROW_CAPACITY(old_capacity);
        array->values=GROW_ARRAY(Value,array->values,old_capacity,array->capacity);
    }

    array->values[array->count++]=value;
}

void FreeValueArray(ValueArray* array)
{
    FREE_ARRAY(Value,array->values,array->capacity);
    InitValueArray(array);
}



void PrintValue(Value value)
{
    printf("%g",value);
}