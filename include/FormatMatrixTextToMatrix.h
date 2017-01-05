//
//  FormatMatrixTextToMatrix.h
//  test
//
//  Created by JetstrokeX on 25/12/2016.
//  Copyright © 2016 David. All rights reserved.
//

#ifndef FormatMatrixTextToMatrix_h
#define FormatMatrixTextToMatrix_h

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define MATRIX_PATH "/Users/jetstrokex/Documents/COURS/C/test/test/key.txt"
#define MATRIX_NB_BYTES 16
#define HENNOU_MATRIX_PATH "/Users/jetstrokex/Documents/COURS/C/test/test/hennouKey.txt"
#define HENNOU_MATRIX_NB_BYTES 8

void getMatrixG4(uint16_t matrix[4]);
uint16_t ConvertStringTo2Octals (unsigned char string[13]);
unsigned char ConvertStringToOctal (unsigned char string[9]);
void getHennouMatrixG4(unsigned char matrix[4], const char * matrixPath);

#endif /* FormatMatrixTextToMatrix_h */
