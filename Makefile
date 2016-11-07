CXX=g++
CXXFLAGS=-Wall -g

geometry.o:
	$(CXX) -c -o geometry.o geometry.cc

.PHONY: clean

clean:
	rm -rf geometry.o
