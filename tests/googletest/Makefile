# Makefile for gtest examples

BIN          := bin
OBJ          := obj
DEPS         := deps

APP          := $(BIN)/app
APP_SRC_DIR  := src
APP_OBJ_DIR  := $(OBJ)/app

TEST         := $(BIN)/tests
TEST_SRC_DIR := tests
TEST_OBJ_DIR := $(OBJ)/tests

APP_SRC      := $(wildcard $(APP_SRC_DIR)/*.cpp)
APP_OBJ      := $(APP_SRC:.cpp=.o)
APP_OBJ      := $(APP_OBJ:src%=$(APP_OBJ_DIR)%)

TEST_SRC     := $(wildcard $(TEST_SRC_DIR)/*.cpp)
TEST_OBJ     := $(TEST_SRC:.cpp=.o)
TEST_OBJ     := $(TEST_OBJ:src%=$(APP_OBJ_DIR)%)

# CPPFLAGS +=
CPPFLAGS += -I. -pthread
CXXFLAGS += -g -Wall -Wextra

.PHONY: all app clean cleand deps

all: app

app: $(APP)

$(APP): $(APP_OBJ) | $(BIN)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $^ -o $@

$(APP_OBJ_DIR)/%.o : $(APP_SRC_DIR)/%.cpp | $(OBJ) $(APP_OBJ_DIR)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

$(BIN) $(OBJ) $(APP_OBJ_DIR) $(DEPS):
	mkdir -p $@

clean:
	$(RM) -rf $(BIN) $(OBJ)

cleand:
	$(RM) -rf $(DEPS)

########################################
# Get 3rd-part dependencies

GOOGLE_TEST_REPO := git@github.com:google/googletest.git
GOOGLE_TEST_DIR  := $(DEPS)/gtest

.PHONY: clone
clone: $(GOOGLE_TEST_DIR) | $(DEPS)

$(GOOGLE_TEST_DIR):
	git clone --depth 1 $(GOOGLE_TEST_REPO) $@

########################################
# googletest
# Builds gtest.a and gtest_main.a.

GTEST_DIR     = $(GOOGLE_TEST_DIR)/googletest
GTEST_OBJ_DIR = $(OBJ)/gtest
GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h \
                $(GTEST_DIR)/include/gtest/internal/*.h

GTEST_CPPFLAGS += -isystem $(GTEST_DIR)/include
GTEST_CXXFLAGS += -g -Wall -Wextra -pthread

GTEST_SRCS_ = $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h $(GTEST_HEADERS)

gtest-all.o : $(GTEST_SRCS_)
	$(CXX) $(GTEST_CPPFLAGS) -I$(GTEST_DIR) $(GTEST_CXXFLAGS) -c \
         $(GTEST_DIR)/src/gtest-all.cc -o $(OBJ)/$@

gtest_main.o : $(GTEST_SRCS_)
	$(CXX) $(GTEST_CPPFLAGS) -I$(GTEST_DIR) $(GTEST_CXXFLAGS) -c \
         $(GTEST_DIR)/src/gtest_main.cc -o $(OBJ)/$@

gtest.a : gtest-all.o
	$(AR) $(ARFLAGS) $@ $^

gtest_main.a : gtest-all.o gtest_main.o
	$(AR) $(ARFLAGS) $@ $^




test: $(TEST)

$(TEST): gtest_main.a | $(BIN)
	@echo "$^ => $@"
# $(CXX) $(CPPFLAGS) $(CXXFLAGS) $^ -o $@
# $(CXX) $(CPPFLAGS) $(CXXFLAGS) -I../src -lpthread $^ -o $@


