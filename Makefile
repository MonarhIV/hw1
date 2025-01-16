CXX = g++
CXXFLAGS = -std=c++11 -Wall -O2

SRCS = main.cpp queue.cpp adapter4queue.cpp
TEST_SRCS= test.cpp queue.cpp adapter4queue.cpp

TARGET = queue.exe

all: $(TARGET) start test clean

$(TARGET):
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET)

start:
	.\queue.exe

test:
	$(CXX) $(CXXFLAGS) $(TEST_SRCS) -o test.exe
	.\test.exe

clean:
	rm -f *.exe
