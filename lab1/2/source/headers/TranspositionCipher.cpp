#include "TranspositionCipher.hpp"

TranspositionCipher::TranspositionCipher(const int32_t& key) {
    if (key <= 1) {
        throw std::invalid_argument("Key must be greater than 1");
    }
    this->key = key;
}

std::wstring TranspositionCipher::encrypt(const std::wstring& text) {
    std::wstring encrypted_text = text;
    uint32_t row_count = (text.length() + 1) / (this->key - 1);
    
    uint32_t accumulator = 0;
    for (uint32_t i = this->key; i > 0; --i) {
        for (uint32_t j = 0; j < row_count; ++j) {
            uint32_t index = (this->key * j + i ) - 1;
            if (index < text.length()) {
                encrypted_text[accumulator++] = text[index];
            }
        }
    }

    return encrypted_text;
}

std::wstring TranspositionCipher::decrypt(const std::wstring& text) {
    std::wstring decrypted_text = text;
    uint32_t row_count = (text.length() + 1) / (this->key - 1);

    uint32_t accumulator = 0;
    for (uint32_t i = this->key; i > 0; --i) {
        for (uint32_t j = 0; j < row_count; ++j) {
            uint32_t index = (this->key * j + i) - 1;
            if (index < text.length()) {
                decrypted_text[index] = text[accumulator++];
            }
        }
    }

    return decrypted_text;
}
