# Makefile for Resman source and examples
# MIT License
# Julien LE THENO

all: setup clean test 

SHELL:=/bin/bash
MAKE=make

BUILD_DIR=build
OBJECTS_DIR=$(BUILD_DIR)/obj
EXE_DIR=$(BUILD_DIR)/exe
SRC_DIR=src
TEST_DIR=test
INC_DIR+=inc
INC_PARAM=$(foreach d, $(INC_DIR), -I$d)

F1_EXISTS=$(shell [ -e $(BUILD_DIR) ] && echo Y || echo N )

.PHONY: all test clean

### EXAMPLES TARGETS

# TEST EXAMPLE
test: test.o 
	gcc -o $(EXE_DIR)/test_exe $(OBJECTS_DIR)/*

test.o: resman.o $(TEST_DIR)/main.c 
	gcc -g -c $(TEST_DIR)/main.c $(SRC_DIR) $(INC_PARAM) -o  $(OBJECTS_DIR)/test.o
### END EXAMPLE TARGETS


### LIB TARGET
lib: resman.o

resman.o: $(SRC_DIR)/resman.c
	gcc -g -c $(SRC_DIR)/resman.c $(INC_PARAM) -o $(OBJECTS_DIR)/resman.o

### END LIB TARGET

setup:
ifeq ($(F1_EXISTS),N)
	@echo "Creating build directory"
	mkdir $(BUILD_DIR)
	mkdir $(EXE_DIR)
	mkdir $(OBJECTS_DIR)
endif

make clean:
	rm -f $(EXE_DIR)/*
	rm -f $(OBJECTS_DIR)/*

make rebuild: clean all
