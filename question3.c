#include "question3.h"

void question3()
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
        buffer[strcspn(buffer, "\n")] = '\0'; // change the linne return to end of char sign
        ppid = fork();
        if (ppid == 0)
        { // command treatment for the child
            if (strcmp(buffer, "exit") == 0 || rt == 0)
            {
                showString(bye);
                exit(1);
            }
            else if (strcmp(buffer, "ls") == 0)
            {
                execlp("ls", "ls", (char *)NULL);
                exit(0);
            }
            // write(1,buffer,rt-1);//print what is received
            exit(0);
        }
        else
        {
            wait(&status);
            if (WEXITSTATUS(status) == 1)
            { // if the exit status was 1 (command to quit the shell in input)
                // then close the programm
                break;
            }
            showString(shell); // show the shell console after all operation are executed
        }
    }
}