/*
** codec.c for mr robot in /home/ghocha/Documents/Securite/sources
**
** Made by Gabriel Hochart
** Login   <ghocha@esgi.fr>
**
** Started on  Fri Dec 16 20:56:30 2016 Gabriel Hochart
** Last update Tue Dec 20 00:05:34 2016 Gabriel Hochart
*/

#include "codec.h"

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
      else if (check_matrice(filename) == 1)
	{
	  printf ("ERREUR MATRICE\n");
	  return ;
	}
      else
	{
	  printf("c'est ok\n");
	  ok = 1;
	}
    }
}

int	check_matrice(char *filename)
{
  char	str[255];
  char	matrix[4][255];
  FILE	*file;
  int	i = 0;
  int	x = 0;
  int	y = 0;

  if ((file = fopen(filename, "r")))
    {
      printf("ca rentre\n");
      fread(str, sizeof(char), 255, file);
      while (str[i] != '\0' && str[i] != '[')
	i++;
      if (str[i] == '[' && (str[i + 1] == '1' || str[i + 1] == '0'))
	{
	  i++;
	  y = 0;
	  while (str[i] != '\0')
	    {
	      if (str[i] == '0' || str[i] == '1')
		matrix[x][y++] = str[i];
	      else if (str[i] == ' ')
		x++;
	      else if (str[i] == ']' && x == 3)
		return (0);
	      else
		return (1);
	      i++;
	    }
	}
      else
	{
	  printf("Erreur de matrice\n");
	  return (1);
	}
    }
  else
    {
      printf("Ce fichier n'existe pas\n");
      return (1);
    }
  return (0);
}
