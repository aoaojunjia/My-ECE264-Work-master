TARGET = shuf
WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c99 -g $(WARNING) $(ERROR)

SRCS = main.c shuffle.c utility.c

OBJS = $(SRCS:%.c=%.o)
VALGRIND = valgrind --tool=memcheck --verbose --log-file

TESTFALGS = -DTEST_MAIN -DTEST_DIV -DTEST_INTER -DTEST_SHUF -DTEST_RSHUF

$(TARGET): $(OBJS)
	$(GCC) $(TESTFALGS) $(OBJS) -o $(TARGET)

testmemory: shuf
	$(VALGRIND)=./valgrind.log ./shuf 2 2

test1: shuf
	./shuf 2 2 | sort > output1
	diff output1 expected/expected1

test2: shuf
	./shuf 4 3 | sort > output2
	diff output2 expected/expected2

test3: shuf
	./shuf 7 2 | sort > output3
	diff output3 expected/expected3	

testall: test1 test2 test3

.c.o:
	$(GCC) $(TESTFALGS) -c $*.c

clean:
	rm -f $(OBJS) $(TARGET)
