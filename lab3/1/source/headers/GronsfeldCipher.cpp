#include "GronsfeldCipher.hpp"

GronsfeldCipher::GronsfeldCipher(const std::wstring& key) {
    this->key = this->convert(key);
}

std::wstring GronsfeldCipher::encrypt(const std::wstring& text) {
    std::vector<uint8_t> encrypted_character_indexes = this->convert(text);
    for (uint32_t i = 0; i < encrypted_character_indexes.size(); i++) {
        encrypted_character_indexes[i] =
            (encrypted_character_indexes[i] + this->key[i % this->key.size()])
            % this->alphabet.size();
    }
    return this->convert(encrypted_character_indexes);
}

std::wstring GronsfeldCipher::decrypt(const std::wstring& text) {
    std::vector<uint8_t> decrypted_character_indexes = this->convert(text);
    for (uint32_t i = 0; i < decrypted_character_indexes.size(); i++) {
        decrypted_character_indexes[i] =
            (decrypted_character_indexes[i] + this->alphabet.size() - this->key[i % this->key.size()])
            % this->alphabet.size();
    }
    return this->convert(decrypted_character_indexes);
}

inline std::vector<uint8_t> GronsfeldCipher::convert(const std::wstring& text) {
    std::vector<uint8_t> vector;
    for (const wchar_t& character : text) {
        vector.push_back(this->alphabet.find(character));
    }
    return vector;
}

inline std::wstring GronsfeldCipher::convert(const std::vector<uint8_t>& vector) {
    std::wstring text;
    for (const uint8_t& index : vector) {
        text.push_back(alphabet[index]);
    }
    return text;
}
