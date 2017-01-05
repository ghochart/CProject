//
//  DecodingFullG4Matrix.c
//  test
//
//  Created by JetstrokeX on 25/12/2016.
//  Copyright © 2016 David. All rights reserved.
//

#include "DecodingFullG4Matrix.h"

unsigned char mToX (uint16_t u, const uint16_t matrix[4])
{
    if (u == 0)
	return 0b0000;

    else if (matrix[3] == u)//g4[3]
	return 0b0001;

    else if (u == matrix[2])//g4[2]
	return 0b0010;

    else if (u == (matrix[2] ^ matrix[3])) //G4[3] ^ g4[2]
	return 0b0011;

    else if (u == matrix[1])//g4[1]
	return 0b0100;

    else if (u == (matrix[1] ^ matrix[3]) )//G4[3] ^ g4[1]
	return 0b0101;

    else if (u == (matrix[1] ^ matrix[2]))//G4[2] ^ g4[1]
	return 0b0110;

    else if (u == (matrix[1] ^ matrix[2] ^ matrix[3]))//G4[2] ^ g4[1] ^ g4[3]
	return 0b0111;

    else if (u == matrix[0])//g4[0]
	return 0b1000;

    else if (u == (matrix[0] ^ matrix[3]))//g4[0] ^ g4[3]
	return 0b1001;

    else if (u == (matrix[0] ^ matrix[2])) //g4[0] ^ g4[2]
	return 0b1010;

    else if (u == (matrix[0] ^ matrix[2] ^ matrix[3]))//g4[0] ^ g4[2] ^ g4[3]
	return 0b1011;

    else if (u == (matrix[0] ^ matrix[1]))// g4[0] ^ g4[1]
	return 0b1100;

    else if (u == (matrix[0] ^ matrix[1] ^ matrix[3]))//g4[0] ^ g4[1] ^ g4[3]
	return 0b1101;

    else if (u == (matrix[0] ^ matrix[1] ^ matrix[2]))//g4[0] ^ g4[1] ^ g4[2]
	return 0b1110;

    else if(u == (matrix[0] ^ matrix[1] ^ matrix[2] ^ matrix[3]))//g4[0] ^ g4[1] ^ g4[2] ^ g4[3]
	return 0b1111;

    return 0xFF;
}

unsigned char decode(uint16_t u1, uint16_t u2, const uint16_t matrix[4])
{
    return ((mToX(u1, matrix)) << 4) + (mToX(u2, matrix));
}

unsigned char decodeHennou(unsigned char u1, unsigned char u2, const unsigned char matrix[4])
{
    return ((hennouMToX(u1, matrix) << 4) + (hennouMToX(u2, matrix)));
}

unsigned char hennouMToX (unsigned char u, const unsigned char matrix[4])
{
    if (u == 0)
	return 0b0000;

    else if (matrix[3] == u)//g4[3]
	return 0b0001;

    else if (u == matrix[2])//g4[2]
	return 0b0010;

    else if (u == (matrix[2] ^ matrix[3])) //G4[3] ^ g4[2]
	return 0b0011;

    else if (u == matrix[1])//g4[1]
	return 0b0100;

    else if (u == (matrix[1] ^ matrix[3]) )//G4[3] ^ g4[1]
	return 0b0101;

    else if (u == (matrix[1] ^ matrix[2]))//G4[2] ^ g4[1]
	return 0b0110;

    else if (u == (matrix[1] ^ matrix[2] ^ matrix[3]))//G4[2] ^ g4[1] ^ g4[3]
	return 0b0111;

    else if (u == matrix[0])//g4[0]
	return 0b1000;

    else if (u == (matrix[0] ^ matrix[3]))//g4[0] ^ g4[3]
	return 0b1001;

    else if (u == (matrix[0] ^ matrix[2])) //g4[0] ^ g4[2]
	return 0b1010;

    else if (u == (matrix[0] ^ matrix[2] ^ matrix[3]))//g4[0] ^ g4[2] ^ g4[3]
	return 0b1011;

    else if (u == (matrix[0] ^ matrix[1]))// g4[0] ^ g4[1]
	return 0b1100;

    else if (u == (matrix[0] ^ matrix[1] ^ matrix[3]))//g4[0] ^ g4[1] ^ g4[3]
	return 0b1101;

    else if (u == (matrix[0] ^ matrix[1] ^ matrix[2]))//g4[0] ^ g4[1] ^ g4[2]
	return 0b1110;

    else if(u == (matrix[0] ^ matrix[1] ^ matrix[2] ^ matrix[3]))//g4[0] ^ g4[1] ^ g4[2] ^ g4[3]
	return 0b1111;

    return 0xFF;
}

int decodeFileHennou (const char *filePath, const char * matrixPath)
{
    FILE * file;
    long fileSize;
    unsigned char * octal = NULL;
    unsigned char * encoded2Words = NULL;
    long encodedFileSize;
    unsigned char matrix[4];
    long i = 0;
    long count = 0;
    char *decodedFile;

    printf("\n%s\n", filePath);
    decodedFile = strdup(filePath);
    decodedFile[strlen(decodedFile) - 1] = 'd';

    getHennouMatrixG4(matrix, matrixPath);

    file = fopen(filePath, "r+b");
    if(file != NULL)
    {
	fseek(file, 0, SEEK_END);
	encodedFileSize = ftell(file);
	fseek(file, 0, SEEK_SET);
	encoded2Words = malloc(sizeof(char) * encodedFileSize);
	if(encoded2Words != NULL)
	{
	    fread(encoded2Words, sizeof(char) * 2, encodedFileSize, file);
	}
	fclose(file);
    }

    fileSize = encodedFileSize / 2;
    octal = malloc(sizeof(char) * fileSize);
    if(octal != NULL)
    {
	for(i = 0; i < encodedFileSize; i += 2)
	{
	    octal[count] = decodeHennou(encoded2Words[i] , encoded2Words[i + 1], matrix);
	    count++;
	}
    }

    file = fopen(decodedFile, "wt");
    if(file != NULL)
    {
	for(i = 0; i < fileSize; i++)
	    fputc(octal[i], file);
	fclose(file);
    }

    return 0;
}
