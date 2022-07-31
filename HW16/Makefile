TARGET = hw16
WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c99 -g $(WARNING) $(ERROR)

SRCS = hw16.c main.c binarytree.c

OBJS = $(SRCS:%.c=%.o)
VALGRIND = valgrind --tool=memcheck --verbose --log-file

TESTFALGS = -DTEST_MAIN -DTEST_FREETREE -DTEST_SEARCH -DTEST_SUBTREE -DTEST_CONTAINED -DPRINT_FUN

$(TARGET): $(OBJS)
	$(GCC) $(TESTFALGS) $(OBJS) -o $(TARGET)

testmemall: testmem1 testmem2 testmem3 testmem4 testmem5 testmem6

testmem1: $(TARGET)
	$(VALGRIND)=./valgrind1.log ./hw16 inputs/tree1/test1.txt inputs/tree2/test1.txt > output/output1.txt
testmem2: $(TARGET)
	$(VALGRIND)=./valgrind2.log ./hw16 inputs/tree1/test2.txt inputs/tree2/test2.txt > output/output2.txt
testmem3: $(TARGET)
	$(VALGRIND)=./valgrind3.log ./hw16 inputs/tree1/test3.txt inputs/tree2/test3.txt > output/output3.txt
testmem4: $(TARGET)
	$(VALGRIND)=./valgrind4.log ./hw16 inputs/tree1/test4.txt inputs/tree2/test4.txt > output/output4.txt
testmem5: $(TARGET)
	$(VALGRIND)=./valgrind5.log ./hw16 inputs/tree1/test5.txt inputs/tree2/test5.txt > output/output5.txt
testmem6: $(TARGET)
	$(VALGRIND)=./valgrind6.log ./hw16 inputs/tree1/test6.txt inputs/tree2/test6.txt > output/output6.txt

test1: $(TARGET)
	./hw16 inputs/tree1/test1.txt inputs/tree2/test1.txt > output/output1.txt  
	diff -i -w output/output1.txt expected/expected1.txt

test2: $(TARGET)
	./hw16 inputs/tree1/test2.txt inputs/tree2/test2.txt > output/output2.txt
	diff -i -w output/output2.txt expected/expected2.txt

test3: $(TARGET)
	./hw16 inputs/tree1/test3.txt inputs/tree2/test3.txt > output/output3.txt
	diff -i -w output/output3.txt expected/expected3.txt

test4: $(TARGET)
	./hw16 inputs/tree1/test4.txt inputs/tree2/test4.txt > output/output4.txt
	diff -i -w output/output4.txt expected/expected4.txt

test5: $(TARGET)
	./hw16 inputs/tree1/test5.txt inputs/tree2/test5.txt > output/output5.txt
	diff -i -w output/output5.txt expected/expected5.txt

test6: $(TARGET)
	./hw16 inputs/tree1/test6.txt inputs/tree2/test6.txt > output/output6.txt
	diff -i -w output/output6.txt expected/expected6.txt

testall: test1 test2 test3 test4 test5 test6

.c.o:
	$(GCC) $(TESTFALGS) -c $*.c

clean:
	rm -f $(OBJS) $(TARGET) valgrind*.log
