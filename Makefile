CC=gcc
LIB=
CFLAG=-O1 -I ./include

ALG_DIR=./alg
TOOL_DIR=./tool
INCLUDE_DIR=./include
BUILD_DIR=build
RESULT_DIR=.

NAME=main

RESULT=$(RESULT_DIR)/$(NAME)

HEADERS=\
		$(INCLUDE_DIR)/common.h\
		$(INCLUDE_DIR)/seqList.h\
		$(INCLUDE_DIR)/seqList_plus.h\
		$(INCLUDE_DIR)/linkList.h\
		$(INCLUDE_DIR)/linkList_plus.h\

OBJS=\
	 $(BUILD_DIR)/main.o\
	 $(BUILD_DIR)/seqList.o\
	 $(BUILD_DIR)/seqList_plus.o\
	 $(BUILD_DIR)/linkList.o\
	 $(BUILD_DIR)/linkList_plus.o\
	 $(BUILD_DIR)/common.o\


###########################################################
#Build rules
all: dir $(RESULT)

dir:
	 mkdir -p $(BUILD_DIR) 

$(RESULT): $(OBJS)
	$(CC) $(CFLAG) $(OBJS) -o $(RESULT)

clean:
	rm -f $(OBJS) $(RESULT)
	rm -r $(BUILD_DIR)

###########################################################
$(BUILD_DIR)/main.o: main.c $(HEADERS)
	$(CC) $(CFLAG) -c $< -o $@

$(BUILD_DIR)/seqList_plus.o: $(TOOL_DIR)/seqList_plus.c $(HEADERS)
	$(CC) $(CFLAG) -c $< -o $@

$(BUILD_DIR)/seqList.o: $(ALG_DIR)/seqList.c $(HEADERS)
	$(CC) $(CFLAG) -c $< -o $@

$(BUILD_DIR)/linkList_plus.o: $(TOOL_DIR)/linkList_plus.c $(HEADERS)
	$(CC) $(CFLAG) -c $< -o $@

$(BUILD_DIR)/linkList.o: $(ALG_DIR)/linkList.c $(HEADERS)
	$(CC) $(CFLAG) -c $< -o $@

$(BUILD_DIR)/common.o: $(TOOL_DIR)/common.c $(HEADERS)
	$(CC) $(CFLAG) -c $< -o $@
