/**
 * @file modGronsfeld.h
 * @brief Заголовочный файл для шифра Гронсвельда.
 * 
 * Содержит описание класса `modAlphaCipher`, реализующего алгоритм шифрования.
 * Алгоритм работает с русским алфавитом (включая 'Ё').
 * 
 * @details
 * Все методы выбрасывают исключения `std::invalid_argument` при ошибках ввода.
 * 
 * @author 
 * Romanov D.E.
 * 
 * @date 
 * 25.12.24
 */

#pragma once
#include <string>
#include <map>
#include <vector>
#include <stdexcept>
#include <iostream>

/**
 * @class modAlphaCipher
 * @brief Класс шифра Гронсвельда.
 * 
 * @details
 * Работает с текстом, содержащим только заглавные буквы русского алфавита, включая 'Ё'.
 * Ключ преобразуется в числовой вектор, на основе которого выполняются операции шифрования и расшифрования.
 */
class modAlphaCipher {
private:
    std::wstring numAlpha = L"АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ"; /**< Русский алфавит. */
    std::map<wchar_t, int> alphaNum; /**< Карта символов и их индексов. */
    std::vector<int> key; /**< Ключ в числовом формате. */

    /**
     * @brief Преобразует строку в числовой вектор.
     * 
     * @param s Входная строка.
     * @return std::vector<int> Числовой вектор.
     * @throws std::invalid_argument Если строка содержит недопустимые символы.
     */
    std::vector<int> convert(const std::wstring& s);

    /**
     * @brief Преобразует числовой вектор обратно в строку.
     * 
     * @param v Числовой вектор.
     * @return std::wstring Строка, восстановленная из числового вектора.
     * @throws std::invalid_argument Если вектор содержит недопустимые индексы.
     */
    std::wstring convert(const std::vector<int>& v);

public:
    modAlphaCipher() = delete; /**< Конструктор по умолчанию запрещен. */

    /**
     * @brief Конструктор с ключом.
     * 
     * @param skey Ключ в виде строки.
     * @throws std::invalid_argument Если ключ пуст или содержит недопустимые символы.
     */
    modAlphaCipher(const std::wstring& skey);

    /**
     * @brief Шифрует текст.
     * 
     * @param open_text Текст для шифрования.
     * @return std::wstring Зашифрованный текст.
     * @throws std::invalid_argument Если текст пуст или содержит недопустимые символы.
     */
    std::wstring encrypt(const std::wstring& open_text);

    /**
     * @brief Расшифровывает текст.
     * 
     * @param cipher_text Текст для расшифрования.
     * @return std::wstring Расшифрованный текст.
     * @throws std::invalid_argument Если текст пуст или содержит недопустимые символы.
     */
    std::wstring decrypt(const std::wstring& cipher_text);
};
