CXXFLAGS = -Wall --std=c++14 -MMD
LDFLAGS=
CPP=g++
LD=g++

.SUFFIXES:
.SUFFIXES: .o .cpp

EXECS = sum sum_lambda foo compose closure closure2 closure3 sumsquares eratostene prime 

SRCS_sum = sum.cpp 
OBJS_sum = ${SRCS_sum:.cpp=.o}

SRCS_foo = foo.cpp 
OBJS_foo = ${SRCS_foo:.cpp=.o}

SRCS_compose = compose.cpp 
OBJS_compose = ${SRCS_compose:.cpp=.o}

SRCS_eratostene = eratostene.cpp 
OBJS_eratostene = ${SRCS_eratostene:.cpp=.o}

SRCS_prime = primes2.cpp 
OBJS_prime = ${SRCS_prime:.cpp=.o}

SRCS_sumsquares = sumsquares.cpp 
OBJS_sumsquares = ${SRCS_sumsquares:.cpp=.o}

SRCS_closure = closure.cpp 
OBJS_closure = ${SRCS_closure:.cpp=.o}

SRCS_closure2 = closure2.cpp 
OBJS_closure2 = ${SRCS_closure2:.cpp=.o}

SRCS_closure3 = closure3.cpp 
OBJS_closure3 = ${SRCS_closure3:.cpp=.o}

SRCS_sum_lambda = sum_lambda.cpp 
OBJS_sum_lambda = ${SRCS_sum_lambda:.cpp=.o}

ALL_SRCS = ${SRCS_sum} ${SRCS_sumsquares} ${SRCS_closure} ${SRCS_closure2} ${SRCS_closure3} ${SRCS_sum_lambda} ${SRCS_eratostene} ${SRCS_prime}  

ALL_DEPS = ${ALL_SRCS:.cpp=.d}

all: $(EXECS)

-include $(ALL_DEPS)


.cpp.o:
	$(CPP) $(CXXFLAGS) -c $<

sum: $(OBJS_sum)
	$(LD) -o $@ $^ $(LDFLAGS) 

foo: $(OBJS_foo)
	$(LD) -o $@ $^ $(LDFLAGS) 

compose: $(OBJS_compose)
	$(LD) -o $@ $^ $(LDFLAGS) 

sumsquares: $(OBJS_sumsquares)
	$(LD) -o $@ $^ $(LDFLAGS) 

closure: $(OBJS_closure)
	$(LD) -o $@ $^ $(LDFLAGS) 

closure2: $(OBJS_closure2)
	$(LD) -o $@ $^ $(LDFLAGS) 

closure3: $(OBJS_closure3)
	$(LD) -o $@ $^ $(LDFLAGS) 

sum_lambda: $(OBJS_sum_lambda)
	$(LD) -o $@ $^ $(LDFLAGS) 

eratostene: $(OBJS_eratostene)
	$(LD) -o $@ $^ $(LDFLAGS) 

prime: $(OBJS_prime)
	$(LD) -o $@ $^ $(LDFLAGS) 

clean:
	rm -rf *.o
	rm -rf $(EXECS)

cleanedit:
	rm -rf *~

