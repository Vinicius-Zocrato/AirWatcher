#makeFile
#todolist : verifier si les dir existent et sinon les créer et 

#Variable:

#compilateur
CXX = g++

#Option de compilation
CXXFLAGS = -ansi -pedantic -Wall -std=c++11  -I$(INCLUDE_DIR)

#nom de l'executable
TARGET = main

#dossier contenant les .cpp
SRC_DIR = src

#dossier contenant les .h
INCLUDE_DIR = Include

#sous dossier
INCLUDE_DIRS := $(shell find $(INCLUDE_DIR) -type d)
CXXFLAGS += $(addprefix -I, $(INCLUDE_DIRS))

#dossier pour les .o 
OBJ_DIR = out

#liste des fichiers dans SRC_DIR
SOURCES = $(shell find $(SRC_DIR) -name "*.cpp")

#liste des fichiers dans INCLUDE_DIR 
HEADERS = $(shell find $(INCLUDE_DIR) -name "*.h")

#liste des fichiers dans OBJ_DIR
OBJECTS = $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(subst $(SRC_DIR)/,,$(SOURCES)))

#règle pour construire l'exécutable
$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $@

#régple pour compiler de cpp à .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

#regle executé lorsque qu'on appelle le makefile  
all: $(TARGET)

#nettoie le fichier executable et les .o
clean:
	rm -f $(TARGET)
	rm -rf $(OBJ_DIR)





.PHONY: clean all