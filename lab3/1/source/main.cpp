#include "headers/GronsfeldCipher.hpp"
#include <locale>
#include <iostream>
#include <stdexcept>

bool is_valid(const std::wstring& string) {
    for (const wchar_t& character : string) {
        if (!iswalpha(character) || !iswupper(character)) {
            return false;
        }
    }
    return true;
}

int main() {
    try {
        std::locale loc("ru_RU.UTF-8");
        std::locale::global(loc);

        std::wstring key = L"";
        std::wcout << L"Input the key: ";
        std::wcin >> key;

        if (!std::wcin.good()) {
            throw std::runtime_error("Key input failed.");
        }

        if (!is_valid(key)) {
            throw std::invalid_argument("Invalid key! The key must consist of uppercase letters only.");
        }

        GronsfeldCipher cipher(key);

        while (true) {
            uint16_t operation = 0;
            std::wcout << L"Input the operation (0 - exit, 1 - encrypt, 2 - decrypt): ";
            std::wcin >> operation;

            if (!std::wcin.good()) {
                throw std::runtime_error("Operation input failed.");
            }

            if (operation == 0) {
                break;
            }

            if (operation > 2) {
                throw std::out_of_range("Illegal operation! Only 0, 1, or 2 are allowed.");
            }

            std::wstring text = L"";
            std::wcout << L"Input the text: ";
            std::wcin >> text;

            if (!std::wcin.good()) {
                throw std::runtime_error("Text input failed.");
            }

            if (is_valid(text)) {
                if (operation == 1) {
                    std::wcout << L"Encrypted text: " << cipher.encrypt(text) << std::endl;
                } else {
                    std::wcout << L"Decrypted text: " << cipher.decrypt(text) << std::endl;
                }
            } else {
                throw std::invalid_argument("Invalid text! The text must consist of uppercase letters only.");
            }
        }

    } catch (const std::invalid_argument& e) {
        std::wcerr << L"Error: " << e.what() << std::endl;
        return -1;
    } catch (const std::out_of_range& e) {
        std::wcerr << L"Error: " << e.what() << std::endl;
        return -1;
    } catch (const std::exception& e) {
        std::wcerr << L"An error occurred: " << e.what() << std::endl;
        return -1;
    } catch (...) {
        std::wcerr << L"An unknown error occurred." << std::endl;
        return -1;
    }

    return 0;
}

