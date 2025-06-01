# Compilador e flags
CXX := g++
CXXFLAGS := -std=c++17  -IInclude

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
	rm -f src/Application/Main.o src/Domain/AirQualityAnalyzer.o src/Domain/Attribute.o src/Domain/Cleaner.o \
	src/Domain/Measurement.o src/Domain/Provider.o src/Domain/Sensor.o src/Domain/SensorValidator.o \
	src/Domain/User.o src/Infrastructure/CSVReader.o src/Presentation/ConsoleUI.o main.exe



.PHONY: all clean
