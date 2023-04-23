APP_NAME = project
LIB_NAME = LibOfProject

source_dirs = src/LibOfProject test_src/test_lib

CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = $(addprefix -I,$(source_dirs)) -MMD

BIN_DIR = bin
OBJ_DIR = obj
SRC_DIR = src

APP_PATH = $(BIN_DIR)/$(APP_NAME)
LIB_PATH = $(OBJ_DIR)/$(SRC_DIR)/$(LIB_NAME)/$(LIB_NAME).a

SRC_EXT = cpp
CC = g++

APP_SOURCES = $(shell find $(SRC_DIR)/$(APP_NAME) -name '*.$(SRC_EXT)')
APP_OBJECTS = $(APP_SOURCES:$(SRC_DIR)/%.$(SRC_EXT)=$(OBJ_DIR)/$(SRC_DIR)/%.o)

LIB_SOURCES = $(shell find $(SRC_DIR)/$(LIB_NAME) -name '*.$(SRC_EXT)')
LIB_OBJECTS = $(LIB_SOURCES:$(SRC_DIR)/%.$(SRC_EXT)=$(OBJ_DIR)/$(SRC_DIR)/%.o)


.PHONY: all clean test
all: $(APP_PATH)

-include $(wildcard *.d) 

$(APP_PATH): $(APP_OBJECTS) $(LIB_PATH)
	$(CC) $(CFLAGS) $(CPPFLAGS) $^ -o $@

$(LIB_PATH): $(LIB_OBJECTS)
	ar rcs $@ $^

$(OBJ_DIR)/%.o: %.cpp
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@


clean:
	find $(BIN_DIR) -name '*' -exec $(RM) '{}' \;
	find $(OBJ_DIR) -name '*.o' -exec $(RM) '{}' \;
	find $(OBJ_DIR) -name '*.d' -exec $(RM) '{}' \;


TEST_NAME = test
TESTLIB_NAME = test_lib

TESTSRC_DIR = test_src

TEST_PATH = $(BIN_DIR)/$(TEST_NAME)
TESTLIB_PATH = $(OBJ_DIR)/$(TESTSRC_DIR)/$(TESTLIB_NAME)/$(TESTLIB_NAME).a

TEST_SOURCES = $(shell find $(TESTSRC_DIR)/$(TEST_NAME) -name '*.$(SRC_EXT)')
TEST_OBJECTS = $(TEST_SOURCES:$(TESTSRC_DIR)/%.$(SRC_EXT)=$(OBJ_DIR)/$(TESTSRC_DIR)/%.o)

TESTLIB_SOURCES = $(shell find $(TESTSRC_DIR)/$(TESTLIB_NAME) -name '*.$(SRC_EXT)')
TESTLIB_OBJECTS = $(TESTLIB_SOURCES:$(TESTSRC_DIR)/%.$(SRC_EXT)=$(OBJ_DIR)/$(TESTSRC_DIR)/%.o)

test: $(TEST_PATH)

$(TEST_PATH): $(TEST_OBJECTS) $(TESTLIB_PATH) $(LIB_PATH)
	$(CC) $(CFLAGS) $(CPPFLAGS) $^ -o $@

$(TESTLIB_PATH): $(TESTLIB_OBJECTS)
	ar rcs $@ $^

$(OBJ_DIR)/%.o: %.cpp
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@