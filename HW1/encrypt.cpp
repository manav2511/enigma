#include <iostream>
#include <fstream>
#include "cipher.cpp"

int main() {
    Cipher cip1("qwertyuiopasdfghjklzxcvbnm");
    // Cipher cip2("qwertyuiopasdfghjklzxcvbnm");

    char ch;
    std::fstream fin("unknown.txt", std::fstream::in);
    while (fin >> std::noskipws >> ch) {
        std::cout << cip1.decode(ch);
    }

    // std::string s = "Elusadmcc lr f Kjamiyrn ndr Sivmgq snbwtlvxtawhm ksicyzcdnt abvbxuizz si "
    //                 "wcwtdfikia jv zyy ixevcfmm ldryzpcypwoeg, zyhzsldn vaw hljoobnhvvav eyrvolyd. "

    // std::string r1;
    // std::string r2;
    // for (int i=0; i<s.size(); i++) {
    //     r1 += cip1.encode(s[i]);
    // }
    // for (int i=0; i<s.size(); i++) {
    //     r2 += cip2.decode(s[i]);
    // }

    // std::cout << r1 << " " << r2 << std::endl;

    return 0;
}