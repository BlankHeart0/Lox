#ifndef __DEBUG_H__
#define __DEBUG_H__

#include "chunk.h"

void DisassembleChunk(Chunk* chunk, const char* name);
int DisassembleInstruction(Chunk* chunk, int offset);

#endif