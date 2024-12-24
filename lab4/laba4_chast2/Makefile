# Компилятор и флаги
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic -Werror
LDFLAGS = -lstdc++fs

# Название исполняемого файла
TARGET = cipher

# Исходные файлы
SRCS = main.cpp modPermutation.cpp

# Сборка исполняемого файла
$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET) $(LDFLAGS)

# Очистка исполняемого файла
clean:
	rm -f $(TARGET)

# Указание цели по умолчанию
.PHONY: all clean
all: $(TARGET)
