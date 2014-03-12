
all: \
../build/common.o \
../build/linkList_plus.o \
../build/seqList_plus.o \
../build/seqStack_plus.o \


../build/common.o: common.c ../include/common.h
	$(CC) $(CFLAG) -I ../include -c $< -o $@

../build/linkList_plus.o: linkList_plus.c ../include/linkList_plus.h \
 ../include/common.h ../include/linkList.h
	$(CC) $(CFLAG) -I ../include -c $< -o $@

../build/seqList_plus.o: seqList_plus.c ../include/seqList_plus.h \
 ../include/common.h ../include/seqList.h
	$(CC) $(CFLAG) -I ../include -c $< -o $@

../build/seqStack_plus.o: seqStack_plus.c ../include/seqStack_plus.h \
 ../include/common.h ../include/seqStack.h ../include/seqList.h
	$(CC) $(CFLAG) -I ../include -c $< -o $@

