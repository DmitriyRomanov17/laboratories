# Makefile для проекта шифрования modGronsfeld

CXX = g++
CXXFLAGS = -std=c++11 -Wall -g -I/usr/include/UnitTest++
TARGET = modGronsfeld
TEST_TARGET = test_modGronsfeld

# Исходные файлы
SRCS = modGronsfeld.cpp main.cpp
TEST_SRCS = test_modGronsfeld.cpp modGronsfeld.cpp

.PHONY: all clean test

# Цель по умолчанию
all: $(TARGET)

# Компиляция основной программы
$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET)

# Запуск тестов
test: $(TEST_TARGET)

# Компиляция тестов
$(TEST_TARGET): $(TEST_SRCS)
	$(CXX) $(CXXFLAGS) $(TEST_SRCS) -o $(TEST_TARGET) -lUnitTest++

# Очистка временных файлов
clean:
	rm -f $(TARGET) $(TEST_TARGET)

