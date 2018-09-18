# Makefile to Final
# Prgm name:  linked list
# Author:  Brian Terrell
# Date:  06/13/2017	
# Description: This program a simple treasure hunt game

#compiler flags
#cpp std
CXXFLAGS = -std=c++0x
#show errors
CXXFLAGS += -Wall -pedantic-errors
#debugging info
CXXFLAGS += -g

#file variables
OBJS = Menu.o main.o validator.o random.o BioLab.o ControlRoom.o CrewQuarters.o EngineRoom.o GameController.o PhysicsLab.o Purse.o Room.o Storage.o

SRCS = Menu.cpp main.cpp validator.cpp random.cpp BioLab.cpp ControlRoom.cpp CrewQuarters.cpp EngineRoom.cpp GameController.cpp PhysicsLab.cpp Purse.cpp Room.cpp Storage.cpp

HEADERS = Menu.h validator.h random.h BioLab.h ControlRoom.h CrewQuarters.h EngineRoom.h GameController.h PhysicsLab.h Purse.h Room.h Storage.h

#linking to STL
output: ${OBJS} 
	${CXX} ${CXXFLAGS} ${OBJS} -o final
#compiling
${OBJS}: ${SRCS} ${HEADERS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

#erase all objects and final
clean:
	rm *.o final

