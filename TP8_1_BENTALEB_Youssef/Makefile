all:
	g++ -std=c++23 -Wall -c movie.cpp
	g++ -std=c++23 -Wall -c movies.cpp
	g++ -std=c++23 -Wall -c main.cpp
	g++ -std=c++23 -Wall -o main movie.o movies.o main.o

clean:
	rm movie.o
	rm movies.o
	rm main.o
	rm main
