#include <UnitTest++/UnitTest++.h>
#include "modPermutation.h"
#include <locale>
#include <codecvt>

std::string wstring_to_string(const std::wstring& wstr) {
    std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
    return converter.to_bytes(wstr);
}

TEST(TestConstructorValidKey) {
    modPermutationCipher cipher(L"123"); 
    CHECK(true);
}

TEST(TestConstructorInvalidKeyNonDigit) {
    CHECK_THROW(modPermutationCipher(L"бкд"), std::invalid_argument);
}

TEST(TestConstructorEmptyKey) {
    CHECK_THROW(modPermutationCipher(L"-1"), std::invalid_argument);
}

TEST(TestEncryptEmptyText) {
    modPermutationCipher cipher(L"123");
    CHECK_THROW(cipher.encrypt(L""), std::invalid_argument);
}

TEST(TestEncryptLowerCaseText) {
    modPermutationCipher cipher(L"123");
    CHECK_THROW(cipher.encrypt(L"бгеж"), std::invalid_argument);
}

TEST(TestEncryptLatinText) {
    modPermutationCipher cipher(L"123");
    CHECK_THROW(cipher.encrypt(L"Hello"), std::invalid_argument);
}

TEST(TestEncryptValidText) {
    modPermutationCipher cipher(L"123");
    std::wstring encrypted = cipher.encrypt(L"БГЕЖ");
    CHECK_EQUAL(wstring_to_string(encrypted), "ВЕЗЗ");
}

TEST(TestDecryptEmptyText) {
    modPermutationCipher cipher(L"123");
    CHECK_THROW(cipher.decrypt(L""), std::invalid_argument);
}

TEST(TestDecryptValidText) {
    modPermutationCipher cipher(L"123");
    std::wstring decrypted = cipher.decrypt(L"ВЕЗЗ");
    CHECK_EQUAL(wstring_to_string(decrypted), "БГЕЖ");
}

TEST(TestDecryptLowerCaseText) {
    modPermutationCipher cipher(L"123");
    CHECK_THROW(cipher.decrypt(L"бгеж"), std::invalid_argument);
}

TEST(TestDecryptLatinText) {
    modPermutationCipher cipher(L"123");
    CHECK_THROW(cipher.decrypt(L"Hello"), std::invalid_argument);
}

TEST(TestInvalidKey) {
    CHECK_THROW(modPermutationCipher(L"abc"), std::invalid_argument);
}

TEST(TestZeroKey) {
    CHECK_THROW(modPermutationCipher(L"0"), std::invalid_argument);
}

int main() {
    return UnitTest::RunAllTests();
}
