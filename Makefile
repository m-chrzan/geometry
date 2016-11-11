CXX=g++
CXXFLAGS=-Wall -g

.PHONY: clean all

all: position_test vector_test

position_test: position_test.o geometry.o testing.o
	$(CXX) $(CXXFLAGS) -o $@ $^

vector_test: vector_test.o geometry.o testing.o
	$(CXX) $(CXXFLAGS) -o $@ $^

geometry.o:
	$(CXX) $(CXXFLAGS) -c -o geometry.o geometry.cc

.PHONY: clean

clean:
	rm -rf *.o position_test vector_test
