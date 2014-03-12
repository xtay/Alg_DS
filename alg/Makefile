
all: \
../build/linkList.o \
../build/seqList.o \
../build/seqStack.o \


../build/linkList.o: linkList.c ../include/common.h ../include/linkList.h \
 ../include/common.h
	$(CC) $(CFLAG) -I ../include -c $< -o $@

../build/seqList.o: seqList.c ../include/common.h ../include/seqList.h \
 ../include/common.h
	$(CC) $(CFLAG) -I ../include -c $< -o $@

../build/seqStack.o: seqStack.c ../include/seqStack.h ../include/seqList.h \
 ../include/common.h
	$(CC) $(CFLAG) -I ../include -c $< -o $@

