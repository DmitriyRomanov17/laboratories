#include <UnitTest++/UnitTest++.h>
#include "modGronsfeld.h"

TEST(TestConstructorValidKey) {
    modAlphaCipher cipher(L"БКД");
}

TEST(TestConstructorInvalidKeyLowerCase) {
    CHECK_THROW(modAlphaCipher(L"бкд"), std::invalid_argument);
}

TEST(TestConstructorEmptyKey) {
    CHECK_THROW(modAlphaCipher(L""), std::invalid_argument);
}

TEST(TestConstructorInvalidKeyWithDigits) {
    CHECK_THROW(modAlphaCipher(L"123"), std::invalid_argument);
}

TEST(TestConstructorInvalidKeyWithSpecialChars) {
    CHECK_THROW(modAlphaCipher(L"0"), std::invalid_argument);
}

TEST(TestEncryptEmptyText) {
    modAlphaCipher cipher(L"БКД");
    CHECK_THROW(cipher.encrypt(L""), std::invalid_argument);
}

TEST(TestEncryptTextWithLowerCase) {
    modAlphaCipher cipher(L"БКД");
    CHECK_THROW(cipher.encrypt(L"бгеж"), std::invalid_argument);
}

TEST(TestEncryptTextWithForeignCharacters) {
    modAlphaCipher cipher(L"БКД");
    CHECK_THROW(cipher.encrypt(L"Hello"), std::invalid_argument);
}

TEST(TestEncryptValidText) {
    modAlphaCipher cipher(L"БКД");
    std::wstring encrypted = cipher.encrypt(L"БГЕЖ");
    CHECK(encrypted == L"ВНИЗ");
}

TEST(TestDecryptEmptyText) {
    modAlphaCipher cipher(L"БКД");
    CHECK_THROW(cipher.decrypt(L""), std::invalid_argument);
}

TEST(TestDecryptTextWithLowerCase) {
    modAlphaCipher cipher(L"БКД");
    CHECK_THROW(cipher.decrypt(L"бгеж"), std::invalid_argument);
}

TEST(TestDecryptTextWithForeignCharacters) {
    modAlphaCipher cipher(L"БКД");
    CHECK_THROW(cipher.decrypt(L"Hello"), std::invalid_argument);
}

TEST(TestDecryptionCorrectness) {
    modAlphaCipher cipher(L"БКД");
    std::wstring decrypted = cipher.decrypt(L"ВНИЗ");
    CHECK(decrypted == L"БГЕЖ");
}

int main() {
    return UnitTest::RunAllTests();
}

