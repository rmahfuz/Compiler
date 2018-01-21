# Compiler
Compiler for a pedagogical language, Micro

This is a compiler for a language, Micro, similar to the language described the book "Crafting a Compiler in C". The tools flex and bison were used for scanning and parsing respectively.

The code gets compiled into assembly code which uses the Tiny instruction set.

How the code is organized:
--------------------------
scanner.lpp and parser.ypp are quite self-explanatory.
ast_node.cpp and sym_table.cpp contain the data structures and functional code required for the 'compiling' after the scanning and parsing.
To compile a file:

make compiler

runme MicroFile.micro > desired_output_file


This was developed as a project for a Compilers class at Purdue University.
