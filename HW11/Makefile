TARGET = hw11
WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c99 -g $(WARNING) $(ERROR)

SRCS = hw11.c bmpimage.c bmpfunc.c

OBJS = $(SRCS:%.c=%.o)
VALGRIND = valgrind --tool=memcheck --verbose --log-file

TESTFALGS = -DTEST_MAIN -DTEST_FUNCGIVEN -DTEST_IMGTOGRAY -DTEST_ADAPTIVETHRESHOLDING -DTEST_HEADERVALID -DTEST_BMPOPENFILE -DTEST_WRITEFUNC -DTEST_BMPFREEFUNC

$(TARGET): $(OBJS)
	$(GCC) $(TESTFALGS) $(OBJS) -o $(TARGET)

testmemory: testmem1 testmem2 testmem3 testmem4

testmem1: hw11
	$(VALGRIND)=./valgrind1.log ./hw11 exampleImages/CondProb.bmp output/CondProb.bmp 1 2
testmem2: hw11
	$(VALGRIND)=./valgrind2.log ./hw11 exampleImages/RV.bmp output/RV.bmp 5 2
testmem3: hw11
	$(VALGRIND)=./valgrind3.log ./hw11 exampleImages/RV2.bmp output/RV2.bmp 3 2
testmem4: hw11
	$(VALGRIND)=./valgrind4.log ./hw11 exampleImages/RV2Small.bmp output/RV2Small.bmp 11 2

test1: hw11
	./hw11 exampleImages/CondProb.bmp output/CondProb.bmp 1 2
	diff expectedImages/expectedCondProb.bmp output/CondProb.bmp
#xxd -b output/grayCondProb.bmp | less > output1
#xxd -b expectedImages/expectedCondProb.bmp | less > expected1
#diff output1 expected1

test2: hw11
	./hw11 exampleImages/RV.bmp output/RV.bmp 5 2
	diff expectedImages/expectedRV.bmp output/RV.bmp
#xxd -b output/grayRV.bmp | less > output2
#xxd -b expectedImages/expectedRV.bmp | less > expected2
#diff output2 expected2

test3: hw11
	./hw11 exampleImages/RV2.bmp output/RV2.bmp 3 2
	diff expectedImages/expectedRV2.bmp output/RV2.bmp
#xxd -b output/grayRV2.bmp | less > output3
#xxd -b expectedImages/expectedRV2.bmp | less > expected3
#diff output3 expected3

test4: hw11
	./hw11 exampleImages/RV2Small.bmp output/RV2Small.bmp 11 2
	diff expectedImages/expectedRV2Small.bmp output/RV2Small.bmp
#xxd -b output/grayRV2Small.bmp | less > output4
#xxd -b expectedImages/expectedRV2Small.bmp | less > expected4
#diff output4 expected4

testall: test1 test2 test3 test4

.c.o:
	$(GCC) $(TESTFALGS) -c $*.c

clean:
	rm -f $(OBJS) $(TARGET)
