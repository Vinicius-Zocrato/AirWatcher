# Makefile (à la racine du projet)
CXX      := g++
CXXFLAGS := -std=c++17 -Wall -IInclude

# Répertoires de code
SRC_DIRS := \
    ../src/Domain \
    ../src/Infrastructure \
    ../src/Presentation

# Fichiers que nous NE voulons PAS compiler
EXCLUDE  := \
    ../src/Domain/AirQualityAnalyzer.cpp \
    ../src/Domain/SensorValidator.cpp

# Recherche tous les .cpp, puis supprime ceux qui sont dans EXCLUDE
ALL_SRCS := $(foreach d,$(SRC_DIRS),$(wildcard $(d)/*.cpp))
SRCS     := $(filter-out $(EXCLUDE),$(ALL_SRCS)) TestsUnitaires.cpp

# Convertit la liste de .cpp en liste de .o
OBJS     := $(SRCS:.cpp=.o)

# Exécutable de tests
TARGET   := run_tests

.PHONY: all clean

all: $(TARGET)

# Lie tous les .o dans l'exécutable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Règle générique pour compiler .cpp en .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	del /Q "..\\src\\Domain\\Attribute.o" "..\\src\\Domain\\Measurement.o" "..\\src\\Domain\\Sensor.o" "..\\src\\Domain\\User.o" "..\\src\\Domain\\Cleaner.o" "..\\src\\Domain\\Provider.o" "..\\src\\Infrastructure\\CSVReader.o" "..\\src\\Presentation\\ConsoleUI.o" "..\\Tests\\TestsUnitaires.o" "run_tests.exe"
