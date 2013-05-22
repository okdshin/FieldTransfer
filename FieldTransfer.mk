CXX = g++ -std=gnu++0x -O3
CXXFLAGS = -Wall -g -D FIELDTRANSFER_UNIT_TEST
INCLUDES = 
LIBS = -lboost_system -lboost_timer -lboost_regex
OBJS = FieldTransfer.o
PROGRAM = FieldTransfer.out

all:$(PROGRAM)

$(PROGRAM): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ $(INCLUDES) $(LIBS) -o $(PROGRAM)

.cpp.o:
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(LIBS) -c $<

.PHONY: clean
clean:
	rm -f *o $(PROGRAM)
