#include "question2.h"

void question2()
{
    char *shell = "\nenseash %%\n";
    char *date = "voici la date\n";
    int rt; // numbers of bits read by read
    int ppid;
    char buffer[BUFFER_SIZE];
    ; // buffer for transmitting info written on the shell
    int status;

    while (1)
    {
        rt = read(STDIN_FILENO, buffer, BUFFER_SIZE);
        buffer[rt] = '\0';                    // signal that the last bit read is not char(enter) but an end of char
        buffer[strcspn(buffer, "\n")] = '\0'; // change the linne return to end of char sign
        ppid = fork();

        if (ppid == 0)
        {
            // command treatment for the child
            if (strcmp(buffer, "date") == 0)
            {
                showString(date);
                exit(0);
            }
            else if (strcmp(buffer, "ls") == 0)
            {
                execlp("ls", "ls", (char *)NULL);
                exit(0);
            }
            // write(1,buffer,rt-1);//print what is received
        }
        else
        {
            wait(&status);
            showString(shell); // show the shell console after all operation are executed
        }
    }
}
