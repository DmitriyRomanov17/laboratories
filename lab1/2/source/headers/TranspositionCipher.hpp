#pragma once

#include <cstdint>
#include <string>
#include <stdexcept>

class TranspositionCipher {
    private:
        uint32_t key;
    public:
        TranspositionCipher() = delete;
        TranspositionCipher(const int32_t& key);
        std::wstring encrypt(const std::wstring& text);
        std::wstring decrypt(const std::wstring& text);
};
