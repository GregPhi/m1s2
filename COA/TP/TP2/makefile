CXXFLAGS = -Wall -std=c++14
LDFLAGS=
CPP=g++
LD=g++

.SUFFIXES:
.SUFFIXES: .o .cpp

EXECS = stack_main stack_test

SRCS_stack = Stack.cpp
OBJS_stack = ${SRCS_stack:.cpp=.o}

<<<<<<< HEAD
SRCS_hanoi = Hanoi.cpp
=======
SRCS_hanoi = Stack.cpp Hanoi.cpp
>>>>>>> 5df3a5ea855bfb5836b97da22a880d88737bc88b
OBJS_hanoi = ${SRCS_hanoi:.cpp=.o}

SRCS_main = main.cpp
OBJS_main = ${SRCS_main:.cpp=.o}

SRCS_test = testoperator.cpp
OBJS_test = ${SRCS_test:.cpp=.o}

all: $(EXECS)

.cpp.o:
	$(CPP) $(CXXFLAGS) -c $<

<<<<<<< HEAD
stack_main: $(OBJS_stack) $(OBJS_hanoi) $(OBJS_main)
=======
stack_main: $(OBJS_stack) $(OBJS_main)
>>>>>>> 5df3a5ea855bfb5836b97da22a880d88737bc88b
	$(LD) $(LDFLAGS) -o $@ $^

stack_test: $(OBJS_stack) $(OBJS_test)
	$(LD) $(LDFLAGS) -o $@ $^

clean:
	rm -rf *.o
	rm -rf $(EXECS)

cleanedit:
	rm -rf *~
