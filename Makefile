objects = main.o chunk.o memory.o debug.o value.o

lox: $(objects)
	gcc -o lox $(objects)

main.o: common.h chunk.h debug.h
chunk.o: chunk.h memory.h
memory.o: memory.h
debug.o: debug.h value.h
value.o: value.h memory.h

.PHONY:clean
clean:
	-rm lox $(objects)