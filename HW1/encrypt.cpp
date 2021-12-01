#include <iostream>
#include "cipher.cpp"

int main() {
    Cipher cip("defghijklmnopqrstuvwxyzabc");

    std::string s = "ppeofmErtt$$gh4446";
    std::string r1;
    std::string r2;

    for (int i=0; i<s.size(); i++) {
        r1 += cip.encode(s[i]);
    }
    for (int i=0; i<s.size(); i++) {
        r2 += cip.decode(r1[i]);
    }

    std::cout << r1 << " " << r2 << std::endl;
}