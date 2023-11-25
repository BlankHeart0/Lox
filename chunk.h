#ifndef __CHUNK_H__
#define __CHUNK_H__

#include "common.h"
#include "value.h"

typedef enum{
    OP_CONSTANT,

    OP_RETURN,

}OpCode;

typedef struct{
    int count;
    int capacity;

    ValueArray constants;

    uint8_t* code;
    int* lines;
}Chunk;

void InitChunk(Chunk* chunk);
void WriteChunk(Chunk* chunk, uint8_t byte, int line);
void FreeChunk(Chunk* chunk);

int AddConstant(Chunk* chunk, Value value);

#endif