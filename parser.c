#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <ctype.h>
#include <string.h>
#include "parser.h"
#include "writer.h"
#include "dictionnaire.h"

void parse_mips_line(FILE *file, FILE *write_file) {
    int rd;
    int rs;
    int rt;
    int immediate;
    int opcode;
    int funct;
    int shamt;
    int binary_line = 0;
    char line[256];

    while (fgets(line, sizeof(line), file)) {
        char *mnemonic = find_mnemonic(line);
        char *sline = strcpy(malloc(sizeof(line)), line + strlen(mnemonic));
        char type_instruction = dictionary_type(mnemonic);

        if (type_instruction == 'R') {
            char *inst = strtok(sline, " ,");
            rd = dictionary_register(inst);

            inst = strtok(NULL, ",");
            rs = dictionary_register(inst);

            inst = strtok(NULL, "\n");
            rt = dictionary_register(inst);

            funct = dictionary_function(mnemonic);
            opcode = 0;
            shamt = 0;
            binary_line = binary_conversion(type_instruction, opcode, rs, rt, rd, immediate, funct, shamt);
            write_line(binary_line, write_file);
        }

        if (type_instruction == 'I') {
            int adresse_immediate = 0;
            int multi;

            if (dictionary_immediate_value(mnemonic)) adresse_immediate = 1;
            if (!adresse_immediate) {
                char *inst = strtok(sline, " ,");
                rt = dictionary_register(inst);
                inst = strtok(NULL, ",");
                rs = dictionary_register(inst);
                inst = strtok(NULL, "\n");
                immediate = find_immediate_value(inst, adresse_immediate, 0);
                opcode = dictionary_opcode(mnemonic);
                binary_line = binary_conversion(type_instruction, opcode, rs, rt, rd, immediate, funct, shamt);
                write_line(binary_line, write_file);
            } else {
                char *inst = strtok(sline, " ,");
                rt = dictionary_register(inst);
                inst = strtok(NULL, "\n");

                rs = find_immediate_value(inst, adresse_immediate, &multi);
                opcode = dictionary_opcode(mnemonic);
                immediate = multi;
                binary_line = binary_conversion(type_instruction, opcode, rs, rt, rd, immediate, funct, shamt);
                write_line(binary_line, write_file);
            }
        }

        if (type_instruction == 'J') {
            //non-implémenté
        }
        free(sline);
    }
}

int find_immediate_value(char *word, int immediate_address, int *multi) {
    if (immediate_address == 1) {
        char *multiplicante = strtok(word, "(");
        *multi = atoi(multiplicante);
        char *remainer = strtok(NULL, ")");
        return dictionary_register(remainer);
    } else {
        int immediate_value = atoi(word);
        return immediate_value;
    }
}

char *find_mnemonic(char *line) {
    char *line_copy = strcpy(malloc(sizeof(line)), line);
    char *mnemonic = strcpy(malloc(5), strtok(line_copy, " "));
    return mnemonic;
}

uint32_t binary_conversion(char type, int opcode, int rs, int rt, int rd, int immediate, int funct, int shamt) {
    uint32_t binary_line = 0;
    int k;

    if (type == 'R') {
        //opcode sur 6 bits
        for (k = 6; k > 0; k--, opcode >>= 1) {
            if (opcode & 1) binary_line |= 1 << (32 - k);
            else binary_line |= 0 << (32 - k);
        }

        //rs sur 5 bits
        for (k = 5; k > 0; k--, rs >>= 1) {
            if (rs & 1) binary_line |= 1 << (26 - k);
            else binary_line |= 0 << (26 - k);
        }

        //rt sur 5 bits
        for (k = 5; k > 0; k--, rt >>= 1) {
            if (rt & 1) binary_line |= 1 << (21 - k);
            else binary_line |= 0 << (21 - k);
        }

        //rd sur 5 bits
        for (k = 5; k > 0; k--, rd >>= 1) {
            if (rd & 1) binary_line |= 1 << (16 - k);
            else binary_line |= 0 << (16 - k);
        }

        //shamt sur 5 bits
        for (k = 5; k > 0; k--, shamt >>= 1) {
            if (shamt & 1) binary_line |= 1 << (11 - k);
            else binary_line |= 0 << (11 - k);
        }

        //funct sur 6 bits
        for (k = 6; k > 0; k--, funct >>= 1) {
            if (funct & 1) binary_line |= 1 << (6 - k);
            else binary_line |= 0 << (6 - k);
        }
        return binary_line;
    } else if (type == 'I') {
        //opcode sur 6 bits
        for (k = 6; k > 0; k--, opcode >>= 1) {
            if (opcode & 1) binary_line |= 1 << (32 - k);
            else binary_line |= 0 << (32 - k);
        }
        //rs sur 5 bits
        for (k = 5; k > 0; k--, rs >>= 1) {
            if (rs & 1) binary_line |= 1 << (26 - k);
            else binary_line |= 0 << (26 - k);
        }
        //rt sur 5 bits
        for (k = 5; k > 0; k--, rt >>= 1) {
            if (rt & 1) binary_line |= 1 << (21 - k);
            else binary_line |= 0 << (21 - k);
        }
        //immediate sur 6 bits
        for (k = 16; k > 0; k--, immediate >>= 1) {
            if (immediate & 1) binary_line |= 1 << (16 - k);
            else binary_line |= 0 << (16 - k);
        }
        return binary_line;
    } else if (type == 'J') {
        // unimplemented
        return binary_line;
    }

    return -1;
}