CXXFLAGS = -Wall
LDFLAGS=
CPP=g++
LD=g++

.SUFFIXES:
.SUFFIXES: .o .cpp

EXECS = diagonal 

SRCS_diagonal = shapes_main.cpp triangle.cpp rect.cpp circle.cpp shape.cpp  
OBJS_diagonal = ${SRCS_diagonal:.cpp=.o}


all: $(EXECS)

.cpp.o:
	$(CPP) $(CXXFLAGS) -c $<

diagonal: $(OBJS_diagonal)
	$(LD) $(LDFLAGS) -o $@ $^

clean:
	rm -rf *.o
	rm -rf $(EXECS)

cleanedit:
	rm -rf *~

