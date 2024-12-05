#ifndef QUESTION5_H
#define QUESTION5_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include <stdlib.h>
#include <sys/wait.h>
#include "question1.h"
#include <time.h>

#define EXIT_NOEXEC 42
#define BUFFER_SIZE 1024
void question5();
void printshell2(int status,int time);
#endif // QUESTION5_H
