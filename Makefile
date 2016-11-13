CXX=g++
CXXFLAGS=-Wall -g -std=c++14

TESTS=position_test vector_test rectangle_test rectangles_test addition_test

.PHONY: clean all

all: $(TESTS)

position_test: position_test.o geometry.o testing.o
	$(CXX) $(CXXFLAGS) -o $@ $^

vector_test: vector_test.o geometry.o testing.o
	$(CXX) $(CXXFLAGS) -o $@ $^

rectangle_test: rectangle_test.o geometry.o testing.o
	$(CXX) $(CXXFLAGS) -o $@ $^

rectangles_test: rectangles_test.o geometry.o testing.o
	$(CXX) $(CXXFLAGS) -o $@ $^

addition_test: addition_test.o geometry.o testing.o
	$(CXX) $(CXXFLAGS) -o $@ $^

geometry.o:
	$(CXX) $(CXXFLAGS) -c -o geometry.o geometry.cc

.PHONY: clean

clean:
	rm -rf *.o $(TESTS)
