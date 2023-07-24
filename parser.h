#ifndef PARSER_H
#define PARSER_H

char *to_binary(uint32_t n);
char *find_next_word(char *line);
void parse_mips_line(FILE *file, FILE *write_file);
int find_immediate_value(char *word, int immediate_address, int *value);
char *find_mnemonic(char *line);
uint32_t binary_conversion(char type, int opcode, int rs, int rt, int rd, int immediate, int funct, int shamt);

#endif
