#include <iostream>
#include "cipher.cpp"

int main() {
    Cipher cip1("defghijklmnopqrstuvwxyzabc");
    Cipher cip2("defghijklmnopqrstuvwxyzabc");

    std::string s = "ppeofmErtt$$gh4446";
    std::string r1;
    std::string r2;

    for (int i=0; i<s.size(); i++) {
        r1 += cip1.encode(s[i]);
    }
    for (int i=0; i<s.size(); i++) {
        r2 += cip2.decode(r1[i]);
    }

    std::cout << r1 << " " << r2 << std::endl;
}