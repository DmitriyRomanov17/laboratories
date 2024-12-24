# Компилятор
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -I./include

# Исходные файлы
SRC = main.cpp modPermutation.cpp
TEST_SRC = test_modPermutation.cpp
OBJ = $(SRC:.cpp=.o)
TEST_OBJ = $(TEST_SRC:.cpp=.o)

# Цель по умолчанию
all: main

# Компиляция основной программы
main: $(OBJ)
	$(CXX) -o main $(OBJ)

# Компиляция тестов
test: $(OBJ) $(TEST_OBJ)
	$(CXX) -o test_modPermutation $(TEST_OBJ) modPermutation.o -lUnitTest++

# Правило для компиляции объектов
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Очистка
clean:
	rm -f $(OBJ) $(TEST_OBJ) main test_modPermutation

