SRCS := $(wildcard *.cpp)

EXES := $(SRCS:.cpp=)

all: $(EXES)

%: %.cpp
	 g++ -std=c++17 -Wall -o $@ $<

clean:
	 rm -f $(EXES)
