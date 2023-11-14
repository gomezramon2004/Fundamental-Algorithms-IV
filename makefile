CXX = g++
CXXFLAGS = -Wall -std=c++17
TARGET = main
GRADIR = graph

SRCS = main.cpp \
		$(GRADIR)/graph.cpp \

EXECUTABLE = a.out

all: $(EXECUTABLE)

$(EXECUTABLE): $(SRCS)
	$(CXX) $(CXXFLAGS) $^ -o $@

run: $(EXECUTABLE)
	./$(EXECUTABLE)

clean:
	rm -f $(EXECUTABLE)

.PHONY: all run clean