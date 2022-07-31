# ***
# *** DO NOT modify this file
# ***

WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c99 -g $(WARNING) $(ERROR)
VAL = valgrind --tool=memcheck --log-file=memcheck.txt --leak-check=full --verbose

TESTFALGS = -DTEST_MAIN -DTEST_COMP -DTEST_COUNT -DTEST_FILL

SRCS = main.c
OBJS = $(SRCS:%.c=%.o)

sort: $(OBJS)
	$(GCC) $(TESTFALGS) $(OBJS) -o sort

.c.o:
	$(GCC) $(TESTFALGS) -c $*.c

testmemory: sort
	$(VAL) ./sort inputs/test3 > output3
#testing only input3 and output3

testall: test1 test2 test3 test4 test5 test6 test7 test8

testadd: sort # sort here to ensure recompilation if necessary
	test1
	test2
	test3

test1: sort
	./sort inputs/test1 > output1
	diff output1 expected/expected1

test2: sort
	./sort inputs/test2 > output2
	diff output2 expected/expected2

test3: sort
	./sort inputs/test3 > output3
	diff output3 expected/expected3

test4: sort
	./sort inputs/test4 > output4
	diff output4 expected/expected4

test5: sort
	./sort inputs/test5 > output5
	diff output5 expected/expected5

test6: sort
	./sort inputs/test6 > output6
	diff output6 expected/expected6

test7: sort
	./sort inputs/test7 > output7
	diff output7 expected/expected7

test8: sort
	./sort inputs/test8 > output8
	diff output8 expected/expected8

clean: # remove all machine generated files
	rm -f sort *.o output?
