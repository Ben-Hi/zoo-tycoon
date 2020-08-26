CXX = g++
CXXFLAGS = -std=c++11
CXXFLAGS += -g
CXXFLAGS += -Wall
#CXXFLAGS += -pedantic-errors

OBJS = main.o Zoo.o Animal.o Tiger.o Penguin.o Turtle.o validateInt.o

SRCS = main.cpp Zoo.cpp Animal.cpp Tiger.cpp Penguin.cpp Turtle.cpp validateInt.cpp

HEADERS = Zoo.hpp Animal.hpp Tiger.hpp Penguin.hpp Turtle.hpp validateInt.hpp

lab3: ${OBJS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${OBJS}  -o Zoo_Tycoon

${OBJS}: ${SRCS} ${HEADERS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o Zoo_Tycoon
