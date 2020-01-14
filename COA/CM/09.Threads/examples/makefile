CXXFLAGS = -Wall -std=c++17 -O2
LDFLAGS= -Wl,--no-as-needed -lpthread 
CPP=g++
LD=g++

.SUFFIXES:
.SUFFIXES: .o .cpp

EXECS = threadex threadex2 thread_ret thread_nodetach thread_class	\
	thread_exception thread_object_end thread_local			\
	thread_mailbox thread_group parallel_vector count_matrix	\
	parallel_sum

all: $(EXECS)

include .deps

.cpp.o:
	$(CPP) $(CXXFLAGS) -c $<

SRCS_threadex = threadex.cpp 
OBJS_threadex = ${SRCS_threadex:.cpp=.o}

threadex: $(OBJS_threadex)
	$(LD) -o $@ $^ $(LDFLAGS)  

SRCS_threadex2 = threadex2.cpp 
OBJS_threadex2 = ${SRCS_threadex2:.cpp=.o}

threadex2: $(OBJS_threadex2)
	$(LD) -o $@ $^ $(LDFLAGS) 

SRCS_thread_ret = thread_ret.cpp 
OBJS_thread_ret = ${SRCS_thread_ret:.cpp=.o}

thread_ret: $(OBJS_thread_ret)
	$(LD) -o $@ $^ $(LDFLAGS) 

SRCS_thread_nodetach = thread_nodetach.cpp 
OBJS_thread_nodetach = ${SRCS_thread_nodetach:.cpp=.o}

thread_nodetach: $(OBJS_thread_nodetach)
	$(LD) -o $@ $^ $(LDFLAGS) 

SRCS_thread_class = thread_class.cpp 
OBJS_thread_class = ${SRCS_thread_class:.cpp=.o}

thread_class: $(OBJS_thread_class)
	$(LD) -o $@ $^ $(LDFLAGS) 

SRCS_thread_exception = thread_exception.cpp 
OBJS_thread_exception = ${SRCS_thread_exception:.cpp=.o}

thread_exception: $(OBJS_thread_exception)
	$(LD) -o $@ $^ $(LDFLAGS) 

SRCS_thread_object_end = thread_object_end.cpp 
OBJS_thread_object_end = ${SRCS_thread_object_end:.cpp=.o}

thread_object_end: $(OBJS_thread_object_end)
	$(LD) -o $@ $^ $(LDFLAGS) 

SRCS_thread_local = thread_local.cpp 
OBJS_thread_local = ${SRCS_thread_local:.cpp=.o}

thread_local: $(OBJS_thread_local)
	$(LD) -o $@ $^ $(LDFLAGS) 

SRCS_thread_mailbox = thread_mailbox.cpp  
OBJS_thread_mailbox = ${SRCS_thread_mailbox:.cpp=.o}

thread_mailbox: $(OBJS_thread_mailbox)
	$(LD) -o $@ $^ $(LDFLAGS) 

SRCS_thread_group = thread_group.cpp barrier.cpp var_printf.cpp
OBJS_thread_group = ${SRCS_thread_group:.cpp=.o}

thread_group: $(OBJS_thread_group) 
	$(LD) -o $@ $^ $(LDFLAGS) 

SRCS_parallel_vector = parallel_vector.cpp barrier.cpp
OBJS_parallel_vector = ${SRCS_parallel_vector:.cpp=.o}

parallel_vector: $(OBJS_parallel_vector)
	$(LD) -o $@ $^ $(LDFLAGS) 

SRCS_count_matrix = count_matrix.cpp barrier.cpp
OBJS_count_matrix = ${SRCS_count_matrix:.cpp=.o}

count_matrix: $(OBJS_count_matrix)
	$(LD) -o $@ $^ $(LDFLAGS) 

SRCS_parallel_sum = parallel_sum.cpp
OBJS_parallel_sum = ${SRCS_parallel_sum:.cpp=.o}

parallel_sum: $(OBJS_parallel_sum)
	$(LD) -o $@ $^ $(LDFLAGS) 

clean:
	rm -rf *.o
	rm -rf $(EXECS)

cleanedit:
	rm -rf *~
