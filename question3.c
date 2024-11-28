#include "question3.h"

void question3(){
  char* welcome="Bienvenue dans le Shell ENSEA. \n";
  char* infos="pour quitter tapez exit \n";
  char* shell="\nenseash %%\n";
  char* date="voici la date\n";
  int rt;
  int ppid;
  char buffer[BUFFER_SIZE];
  char* fortune;

  write(STDOUT_FILENO,welcome,strlen(welcome));
  write(STDOUT_FILENO,infos,strlen(infos));


  while(1){
    write(STDOUT_FILENO,shell,strlen(shell));
    rt = read(STDIN_FILENO,buffer,BUFFER_SIZE);
    buffer[rt] = '\0';
    buffer[strcspn(buffer, "\n")] = '\0';
    ppid=fork();
    if (ppid == 0){
        if(strcmp(buffer,"date")==0){
            write(STDOUT_FILENO,date,strlen(date));
        }
        else if (strcmp(buffer,"ls")==0)
        {
            execlp("ls","ls",(char*)NULL);
        }
        
        break;
    }
    else{
    write(1,buffer,rt-1);
    }
  }

    
}