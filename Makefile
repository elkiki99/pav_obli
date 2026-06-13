CXX = g++
# DEBUG=1 to enable debug symbols (-g). Default: optimized build.
DEBUG ?= 0
ifeq ($(DEBUG),1)
CXXFLAGS = -std=c++17 -Wall -Wextra -I. -g
else
CXXFLAGS = -std=c++17 -Wall -Wextra -I. -O2
endif
LDFLAGS =
TARGET = pav_obli
SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)

.PHONY: all clean run debug

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(LDFLAGS) -o $@ $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: all
	./$(TARGET)

debug:
	$(MAKE) DEBUG=1 all

clean:
	rm -f $(OBJS) $(TARGET)
