#include "Shablon.h"
#include <cstring>
#include <algorithm>
#include <iostream>

Shablon::Shablon() : mArrSize(0) {}

Shablon::~Shablon() {}

int Shablon::Encrypt(const unsigned char* psource, unsigned int sourcesize, unsigned char* pout, unsigned int& outsize)
{
    if (!psource || !pout || !sourcesize || !outsize || outsize < sourcesize)
        return -1;

    for (unsigned int i = 0; i < sourcesize; ++i)
    {
        pout[i] = mEncryptTable[1][psource[i]];
    }
    return 0;
}

int Shablon::Decrypt(const unsigned char* psource, unsigned int sourcesize, unsigned char* pout, unsigned int& outsize)
{
    if (!psource || !pout || !sourcesize || !outsize || outsize < sourcesize)
        return -1;

    for (unsigned int i = 0; i < sourcesize; ++i)
    {
        pout[i] = mDecryptTable[1][psource[i]];
    }
    return 0;
}

int Shablon::SetTemplateTable(const unsigned char* pEncodeArr, const unsigned char* pDecodeArr, size_t size)
{
    if (!pEncodeArr || !pDecodeArr || !size)
        return -1;

    std::memcpy(mEncryptTable[0], pEncodeArr, size);
    std::memcpy(mEncryptTable[1], pDecodeArr, size);

    std::memcpy(mDecryptTable[0], mEncryptTable[1], size);
    std::memcpy(mDecryptTable[1], mEncryptTable[0], size);

    for (size_t i = 0; i < size; ++i)
    {
        size_t j;
        for (j = i; j < size; ++j)
        {
            if (i == mDecryptTable[0][j])
                break;
        }
        if (j != i)
        {
            std::swap(mDecryptTable[0][j], mDecryptTable[0][i]);
            std::swap(mDecryptTable[1][j], mDecryptTable[1][i]);
        }
    }
    mArrSize = size;
    return 0;
}
