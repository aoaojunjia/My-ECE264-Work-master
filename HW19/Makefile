TARGET = hw19
WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c99 -g $(WARNING) $(ERROR)

TESTFLAGS = -DTEST_MAIN -DTEST_CREATENODE -DTEST_LINKEDLISTCREATE -DTEST_DIST -DTEST_CENT -DTEST_FUSE -DTEST_CLUSTER

SRCS = main.c hw19.c
OBJS = $(SRCS:%.c=%.o)

VALGRIND = valgrind --tool=memcheck --verbose --log-file

hw18: $(OBJS) 
	$(GCC) $(TESTFLAGS) $(OBJS) -o hw19

.c.o: 
	$(GCC) $(TESTFLAGS) -c $*.c

testall: test1 test2 test3 test4 test5 test6 test7 test8 test9 test10
testmemall: testmem1 testmem2 testmem3 testmem4 testmem5 testmem6 testmem7 testmem8 testmem9 testmem10

testmem1: $(TARGET)
	$(VALGRIND)=./valgrind1.log ./hw19 inputs/test1.txt > output/output1.txt
testmem2: $(TARGET)
	$(VALGRIND)=./valgrind2.log ./hw19 inputs/test2.txt > output/output2.txt
testmem3: $(TARGET)
	$(VALGRIND)=./valgrind3.log ./hw19 inputs/test3.txt > output/output3.txt
testmem4: $(TARGET)
	$(VALGRIND)=./valgrind4.log ./hw19 inputs/test4.txt > output/output4.txt
testmem5: $(TARGET)
	$(VALGRIND)=./valgrind5.log ./hw19 inputs/test5.txt > output/output5.txt
testmem6: $(TARGET)
	$(VALGRIND)=./valgrind6.log ./hw19 inputs/test6.txt > output/output6.txt
testmem7: $(TARGET)
	$(VALGRIND)=./valgrind7.log ./hw19 inputs/test7.txt > output/output7.txt
testmem8: $(TARGET)
	$(VALGRIND)=./valgrind8.log ./hw19 inputs/test8.txt > output/output8.txt
testmem9: $(TARGET)
	$(VALGRIND)=./valgrind9.log ./hw19 inputs/test9.txt > output/output9.txt
testmem10: $(TARGET)
	$(VALGRIND)=./valgrind10.log ./hw19 inputs/test10.txt > output/output10.txt

#test1 -> 5 2 inputs/test1.txt
test1: $(TARGET)
	./hw19 inputs/test1.txt > output/output1.txt
	diff output/output1.txt expected/expected1.txt

#test2 -> 33 3 inputs/test2.txt
test2: $(TARGET)
	./hw19 inputs/test2.txt > output/output2.txt
	diff output/output2.txt expected/expected2.txt

test3: $(TARGET)
	./hw19 inputs/test3.txt > output/output3.txt
	diff output/output3.txt expected/expected3.txt

test4: $(TARGET)
	./hw19 inputs/test4.txt > output/output4.txt
	diff output/output4.txt expected/expected4.txt

test5: $(TARGET)
	./hw19 inputs/test5.txt > output/output5.txt
	diff output/output5.txt expected/expected5.txt

test6: $(TARGET)
	./hw19 inputs/test6.txt > output/output6.txt
	diff output/output6.txt expected/expected6.txt

test7: $(TARGET)
	./hw19 inputs/test7.txt > output/output7.txt
	diff output/output7.txt expected/expected7.txt

test8: $(TARGET)
	./hw19 inputs/test8.txt > output/output8.txt
	diff output/output8.txt expected/expected8.txt

test9: $(TARGET)
	./hw19 inputs/test9.txt > output/output9.txt
	diff output/output9.txt expected/expected9.txt

test10: $(TARGET)
	./hw19 inputs/test10.txt > output/output10.txt
	diff output/output10.txt expected/expected10.txt

clean: # remove all machine generated files
	rm -f split *.o output*.txt hw19 valgrind*.log
