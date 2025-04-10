SRCS = Account.cpp Savings_Account.cpp Checking_Account.cpp Trust_Account.cpp Account_Util.cpp main.cpp

OBJS = $(SRCS:.cpp=.o)

all: main

main: $(OBJS)
	g++ -Wall -Wextra -std=c++23 -o $@ $^

%.o: %.cpp
	g++ -Wall -Wextra -std=c++23 -c $< -o $@

clean:
	rm *.o main
