# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall

# Find all .cpp files in the directory
SRCS := $(wildcard *.cpp)

# Create a list of executables (removes .cpp extension)
EXES := $(SRCS:.cpp=)

# Rule to build all executables
all: $(EXES)

# Rule to compile each .cpp file into an executable
%: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

# Clean up all executables
clean:
	rm -f $(EXES)
