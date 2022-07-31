WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c99 -g $(WARNING) $(ERROR)
VAL = valgrind --tool=memcheck --log-file=memcheck.txt --leak-check=full --verbose

TESTFALGS = -DTEST_MERGE -DTEST_MERGESSORT -DTEST_MERGESORT

SRCS = main.c
OBJS = $(SRCS:%.c=%.o)

hw07: $(OBJS)
	$(GCC) $(TESTFALGS) $(OBJS) -o hw07

testmem: hw07
	$(VAL) ./hw07 Input/Test1 Output1
	$(VAL) ./hw07 Input/Test2 Output2
	$(VAL) ./hw07 Input/Test3 Output3

.c.o: 
	$(GCC) $(TESTFALGS) -c $*.c

testall: test1 test2 test3 test4 test5 test7

test1: hw07
	./hw07 Input/Test1 Output1
	diff Output1 Expected/Expected1

test2: hw07
	./hw07 Input/Test2 Output2
	diff Output2 Expected/Expected2

test3: hw07
	./hw07 Input/Test3 Output3
	diff Output3 Expected/Expected3

test4: hw07
	./hw07 Input/Test4 Output4
	diff Output4 Expected/Expected4

test5: hw07
	./hw07 Input/Test5 Output5
	diff Output5 Expected/Expected5

test7: hw07
	./hw07 Input/Test7 Output7
	diff Output7 Expected/Expected7

clean:
	rm -f hw07 *.o
