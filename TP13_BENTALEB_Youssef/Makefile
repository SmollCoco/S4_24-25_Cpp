TARGETS := exo1 exo2 exo3 exo4

all: $(TARGETS)

%: %.cpp
	g++ -Wall -Wextra -std=c++23 $< -o $@

clean:
	rm $(TARGETS)

.PHONY: all clean
