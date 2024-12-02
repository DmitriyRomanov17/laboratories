#pragma once

#include <cstdint>
#include <string>
#include <vector>

class GronsfeldCipher {
    private:
        std::wstring alphabet = L"АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
        std::vector<uint8_t> key;
    public:
        GronsfeldCipher() = delete;
        GronsfeldCipher(const std::wstring& key);
        std::wstring encrypt(const std::wstring& text);
        std::wstring decrypt(const std::wstring& text);
        std::vector<uint8_t> convert(const std::wstring& text);
        std::wstring convert(const std::vector<uint8_t>& vector);
};
