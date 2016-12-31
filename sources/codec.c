/*
** codec.c for mr robot in /home/ghocha/Documents/Securite/sources
**
** Made by Gabriel Hochart
** Login   <ghocha@esgi.fr>
**
** Started on  Fri Dec 16 20:56:30 2016 Gabriel Hochart
** Last update Sat Dec 31 12:34:04 2016 Gabriel Hochart
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
  int	action;

  printf(GREEN"   ______    ___   ______   ________    ______ \n");
  printf(" .' ___  | .'   `.|_   _ `.|_   __  | .' ___  |\n");
  printf("/ .'   \\_|/  .-.  \\ | | `. \\ | |_ \\_|/ .'   \\_| \n");
  printf("| |       | |   | | | |  | | |  _| _ | |       \n");
  printf("\\ `.___.'\\\\  `-'  /_| |_.' /_| |__/ |\\ `.___.'\\ \n");
  printf(" `.____ .' `.___.'|______.'|________| `.____ .' \n\n"RESET);
  get_matrice();
  printf(RESET"Do you wan't to encode or decode the file ?\n");
  action = get_action();
  if (action == 0)
    get_file("encode");
  else if (action == 1)
    get_file("decode");
  return (0);
}

char    *my_gets(char *str, int size)
{
  fgets(str, size, stdin);
  if (str[strlen(str) - 1] == '\n')
    str[strlen(str) - 1] = '\0';
  return (str);
}

int	get_action()
{
  char	action[7];

  while (1)
    {
      strcpy(action, my_gets(action, 7));
      if ((strcmp(action, "encode") == 0))
	return (0);
      else if ((strcmp(action, "decode") == 0))
	return (1);
      printf(RED"\"encode\" or \"decode\" the file ?\n"RESET);
    }
}

void	get_file(char *action)
{
  char	filename[255];

  printf(RESET"Name of the file you wan't to %s : ", action);
  strcpy(filename, my_gets(filename, 255));
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
	return (1);
      fclose(file);
    }
  else
    return (puterror(RED"This file does not exist or you don't have the right to access it\n", 2));
  return (0);
}

int	puterror(char *str, int fd)
{
  write(fd, (str++), strlen(str));
  return (fd);
}
