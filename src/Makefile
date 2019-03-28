CPP = g++
CXXFLAGS = -Wall -pedantic
LDFLAGS= -g
RM= rm -f
CPPFLAGS=-g $(shell root-config --cflags)
LDFLAGS=-g $(shell root-config --ldflags)
LDLIBS=$(shell root-config --libs)

SRCS= main_list.cpp SL_List.cpp
OBJS=$(subst .cpp,.o,$(SRCS))

all: main_list.out

main_list.out : main_list.o SL_List.o
	$(CPP) $(CXXFLAGS) -o main_list main_list.o SL_List.o 

SL_List.o : SL_List.cpp
	$(CPP) $(CXXFLAGS) -c -o SL_List.o SL_List.cpp  
	
main_list.o : main_list.cpp SL_List.h
	$(CPP) $(CXXFLAGS) -c -o main_list.o  main_list.cpp 

clean :
	$(RM) $(OBJS) *.o

