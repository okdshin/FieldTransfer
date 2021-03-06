CXX = g++ -std=gnu++0x -O3
CXXFLAGS = -Wall -g -D MAIN_UNIT_TEST
INCLUDES = 
LIBS =
OBJS = main.o
PROGRAM = main.out

all:$(PROGRAM)

$(PROGRAM): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ $(INCLUDES) $(LIBS) -o $(PROGRAM)

.cpp.o:
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(LIBS) -c $<

.PHONY: clean
clean:
	rm -f *o $(PROGRAM)
