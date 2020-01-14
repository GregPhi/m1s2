CXXFLAGS = -Wall -std=c++17 -MMD 
LDFLAGS=
CPP=g++
LD=g++

.SUFFIXES:
.SUFFIXES: .o .cpp

EXECS = fibonacci select container_constexpr fun_policy fun_policy2 fun_policy3 safe_printf tuple constexpr

SRCS_fibonacci = fibonacci.cpp 
OBJS_fibonacci = ${SRCS_fibonacci:.cpp=.o}

SRCS_select = select.cpp 
OBJS_select = ${SRCS_select:.cpp=.o}

SRCS_container = container.cpp triangle.cpp rect.cpp circle.cpp shape.cpp  
OBJS_container = ${SRCS_container:.cpp=.o}

SRCS_container_constexpr = container_constexpr.cpp triangle.cpp rect.cpp circle.cpp shape.cpp  
OBJS_container_constexpr = ${SRCS_container_constexpr:.cpp=.o}

SRCS_fun_policy = fun_policy.cpp 
OBJS_fun_policy = ${SRCS_fun_policy:.cpp=.o}

SRCS_fun_policy2 = fun_policy2.cpp 
OBJS_fun_policy2 = ${SRCS_fun_policy2:.cpp=.o}

SRCS_fun_policy3 = fun_policy3.cpp 
OBJS_fun_policy3 = ${SRCS_fun_policy3:.cpp=.o}

SRCS_safe_printf = safe_printf.cpp 
OBJS_safe_printf = ${SRCS_safe_printf:.cpp=.o}

SRCS_tuple = tuples.cpp
OBJS_tuple = ${SRCS_tuple:.cpp=.o}

SRCS_constexpr = constexpr.cpp
OBJS_constexpr = ${SRCS_constexpr:.cpp=.o}



ALL_SRCS = ${SRCS_fibonacci} ${SRCS_select} ${SRCS_container} ${SRCS_container_constexpr} ${SRCS_fun_policy} ${SRCS_fun_policy2} ${SRCS_fun_policy3} ${SRCS_safe_printf} ${SRCS_tuple} ${SRCS_constexpr}

ALL_DEPS = ${ALL_SRCS:.cpp=.d}

all: $(EXECS)

-include $(ALL_DEPS)

.cpp.o:
	$(CPP) $(CXXFLAGS) -c $<

fibonacci: $(OBJS_fibonacci)
	$(LD) -o $@ $^ $(LDFLAGS) 

select: $(OBJS_select)
	$(LD) -o $@ $^ $(LDFLAGS) 

container: $(OBJS_container)
	$(LD) -o $@ $^ $(LDFLAGS) 

container_constexpr: $(OBJS_container_constexpr)
	$(LD) -o $@ $^ $(LDFLAGS) 

fun_policy: $(OBJS_fun_policy)
	$(LD) -o $@ $^ $(LDFLAGS) 

fun_policy2: $(OBJS_fun_policy2)
	$(LD) -o $@ $^ $(LDFLAGS) 

fun_policy3: $(OBJS_fun_policy3)
	$(LD) -o $@ $^ $(LDFLAGS) 

safe_printf: $(OBJS_safe_printf)
	$(LD) -o $@ $^ $(LDFLAGS) 

tuple: $(OBJS_tuple)
	$(LD) -o $@ $^ $(LDFLAGS) 

constexpr: $(OBJS_constexpr)
	$(LD) -o $@ $^ $(LDFLAGS) 


clean:
	rm -rf *.o
	rm -rf $(EXECS)

cleanedit:
	rm -rf *~

