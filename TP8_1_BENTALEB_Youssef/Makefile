all:
	g++ -std=c++23 -Wall -c movie.cpp
	g++ -std=c++23 -Wall -c movies.cpp
	g++ -std=c++23 -Wall -c main.cpp
	g++ -std=c++23 -Wall -o main movie.o movies.o main.o

clean:
	del movie.o
	del movies.o
	del main.o
	del main.exe
