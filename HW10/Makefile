TARGET = hw10
WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c99 -g $(WARNING) $(ERROR)

SRCS = hw10.c bmpimage.c bmpfunc.c

OBJS = $(SRCS:%.c=%.o)
VALGRIND = valgrind --tool=memcheck --verbose --log-file

TESTFALGS = -DTEST_MAINFUNC -DTEST_FUNCGIVEN -DTEST_IMGTOGRAY -DTEST_HEADERVALID -DTEST_BMPOPENFILE -DTEST_BMPWRITEFUNC -DTEST_BMPFREEFUNC

$(TARGET): $(OBJS)
	$(GCC) $(TESTFALGS) $(OBJS) -o $(TARGET)

testmemory: hw10 
	$(VALGRIND)=./valgrind.log ./hw10 exampleImages/RV2.bmp output/grayRV2.bmp

test1: hw10
	./hw10 exampleImages/CondProb.bmp output/grayCondProb.bmp
	xxd -b output/grayCondProb.bmp | less > output1
	xxd -b expectedImages/expectedCondProb.bmp | less > expected1
	diff output1 expected1

test2: hw10
	./hw10 exampleImages/RV.bmp output/grayRV.bmp
	xxd -b output/grayRV.bmp | less > output2
	xxd -b expectedImages/expectedRV.bmp | less > expected2
	diff output2 expected2

test3: hw10
	./hw10 exampleImages/RV2.bmp output/grayRV2.bmp
	xxd -b output/grayRV2.bmp | less > output3
	xxd -b expectedImages/expectedRV2.bmp | less > expected3
	diff output3 expected3

test4: hw10
	./hw10 exampleImages/RV2Small.bmp output/grayRV2Small.bmp
	xxd -b output/grayRV2Small.bmp | less > output4
	xxd -b expectedImages/expectedRV2Small.bmp | less > expected4
	diff output4 expected4

testall: test1 test2 test3 test4

.c.o:
	$(GCC) $(TESTFALGS) -c $*.c

clean:
	rm -f $(OBJS) $(TARGET)
