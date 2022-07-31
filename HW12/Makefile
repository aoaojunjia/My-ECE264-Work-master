TARGET = hw12
WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c99 -g $(WARNING) $(ERROR)

SRCS = hw12.c main.c

OBJS = $(SRCS:%.c=%.o)
VALGRIND = valgrind --tool=memcheck --verbose --log-file

TESTFALGS = -DLINKEDLIST -DTEST_MAIN -DTEST_CREATENODE -DTEST_LINKEDLISTCREATE -DTEST_JOSEPHUS

$(TARGET): $(OBJS)
	$(GCC) $(TESTFALGS) $(OBJS) -o $(TARGET)

testmemall: testmem1 testmem2 testmem3 testmem4 testmem5 testmem6

testmem1: hw12
	$(VALGRIND)=./valgrind1.log ./hw12 10 3 1 > output/output1.txt
testmem2: hw12
	$(VALGRIND)=./valgrind2.log ./hw12 10 4 2 > output/output2.txt
testmem3: hw12
	$(VALGRIND)=./valgrind3.log ./hw12 8 5 3 > output/output3.txt
testmem4: hw12
	$(VALGRIND)=./valgrind4.log ./hw12 8 9 1 > output/output4.txt
testmem5: hw12
	$(VALGRIND)=./valgrind5.log ./hw12 41 3 1 > output/output5.txt
testmem6: hw12
	$(VALGRIND)=./valgrind6.log ./hw12 100 3 20 > output/output6.txt

test1: hw12
	./hw12 10 3 1 > output/output1.txt
	diff output/output1.txt expected/expected1.txt

test2: hw12
	./hw12 10 4 2 > output/output2.txt
	diff output/output2.txt expected/expected2.txt

test3: hw12
	./hw12 8 5 3 > output/output3.txt
	diff output/output3.txt expected/expected3.txt

test4: hw12
	./hw12 8 9 1 > output/output4.txt
	diff output/output4.txt expected/expected4.txt

test5: hw12
	./hw12 41 3 1 > output/output5.txt
	diff output/output5.txt expected/expected5.txt

test6: hw12
	./hw12 100 3 20 > output/output6.txt
	diff output/output6.txt expected/expected6.txt

testall: test1 test2 test3 test4 test5 test6

.c.o:
	$(GCC) $(TESTFALGS) -c $*.c

clean:
	rm -f $(OBJS) $(TARGET) valgrind*.log
