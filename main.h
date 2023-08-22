#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/stat.h>
#include <signal.h>


extern char **environ;

int _strcmp(const char *s1, const char *s2);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
char **divide_string(char *buf, char *delimiter);
char *bring_env(const char *check_env);
void print_env(void);
char *Check_Command(char *command);
void exec_cmd(char **arr, char **argv, int count);
#endif
