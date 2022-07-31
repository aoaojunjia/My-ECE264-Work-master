# ***
# *** DO NOT modify this file 
# ***

WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c99 -g $(WARNING) $(ERROR) 

TESTFALGS = -DTEST_JOSEPHUS

SRCS = main.c josephus.c
OBJS = $(SRCS:%.c=%.o)

main: $(OBJS) 
	$(GCC) $(TESTFALGS) $(OBJS) -o main

.c.o: 
	$(GCC) $(TESTFALGS) -c $*.c 

testall: test1 test2 test3 test4 test5 test6

test1: main
	./main 6 3 > output1
	diff output1 expected1

test2: main
	./main 6 4 > output2
	diff output2 expected2

test3: main
	./main 25 7 > output3
	diff output3 expected3

test4: main
	./main 5 7 > output4
	diff output4 expected4

test5: main
	./main 7 14 > output5
	diff output5 expected5

test6: main
	./main 7 3 > output6
	diff output6 expected6

clean: # remove all machine generated files
	rm -f main *.o output?


