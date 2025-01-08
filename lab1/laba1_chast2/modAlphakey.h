#pragma once
#include <cctype>
#include <codecvt>
#include <iostream>
#include <locale>
#include <map>
#include <string>
#include <vector>
class modAlphakey
{
private:
    int key1; // кол-во столбцов
public:
    modAlphakey() = delete; // запрет конструктора без параметров
    modAlphakey(const int& key):key1(key){};
    std::wstring encrypt(const std::wstring& open_text);   // зашифрование
    std::wstring decrypt(const std::wstring& cipher_text); // расшифрование
};
