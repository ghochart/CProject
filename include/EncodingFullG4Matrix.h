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

void encode(unsigned char byte, uint16_t g4[4], uint16_t * u1, uint16_t * u2);
uint16_t convertInto12Bytes (unsigned char byte, uint16_t g4[4]);

void encodeHennou(unsigned char byte, unsigned char g4[4], unsigned char * u1, unsigned char * u2);
unsigned char convertInto8Bytes (unsigned char byte, unsigned char g4[4]);
void doAnd3(unsigned char first, unsigned char second, unsigned char third);


#endif /* EncodingFullG4Matrix_h */
