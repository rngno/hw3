CXX := g++
CXXFLAGS := -g -Wall --std=c++11
VALGRIND := valgrind --tool=memcheck --leak-check=yes

all: llrec-test

#-----------------------------------------------------
# ADD target(s) to build your llrec-test executable
#-----------------------------------------------------
llrec-test: llrec.o llrec-test.o
	$(CXX) $(CXXFLAGS) -o llrec-test llrec.o llrec-test.o

llrec.o: llrec.cpp
	$(CXX) $(CXXFLAGS) -c llrec.cpp

llrec-test.o: llrec-test.cpp
	$(CXX) $(CXXFLAGS) -c llrec-test.cpp

run: llrec-test
	$(VALGRIND) ./llrec-test

clean:
	rm -f *.o rh llrec-test *~

.PHONY: clean 