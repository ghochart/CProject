/*
** codec.h for codec.h in /home/ghocha/Documents/Securite
**
** Made by Gabriel Hochart
** Login   <ghocha@esgi.fr>
**
** Started on  Fri Dec 16 20:59:27 2016 Gabriel Hochart
** Last update Sat Dec 31 12:31:40 2016 Gabriel Hochart
*/

#ifndef CODEC_H_
# define CODEC_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int	check_matrice(char *);
void	get_matrice();
char    *my_gets(char *, int);
int	puterror(char *, int);
int	get_action();
void	get_file(char *);

#endif /* !CODEC_H_ */
