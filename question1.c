//
// Created by leo on 28/11/24.
//
#include "question1.h"
void question1()
{
  char *welcome = "Bienvenue dans le Shell ENSEA. \n";
  char *infos = "pour quitter tapez exit \n";
  char *shell = "\nenseash %%\n";

  showString(welcome);
  showString(infos);
  showString(shell);
}

void showString(char *string)
{
  // write on the console the characters from string
  write(STDIN_FILENO, string, strlen(string));
}