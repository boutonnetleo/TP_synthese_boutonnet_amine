//
// Created by leo on 28/11/24.
//
#include "question1.h"
void question1(){
  char* welcome="Bienvenue dans le Shell ENSEA. \n";
  char* infos="pour quitter tapez exit \n";
  char* shell="enseash %%";
  char* bye="Au revoir !\n";
  int rt;
  char* buffer;
  write(1,welcome,strlen(welcome));
  write(1,infos,strlen(infos));
    while(1) {
        write(1,shell,strlen(shell));
        rt = read(0,buffer,BUFFER_SIZE);
        buffer[rt] = '\0';
        buffer[strcspn(buffer, "\n")] = '\0';
        if (strcmp(buffer, "exit") == 0) {
            write(1,bye,strlen(bye));
            break;
        }
        write(1,buffer,rt-1);
    }
  }