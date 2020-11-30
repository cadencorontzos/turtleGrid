CXX=g++
CXX_FLAGS=-g -std=c++11
.PHONY: all clean
TARGETS=try_turtle

all: $(TARGETS)


Turtle.o: Turtle.hh
Turtle.o: Turtle.cc
	$(CXX) $(CXX_FLAGS) -c -o $@ $<

Grid.o: Grid.hh
Grid.o: Grid.cc
	$(CXX) $(CXX_FLAGS) -c -o $@ $<

try_turtle.o: Turtle.hh
try_turtle.o: Grid.hh
try_turtle.o: try_turtle.cc
	$(CXX) $(CXX_FLAGS) -c -o $@ $<

try_turtle: try_turtle.o Turtle.o Grid.o
	$(CXX) $(CXX_FLAGS) -o $@ $^

clean:
	rm -f *~ *.o $(TARGETS)
