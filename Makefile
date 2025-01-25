# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++11 -Wall

# Source files
SRCS = main.cpp priorityQueue.cpp event.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Output executable
TARGET = main

# Build the target
$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)

# Clean up object files
clean:
	rm -f $(OBJS) $(TARGET)
