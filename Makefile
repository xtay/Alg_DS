CC=gcc
CFLAG=-O1
export CC
export CFLAG
LIB=

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

#details of the $< will be explained later
$(RESULT): .algStamp .toolStamp makeAlg makeTool $(OBJS)
	$(CC) $(CFLAG) -I $(INCLUDE_DIR) $(OBJS) -o $(RESULT)

clean:
	rm -rf $(BUILD_DIR)
	rm -f $(RESULT)
	rm -f .algStamp .toolStamp

###########################################################
$(BUILD_DIR)/main.o: main.c $(HEADERS)
	$(CC) $(CFLAG) -I $(INCLUDE_DIR) -c $< -o $@

#excute Makefile in the alg dir
makeAlg:
	$(MAKE) -C $(ALG_DIR)

#excute Makefile in the tool dir
makeTool:
	$(MAKE) -C $(TOOL_DIR)

#create or recreate the Makefile while new files added into the alg dir
.algStamp: $(ALG_DIR)
	cd $(ALG_DIR); \
	bash genMake.sh;  \
	cd ..;
	touch .algStamp

#create or recreate the Makefile while new files added into the tool dir
.toolStamp: $(TOOL_DIR)
	cd $(TOOL_DIR); \
	bash genMake.sh;  \
	cd ..;
	touch .toolStamp
