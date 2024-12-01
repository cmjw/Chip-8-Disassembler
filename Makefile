CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2

TARGET = disassembler
SOURCES = src/main.cpp src/disassembler.cpp
HEADERS = src/disassembler.h

# default rule
all : $(TARGET)

# target executable
$(TARGET) : $(SOURCES) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET)

# clean build files
clean:
	$(RM) $(TARGET)

# phony targets
.PHONY: all clean