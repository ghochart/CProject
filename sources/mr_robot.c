/*
** mr_robot.c for mr robot in /home/ghocha/Documents/Securite/sources
**
** Made by Gabriel Hochart
** Login   <ghocha@esgi.fr>
**
** Started on  Fri Dec 16 20:56:30 2016 Gabriel Hochart
** Last update Fri Dec 16 21:31:19 2016 Gabriel Hochart
*/

#include "mr_robot.h"

int main()
{
  printf("Bienvenue\n");
  get_matrice();
  return (0);
}

char    *my_gets(char *str, int size)
{
  fgets(str, size, stdin);
  if (str[strlen(str) - 1] == '\n')
    str[strlen(str) - 1] = '\0';
  return (str);
}

void	get_matrice()
{
  char	filename[255];
  int	len;
  int	ok = 0;

  printf("Veuillez entrer le nom du fichier contenant la matrice\n");
  while (ok != 1)
    {
      strcpy(filename, my_gets(filename, 255));
      if ((len = strlen(filename)) < 5) // Format .txt ?
	printf("Veuillez entrer un nom de fichier valide\n");
      else if (strcmp(filename + (len - 4), ".txt") != 0)
	printf("Le fichier doit etre au format '.txt'\n");
      else
	{
	  printf("c'est ok\n");
	  ok = 1;
	}
    }
}
