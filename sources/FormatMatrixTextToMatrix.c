//
//  FormatMatrixTextToMatrix.c
//  test
//
//  Created by JetstrokeX on 25/12/2016.
//  Copyright © 2016 David. All rights reserved.
//

#include "FormatMatrixTextToMatrix.h"


void getMatrixG4(uint16_t matrix[4] )
{
    FILE * file;
    unsigned char stringOctal[17] = {'\0'};
   
    file = fopen(MATRIX_PATH, "r+b");
    
    if(file != NULL)
    {
        fseek(file, sizeof(char) * 5, SEEK_SET);
        fread(stringOctal, sizeof(char), MATRIX_NB_BYTES, file);
        matrix[0] = ConvertStringTo2Octals(stringOctal);
        fseek(file, sizeof(char), SEEK_CUR);
        fread(stringOctal, sizeof(char), MATRIX_NB_BYTES, file);
        matrix[1] = ConvertStringTo2Octals(stringOctal);
        fseek(file, sizeof(char), SEEK_CUR);
        fread(stringOctal, sizeof(char), MATRIX_NB_BYTES, file);
        matrix[2] = ConvertStringTo2Octals(stringOctal);
        fseek(file, sizeof(char), SEEK_CUR);
        fread(stringOctal, sizeof(char), MATRIX_NB_BYTES, file);
        matrix[3] = ConvertStringTo2Octals(stringOctal);
        fclose(file);
    }
}

uint16_t ConvertStringTo2Octals (unsigned char string[13])
{
    unsigned char i = 0;
    uint16_t octal = 0;

    for(i = 0; i < 12; i++)
    {
        if(string[i] == '1')
            octal |= 0x0001;
        
        if(i != 11)
            octal <<= 1;
    }
    
    return octal;
}

void getHennouMatrixG4(unsigned char matrix[4] )
{
    unsigned char stringOctal[9] = {'\0'};
    FILE * file;
    
    file = fopen(HENNOU_MATRIX_PATH, "r+b");
    
    if(file != NULL)
    {
        fseek(file, sizeof(char) * 5, SEEK_SET);
        fread(stringOctal, sizeof(char), HENNOU_MATRIX_NB_BYTES, file);
        matrix[0] = ConvertStringToOctal(stringOctal);
        fseek(file, sizeof(char), SEEK_CUR);
        fread(stringOctal, sizeof(char), HENNOU_MATRIX_NB_BYTES, file);
        matrix[1] = ConvertStringToOctal(stringOctal);
        fseek(file, sizeof(char), SEEK_CUR);
        fread(stringOctal, sizeof(char), HENNOU_MATRIX_NB_BYTES, file);
        matrix[2] = ConvertStringToOctal(stringOctal);
        fseek(file, sizeof(char), SEEK_CUR);
        fread(stringOctal, sizeof(char), HENNOU_MATRIX_NB_BYTES, file);
        matrix[3] = ConvertStringToOctal(stringOctal);
        fclose(file);
    }
}

unsigned char ConvertStringToOctal (unsigned char string[9])
{
    unsigned char i = 0;
    unsigned char octal = 0;
    
    for(i = 0; i < 8; i++)
    {
        if(string[i] == '1')
            octal |= 0x01;
        
        if(i != 7)
            octal <<= 1;
    }
    
    return octal;
}
