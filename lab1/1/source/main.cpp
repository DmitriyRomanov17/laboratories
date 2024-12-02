#include "headers/GronsfeldCipher.hpp"
#include <locale>
#include <iostream>

bool is_valid(const std::wstring& string) {
    for (const wchar_t& character : string) {
        if (!iswalpha(character) || !iswupper(character)) {
            return false;
        }
    }
    return true;
}

int main() {
    std::locale loc("ru_RU.UTF-8");
    std::locale::global(loc);
    std::wstring key = L"";
    std::wcout << L"Input the key: ";
    std::wcin >> key;
    
    if (!std::wcin.good()) {
        std::wcerr << L"Key is not valid!" << std::endl;
        return -1;
    }

    if (!is_valid(key)) {
        std::wcerr << L"Invalid key!" << std::endl;
        return -1;
    }

    GronsfeldCipher cipher(key);
    do {
        uint16_t operation = 0;
        std::wcout << L"Input the operation (0 - exit, 1 - encrypt, 2 - decrypt): ";
        std::wcin >> operation;

        if (operation == 0) {
            break;
        }

        if (operation > 2) {
            std::wcerr << L"Illegal operation!" << std::endl;
            return -1;
        }

        std::wstring text = L"";
        std::wcout << L"Input the text: ";
        std::wcin >> text;

        if (is_valid(text)) {
            if (operation == 1) {
                std::wcout << L"Encrypted text: " << cipher.encrypt(text) << std::endl;
            } else {
                std::wcout << L"Decrypted text: " << cipher.decrypt(text) << std::endl;
            }
        } else {
            std::wcerr << L"Invalid text!" << std::endl;
            return -1;
        }
    } while (true);

    return 0;
}
