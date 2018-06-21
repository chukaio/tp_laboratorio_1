#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

char menu(void);
int isNum(char []);
int intOrFloat(char []);
int isLwrThan(char [],int);
char isThat(char,char,char);

#endif // INPUT_H_INCLUDED

