#include "Shablon.h"
#include <iostream>
#include <algorithm>
#include <random>
#include <cstring>

#define BUF_SIZE 1024

unsigned char encode_arr[TemplateSize];
unsigned char decode_arr[TemplateSize];

int InitTemplateKeytable(unsigned char* enc_arr, unsigned char* dec_arr, unsigned int TemplateSize)
{
    std::cout << "\nInitTemplateKeytable\n";

    if (!encode_arr || !decode_arr || !TemplateSize)
        return -1;
     
    for (unsigned int i = 0; i < TemplateSize; ++i)
    {
        dec_arr[i] = encode_arr[i] = i;
    }

    // Time-based seed for shuffling
    unsigned seed = 0;
    std::shuffle(dec_arr, dec_arr + TemplateSize, std::default_random_engine(seed));

    std::cout << "\nOriginal Encode Array:\n";
    for (unsigned int i = 0; i < TemplateSize; ++i)
    {
        std::cout << (unsigned int)encode_arr[i] << ' ';
    }

    std::cout << "\n\nShuffled Decode Array:\n";
    for (unsigned int i = 0; i < TemplateSize; ++i)
    {
        std::cout << (unsigned int)decode_arr[i] << ' ';
    }

    std::cout << "\n\nEnd\n\n";
    return 0;
}

int main()
{
    unsigned char src[BUF_SIZE], dest[BUF_SIZE], decrypt[BUF_SIZE];
    std::string str("This is an apple");
    unsigned int size = (unsigned int)str.size();

    strcpy((char*)src, str.c_str());
    std::cout << "Text to encrypt:\n" << src << std::endl;

    InitTemplateKeytable(encode_arr, decode_arr, TemplateSize);

    Shablon obj;
    obj.SetTemplateTable(encode_arr, decode_arr, TemplateSize);

    if (obj.Encrypt(src, size, dest, size))
    {
        std::cout << "Failed to Encrypt...\n";
        return -1;
    }

    dest[size] = 0;
    std::cout << "Encrypted text: " << dest << std::endl;

    if (obj.Decrypt(dest, size, decrypt, size))
    {
        std::cout << "Failed to Decrypt...\n";
        return -2;
    }

    decrypt[size] = 0;
    std::cout << "Decrypted text: " << decrypt << std::endl;

    if (strcmp((const char*)src, (const char*)decrypt))
    {
        std::cout << "Decryption failed" << std::endl;
    }
    else
    {
        std::cout << "Success" << std::endl;
    }

    return 0;
}
