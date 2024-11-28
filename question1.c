//
// Created by leo on 28/11/24.
//
#include "question1.h"
void question1(){
  char* welcome="Bienvenue dans le Shell ENSEA. \n";
  char* infos="pour quitter tapez exit \n";
  char* shell="\nenseash %%\n";

  write(1,welcome,strlen(welcome));
  write(1,infos,strlen(infos));
  write(1,shell,strlen(shell));
}