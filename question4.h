#ifndef QUESTION4_H
#define QUESTION4_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include <stdlib.h>
#include <sys/wait.h>
#include "question1.h"
#define BUFFER_SIZE 1024
#define EXIT_NOEXEC 42
void question4();
void printshell(int status);

#endif // QUESTION4_H
