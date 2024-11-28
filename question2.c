#include "question2.h"

void question2(){
  char* shell="\nenseash %%\n";
  char* date="voici la date\n";
  int rt;
  int ppid;
  char buffer[BUFFER_SIZE];

  while(1){

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
        write(STDOUT_FILENO,shell,strlen(shell));
  }

    
}