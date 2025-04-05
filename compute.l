%{
#include <stdio.h>
#include "compute.h"

double aVal = 0.0;
double bVal = 0.0;
double cVal = 0.0;
double dVal = 0.0;
%}

%%
[ \t\n]+    /* ignore whitespace */
"compute"   { return COMPUTE; }
"Z"         { return Z; }
"="         { return EQUALS; }
"C"         { 
              printf("Enter value for C: ");
              scanf("%lf", &cVal);
              return C; 
            }
"-"         { return MINUS; }
"("         { return LEFT_PAREN; }
"A"         { 
              printf("Enter value for A: ");
              scanf("%lf", &aVal);
              return A; 
            }
"*"         { return MULTIPLY; }
"B"         { 
              printf("Enter value for B: ");
              scanf("%lf", &bVal);
              return B; 
            }
")"         { return RIGHT_PAREN; }
"D"         { 
              printf("Enter value for D: ");
              scanf("%lf", &dVal);
              return D; 
            }
";"         { return END; }
.           { printf("Unrecognized character: %s\n", yytext); }
%%

int yywrap()
{
    return 1;
}