# Makefile for gtest examples

BIN          := bin
OBJ          := obj

APP          := $(BIN)/app
APP_SRC_DIR  := src
APP_OBJ_DIR  := $(OBJ)/app

TEST         := $(BIN)/test
TEST_SRC_DIR := test
TEST_OBJ_DIR := $(OBJ)/test

APP_SRC      := $(wildcard $(APP_SRC_DIR)/*.cpp)
APP_OBJ      := $(APP_SRC:.cpp=.o)
APP_OBJ      := $(APP_OBJ:src%=$(APP_OBJ_DIR)%)

TEST_SRC     := $(wildcard $(TEST_SRC_DIR)/*.cpp)
TEST_OBJ     := $(TEST_SRC:.cpp=.o)
TEST_OBJ     := $(TEST_OBJ:src%=$(APP_OBJ_DIR)%)

# CPPFLAGS +=
CPPFLAGS += -I. -pthread
CXXFLAGS += -g -Wall -Wextra

.PHONY: all app clean

all: app

app: $(APP)

$(APP): $(APP_OBJ) | $(BIN)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $^ -o $@

$(APP_OBJ_DIR)/%.o : $(APP_SRC_DIR)/%.cpp | $(OBJ) $(APP_OBJ_DIR)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

$(BIN) $(OBJ) $(APP_OBJ_DIR):
	mkdir $@

clean:
	$(RM) -rf $(BIN) $(OBJ)
