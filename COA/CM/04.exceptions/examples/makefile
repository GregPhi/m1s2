CXXFLAGS = -Wall --std=c++14
LDFLAGS=
CPP=g++
LD=g++

.SUFFIXES:
.SUFFIXES: .o .cpp

EXECS = stack iterator-example2 sort-example iterator-example3 iterator-example4 exception-example iterator-example swap rawp map_example exception_wrap terminator stack_template_main operatornew stdfunctions


SRCS_stack = stack_main.cpp stack.cpp  
OBJS_stack = ${SRCS_stack:.cpp=.o}

SRCS_stack_template_main = stack_template_main.cpp 
OBJS_stack_template_main = ${SRCS_stack_template_main:.cpp=.o}

SRCS_terminator = terminate.cpp
OBJS_terminator = ${SRCS_terminator:.cpp=.o}

SRCS_iterator-example2 = iterator-example2.cpp 
OBJS_iterator-example2 = ${SRCS_iterator-example2:.cpp=.o}

SRCS_sort-example = sort-example.cpp 
OBJS_sort-example = ${SRCS_sort-example:.cpp=.o}

SRCS_iterator-example3 = iterator-example3.cpp 
OBJS_iterator-example3 = ${SRCS_iterator-example3:.cpp=.o}

SRCS_iterator-example4 = iterator-example4.cpp 
OBJS_iterator-example4 = ${SRCS_iterator-example4:.cpp=.o}

SRCS_exception-example = exception-example.cpp 
OBJS_exception-example = ${SRCS_exception-example:.cpp=.o}

SRCS_iterator-example = iterator-example.cpp 
OBJS_iterator-example = ${SRCS_iterator-example:.cpp=.o}

SRCS_operatornew = operatornew.cpp 
OBJS_operatornew = ${SRCS_operatornew:.cpp=.o}

SRCS_stdfunctions = stdfunctions.cpp 
OBJS_stdfunctions = ${SRCS_stdfunctions:.cpp=.o}


SRCS_swap = swap.cpp 
OBJS_swap = ${SRCS_swap:.cpp=.o}

SRCS_rawp = rawp.cpp 
OBJS_rawp = ${SRCS_rawp:.cpp=.o}

SRCS_map_example = map_example.cpp 
OBJS_map_example = ${SRCS_map_example:.cpp=.o}

SRCS_exception_wrap = exception_wrap.cpp 
OBJS_exception_wrap = ${SRCS_exception_wrap:.cpp=.o}

all: $(EXECS)

operatornew.o : operatornew.cpp myclass.hpp

stack_template_main.o : stack_template_main.cpp stack_template.hpp

.cpp.o:
	$(CPP) $(CXXFLAGS) -c $<

stack: $(OBJS_stack)
	$(LD) -o $@ $^ $(LDFLAGS) 

iterator-example2: $(OBJS_iterator-example2)
	$(LD) -o $@ $^ $(LDFLAGS) 

sort-example: $(OBJS_sort-example)
	$(LD) -o $@ $^ $(LDFLAGS) 

iterator-example3: $(OBJS_iterator-example3)
	$(LD) -o $@ $^ $(LDFLAGS) 

iterator-example4: $(OBJS_iterator-example4)
	$(LD) -o $@ $^ $(LDFLAGS) 

exception-example: $(OBJS_exception-example)
	$(LD) -o $@ $^ $(LDFLAGS) 

iterator-example: $(OBJS_iterator-example)
	$(LD) -o $@ $^ $(LDFLAGS) 

swap: $(OBJS_swap)
	$(LD) -o $@ $^ $(LDFLAGS) 

rawp: $(OBJS_rawp)
	$(LD) -o $@ $^ $(LDFLAGS) 

map_example: $(OBJS_map_example)
	$(LD) -o $@ $^ $(LDFLAGS) 

exception_wrap: $(OBJS_exception_wrap)
	$(LD) -o $@ $^ $(LDFLAGS) 

terminator: $(OBJS_terminator)
	$(LD) -o $@ $^ $(LDFLAGS) 

stack_template_main : $(OBJS_stack_template_main)
	$(LD) -o $@ $^ $(LDFLAGS) 

operatornew : $(OBJS_operatornew)
	$(LD) -o $@ $^ $(LDFLAGS) 

stdfunctions : $(OBJS_stdfunctions)
	$(LD) -o $@ $^ $(LDFLAGS) 

clean:
	rm -rf *.o
	rm -rf $(EXECS)

cleanedit:
	rm -rf *~

