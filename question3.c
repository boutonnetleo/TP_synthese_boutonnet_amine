#include "question3.h"

void question3(){
  char* shell="\nenseash %%\n";
  char* bye="Bye bye ...\n";
  int rt;
  int ppid;
  char buffer[BUFFER_SIZE];
  int status;

  while(1){

    rt = read(STDIN_FILENO,buffer,BUFFER_SIZE);
    buffer[rt] = '\0';
    buffer[strcspn(buffer, "\n")] = '\0';
    ppid=fork();
    if (ppid == 0){
        if(strcmp(buffer,"exit")==0 || rt==0){
            write(STDOUT_FILENO,bye,strlen(bye));
            exit(2);
        }
        else if (strcmp(buffer,"ls")==0)
        {
            execlp("ls","ls",(char*)NULL);
            exit(0);
        }
        write(1,buffer,rt-1);
        exit(1);
    }
    else{
    wait(&status);
    if(status==(2)){
        break;
    }
    }
        write(STDOUT_FILENO,shell,strlen(shell));
  }

    
}