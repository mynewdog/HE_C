# set compiler: g++ for C++
CC = gcc

#Flags
CFLAGS = -g -Wall -Wextra
RFLAGS = -O3

#Name of file
TARGET = password_cracker

$(TARGET): cracker.o functions.o
	$(CC) $(CFLAGS) $(RFLAGS) -o $(TARGET) cracker.o functions.o -lcrypt

cracker.o: cracker.c
	$(CC) $(CFLAGS) -c -o cracker.o cracker.c

functions.o: functions.c
	$(CC) $(CFLAGS) -c -o functions.o functions.c

clean:
	rm *.o $(TARGET)

remake: clean $(TARGET)