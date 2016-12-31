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
