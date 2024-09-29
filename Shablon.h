#pragma once

#include "Crypto.h"
#include <cstddef>

const unsigned int TemplateSize = 256;

class Shablon : public Crypto
{
public:
    Shablon();
    virtual ~Shablon();

    virtual int Encrypt(const unsigned char* pSrc, unsigned int SrcSz, unsigned char* pOut, unsigned int& Outsz) override;
    virtual int Decrypt(const unsigned char* pSrc, unsigned int SrcSz, unsigned char* pOut, unsigned int& Outsz) override;

    int SetTemplateTable(const unsigned char* pEncodeArr, const unsigned char* pDecodeArr, size_t size);

private:
    unsigned char mEncryptTable[2][TemplateSize];
    unsigned char mDecryptTable[2][TemplateSize];
    size_t mArrSize;
};
