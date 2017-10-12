# build an executable named myprog from main.cpp
  all: main.cpp
  	g++ -g -Wall main.cpp -o main

  clean: 
	  $(RM) main
