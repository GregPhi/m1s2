CXXFLAGS = -Wall -std=c++14 -MMD -fno-elide-constructors
LDFLAGS=
CPP=g++
LD=g++

.SUFFIXES:
.SUFFIXES: .o .cpp

EXECS = shared weak ArrayWrapper2 ArrayWrapper shared_problem UniquePtrEx 

SRCS_shared = shared.cpp 
OBJS_shared = ${SRCS_shared:.cpp=.o}

SRCS_shared_problem = shared_problem.cpp 
OBJS_shared_problem = ${SRCS_shared_problem:.cpp=.o}

SRCS_weak = weak.cpp 
OBJS_weak = ${SRCS_weak:.cpp=.o}

SRCS_ArrayWrapper2 = ArrayWrapper2.cpp 
OBJS_ArrayWrapper2 = ${SRCS_ArrayWrapper2:.cpp=.o}

SRCS_UniquePtrEx = UniquePtrEx.cpp 
OBJS_UniquePtrEx = ${SRCS_UniquePtrEx:.cpp=.o}

SRCS_ArrayWrapper = ArrayWrapper.cpp 
OBJS_ArrayWrapper = ${SRCS_ArrayWrapper:.cpp=.o}


ALL_SRCS = ${SRCS_shared} ${SRCS_shared_problem} ${SRCS_weak} ${SRCS_ArrayWrapper2} ${SRCS_UniquePtrEx} ${SRCS_ArrayWrapper2}

ALL_DEPS = ${ALL_SRCS:.cpp=.d}

all: $(EXECS)

-include $(ALL_DEPS)

.cpp.o:
	$(CPP) $(CXXFLAGS) -c $<

shared: $(OBJS_shared)
	$(LD) -o $@ $^ $(LDFLAGS) 

shared_problem: $(OBJS_shared_problem)
	$(LD) -o $@ $^ $(LDFLAGS) 

weak: $(OBJS_weak)
	$(LD) -o $@ $^ $(LDFLAGS) 

ArrayWrapper2: $(OBJS_ArrayWrapper2)
	$(LD) -o $@ $^ $(LDFLAGS) 

UniquePtrEx: $(OBJS_UniquePtrEx)
	$(LD) -o $@ $^ $(LDFLAGS) 

ArrayWrapper: $(OBJS_ArrayWrapper)
	$(LD) -o $@ $^ $(LDFLAGS) 

clean:
	rm -rf *.o
	rm -rf $(EXECS)

cleanedit:
	rm -rf *~

