# Makefile in Tests/

CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -I../Include -I../Include/Domain -I../Include/Presentation

SRC = testsunitaires.cpp
OUT = tests

all: $(OUT)

$(OUT): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(OUT) $(SRC)

clean:
	rm -f $(OUT)

.PHONY: all clean
