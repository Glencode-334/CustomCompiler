# Custom Equation Compiler

## Overview
This is a custom compiler for the equation `Z = C - (A*B)*D`. It parses the exact syntax of the equation and computes the result based on user-provided values.

## Files
- **compute.h**: Defines all the token types needed for our expression, including Z, C, A, B, D, operators, and parentheses.
- **main.c**: Simple entry point that prompts the user and calls the main computation function.
- **compute.c**: The main parser that validates the input expression by checking each token in the expected order. Once validated, it calculates the result using the values collected from user input.
- **compute.l**: The lexical analyzer (flex file) that tokenizes the input and collects values for A, B, C, and D from the user when these variables are encountered.
- **Makefile**: Builds the project by compiling all source files and linking them together.

## How It Works
The program expects the user to enter the exact expression `compute Z = C - (A*B)*D;` and will ask for values for C, A, B, and D during tokenization. It will then calculate Z using the formula Z = C - (A*B)*D and display the result.

## Compilation Instructions

### Using Make (Linux/macOS/MSYS2)
If you have Make and Flex installed:
```
make
```

### Manual Compilation (Windows/Linux/macOS)
If you don't have Make or need to compile manually:

1. Generate lexer:
```
flex compute.l
```

2. Compile individual files:
```
gcc -c lex.yy.c
gcc -c main.c
gcc -c compute.c
```

3. Link files:
```
gcc -o equation_compiler main.o compute.o lex.yy.o
```
Note: On some systems, you may need to add `-lfl` or `-ll` to link with the Flex library.

## Running the Program
Execute the compiled program:
```
./equation_compiler    # Linux/macOS
equation_compiler.exe  # Windows
```

## Example Usage
```
Enter expression like: compute Z = C - (A*B)*D;
> compute Z = C - (A*B)*D;
Enter value for C: 10
Enter value for A: 2
Enter value for B: 3
Enter value for D: 4
Result of Z = C - (A*B)*D with A=2.00, B=3.00, C=10.00, D=4.00 is: -14.00
```

## Requirements
- GCC or compatible C compiler
- Flex (for lexical analysis)
- Make (optional, for easier compilation)