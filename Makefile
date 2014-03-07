CC=gcc
LIB=
CFLAG=-O1 -I ./include

ALG_DIR=alg
TOOL_DIR=tool
INCLUDE_DIR=include
BUILD_DIR=build
RESULT_DIR=.

NAME=main

RESULT=$(RESULT_DIR)/$(NAME)

#get all of the header files
HEADERS = $(shell find $(INCLUDE_DIR) -name '*.h')

#the name of C file should be preserved, so that this line could guess all the object files that will be generated during the compilation.
OBJS = $(shell find $(ALG_DIR) $(TOOL_DIR) -name '*.c' | cut -d '/' -f 2 | sed -e "s/.c$$/.o/g" | sed -s "s/^/$(BUILD_DIR)\//g" )

OBJS += $(BUILD_DIR)/main.o

###########################################################
#Build rules
all: dir $(RESULT)

dir:
	@if [ ! -d $(BUILD_DIR) ]; then\
		 mkdir -p $(BUILD_DIR);\
	 fi

$(RESULT): .algStamp .toolStamp makeAlg makeTool $(OBJS)
	$(CC) $(CFLAG) $(OBJS) -o $(RESULT)

clean:
	rm -rf $(BUILD_DIR)
	rm -f $(RESULT)
	rm -f .algStamp .toolStamp

###########################################################
$(BUILD_DIR)/main.o: main.c $(HEADERS)
	$(CC) $(CFLAG) -c $< -o $@

makeAlg:
	$(MAKE) -C $(ALG_DIR)

makeTool:
	$(MAKE) -C $(TOOL_DIR)

.algStamp: $(ALG_DIR)
	cd $(ALG_DIR) \
	. genMake.sh  \
	cd ..
	touch .algStamp

.toolStamp: $(TOOL_DIR)
	cd $(TOOL_DIR) \
	. genMake.sh  \
	cd ..
	touch .toolStamp
