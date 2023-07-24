#ifndef WRITER_H
#define WRITER_H

char * generate_filename(char * nom_fichier);
FILE * open_file_to_write(char * nom_fichier);
int write_line(uint32_t ligne, FILE * fichier);

#endif
