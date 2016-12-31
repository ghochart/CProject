/*
** codec.c for mr robot in /home/ghocha/Documents/Securite/sources
**
** Made by Gabriel Hochart
** Login   <ghocha@esgi.fr>
**
** Started on  Fri Dec 16 20:56:30 2016 Gabriel Hochart
** Last update Sat Dec 31 11:56:36 2016 Gabriel Hochart
*/

#include "codec.h"
#include <unistd.h>

#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define RESET   "\x1b[0m"

int main()
{
  printf(GREEN"   ______    ___   ______   ________    ______ \n");
  printf(" .' ___  | .'   `.|_   _ `.|_   __  | .' ___  |\n");
  printf("/ .'   \\_|/  .-.  \\ | | `. \\ | |_ \\_|/ .'   \\_| \n");
  printf("| |       | |   | | | |  | | |  _| _ | |       \n");
  printf("\\ `.___.'\\\\  `-'  /_| |_.' /_| |__/ |\\ `.___.'\\ \n");
  printf(" `.____ .' `.___.'|______.'|________| `.____ .' \n\n"RESET);
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

  while (ok != 1)
    {
      printf(RESET"Name of the file with the matrix : ");
      strcpy(filename, my_gets(filename, 255));
      if ((len = strlen(filename)) < 5) // Format .txt ?
	printf(RED"\nFilename incorrect\n\n");
      else if (strcmp(filename + (len - 4), ".txt") != 0)
	printf(RED"\nFilename incorrect (.txt needed)\n\n");
      else if (check_matrice(filename) == 1)
	printf (RED"\nMatrix error\n\n");
      else
	{
	  printf(GREEN"\nc'est ok\n\n");
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
      printf(GREEN"ca rentre\n");
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
	return (puterror(RED"Matrix error\n"));
    }
  else
    return (puterror(RED"This file does not exist or you don't have the right to access it\n"));
  return (0);
}

int	puterror(char *str)
{
  write(2, (str++), strlen(str));
  return (1);
}
