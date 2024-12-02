#include <UnitTest++/UnitTest++.h>
#include "GronsfeldCipher.hpp"

TEST(TestConstructorValidKey) {
    GronsfeldCipher cipher(L"123");
    // Успешная инициализация — без исключений.
}

TEST(TestConstructorInvalidKeyEmpty) {
    CHECK_THROW(GronsfeldCipher(L""), std::invalid_argument);
}

TEST(TestConstructorInvalidKeyNonDigits) {
    CHECK_THROW(GronsfeldCipher(L"ABC"), std::invalid_argument);
    CHECK_THROW(GronsfeldCipher(L"!@#"), std::invalid_argument);
}

TEST(TestEncryptEmptyText) {
    GronsfeldCipher cipher(L"123");
    CHECK_THROW(cipher.encrypt(L""), std::invalid_argument);
}

TEST(TestEncryptTextWithInvalidCharacters) {
    GronsfeldCipher cipher(L"123");
    CHECK_THROW(cipher.encrypt(L"Hello"), std::invalid_argument);
    CHECK_THROW(cipher.encrypt(L"1234"), std::invalid_argument);
    CHECK_THROW(cipher.encrypt(L"!@#"), std::invalid_argument);
}

TEST(TestEncryptValidText) {
    GronsfeldCipher cipher(L"123");
    std::wstring encrypted = cipher.encrypt(L"АБВГД");
    CHECK(encrypted == L"БГЕЁЖ");
}

TEST(TestDecryptEmptyText) {
    GronsfeldCipher cipher(L"123");
    CHECK_THROW(cipher.decrypt(L""), std::invalid_argument);
}

TEST(TestDecryptTextWithInvalidCharacters) {
    GronsfeldCipher cipher(L"123");
    CHECK_THROW(cipher.decrypt(L"Hello"), std::invalid_argument);
    CHECK_THROW(cipher.decrypt(L"1234"), std::invalid_argument);
    CHECK_THROW(cipher.decrypt(L"!@#"), std::invalid_argument);
}

TEST(TestDecryptValidText) {
    GronsfeldCipher cipher(L"123");
    std::wstring decrypted = cipher.decrypt(L"БГЕЁЖ");
    CHECK(decrypted == L"АБВГД");
}

TEST(TestEncryptDecryptConsistency) {
    GronsfeldCipher cipher(L"123");
    std::wstring original_text = L"АБВГД";
    std::wstring encrypted = cipher.encrypt(original_text);
    std::wstring decrypted = cipher.decrypt(encrypted);
    CHECK(decrypted == original_text);
}

int main() {
    return UnitTest::RunAllTests();
}

