#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char ** argv)
{
    pid_t child;
    pid_t child2;
    int exitStatus;

    // at least, there should be 3 arguments
    // 2 for the first command, and the rest for the second command
    if (argc < 4) {
        fprintf(stderr, "Usage: %s cmd1 cmd1_arg cmd2 [cmd2_args ..]\n", argv[0]);
        return 1;
    }

    // TODO
    child = fork();
    if(child < 0) //error if fork() returns a negative
    {
        perror("fork()");
        exit(1);
    }
    else if(child == 0) //this is a child process
    {
        execlp(argv[1], argv[1], argv[2], NULL); //replace current process with command argv[1], process argv[2]
        perror("excelp()"); //raises error if anything is returned
        exit(1);
    }

    waitpid(child, &exitStatus, 0); //wait for child to finish. Store exit status in corresponding variable
    if(WIFEXITED(exitStatus)) //checks if exited correctly
    {
        //prints if exited and the exit code
        printf("exited=%d exitstatus=%d\n", WIFEXITED(exitStatus), WEXITSTATUS(exitStatus));
    }

    child2 = fork();
    if(child2 < 0) //error if fork() returns a negative
    {
        perror("fork()");
        exit(1);
    }
    else if(child2 == 0) //this is a child process
    {
        execvp(argv[3], &argv[3]); //replaces the old process with arguments 3 and on
        perror("excevp()"); //raises error if anything is returned
        exit(1);
    }

    waitpid(child2, &exitStatus, 0); //wait for child to finish. Store exit status in corresponding variable
    if(WIFEXITED(exitStatus)) //checks if exited correctly
    {
        //prints if exited and the exit code
        printf("exited=%d exitstatus=%d\n", WIFEXITED(exitStatus), WEXITSTATUS(exitStatus));
    }

    return 0;
}
