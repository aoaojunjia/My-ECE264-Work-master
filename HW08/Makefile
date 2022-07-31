# Makefile

TARGET = shuf
WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c99 -g $(WARNING) $(ERROR)

#declare test flags, for example: TESTFLAGS = -DTEST_MAIN -DTEST_SHUF -DTEST_INTER -DTEST_DIV

TESTFLAGS = -DTEST_MAIN -DTEST_SHUF -DTEST_SHUF -DTEST_INTER -DTEST_DIV

SRCS =  main.c utility.c shuffle.c
OBJS = $(SRCS:%.c=%.o)

VAL = valgrind --tool=memcheck --log-file=memcheck.txt --leak-check=full --verbose

$(TARGET): $(OBJS)
	$(GCC) $(TESTFLAGS) $(OBJS) -o $(TARGET)
	
.c.o: 
	$(GCC) $(TESTFLAGS) -c $*.c 

testmem: shuf
	$(VAL) ./shuf 4

test1: shuf
	./shuf 4 | sort > output_file.txt
	diff output_file.txt expected/expected1.txt
	
test2: shuf
	./shuf 8 | sort > output_file.txt
	diff output_file.txt expected/expected2.txt

test3: shuf
	./shuf 11 | sort > output_file.txt
	diff output_file.txt expected/expected3.txt

clean:
	rm -f $(OBJS) $(TARGET)
