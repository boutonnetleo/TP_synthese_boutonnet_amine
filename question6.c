#include "question6.h"

void question6()
{
    char *shell = "\nenseash %%\n";
    char *bye = "Bye bye ...\n";
    int rt; // numbers of bits read by read
    int ppid;
    char buffer[BUFFER_SIZE]; // buffer for transmitting info written on the shell
    int status;

    while (1)
    {

        rt = read(STDIN_FILENO, buffer, BUFFER_SIZE);
        buffer[rt] = '\0';                    // signal that the last bit read is not char(enter) but an end of char
        buffer[strcspn(buffer, "\n")] = '\0'; // change the line return to end of char sign
        ppid = fork();
        if (ppid == 0)
        { // command treatment for the child
            if (strcmp(buffer, "exit") == 0 || rt == 0)
            {
                showString(bye);
                exit(2);
            }
            else{
                char cmd = extract_word(buffer);
                execlp(cmd[0], &cmd);
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
                    // then close the program
                    exit(EXIT_SUCCESS);
                }
            }
            showString(shell); // show the shell console after all operation are executed
        }
    }
}


char extract_word(char *buffer){
    int i=0;
    int n=1;
    while(buffer[i]!='\0'){
        if(buffer[i]==' '){n++}
        i++;
    }
    char ret[n][BUFFER_SIZE];
    i=0;
    for(int j=0;j<n;j++){
        int k=0;
        while(buffer[i]!='\0' && buffer[i]!=' '){
            ret[j][k] = buffer[i];
            i++; k++;
        }
        i++
    }
    return ret;
}