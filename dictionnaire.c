#include <string.h>
#include "dictionnaire.h"

char dictionary_type(char *word) {
    if (!strcmp(word, "addi")
        || !strcmp(word, "andi")
        || !strcmp(word, "lw")
        || !strcmp(word, "lb")
        || !strcmp(word, "lh")
        || !strcmp(word, "sw")
        || !strcmp(word, "sh")
        || !strcmp(word, "sb")
        || !strcmp(word, "ori"))
        return 'I';

    if (!strcmp(word, "add")
        || !strcmp(word, "sub")
        || !strcmp(word, "and")
        || !strcmp(word, "or")
        || !strcmp(word, "nor"))
        return 'R';
    else return 'J';
}

int dictionary_immediate_value(char *word) {
    if (!strcmp(word, "lw")
        || !strcmp(word, "lb")
        || !strcmp(word, "lh")
        || !strcmp(word, "sw")
        || !strcmp(word, "sh")
        || !strcmp(word, "sb"))
        return 1;
    return 0;
}

int dictionary_opcode(char *word) {
    if (!strcmp(word, "addi")) return 0x08;
    if (!strcmp(word, "andi")) return 0x0C;
    if (!strcmp(word, "lw")) return 0x23;
    if (!strcmp(word, "lb")) return 0x20;
    if (!strcmp(word, "lh")) return 0x21;
    if (!strcmp(word, "sw")) return 0x2B;
    if (!strcmp(word, "sh")) return 0x29;
    if (!strcmp(word, "sb")) return 0x28;
    if (!strcmp(word, "ori")) return 0x0D;
    if (!strcmp(word, "j")) return 0x02;
    else return 0;
}

int dictionary_register(char *word) {
    if (!strcmp(word, "$zero")) return 0;
    if (!strcmp(word, "$at")) return 1;
    if (!strcmp(word, "$v0")) return 2;
    if (!strcmp(word, "$v1")) return 3;
    if (!strcmp(word, "$a0")) return 4;
    if (!strcmp(word, "$a1")) return 5;
    if (!strcmp(word, "$a2")) return 6;
    if (!strcmp(word, "$a3")) return 7;
    if (!strcmp(word, "$t0")) return 8;
    if (!strcmp(word, "$t1")) return 9;
    if (!strcmp(word, "$t2")) return 10;
    if (!strcmp(word, "$t3")) return 11;
    if (!strcmp(word, "$t4")) return 12;
    if (!strcmp(word, "$t5")) return 13;
    if (!strcmp(word, "$t6")) return 14;
    if (!strcmp(word, "$t7")) return 15;
    if (!strcmp(word, "$s0")) return 16;
    if (!strcmp(word, "$s1")) return 17;
    if (!strcmp(word, "$s2")) return 18;
    if (!strcmp(word, "$s3")) return 19;
    if (!strcmp(word, "$s4")) return 20;
    if (!strcmp(word, "$s5")) return 21;
    if (!strcmp(word, "$s6")) return 22;
    if (!strcmp(word, "$s7")) return 23;
    if (!strcmp(word, "$t8")) return 24;
    if (!strcmp(word, "$t9")) return 25;
    if (!strcmp(word, "$k0")) return 26;
    if (!strcmp(word, "$k1")) return 27;
    if (!strcmp(word, "$gp")) return 28;
    if (!strcmp(word, "$sp")) return 29;
    if (!strcmp(word, "$fp")) return 30;
    if (!strcmp(word, "$ra")) return 31;
    return -1;
}

int dictionary_function(char *word) {
    if (!strcmp(word, "add")) return 0x20;
    if (!strcmp(word, "sub")) return 0x22;
    if (!strcmp(word, "and")) return 0x24;
    if (!strcmp(word, "or")) return 0x25;
    if (!strcmp(word, "nor")) return 0x27;
    return -1;
}