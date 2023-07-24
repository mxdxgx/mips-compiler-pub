#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "argument.h"
#include "parser.h"
#include "writer.h"

int main(int argc, char * args[]){

 FILE *fichier = fopen(args[1], "r");
 if(fichier == NULL) {
	 printf("File doesn't exists, try with a file that exists.\n");
	 return EXIT_FAILURE;
 }

 if(!validate_filename(args[1]) && !validate_arguments(argc)) return EXIT_FAILURE;

 char * write_filename = generate_filename(args[1]);
 FILE * write_file = open_file_to_write(write_filename);
 parse_mips_line(fichier, write_file);
 
 fclose(fichier);
 fclose(write_file);

 return EXIT_SUCCESS;
}
