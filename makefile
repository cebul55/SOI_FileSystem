all: main.cpp fs.cpp fs.h
	g++ main.cpp fs.cpp -oVirtualFS -g -Wall -lboost_program_options -lboost_filesystem -lboost_system
run:
	./VirtualFS