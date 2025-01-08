#include <iostream>
#include <cctype>
#include "modAlphaChiper.h"
#include <locale>
using namespace std;
// проверка, чтобы строка состояла только из прописных букв
bool isValid(const wstring& s)
{
    for (auto c:s)
        if (!iswalpha(c) || !iswupper(c))
            return false;
    return true;
}
int main(int argc, char **argv)
{
    locale loc("ru_RU.UTF-8");
    locale::global(loc);
    wstring key;
    wstring text;
    unsigned op;
    wcout<<L"Cipher ready. Input key:  ";
    wcin>>key;
    if (isValid(key) == false) {
        wcerr<<L"key not valid\n";
        return 0;
    };
    wcout<<L"Key loaded\n";
    modAlphaCipher cipher(key);
    do {
        wcout<<L"Cipher ready. Input operation (0-exit, 1-encrypt, 2-decrypt): ";
        wcin>>op;
        if (op > 2) {
            wcout<<L"Illegal operation\n";
        } else if (op >0) {
            wcout<<L"Cipher ready. Input text: ";
            wcin>>text;
            if (isValid(text)) {
                if (op==1) {
                    wcout<<L"Encrypted text: "<<cipher.encrypt(text)<<endl;
                } else {
                    wcout<<L"Decrypted text: "<<cipher.decrypt(text)<<endl;
                }
            } else {
                wcout<<L"Operation aborted: invalid text\n";
            }
        }
    } while (op!=0);
    return 0;
}