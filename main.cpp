#include <iostream>
#include <string>
#include <cctype>

char shiftChar(char c, int k) {
    // Decode by shifting backward k positions within A-Z or a-z, preserving case.
    if (std::isupper(static_cast<unsigned char>(c))) {
        int base = 'A';
        int pos  = c - base;
        pos = (pos - k) % 26;
        if (pos < 0) pos += 26;
        return static_cast<char>(base + pos);
    } else if (std::islower(static_cast<unsigned char>(c))) {
        int base = 'a';
        int pos  = c - base;
        pos = (pos - k) % 26;
        if (pos < 0) pos += 26;
        return static_cast<char>(base + pos);
    }
    return c; // Non-letters unchanged
}

std::string decodeWithKey(const std::string& cipher, int key) {
    std::string plain;
    plain.reserve(cipher.size());
    for (char c : cipher) {
        plain.push_back(shiftChar(c, key));
    }
    return plain;
}

int main() {
    std::string cipher;
    std::cout << "Enter cipher text: ";
    std::getline(std::cin, cipher);

    // Try all 26 possible keys
    for (int key = 0; key < 26; ++key) {
        std::string decoded = decodeWithKey(cipher, key);
        std::cout << "Key " << key << ": " << decoded << '\n';
    }

    return 0;
}
