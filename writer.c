#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "writer.h"

char * generate_filename(char * nom_fichier){
  return strcat(nom_fichier, ".asm");
}

FILE * open_file_to_write(char * nom_fichier){
  FILE * fichier = fopen(nom_fichier, "ab+");
  rewind(fichier);
  return fichier;
}

int write_line(uint32_t ligne, FILE * fichier){
  fwrite( &ligne, sizeof(uint32_t), 1, fichier);
  return 0;
}
