SRCS = main.cc
OBJS = $(SRCS:.cc = .o)
CXX = g++
CCFLAGS = -g -Wall
.PHONY: clean

main : $(OBJS)
	$(CXX) $^ -o $@

%.o : %.cc
	$(CXX) -c $< $(CCFLAGS)

clean :
	rm *.o
