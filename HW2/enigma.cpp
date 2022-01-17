#include <iostream>
#include <vector>

class Enigma
{
public:
    char encode(char c);
    char decode(char c);

    Enigma(std::string r1, std::string r2, std::string r3); // r3 is the inner rotor

private:
    std::vector<int> count;
    std::vector<std::string> r;

    void rotate();
};

// Instantiate rotors and count
Enigma::Enigma(std::string r1, std::string r2, std::string r3) {
    this->count = {0, 0, 0};
    this->r = {r1, r2, r3};
}

// Encode a single character
char Enigma::encode(char c)
{
    if (isalpha(c) || c == '#')
    {
        char k;
        // find character index on inner rotor and set to character aligned with it on outer rotor
        k = r[0][r[2].find_first_of(c)];
        // find character index on middle rotor and set to character aligned with it on outer rotor
        k = r[0][r[1].find_first_of(k)];

        rotate();
        return k;
    }
    else
    {
        rotate();
        return c;
    }
}

// Decode a single character
char Enigma::decode(char c)
{
    if (isalpha(c) || c == '#')
    {
        char k;
        // find character index on outer rotor and set to character aligned with it on middle rotor
        k = r[1][r[0].find_first_of(c)];
        // find character index on outer rotor and set to character aligned with it on inner rotor
        k = r[2][r[0].find_first_of(k)];

        rotate();
        return k;
    }
    else
    {
        rotate();
        return c;
    }
}

// Rotate the rotor clockwise
void Enigma::rotate()
{
    // Rotate inner rotor
    std::rotate(r[2].begin(), r[2].begin() + r[2].size() - 1, r[2].end());
    count[2]++;

    // Rotate middle rotor if count of rotations of inner rotor is a multiple of 27
    if (count[2] > 0 && count[2] % 27 == 0) { 
        std::rotate(r[1].begin(), r[1].begin() + r[1].size()  - 1, r[1].end());
        count[1]++;
    }
    // Rotate outer rotor if count of rotations of middle rotor is a multiple of 27
    if (count[1] > 0 && count[1] % 27 == 0) { 
        std::rotate(r[0].begin(), r[0].begin() + r[0].size()  - 1, r[0].end());
        count[0]++;
    }
}