#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

size_t strlen(const char *string);
char* strcpy(char *s1, const char *s2);
int strcmp(const char *s1, const char *s2);
int strcmpi(const char *s1, const char *s2);
int strncmp(const char *s1, const char *s2, size_t num);
char* strcat(char*s1, const char *s2);
char* strstr(char *s1,char *s2);

#endif // FUNCIONES_H_INCLUDED
