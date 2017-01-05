//
//  EncodingFullG4Matrix.h
//  test
//
//  Created by JetstrokeX on 25/12/2016.
//  Copyright © 2016 David. All rights reserved.
//

#ifndef EncodingFullG4Matrix_h
#define EncodingFullG4Matrix_h

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "codec.h"
#include "FormatMatrixTextToMatrix.h"

#define FILE_TO_ENCODE_PATH "/Users/jetstrokex/Documents/COURS/C/test/test/textFile.txt"
#define FILE_ENCODED_PATH "/Users/jetstrokex/Documents/COURS/C/test/test/textFile.txtc"

typedef struct Message
{
    uint16_t u1;
    uint16_t u2;
} Message;

typedef struct HennouMessage
{
    uint8_t u1;
    uint8_t u2;
} HennouMessage;

void encode(unsigned char byte, uint16_t g4[4], uint16_t * u1, uint16_t * u2);
uint16_t convertInto12Bytes (unsigned char byte, uint16_t g4[4]);

void encodeHennou(unsigned char byte, unsigned char g4[4], unsigned char * u1, unsigned char * u2);
unsigned char convertInto8Bytes (unsigned char byte, unsigned char g4[4]);
void doAnd3(unsigned char first, unsigned char second, unsigned char third);
int encodeFileHennou(const char * filePath, const char * matrixPath);


#endif /* EncodingFullG4Matrix_h */
