<<<<<<< Updated upstream
# ========================
# Makefile pour les tests
# ========================
=======
# Makefile (à la racine du projet)
CXX      := g++
CXXFLAGS := -std=c++17 -Wall -IInclude -w
>>>>>>> Stashed changes

# Nom du compilateur
CXX = g++

<<<<<<< Updated upstream
# Répertoires
TEST_DIR := .
SRC_DIR := ../src
INCLUDE_DIR := ../Include
OBJ_DIR := out
BIN_DIR := exe
=======
# Fichiers que nous NE voulons PAS compiler
EXCLUDE  := \
    ../src/Domain/SensorValidator.cpp
>>>>>>> Stashed changes

# Flags
INCLUDE_DIRS := $(shell find $(INCLUDE_DIR) -type d)
CXXFLAGS = -std=c++11  $(addprefix -I, $(INCLUDE_DIRS)) -I$(SRC_DIR)

# Fichiers source des tests (chaque .cpp dans ce dossier avec main)
TEST_SOURCES := $(wildcard $(TEST_DIR)/*.cpp)
TEST_NAMES := $(notdir $(basename $(TEST_SOURCES)))
EXECUTABLES := $(addprefix $(BIN_DIR)/,$(TEST_NAMES))

# Sources de l'application
APP_SOURCES := $(shell find $(SRC_DIR) -name "*.cpp")

# Règle principale
all: $(BIN_DIR) $(EXECUTABLES)

# Crée le dossier exe s'il n'existe pas
$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Compilation des tests avec les sources de l'application
$(BIN_DIR)/%: $(TEST_DIR)/%.cpp $(APP_SOURCES)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Nettoyage
clean:
<<<<<<< Updated upstream
	rm -rf $(BIN_DIR)

.PHONY: all clean
=======
	del /Q "..\\src\\Domain\\Attribute.o" "..\\src\\Domain\\AirQualityAnalyzer.o" "..\\src\\Domain\\Measurement.o" "..\\src\\Domain\\Sensor.o" "..\\src\\Domain\\User.o" "..\\src\\Domain\\Cleaner.o" "..\\src\\Domain\\Provider.o" "..\\src\\Infrastructure\\CSVReader.o" "..\\src\\Presentation\\ConsoleUI.o" "..\\Tests\\TestsUnitaires.o" "run_tests.exe"
>>>>>>> Stashed changes
