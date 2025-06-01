# Makefile pour compiler CSVReaderTest avec toutes ses dépendances

CXX      := g++
CXXFLAGS := -std=c++17 -IInclude -w

# Fichier source du test
TEST_SRC := CSVReaderTest.cpp

# Dépendances de CSVReader
DEPS := \
    ../src/Infrastructure/CSVReader.cpp \
    ../src/Domain/Sensor.cpp \
    ../src/Domain/User.cpp \
    ../src/Domain/Measurement.cpp \
    ../src/Domain/Attribute.cpp \
    ../src/Domain/Cleaner.cpp \
    ../src/Domain/Provider.cpp

# Objets à compiler
OBJS := $(TEST_SRC:.cpp=.o) $(DEPS:.cpp=.o)

# Nom de l'exécutable
TARGET := csv_reader_test

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
