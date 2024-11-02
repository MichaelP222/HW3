CXX = g++
CXXFLAGS = -std=c++20 -I include -fsanitize=address -g -Wall -Wextra -Werror

SRC = src/futsal.cpp src/hw03_main.cpp src/llqueue.cpp src/player.cpp
OBJ = $(SRC:.cpp=.o)

TARGET = hw03_executable

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJ)

src/futsal.o: src/futsal.cpp include/futsal.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

src/hw03_main.o: src/hw03_main.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

src/llqueue.o: src/llqueue.cpp include/llqueue.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

src/player.o: src/player.cpp include/player.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)