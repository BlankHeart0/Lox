#include <stdlib.h>

#include "chunk.h"
#include "memory.h"

void InitChunk(Chunk* chunk)
{
    chunk->capacity=0;
    chunk->count=0;
    chunk->code=NULL;
    chunk->lines=NULL;

    InitValueArray(&chunk->constants);
}

void WriteChunk(Chunk* chunk, uint8_t byte, int line)
{
    if(chunk->capacity<chunk->count+1){
        int old_capacity=chunk->capacity;
        chunk->capacity=GROW_CAPACITY(old_capacity);
        chunk->code=GROW_ARRAY(uint8_t,chunk->code,old_capacity,chunk->capacity);
        chunk->lines=GROW_ARRAY(int,chunk->lines,old_capacity,chunk->capacity);
    }

    chunk->code[chunk->count]=byte;
    chunk->lines[chunk->count]=line;
    chunk->count++;
}

void FreeChunk(Chunk* chunk)
{
    FREE_ARRAY(uint8_t,chunk->code,chunk->capacity);
    FREE_ARRAY(int,chunk->lines,chunk->capacity);
    FreeValueArray(&chunk->constants);
    InitChunk(chunk);
}



int AddConstant(Chunk* chunk, Value value)
{
    WriteValueArray(&chunk->constants,value);
    return chunk->constants.count-1;
}
