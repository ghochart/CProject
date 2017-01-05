//
//  EncodingFullG4Matrix.c
//  test
//
//  Created by JetstrokeX on 25/12/2016.
//  Copyright © 2016 David. All rights reserved.
//

#include "EncodingFullG4Matrix.h"

void encode(unsigned char byte, uint16_t g4[4], uint16_t * u1, uint16_t * u2)
{
    uint8_t mask = 0x0F;
    
    *u1 = convertInto12Bytes(((byte >> 4) & mask), g4);
    *u2 = convertInto12Bytes(((byte << 4)  >> 4) & mask,  g4);
}

uint16_t convertInto12Bytes (unsigned char byte, uint16_t g4[4])
{
    uint16_t result = 0;
    
    switch (byte)
    {
        case 0b0000:
            result = 0;
            break;
            
        case 0b0001:
            result = g4[3];
            break;
            
        case 0b0010:
            result = g4[2];
            break;
            
        case 0b0011:
            result = (g4[2] ^ g4[3]);
            break;
            
        case  0b0100:
            result = g4[1];
            break;
            
        case  0b0101:
            result = (g4[1] ^ g4[3]);
            break;
            
        case 0b0110:
            result = (g4[1] ^ g4[2]);
            break;
            
        case  0b0111:
            result = (g4[1] ^ g4[2] ^ g4[3]);
            break;
            
        case  0b1000:
            result = g4[0];
            break;
            
        case 0b1001:
            result = (g4[0] ^ g4[3]);
            break;
            
        case 0b1010:
            result = (g4[0] ^ g4[2]);
            break;
            
        case 0b1011:
            result = (g4[0] ^ g4[2] ^ g4[3]);
            break;
            
        case 0b1100:
            result = (g4[0] ^ g4[1]);
            break;
            
        case 0b1101:
            result = (g4[0] ^ g4[1] ^ g4[3]);
            break;
            
        case 0b1110:
            result = (g4[0] ^ g4[1] ^ g4[2]);
            break;
            
        case 0b1111:
            result = (g4[0] ^ g4[1] ^ g4[2] ^ g4[3]);
            break;
    }
    
    return result;
}

void encodeHennou(unsigned char byte, unsigned char g4[4], unsigned char * u1, unsigned char * u2)
{
    uint8_t mask = 0x0F;
    
    *u1 = convertInto8Bytes(((byte >> 4) & mask), g4);
    *u2 = convertInto8Bytes(((byte << 4)  >> 4) & mask,  g4);
}
unsigned char convertInto8Bytes (unsigned char byte, unsigned char g4[4])
{
    unsigned char  result = 0;
    
    switch (byte)
    {
        case 0b0000:
            result = 0;
            break;
            
        case 0b0001:
            result = g4[3];
            break;
            
        case 0b0010:
            result = g4[2];
            break;
            
        case 0b0011:
            result = (g4[2] ^ g4[3]);
            break;
            
        case  0b0100:
            result = g4[1];
            break;
            
        case  0b0101:
            result = (g4[1] ^ g4[3]);
            break;
            
        case 0b0110:
            result = (g4[1] ^ g4[2]);
            break;
            
        case  0b0111:
            result = ((g4[1] ^ g4[2]) ^ g4[3]);
            break;
            
        case  0b1000:
            result = g4[0];
            break;
            
        case 0b1001:
            result = (g4[0] ^ g4[3]);
            break;
            
        case 0b1010:
            result = (g4[0] ^ g4[2]);
            break;
            
        case 0b1011:
            result = ((g4[0] ^ g4[2]) ^ g4[3]);
            break;
            
        case 0b1100:
            result = (g4[0] ^ g4[1]);
            break;
            
        case 0b1101:
            result = ((g4[0] ^ g4[1]) ^ g4[3]);
            break;
            
        case 0b1110:
            result = ((g4[0] ^ g4[1] ) ^ g4[2]);
            break;
            
        case 0b1111:
            result = (((g4[0] ^ g4[1]) ^ g4[2]) ^ g4[3]);
            break;
    }
    
    return result;
}

int encodeFileHennou(const char * filePath, const char * matrixPath)
{
    FILE * file;
    long fileSize;
    unsigned char * octal = NULL;
    HennouMessage m;
    unsigned char * encoded2Words;
    long encodedFileSize;
    unsigned char matrix[4];
    long i = 0;
    long count = 0;
    char encodedFile [255];
    
    strcpy(encodedFile, filePath);
    strcat(encodedFile, "c");
    getHennouMatrixG4(matrix, matrixPath);
    file = fopen(filePath, "r+");
    if(file != NULL)
    {
        fseek(file, 0, SEEK_END);
        fileSize = ftell(file);
        fseek(file, 0, SEEK_SET);
        octal = malloc(sizeof(char) * fileSize);
        if(octal != NULL)
        {
            fread(octal, sizeof(char), fileSize, file);
        }
        fclose(file);
    }
    
    encodedFileSize = fileSize * 2;
    encoded2Words = malloc(sizeof(char) * encodedFileSize);
    if(encoded2Words != NULL)
    {
        for(i = 0; i < fileSize; i++)
        {
            encodeHennou(octal[i] , matrix, &m.u1, &m.u2);
            encoded2Words[count] = m.u1;
            encoded2Words[++count] = m.u2;
            count++;
        }
    }
    
    file = fopen(encodedFile, "wb");
    if(file != NULL)
    {
        fwrite(encoded2Words, sizeof(char), encodedFileSize, file);
        fclose(file);
    }
    
    if(octal != NULL)
        free(octal);
    if(encoded2Words != NULL)
        free(encoded2Words);
    
    return 0;
}
