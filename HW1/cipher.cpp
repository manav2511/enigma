#include <iostream>

class Cipher
{
public:
    char encode(char c);
    char decode(char c);

    Cipher(std::string key);

private:
    std::string key;
    std::string alphabet = "abcdefghijklmnopqrstuvwxyz";

    void rotate();
};

Cipher::Cipher(std::string key)
{
    this->key = key;
}

// Encode a single character
char Cipher::encode(char c)
{
    if (isalpha(c))
    {
        char r;
        if (isupper(c))
            r = toupper(key[alphabet.find_first_of(tolower(c))]);
        else
            r = key[alphabet.find_first_of(c)];
        rotate();
        return r;
    }
    else
    {
        rotate();
        return c;
    }
}

// Decode a single character
char Cipher::decode(char c)
{
    if (isalpha(c))
    {
        char r;
        if (isupper(c))
            r = toupper(alphabet[key.find_first_of(tolower(c))]);
        else
            r = alphabet[key.find_first_of(c)];
        rotate();
        return r;
    }
    else
    {
        rotate();
        return c;
    }
}

/* Rotate the key */
void Cipher::rotate()
{
    std::rotate(key.begin(), key.begin()+1, key.end());
}