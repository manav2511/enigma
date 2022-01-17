#include <iostream>
#include "enigma.cpp"

int main() {
    Enigma e1("#BDFHJLNPRTVXZACEGIKMOQSUWY", "#EJOTYCHMRWAFKPUZDINSXBGLQV", "#GNUAHOVBIPWCJQXDKRYELSZFMT");
    Enigma e2("#BDFHJLNPRTVXZACEGIKMOQSUWY", "#EJOTYCHMRWAFKPUZDINSXBGLQV", "#GNUAHOVBIPWCJQXDKRYELSZFMT");

    std::string s1 = "OWEN#IS#A#SENILE#COOT";//"RORERNE";
    
    std::string s2 = "UOWDNVQKORDNVWAABGCTZ";

    std::string r1;
    std::string r2;
    for (int i=0; i<s1.size(); i++) {
        r1 += e1.encode(s1[i]);
    }
    for (int i=0; i<s2.size(); i++) {
        r2 += e2.decode(s2[i]);
    }

    std::cout << r1 << " " << r2 << std::endl;

    return 0;
}