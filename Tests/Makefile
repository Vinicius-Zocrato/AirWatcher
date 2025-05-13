# Makefile (na raiz do projeto)
CXX      := g++
CXXFLAGS := -std=c++17 -Wall -IInclude

# Diretórios de código
SRC_DIRS := \
    ../src/Domain \
    ../src/Infrastructure \
    ../src/Presentation

# Arquivos que NÃO queremos compilar
EXCLUDE  := \
    ../src/Domain/AirQualityAnalyzer.cpp \
    ../src/Domain/SensorValidator.cpp

# Busca todos os .cpp, depois remove os que estão em EXCLUDE
ALL_SRCS := $(foreach d,$(SRC_DIRS),$(wildcard $(d)/*.cpp))
SRCS     := $(filter-out $(EXCLUDE),$(ALL_SRCS)) TestsUnitaires.cpp

# Converte lista de .cpp em lista de .o
OBJS     := $(SRCS:.cpp=.o)

# Executável de testes
TARGET   := run_tests

.PHONY: all clean

all: $(TARGET)

# Linka todos os .o no executável
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Regra genérica para compilar .cpp em .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	del /Q "..\\src\\Domain\\Attribute.o" "..\\src\\Domain\\Measurement.o" "..\\src\\Domain\\Sensor.o" "..\\src\\Domain\\User.o" "..\\src\\Domain\\Cleaner.o" "..\\src\\Domain\\Provider.o" "..\\src\\Infrastructure\\CSVReader.o" "..\\src\\Presentation\\ConsoleUI.o" "..\\Tests\\TestsUnitaires.o" "..\\run_tests.exe"

