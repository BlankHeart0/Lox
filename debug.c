#include <stdio.h>

#include "debug.h"
#include "value.h"

void DisassembleChunk(Chunk* chunk, const char* name)
{
    printf("=== %s ===\n",name);

    for(int offset=0;offset<chunk->count;)
    {
        offset=DisassembleInstruction(chunk,offset);
    }
}

static int ConstantInstruction(const char* name, Chunk* chunk, int offset)
{
    uint8_t constant_index=chunk->code[offset+1];
    printf("%-16s %4d '",name,constant_index);
    PrintValue(chunk->constants.values[constant_index]);
    printf("'\n");

    return offset+2;
}
static int SimpleInstruction(const char* name, int offset)
{
    printf("%s\n",name);
    return offset+1;
}

int DisassembleInstruction(Chunk* chunk, int offset)
{
    printf("%04d ",offset);

    if(offset>0&&chunk->lines[offset]==chunk->lines[offset-1])
        printf("   | ");
    else printf("%4d ",chunk->lines[offset]);

    uint8_t instruction=chunk->code[offset];
    switch(instruction)
    {
        case OP_CONSTANT:
            return ConstantInstruction("OP_CONSTANT",chunk,offset);
        case OP_RETURN:
            return SimpleInstruction("OP_RETURN",offset);
        default:
            printf("Unknown opcode %d\n",instruction);
            return offset+1;
    }
}

