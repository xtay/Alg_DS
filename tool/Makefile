CC=gcc
CFLAGS=-O1 -I ../include

all: \
../build/common.o \
../build/linkList_plus.o \
../build/seqList_plus.o \


../build/common.o: common.c ../include/common.h
	$(CC) $(CFLAGS) -c $< -o $@

../build/linkList_plus.o: linkList_plus.c ../include/linkList_plus.h \
 ../include/common.h ../include/linkList.h
	$(CC) $(CFLAGS) -c $< -o $@

../build/seqList_plus.o: seqList_plus.c ../include/seqList_plus.h \
 ../include/common.h ../include/seqList.h
	$(CC) $(CFLAGS) -c $< -o $@

