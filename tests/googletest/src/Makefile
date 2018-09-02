LINK_TARGET = example
CFLAGS = -std=c++17
GIT_GOOGLE_TEST = git@github.com:google/googletest.git

OBJS =  \
 $(LINK_TARGET).o

REBUILDABLES = $(OBJS) $(LINK_TARGET)_app

.PHONY: clean run

all : clean $(LINK_TARGET)

clean :
	@echo "Cleaning..."
	rm -f $(REBUILDABLES)

# $@ for the pattern-matched target
# $^ expands to the rule's dependencies
# $< for the pattern-matched dependency

$(LINK_TARGET) : $(OBJS)
	@echo "\nLinking..."
	g++ -o $@_app $^

%.o : %.cpp
	@echo "\nCompiling..."
	g++ -g -c -o $@ $< $(CFLAGS)


run:
	@echo
	./$(LINK_TARGET)_app $(filter-out $@,$(MAKECMDGOALS))
%:
	@:


# These are Dependency Rules, which are rules without any command.
# Main.o : Main.h Test1.h Test2.h
# Test1.o : Test1.h Test2.h
# Test2.o : Test2.h
main_tests.o : example.spec.cpp
example.spec.cpp : ../src/example.h


# Alternatively to manually capturing dependencies, several automated
# dependency generators exist.  Here is one possibility (commented out)...
# %.dep : %.cpp
#   g++ -M $(FLAGS) $< > $@
# include $(OBJS:.o=.dep)
