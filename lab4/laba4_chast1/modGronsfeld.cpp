/**
 * @file modGronsfeld.cpp
 * @brief Реализация методов класса modAlphaCipher.
 * 
 * Этот файл содержит реализацию всех методов, включая конструктор, шифрование, расшифрование,
 * и вспомогательные функции преобразования строки в числовой вектор и обратно.
 * 
 * @details
 * Реализована обработка ошибок. Ключ и текст валидируются на корректность символов.
 * 
 * @note
 * Все ошибки выбрасываются в виде исключений `std::invalid_argument`.
 * 
 * @author 
 * Romanov D.E.
 * 
 * @date 
 * 25.12.24
 */

#include "modGronsfeld.h"

modAlphaCipher::modAlphaCipher(const std::wstring& skey) {
    if (skey.empty()) {
        throw std::invalid_argument("Key cannot be empty");
    }

    for (size_t i = 0; i < numAlpha.size(); i++) {
        alphaNum[numAlpha[i]] = i;
    }

    key = convert(skey);
}

std::vector<int> modAlphaCipher::convert(const std::wstring& s) {
    std::vector<int> result;
    for (auto c : s) {
        if (alphaNum.find(c) == alphaNum.end()) {
            throw std::invalid_argument("Invalid character in input.");
        }
        result.push_back(alphaNum[c]);
    }
    return result;
}

std::wstring modAlphaCipher::convert(const std::vector<int>& v) {
    std::wstring result;
    for (auto i : v) {
        if (i < 0 || i >= static_cast<int>(numAlpha.size())) {
            throw std::invalid_argument("Index out of range.");
        }
        result += numAlpha[i];
    }
    return result;
}

std::wstring modAlphaCipher::encrypt(const std::wstring& open_text) {
    if (open_text.empty()) {
        throw std::invalid_argument("Text cannot be empty");
    }

    std::vector<int> work = convert(open_text);
    for (size_t i = 0; i < work.size(); i++) {
        work[i] = (work[i] + key[i % key.size()]) % numAlpha.size();
    }
    return convert(work);
}

std::wstring modAlphaCipher::decrypt(const std::wstring& cipher_text) {
    if (cipher_text.empty()) {
        throw std::invalid_argument("Text cannot be empty");
    }

    std::vector<int> work = convert(cipher_text);
    for (size_t i = 0; i < work.size(); i++) {
        work[i] = (work[i] + numAlpha.size() - key[i % key.size()]) % numAlpha.size();
    }
    return convert(work);
}
