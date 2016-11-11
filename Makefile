CXX=g++
CXXFLAGS=-Wall -g -std=c++0x

.PHONY: clean all

all: position_test vector_test rectangle_test rectangles_test

position_test: position_test.o geometry.o testing.o
	$(CXX) $(CXXFLAGS) -o $@ $^

vector_test: vector_test.o geometry.o testing.o
	$(CXX) $(CXXFLAGS) -o $@ $^

rectangle_test: rectangle_test.o geometry.o testing.o
	$(CXX) $(CXXFLAGS) -o $@ $^

rectangles_test: rectangles_test.o geometry.o testing.o
	$(CXX) $(CXXFLAGS) -o $@ $^

geometry.o:
	$(CXX) $(CXXFLAGS) -c -o geometry.o geometry.cc

.PHONY: clean

clean:
	rm -rf *.o position_test vector_test rectangle_test rectangles_test
