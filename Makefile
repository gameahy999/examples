PROG=test
CFLAGS=-c -Wall -std=c++14 -g
LIBS=-lpthread

ALL_SOURCES := main.cpp
ALL_SOURCES += copy_control.cpp
ALL_SOURCES += grammer.cpp
ALL_SOURCES += math_experiment.cpp
ALL_SOURCES += memory_leak.cpp
ALL_SOURCES += misc.cpp
ALL_SOURCES += standard_library.cpp
ALL_SOURCES += utils.cpp

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
