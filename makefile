TARGET = arithmetic
OBJ = arithmetic.o commonLib.o sortLib.o
CC = gcc

$(TARGET) : $(OBJ)
	$(CC) -o $(TARGET) $(OBJ)
arithmetic.o : arithmetic.c commonLib.h sortLib.h
	$(CC) -c -g arithmetic.c
commonLib.o : commonLib.c commonLib.h
	$(CC) -c -g commonLib.c
sortLib.o : sortLib.c sortLib.h
	$(CC) -c -g sortLib.c

clean:
	rm $(TARGET) $(OBJ)
