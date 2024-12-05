#include "question5.h"
void question5()
{
    {
        char *shell = "\nenseash %%\n";
        char *bye = "Bye bye ...\n";
        int rt; // numbers of bits read by read
        int ppid;
        char buffer[BUFFER_SIZE]; // buffer for transmitting info written on the shell
        int status;
        char *error_message = " ERROR Function not found :";
        struct timespec tpsStart;
        struct timespec tpsEnd;
        char temps[BUFFER_SIZE];

        while (1)
        {

            rt = read(STDIN_FILENO, buffer, BUFFER_SIZE);
            buffer[rt] = '\0';                    // signal that the last bit read is not char(enter) but an end of char
            buffer[strcspn(buffer, "\n")] = '\0'; // change the linne return to end of char sign
            ppid = fork();
            clock_gettime(CLOCK_REALTIME, &tpsStart);
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
                clock_gettime(CLOCK_REALTIME, &tpsEnd);
                int time_elapsed = (int) ((tpsEnd.tv_sec - tpsStart.tv_sec)* 1000 + (tpsEnd.tv_nsec - tpsStart.tv_nsec) / 1000000) ;
                if (WIFEXITED(status))
                {
                    if (WEXITSTATUS(status) == 2)
                    { // if the exit status was 1 (command to quit the shell in input)
                        // then close the programm
                        exit(EXIT_SUCCESS);
                    }
                }
                printshell2(status,time_elapsed); // show the shell console after all operation are executed
            }
        }
    }
}
void printshell2(int status,int time)
{
    char buffer[BUFFER_SIZE];
    char *shell = "\nenseash [%s : %d]| %dms %% \n";
    if (WIFEXITED(status))
    {
        if (status != EXIT_NOEXEC)
        {
            sprintf(buffer, shell, "exit", WEXITSTATUS(status),time);
        }
        else
        {
            sprintf(buffer, "\nenseash %%\n");
        }
    }
    else if (WIFSIGNALED(status))
    {
        sprintf(buffer, shell, "signal", WTERMSIG(status),time);
    }
    showString(buffer);
}

