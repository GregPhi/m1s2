CXXFLAGS = -Wall -std=c++14
LDFLAGS=
CPP=g++
LD=g++

.SUFFIXES:
.SUFFIXES: .o .cpp

EXECS = shapes example1 virt_in_constr duplicate breaktie slicing offset dominance vbase  dominance2 multiple

SRCS_shapes = shape.cpp rect.cpp circle.cpp triangle.cpp main.cpp  
OBJS_shapes = ${SRCS_shapes:.cpp=.o}

SRCS_example1 = example1.cpp 
OBJS_example1 = ${SRCS_example1:.cpp=.o}

SRCS_virt_in_constr = virt_in_constr.cpp 
OBJS_virt_in_constr = ${SRCS_virt_in_constr:.cpp=.o}

SRCS_duplicate = duplicate.cpp 
OBJS_duplicate = ${SRCS_duplicate:.cpp=.o}

SRCS_breaktie = breaktie.cpp 
OBJS_breaktie = ${SRCS_breaktie:.cpp=.o}

SRCS_slicing = slicing.cpp 
OBJS_slicing = ${SRCS_slicing:.cpp=.o}

SRCS_offset = offset.cpp 
OBJS_offset = ${SRCS_offset:.cpp=.o}

SRCS_dominance = dominance.cpp 
OBJS_dominance = ${SRCS_dominance:.cpp=.o}

SRCS_vbase = vbase.cpp 
OBJS_vbase = ${SRCS_vbase:.cpp=.o}

SRCS_dominance2 = dominance2.cpp 
OBJS_dominance2 = ${SRCS_dominance2:.cpp=.o}

SRCS_multiple = multiple.cpp 
OBJS_multiple = ${SRCS_multiple:.cpp=.o}



all: $(EXECS)

.cpp.o:
	$(CPP) $(CXXFLAGS) -c $<

shapes: $(OBJS_shapes)
	$(LD) $(LDFLAGS) -o $@ $^

example1: $(OBJS_example1)
	$(LD) $(LDFLAGS) -o $@ $^

virt_in_constr: $(OBJS_virt_in_constr)
	$(LD) $(LDFLAGS) -o $@ $^

duplicate: $(OBJS_duplicate)
	$(LD) $(LDFLAGS) -o $@ $^

breaktie: $(OBJS_breaktie)
	$(LD) $(LDFLAGS) -o $@ $^

slicing: $(OBJS_slicing)
	$(LD) $(LDFLAGS) -o $@ $^

offset: $(OBJS_offset)
	$(LD) $(LDFLAGS) -o $@ $^

dominance: $(OBJS_dominance)
	$(LD) $(LDFLAGS) -o $@ $^

vbase: $(OBJS_vbase)
	$(LD) $(LDFLAGS) -o $@ $^

dominance2: $(OBJS_dominance2)
	$(LD) $(LDFLAGS) -o $@ $^

multiple: $(OBJS_multiple)
	$(LD) $(LDFLAGS) -o $@ $^


clean:
	rm -rf *.o
	rm -rf $(EXECS)

cleanedit:
	rm -rf *~

