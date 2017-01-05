/*
** codec.h for codec.h in /home/ghocha/Documents/Securite
**
** Made by Gabriel Hochart
** Login   <ghocha@esgi.fr>
**
** Started on  Fri Dec 16 20:59:27 2016 Gabriel Hochart
** Last update Sun Jan  1 20:59:08 2017 Gabriel Hochart
*/

#ifndef CODEC_H_
# define CODEC_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "EncodingFullG4Matrix.h"
#include "DecodingFullG4Matrix.h"
#include "FormatMatrixTextToMatrix.h"

int	check_matrice(char *);
char	*get_matrice();
char    *my_gets(char *, int);
int	puterror(char *, int);
int	get_action();
void	get_file(char *, char *);

#endif /* !CODEC_H_ */
