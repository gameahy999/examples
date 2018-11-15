PROG=test
CFLAGS=-c -Wall -std=c++14 -g
LIBS=
ALL_SOURCES=main.cpp
ALL_OBJECTS=$(ALL_SOURCES:.cpp=.o)

.PHONY: clean all

all: $(PROG)
	@echo "Job's done!"

%.o: %.cpp
	g++ $(CFLAGS) $< -o $@

test: $(ALL_OBJECTS)
	g++ $^ -o $@ $(LIBS)

clean:
	-/bin/rm $(PROG)
	-/bin/rm $(ALL_OBJECTS)
