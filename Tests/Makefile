# ========================
# Makefile pour les tests
# ========================

# Nom du compilateur
CXX = g++

# Répertoires
TEST_DIR := .
SRC_DIR := ../src
INCLUDE_DIR := ../Include
OBJ_DIR := out
BIN_DIR := exe

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
	rm -rf $(BIN_DIR)

.PHONY: all clean
