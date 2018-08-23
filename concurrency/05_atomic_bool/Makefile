LINK_TARGET = atomic_bool
# CFLAGS = -ggdb -std=c++11 -stdlib=libc++
# CFLAGS = -std=c++14 -pthread
CFLAGS = -std=c++11

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
	# -g -fno-inline-functions -O0
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

# Alternatively to manually capturing dependencies, several automated
# dependency generators exist.  Here is one possibility (commented out)...
# %.dep : %.cpp
#   g++ -M $(FLAGS) $< > $@
# include $(OBJS:.o=.dep)
