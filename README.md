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


How it works:
--------------------------
While parsing, each token returns a value, often of the type ASTNode (Abstract Syntax Tree Node) to the token higher up in the hierarchy. The generate_code() member function of the ASTNode class is called for a nearly highest-level token (the value of which is of the type ASTNode), which creates a linked list of 3AC (3 Address Code, a type of Intermediate Representation), the head of which is pointed to by the head_code variable of the LinkedListNode* type. The generate_code() function recursively calls this function for all children ASTNodes of the current ASTNode. This 3AC code is converted to assembly by calling the function gen_asm(head_code), which generates assembly code for the 3AC by accepting the head of the linked list that stores the 3AC. This assembly code is stored in another linked list, the head of which is the head_asm variable of LinkedListNode* type. To print the assembly code, this linked list simply needs to be printed/outputted to a file.

The key translation engineering (the most happenning part of the code) is in generate_code() and gen_asm functions.
