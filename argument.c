#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "argument.h"

int validate_arguments(int number_arguments)
{
  if (number_arguments > 2)
  {
    printf("Erreur : Ce programme fonctionne avec qu'un (1) seul fichier d'entré.\n");
    return 0;
  }

  if (number_arguments < 2)
  {
    printf("Erreur : fichier manquant.\n");
    return 0;
  }
  return 1;
}

int validate_filename(char *file_name)
{
  char *extension = strrchr(file_name, '.');
  if (extension != NULL && !strcmp(extension, ".mips"))
  {
    return 1;
  }
  else
  {
    printf("Fichier invalide, l'extension devrait être '.mips'\n");
    return 0;
  }
}
