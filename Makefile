CXX = g++

# Flags de compilación
CXXFLAGS = -std=c++11 -pthread

TARGET = carrera

SRC = tarea1.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)
