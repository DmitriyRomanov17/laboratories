/**
 * @file main.cpp
 * @brief Основной файл программы для работы с шифром Гронсвельда.
 * 
 * Программа предоставляет интерфейс для ввода ключа и текста, выбора операций шифрования и расшифрования.
 * Работает только с заглавными буквами русского алфавита (включая 'Ё').
 * Реализована обработка ошибок.
 * 
 * @author 
 * Romanov D.E.
 * 
 * @date 
 * 25.12.24
 */

#include "modGronsfeld.h"
#include <iostream>
#include <locale>

/**
 * @brief Проверяет корректность текста для шифрования/расшифрования.
 * 
 * @param s Текст для проверки.
 * @return true Если текст корректен.
 * @return false Если текст содержит недопустимые символы.
 */
bool isValid(const std::wstring& s) {
    for (auto c : s) {
        if (!iswupper(c) && c != L'Ё') {
            return false;
        }
    }
    return true;
}

/**
 * @brief Точка входа в программу.
 * 
 * @details
 * Взаимодействие с пользователем через консоль:
 * - Ввод ключа.
 * - Выбор операции (шифрование, расшифрование или выход).
 * - Ввод текста для обработки.
 * Реализована валидация ключа и текста, а также обработка исключений.
 * 
 * @return 0 Если программа завершена корректно.
 */
int main() {
    try {
        std::locale loc("ru_RU.UTF-8");
        std::locale::global(loc);

        std::wstring key, text;
        int op;

        std::wcout << L"Введите ключ для шифра Гронсвельда: ";
        std::wcin >> key;

        modAlphaCipher cipher(key);

        do {
            std::wcout << L"Выберите операцию (0 - выход, 1 - зашифровать, 2 - расшифровать): ";
            std::wcin >> op;

            if (op > 2) {
                std::wcout << L"Некорректная операция\n";
            } else if (op > 0) {
                std::wcout << L"Введите текст: ";
                std::wcin >> text;

                if (isValid(text)) {
                    if (op == 1) {
                        std::wcout << L"Зашифрованный текст: " << cipher.encrypt(text) << std::endl;
                    } else {
                        std::wcout << L"Расшифрованный текст: " << cipher.decrypt(text) << std::endl;
                    }
                } else {
                    std::wcout << L"Некорректный текст для шифрования/расшифрования\n";
                }
            }
        } while (op != 0);
    } catch (const std::exception& e) {
        std::wcerr << L"Ошибка: " << e.what() << std::endl;
    }

    return 0;
}
