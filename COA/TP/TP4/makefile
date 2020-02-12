CXXFLAGS = -Wall -std=c++14 -MMD
LDFLAGS=
CPP=g++
LD=g++

.SUFFIXES:
.SUFFIXES: .o .cpp

EXECS = main test

SRCS_main = main.cpp
OBJS_main = ${SRCS_main:.cpp=.o}

SRCS_test = test.cpp test_intersect.cpp
OBJS_test = ${SRCS_test:.cpp=.o}

SRCS_ope = set_operations.cpp
OBJS_ope = ${SRCS_ope:.cpp=.o}

ALL_SRCS = ${SRCS_ope} ${SRCS_main} ${SRCS_test}

ALL_DEPS = ${ALL_SRCS:.cpp=.d}

all: $(EXECS)

-include $(ALL_DEPS)

.cpp.o:
	$(CPP) $(CXXFLAGS) -c $<

main: $(OBJS_main)
	$(LD) -o $@ $^ $(LDFLAGS)

test: $(OBJS_test)
	$(LD) -o $@ $^ $(LDFLAGS)


clean:
	rm -rf *.o
	rm -rf $(EXECS)

cleanedit:
	rm -rf *~
