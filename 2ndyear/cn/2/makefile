CXX = g++

CXXFLAGS = -std=c++11 -Wall

SOURCES = $(wildcard *.cpp)

EXECUTABLES = $(SOURCES:.cpp=)

all: $(EXECUTABLES)

%: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

clean:
	rm -f $(EXECUTABLES)

.PHONY: all clean
