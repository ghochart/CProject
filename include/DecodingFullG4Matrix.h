//
//  DecodingFullG4Matrix.h
//  test
//
//  Created by JetstrokeX on 25/12/2016.
//  Copyright © 2016 David. All rights reserved.
//

#ifndef DecodingFullG4Matrix_h
#define DecodingFullG4Matrix_h

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "FormatMatrixTextToMatrix.h"

unsigned char decode(uint16_t u1, uint16_t u2, const uint16_t matrix[4]);
unsigned char mToX (uint16_t u, const uint16_t matrix[4]);

unsigned char decodeHennou(unsigned char u1, unsigned char u2, const unsigned char matrix[4]);
unsigned char secondQuarterHennouMatrix(unsigned char u,const unsigned char matrix[4]);
unsigned char firstQuarterHennouMatrix(unsigned char u,const unsigned char matrix[4]);
unsigned char thirdQuarterHennouMatrix(unsigned char u,const unsigned char matrix[4]);
unsigned char fourthQuarterHennouMatrix(unsigned char u,const unsigned char matrix[4]);
unsigned char hennouMToX (unsigned char u, const unsigned char matrix[4]);
int decodeFileHennou (const char * filePath, const char * matrixPath);


#endif /* DecodingFullG4Matrix_h */
