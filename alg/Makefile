CC=gcc
CFLAGS=-O1 -I ../include

all: \
../build/linkList.o \
../build/seqList.o \


../build/linkList.o: linkList.c ../include/common.h ../include/linkList.h \
 ../include/common.h
	$(CC) $(CFLAGS) -c $< -o $@

../build/seqList.o: seqList.c ../include/common.h ../include/seqList.h \
 ../include/common.h
	$(CC) $(CFLAGS) -c $< -o $@

