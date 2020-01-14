CXXFLAGS = -Wall -std=c++14
LDFLAGS=
CPP=g++
LD=g++

.SUFFIXES:
.SUFFIXES: .o .cpp

EXECS = destructor copy1 manyobj referencearg pointerarg overload 

SRCS_destructor = destructor.cpp 
OBJS_destructor = ${SRCS_destructor:.cpp=.o}

SRCS_copy1 = copy1.cpp myclass.cpp  
OBJS_copy1 = ${SRCS_copy1:.cpp=.o}

SRCS_manyobj = manyobj.cpp manyobj-main.cpp  
OBJS_manyobj = ${SRCS_manyobj:.cpp=.o}

SRCS_referencearg = referencearg.cpp 
OBJS_referencearg = ${SRCS_referencearg:.cpp=.o}

SRCS_pointerarg = pointerarg.cpp 
OBJS_pointerarg = ${SRCS_pointerarg:.cpp=.o}

SRCS_overload = overload.cpp 
OBJS_overload = ${SRCS_overload:.cpp=.o}


all: $(EXECS)

.cpp.o:
	$(CPP) $(CXXFLAGS) -c $<

destructor: $(OBJS_destructor)
	$(LD) $(LDFLAGS) -o $@ $^

copy1: $(OBJS_copy1)
	$(LD) $(LDFLAGS) -o $@ $^

manyobj: $(OBJS_manyobj)
	$(LD) $(LDFLAGS) -o $@ $^

referencearg: $(OBJS_referencearg)
	$(LD) $(LDFLAGS) -o $@ $^

pointerarg: $(OBJS_pointerarg)
	$(LD) $(LDFLAGS) -o $@ $^

overload: $(OBJS_overload)
	$(LD) $(LDFLAGS) -o $@ $^


clean:
	rm -rf *.o
	rm -rf $(EXECS)

cleanedit:
	rm -rf *~

