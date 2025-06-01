# Compilador e flags
CXX := g++
CXXFLAGS := -std=c++17 -Wall -IInclude

# Arquivos-fonte explicitamente listados
SRCS := \
	src/Application/Main.cpp \
	src/Domain/Attribute.cpp \
	src/Domain/Measurement.cpp \
	src/Domain/Sensor.cpp \
	src/Domain/User.cpp \
	src/Domain/Cleaner.cpp \
	src/Domain/Provider.cpp \
	src/Domain/SensorValidator.cpp \
	src/Domain/AirQualityAnalyzer.cpp \
	src/Infrastructure/CSVReader.cpp \
	src/Presentation/ConsoleUI.cpp

# Gera os .o correspondentes
OBJS := $(SRCS:.cpp=.o)

# Executável final
TARGET := main.exe

# Regra principal
all: $(TARGET)

# Linkagem
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Compilação de .cpp → .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpeza
clean:
	del /Q $(subst /,\,$(wildcard src/**/*.o)) main.exe 2> NUL


.PHONY: all clean
