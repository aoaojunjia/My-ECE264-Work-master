TARGET = hw13
WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c99 -g $(WARNING) $(ERROR)

SRCS = hw13.c main.c

OBJS = $(SRCS:%.c=%.o)
VALGRIND = valgrind --tool=memcheck --verbose --log-file

TESTFALGS = -DTEST_MAIN -DTEST_CREATENODE -DTEST_LINKEDLISTCREATE -DTEST_SPLIT -DTEST_DIV -DLINKEDLIST

$(TARGET): $(OBJS)
	$(GCC) $(TESTFALGS) $(OBJS) -o $(TARGET)

testmemall: testmem1 testmem2 testmem3 testmem4 testmem5 testmem6

testmem1: hw13
	$(VALGRIND)=./valgrind1.log ./hw13 inputs/test1.txt > output/output1.txt
testmem2: hw13
	$(VALGRIND)=./valgrind2.log ./hw13 inputs/test2.txt > output/output2.txt
testmem3: hw13
	$(VALGRIND)=./valgrind3.log ./hw13 inputs/test3.txt > output/output3.txt
testmem4: hw13
	$(VALGRIND)=./valgrind4.log ./hw13 inputs/test4.txt > output/output4.txt
testmem5: hw13
	$(VALGRIND)=./valgrind5.log ./hw13 inputs/test5.txt > output/output5.txt

test1: hw13
	./hw13 inputs/test1.txt  > output/output1.txt
	diff output/output1.txt expected/expected1.txt

test2: hw13
	./hw13 inputs/test2.txt > output/output2.txt
	diff output/output2.txt expected/expected2.txt

test3: hw13
	./hw13 inputs/test3.txt > output/output3.txt
	diff output/output3.txt expected/expected3.txt

test4: hw13
	./hw13 inputs/test4.txt > output/output4.txt
	diff output/output4.txt expected/expected4.txt

test5: hw13
	./hw13 inputs/test5.txt > output/output5.txt
	diff output/output5.txt expected/expected5.txt

testall: test1 test2 test3 test4 test5

.c.o:
	$(GCC) $(TESTFALGS) -c $*.c

clean:
	rm -f $(OBJS) $(TARGET) valgrind*.log
