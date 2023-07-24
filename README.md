MIPS Compiler.
----

Essentially, it compiles MIPS assembly code into binary.

Prerequisites :

1. gcc

Compile with "make"

Known issues :

1. Does not compile JUMP instructions yet.

Usage:

./mips mips_filename

Will produce mips_filename.mips.asm file that you can read via "hexdump"

See tests folder for examples. 