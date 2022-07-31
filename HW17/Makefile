TARGET = hw17
WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c99 -g $(WARNING) $(ERROR)

SRCS = main.c bst.c

OBJS = $(SRCS:%.c=%.o)
VALGRIND = valgrind --tool=memcheck --verbose --log-file

TESTFALGS = -DTEST_MAIN  -DTEST_CREATEBST -DTEST_DIST -DTEST_PRINT

$(TARGET): $(OBJS)
	$(GCC) $(TESTFALGS) $(OBJS) -o $(TARGET)

testmemall: testmem1 testmem2 testmem3 testmem4 testmem5 testmem6 testmem7

testmem1: $(TARGET)
	$(VALGRIND)=./valgrind1.log ./hw17 inputs/test1.txt > output/output1.txt
testmem2: $(TARGET)
	$(VALGRIND)=./valgrind2.log ./hw17 inputs/test2.txt > output/output2.txt
testmem3: $(TARGET)
	$(VALGRIND)=./valgrind3.log ./hw17 inputs/test3.txt > output/output3.txt
testmem4: $(TARGET)
	$(VALGRIND)=./valgrind4.log ./hw17 inputs/test4.txt > output/output4.txt
testmem5: $(TARGET)
	$(VALGRIND)=./valgrind5.log ./hw17 inputs/test5.txt > output/output5.txt
testmem6: $(TARGET)
	$(VALGRIND)=./valgrind6.log ./hw17 inputs/test6.txt > output/output6.txt
testmem7: $(TARGET)
	$(VALGRIND)=./valgrind7.log ./hw17 inputs/test7.txt > output/output7.txt

test1: $(TARGET)
	./hw17 inputs/test1.txt > output/output1.txt 
	diff output/output1.txt expected/expected1.txt

test2: $(TARGET)
	./hw17 inputs/test2.txt > output/output2.txt  
	diff output/output2.txt expected/expected2.txt

test3: $(TARGET)
	./hw17 inputs/test3.txt > output/output3.txt  
	diff output/output3.txt expected/expected3.txt

test4: $(TARGET)
	./hw17 inputs/test4.txt > output/output4.txt  
	diff output/output4.txt expected/expected4.txt

test5: $(TARGET)
	./hw17 inputs/test5.txt > output/output5.txt  
	diff output/output5.txt expected/expected5.txt

test6: $(TARGET)
	./hw17 inputs/test6.txt > output/output6.txt  
	diff output/output6.txt expected/expected6.txt

test7: $(TARGET)
	./hw17 inputs/test7.txt > output/output7.txt
	diff output/output7.txt expected/expected7.txt

testall: test1 test2 test3 test4 test5 test6 test7

.c.o:
	$(GCC) $(TESTFALGS) -c $*.c

clean:
	rm -f $(OBJS) $(TARGET) valgrind*.log
