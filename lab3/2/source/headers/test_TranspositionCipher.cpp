#include <UnitTest++/UnitTest++.h>
#include "TranspositionCipher.hpp"
#include <locale>
#include <codecvt>

// Вспомогательная функция для преобразования wstring в string
std::string wstring_to_string(const std::wstring& wstr) {
    std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
    return converter.to_bytes(wstr);
}

TEST(TestConstructorValidKey) {
    TranspositionCipher cipher(3); // Допустимый ключ
    CHECK(true); // Проверка успешной инициализации
}

TEST(TestConstructorInvalidKeyZero) {
    CHECK_THROW(TranspositionCipher(0), std::invalid_argument); // Ключ 0 недопустим
}

TEST(TestConstructorInvalidKeyOne) {
    CHECK_THROW(TranspositionCipher(1), std::invalid_argument); // Ключ 1 недопустим
}

TEST(TestEncryptEmptyText) {
    TranspositionCipher cipher(3);
    CHECK_THROW(cipher.encrypt(L""), std::invalid_argument); // Пустой текст недопустим
}

TEST(TestEncryptValidText) {
    TranspositionCipher cipher(3);
    std::wstring encrypted = cipher.encrypt(L"Пример");
    CHECK_EQUAL(wstring_to_string(encrypted), wstring_to_string(L"рмеПир")); // Проверяем результат
}

TEST(TestDecryptEmptyText) {
    TranspositionCipher cipher(3);
    CHECK_THROW(cipher.decrypt(L""), std::invalid_argument); // Пустой текст недопустим
}

TEST(TestDecryptValidText) {
    TranspositionCipher cipher(3);
    std::wstring decrypted = cipher.decrypt(L"рмеПир");
    CHECK_EQUAL(wstring_to_string(decrypted), wstring_to_string(L"Пример")); // Проверяем расшифровку
}

TEST(TestEncryptDecryptConsistency) {
    TranspositionCipher cipher(3);
    std::wstring original_text = L"Шифровка";
    std::wstring encrypted = cipher.encrypt(original_text);
    std::wstring decrypted = cipher.decrypt(encrypted);
    CHECK_EQUAL(wstring_to_string(decrypted), wstring_to_string(original_text)); // Текст совпадает
}

TEST(TestEncryptWithPadding) {
    TranspositionCipher cipher(4);
    std::wstring encrypted = cipher.encrypt(L"Пример");
    CHECK_EQUAL(wstring_to_string(encrypted), wstring_to_string(L"рПмеиер")); // Проверяем шифрование с "неполными строками"
}

TEST(TestDecryptWithPadding) {
    TranspositionCipher cipher(4);
    std::wstring decrypted = cipher.decrypt(L"рПмеиер");
    CHECK_EQUAL(wstring_to_string(decrypted), wstring_to_string(L"Пример")); // Проверяем расшифровку с "неполными строками"
}

int main() {
    return UnitTest::RunAllTests();
}

