#include "question4.h"
void question4()
{
    char *shell = "\nenseash %%\n";
    char *bye = "Bye bye ...\n";
    int rt; // numbers of bits read by read
    int ppid;
    char buffer[BUFFER_SIZE]; // buffer for transmitting info written on the shell
    int status;
    char * error_message = " ERROR Function not found :";
    while (1)
    {

        rt = read(STDIN_FILENO, buffer, BUFFER_SIZE);
        buffer[rt] = '\0';                    // signal that the last bit read is not char(enter) but an end of char
        buffer[strcspn(buffer, "\n")] = '\0'; // change the linne return to end of char sign
        ppid = fork();
        if (ppid == 0)
        { // command treatment for the child
            if (strcmp(buffer, "exit") == 0 || rt == 0)
            {
                showString(bye);
                exit(2);
            }
            else // if (strcmp(buffer, "ls") == 0)
            {
                execlp(buffer, buffer, (char *)NULL);
                perror(error_message);
                exit(EXIT_FAILURE);
            }
            // write(1,buffer,rt-1);//print what is received
            exit(EXIT_NOEXEC);
        }
        else
        {
            wait(&status);
            if (WIFEXITED(status))
            {
                if (WEXITSTATUS(status) == 2)
                { // if the exit status was 1 (command to quit the shell in input)
                    // then close the programm
                    exit(EXIT_SUCCESS);
                }
            }
            printshell(status); // show the shell console after all operation are executed
        }
    }
}

void printshell(int status){
    char buffer[BUFFER_SIZE];
    char* shell="\nenseash [%s : %d] %% \n";
    if (WIFEXITED(status)){
        if(status != EXIT_NOEXEC){
            sprintf(buffer,shell,"exit",WEXITSTATUS(status));
        }else{
            sprintf(buffer,"\nenseash %%\n");
        }
    }
    else if (WIFSIGNALED(status)){
        sprintf(buffer,shell,"signal",WSTOPSIG(status));
    }
    showString(buffer); 

}
