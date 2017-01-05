/*
** codec.c for mr robot in /home/ghocha/Documents/Securite/sources
**
** Made by Gabriel Hochart
** Login   <ghocha@esgi.fr>
**
** Started on  Fri Dec 16 20:56:30 2016 Gabriel Hochart
** Last update Thu Jan  5 17:31:33 2017 Gabriel Hochart
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
  char	matrix_name[255];
  int	i = 0;

  printf(GREEN"   ______    ___   ______   ________    ______ \n");
  printf(" .' ___  | .'   `.|_   _ `.|_   __  | .' ___  |\n");
  printf("/ .'   \\_|/  .-.  \\ | | `. \\ | |_ \\_|/ .'   \\_| \n");
  printf("| |       | |   | | | |  | | |  _| _ | |       \n");
  printf("\\ `.___.'\\\\  `-'  /_| |_.' /_| |__/ |\\ `.___.'\\ \n");
  printf(" `.____ .' `.___.'|______.'|________| `.____ .' \n\n"RESET);
  strcpy(matrix_name, get_matrice());
  while (i == 0)
    {
      printf(BLUE"What do you wan't to do ? \"encode\", \"decode\", \"quit\" ? "RESET);
      action = get_action();
      if (action == 0)
	{
	  get_file("encode", matrix_name);
	  printf(GREEN"Encoding done\n");
	}
      else if (action == 1)
	{
	  get_file("decode", matrix_name);
	  printf(GREEN"Decoding done\n");
	}
      else
	return (0);
    }
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
  char	*act;

  while (1)
    {
      act = strdup(my_gets(action, 7));
      if ((strcmp(act, "encode") == 0))
	return (0);
      else if ((strcmp(act, "decode") == 0))
	return (1);
      else if ((strcmp(act, "quit") == 0))
	return (2);
      printf(RED"\"encode\" or \"decode\" the file ?\n"RESET);
    }
}

void	get_file(char *action, char *matrix_name)
{
  char	filename[255];
  int	ok = 0;
  FILE	*file;

  while (ok != 1)
    {
      printf(BLUE"Name of the file you wan't to %s : "RESET, action);
      strcpy(filename, my_gets(filename, 255));
      if ((file = fopen(filename, "r")))
	{
	  if ((strcmp(action, "encode") == 0))
	    encodeFileHennou(filename, matrix_name);
	  else if ((strcmp(action, "decode") == 0))
	    decodeFileHennou(filename, matrix_name);
	  ok = 1;
	}
      else
	printf(RED"\nThis file does not exist or you don't have the right to access it\n\n");
    }
  fclose(file);
}

char	*get_matrice()
{
  char	filename[255];
  int	len;
  char	*file;

  while (1)
    {
      printf(BLUE"Name of the file with the matrix : "RESET);
      file = strdup(my_gets(filename, 255));
      if ((len = strlen(file)) < 5) // Format .txt ?
	printf(RED"\nFilename incorrect\n\n");
      else if (strcmp(file + (len - 4), ".txt") != 0)
	printf(RED"\nFilename incorrect (.txt needed)\n\n");
      else if (check_matrice(file) == 1)
	printf (RED"\nMatrix error\n\n");
      else
	{
	  printf(GREEN"\nMatrix ok\n\n");
	  return (file);
	}
    }
}

int	check_matrice(char *filename)
{
  char	str[255];
  FILE	*file;
  int	i = 0;
  int	x = 0;

  if ((file = fopen(filename, "r")))
    {
      fread(str, sizeof(char), 255, file);
      while (str[i] != '\0' && str[i] != '[')
	i++;
      if (str[i] == '[' && (str[i + 1] == '1' || str[i + 1] == '0'))
	{
	  i++;
	  while (str[i] != '\0')
	    {
	      if (str[i] == ' ')
		x++;
	      else if (str[i] == ']' && x == 3)
		return (0);
	      else if (str[i] != '1' && str[i] != '0')
		return (1);
	      i++;
	    }
	}
      else
	return (1);
      fclose(file);
    }
  else
    {
      printf(RED"This file does not exist or you don't have the right to access it\n");
      return (2);
    }
  return (0);
}
