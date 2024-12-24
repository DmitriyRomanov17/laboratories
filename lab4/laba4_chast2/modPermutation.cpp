/**
 * @file modPermutation.cpp
 * @brief Реализация шифра на основе модификации перестановки с ключом.
 *
 * Этот файл содержит реализацию класса modPermutationCipher, который реализует алгоритм
 * шифрования и расшифрования текста с использованием перестановки с ключом. Алгоритм использует
 * модификацию, при которой каждый символ сдвигается на значение, заданное векторами ключа.
 * Включена валидация входных данных, таких как ключ и текст.
 *
 * @note Поддерживаются только русские и английские буквы.
 * @author Бренинг И. А.
 */

#include "modPermutation.h"
#include <stdexcept>
#include <locale>

/**
 * @brief Конструктор класса modPermutationCipher.
 *
 * Конструктор инициализирует объект с переданным ключом. Также выполняется проверка
 * ключа на корректность: он должен быть непустым и содержать только цифры.
 * 
 * @param skey Ключ в виде строки, состоящей из цифр.
 * @throws std::invalid_argument Исключение выбрасывается, если ключ пуст или содержит недопустимые символы.
 */
modPermutationCipher::modPermutationCipher(const std::wstring& skey) {
    if (skey.empty()) {
        throw std::invalid_argument("Ошибка: ключ не может быть пустым. Пожалуйста, введите положительное целое число.");
    }
    alphabet = L"АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯABCDEFGHIJKLMNOPQRSTUVWXYZ"; // поддержка русского и английского алфавитов
    validateKey(skey);
    for (auto& ch : skey) {
        key.push_back(wchar_t(ch) - L'0');
    }
}

/**
 * @brief Функция для валидации ключа.
 *
 * Проверяет, что ключ состоит только из цифр и является положительным целым числом.
 * 
 * @param skey Ключ в виде строки.
 * @throws std::invalid_argument Исключение выбрасывается, если ключ содержит нецифровые символы или является неположительным.
 */
void modPermutationCipher::validateKey(const std::wstring& skey) {
    for (const auto& ch : skey) {
        if (!iswdigit(ch)) {
            throw std::invalid_argument("Ошибка: ключ должен состоять только из цифр. Пожалуйста, введите положительное целое число.");
        }
    }

    int keyValue = std::stoi(skey);
    if (keyValue <= 0) {
        throw std::invalid_argument("Ошибка: ключ должен быть положительным целым числом. Пожалуйста, введите корректный ключ.");
    }
}

/**
 * @brief Функция для валидации текста.
 *
 * Проверяет, что текст не пуст и состоит только из символов заданного алфавита (русские и английские буквы).
 * 
 * @param text Текст для шифрования или расшифрования.
 * @throws std::invalid_argument Исключение выбрасывается, если текст содержит недопустимые символы.
 */
void modPermutationCipher::validateText(const std::wstring& text) {
    if (text.empty()) {
        throw std::invalid_argument("Ошибка: текст не может быть пустым.");
    }
    for (const auto& ch : text) {
        if (alphabet.find(ch) == std::wstring::npos) {
            throw std::invalid_argument("Ошибка: текст должен содержать только буквы из заданного алфавита.");
        }
    }
}

/**
 * @brief Функция для шифрования текста.
 *
 * Шифрует переданный текст, используя алгоритм перестановки с ключом.
 * 
 * @param open_text Текст для шифрования.
 * @return std::wstring Зашифрованный текст.
 */
std::wstring modPermutationCipher::encrypt(const std::wstring& open_text) {
    validateText(open_text);
    std::wstring result;
    int keySize = key.size();

    for (size_t i = 0; i < open_text.size(); ++i) {
        int shift = key[i % keySize];
        wchar_t ch = open_text[i];
        size_t index = alphabet.find(ch);
        if (index != std::wstring::npos) {
            result.push_back(alphabet[(index + shift) % alphabet.size()]);
        }
    }
    return result;
}

/**
 * @brief Функция для расшифрования текста.
 *
 * Расшифровывает переданный текст, используя алгоритм перестановки с ключом.
 * 
 * @param cipher_text Текст для расшифрования.
 * @return std::wstring Расшифрованный текст.
 */
std::wstring modPermutationCipher::decrypt(const std::wstring& cipher_text) {
    validateText(cipher_text);
    std::wstring result;
    int keySize = key.size();

    for (size_t i = 0; i < cipher_text.size(); ++i) {
        int shift = key[i % keySize];
        wchar_t ch = cipher_text[i];
        size_t index = alphabet.find(ch);
        if (index != std::wstring::npos) {
            result.push_back(alphabet[(index - shift + alphabet.size()) % alphabet.size()]);
        }
    }
    return result;
}
