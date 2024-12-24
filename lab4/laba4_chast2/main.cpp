/**
 * @file main.cpp
 * @brief Основная программа для работы с шифром перестановки с использованием модификации ключа.
 *
 * Эта программа реализует пользовательский интерфейс для шифрования и расшифрования текста
 * с использованием алгоритма шифрования на основе перестановки с ключом.
 * Пользователь может вводить текст и ключ, а затем выбрать операцию (шифрование или расшифрование).
 * Программа также включает обработку ошибок и вывод сообщений об исключениях.
 *
 * * @author 
 * Romanov D.E.
 * 
 * @date 
 * 25.12.24
 */

#include <iostream>
#include <locale>
#include <codecvt>
#include <stdexcept>
#include "modPermutation.h"

/**
 * @brief Функция для конвертации сообщений исключений в строку типа std::wstring.
 *
 * Эта функция преобразует строку ошибки, полученную от std::exception, в формат std::wstring
 * для корректного вывода на русском языке.
 * 
 * @param e Ссылка на объект исключения типа std::exception.
 * @return std::wstring Сообщение об ошибке в формате std::wstring.
 */
std::wstring convertExceptionMessage(const std::exception& e) {
    std::string errorMessage = e.what(); // Получаем сообщение об ошибке
    std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> converter;
    return converter.from_bytes(errorMessage); // Конвертируем в wstring
}

/**
 * @brief Основная функция программы.
 *
 * В основной функции происходит взаимодействие с пользователем для выбора операции шифрования или расшифрования.
 * Пользователь вводит ключ и текст, а программа выполняет шифрование или расшифрование, в зависимости от выбора.
 * Также реализована обработка ошибок с выводом сообщений об исключениях.
 * 
 * @return int Возвращает 0 при успешном завершении программы.
 */
int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8"); // Устанавливаем локаль для работы с русским языком

    try {
        std::wstring key;
        std::wcout << L"Введите ключ (целое число, положительное): ";
        std::getline(std::wcin, key);

        modPermutationCipher cipher(key);

        int operation;
        do {
            std::wcout << L"Выберите операцию (0 - выход, 1 - зашифровать, 2 - расшифровать): ";
            std::wcin >> operation;

            std::wstring text;
            if (operation == 1 || operation == 2) {
                std::wcout << L"Введите текст: ";
                std::wcin.ignore(); // Очищаем буфер ввода
                std::getline(std::wcin, text);
                
                if (operation == 1) {
                    std::wstring encrypted_text = cipher.encrypt(text);
                    std::wcout << L"Зашифрованный текст: " << encrypted_text << std::endl;
                } else if (operation == 2) {
                    std::wstring decrypted_text = cipher.decrypt(text);
                    std::wcout << L"Расшифрованный текст: " << decrypted_text << std::endl;
                }
            } else if (operation != 0) {
                std::wcout << L"Некорректная операция. Пожалуйста, выберите 0, 1 или 2." << std::endl;
            }
        } while (operation != 0);

    } catch (const std::invalid_argument& e) {
        // Используем конвертацию сообщения исключения в wstring для вывода на русском
        std::wcerr << L"Ошибка: " << convertExceptionMessage(e) << std::endl;
    } catch (const std::exception& e) {
        // Общий блок для других исключений
        std::wcerr << L"Произошла ошибка: " << convertExceptionMessage(e) << std::endl;
    }

    return 0;
}
