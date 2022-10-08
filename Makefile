CXX := g++
CXXFLAGS := -g -Wall --std=c++11
VALGRIND := valgrind --tool=memcheck --leak-check=yes

all: llrec-test

#-----------------------------------------------------
# ADD target(s) to build your llrec-test executable
#-----------------------------------------------------

llrec-test: llrec-test.cpp llrec.h llrec.cpp
	$(CXX) $(CXXFLAGS) llrec-test.cpp llrec.cpp -o $@
	

clean:
	rm -f *.o rh llrec-test *~

.PHONY: clean 