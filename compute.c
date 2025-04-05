#include <stdio.h>
#include "compute.h"

extern int yylex();
extern double aVal, bVal, cVal, dVal;

void computeExpression()
{
    int token;
    token = yylex(); // compute
    if (token != COMPUTE)
    {
        printf("Expected 'compute'\n");
        return;
    }

    token = yylex(); // Z
    if (token != Z)
    {
        printf("Expected 'Z'\n");
        return;
    }

    token = yylex(); // =
    if (token != EQUALS)
    {
        printf("Expected '='\n");
        return;
    }

    token = yylex(); // C
    if (token != C)
    {
        printf("Expected 'C'\n");
        return;
    }

    token = yylex(); // -
    if (token != MINUS)
    {
        printf("Expected '-'\n");
        return;
    }

    token = yylex(); // (
    if (token != LEFT_PAREN)
    {
        printf("Expected '('\n");
        return;
    }

    token = yylex(); // A
    if (token != A)
    {
        printf("Expected 'A'\n");
        return;
    }

    token = yylex(); // *
    if (token != MULTIPLY)
    {
        printf("Expected '*'\n");
        return;
    }

    token = yylex(); // B
    if (token != B)
    {
        printf("Expected 'B'\n");
        return;
    }

    token = yylex(); // )
    if (token != RIGHT_PAREN)
    {
        printf("Expected ')'\n");
        return;
    }

    token = yylex(); // *
    if (token != MULTIPLY)
    {
        printf("Expected '*'\n");
        return;
    }

    token = yylex(); // D
    if (token != D)
    {
        printf("Expected 'D'\n");
        return;
    }

    token = yylex(); // ;
    if (token != END)
    {
        printf("Expected ';'\n");
        return;
    }

    double result = cVal - (aVal * bVal) * dVal;
    printf("Result of Z = C - (A*B)*D with A=%.2f, B=%.2f, C=%.2f, D=%.2f is: %.2f\n", 
           aVal, bVal, cVal, dVal, result);
}