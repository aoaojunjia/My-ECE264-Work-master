TARGET = hw20
WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c99 -g $(WARNING) $(ERROR)

SRCS = main.c decode.c list.c tree.c utility.c

OBJS = $(SRCS:%.c=%.o)
VALGRIND = valgrind --tool=memcheck --verbose --log-file

TESTFALGS = -DTEST_READHEADER -DTEST_DECODE -DTEST_MERGELIST -DDO_NOT_MODIFY

$(TARGET): $(OBJS)
	$(GCC) $(TESTFALGS) $(OBJS) -o $(TARGET)

testmemall: testmem1 testmem2 testmem3 testmem4 testmem5 testmem6 testmem7 testmem8

testmem1: $(TARGET)
	$(VALGRIND)=./valgrind1.log ./$(TARGET) input/input1.bin output1.txt
testmem2: $(TARGET)
	$(VALGRIND)=./valgrind2.log ./$(TARGET) input/input2.bin output2.txt
testmem3: $(TARGET)
	$(VALGRIND)=./valgrind3.log ./$(TARGET) input/input3.bin output3.txt
testmem4: $(TARGET)
	$(VALGRIND)=./valgrind4.log ./$(TARGET) input/input4.bin output4.txt
testmem5: $(TARGET)
	$(VALGRIND)=./valgrind5.log ./$(TARGET) input/input5.bin output5.txt
testmem6: $(TARGET)
	$(VALGRIND)=./valgrind6.log ./$(TARGET) input/input6.bin output6.txt
testmem7: $(TARGET)
	$(VALGRIND)=./valgrind7.log ./$(TARGET) input/input7.bin output7.txt
testmem8: $(TARGET)
	$(VALGRIND)=./valgrind8.log ./$(TARGET) input/input8.bin output8.txt

test1: $(TARGET)
	./$(TARGET) input/input1.bin output1.txt 
	diff -i -w output1.txt expected/expected1.txt

test2: $(TARGET)
	./$(TARGET) input/input2.bin output2.txt 
	diff -i -w output2.txt expected/expected2.txt

test3: $(TARGET)
	./$(TARGET) input/input3.bin output3.txt 
	diff -i -w output3.txt expected/expected3.txt

test4: $(TARGET)
	./$(TARGET) input/input4.bin output4.txt 
	diff -i -w output4.txt expected/expected4.txt

test5: $(TARGET)
	./$(TARGET) input/input5.bin output5.txt 
	diff -i -w output5.txt expected/expected5.txt

test6: $(TARGET)
	./$(TARGET) input/input6.bin output6.txt 
	diff -i -w output6.txt expected/expected6.txt

test7: $(TARGET)
	./$(TARGET) input/input7.bin output7.txt 
	diff -i -w output7.txt expected/expected7.txt

test8: $(TARGET)
	./$(TARGET) input/input8.bin output8.txt 
	diff -i -w output8.txt expected/expected8.txt

testall: test1 test2 test3 test4 test5 test6 test7 test8

.c.o:
	$(GCC) $(TESTFALGS) -c $*.c

clean:
	rm -f $(OBJS) $(TARGET) valgrind*.log output*.txt
