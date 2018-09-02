# Makefile for gtest examples

GTEST_DIR = ./dependencies/gtest/googletest

CPPFLAGS += -isystem $(GTEST_DIR)/include
CXXFLAGS += -g -Wall -Wextra -pthread


GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h \
                $(GTEST_DIR)/include/gtest/internal/*.h

TARGET = test-runner

OBJECTS = test-runner.o \
 string-compare.o \
 ../src/example.o \
 example.spec.o


all: $(TARGET)

clean:
	rm -f gtest.a gtest_main.a *.o $(OBJECTS) $(TARGET)

# Builds gtest.a and gtest_main.a.

GTEST_SRCS_ = $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h $(GTEST_HEADERS)

gtest-all.o : $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c \
            $(GTEST_DIR)/src/gtest-all.cc

gtest_main.o : $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c \
            $(GTEST_DIR)/src/gtest_main.cc

gtest.a : gtest-all.o
	$(AR) $(ARFLAGS) $@ $^

gtest_main.a : gtest-all.o gtest_main.o
	$(AR) $(ARFLAGS) $@ $^


# Build test-runner
$(TARGET): $(OBJECTS) gtest_main.a
	@echo "Target..."
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -I../src -lpthread $^ -o $@

%.o : %.cpp $(GTEST_HEADERS)
	@echo "Objects..."
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -I../src -c $< -o $@

.PHONY: all clean
