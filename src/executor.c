#include "executor.h"
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

RET ExecuteCommand(commandStru *cmdHead)
{
    int prevPipeFd[2] = {-1, -1};
    pid_t pid;

    while (cmdHead)
    {
        int currPipeFd[2] = {-1, -1};
        if (cmdHead->next)
        {
            if (pipe(currPipeFd) == -1)
            {
                perror("pipe");
                return RET_ERROR;
            }
        }
        pid = fork();
        if (pid < 0)
        {
            perror("fork");
            return RET_ERROR;
        }
        if (pid == 0)
        {
            if (prevPipeFd[0] != -1)
            {
                dup2(prevPipeFd[0], STDIN_FILENO);
            }
            if (cmdHead->next)
            {
                dup2(currPipeFd[1], STDOUT_FILENO);
            }
            if (prevPipeFd[0] != -1)
                close(prevPipeFd[0]);
            if (prevPipeFd[1] != -1)
                close(prevPipeFd[1]);
            if (currPipeFd[0] != -1)
                close(currPipeFd[0]);
            if (currPipeFd[1] != -1)
                close(currPipeFd[1]);
            execvp(cmdHead->argv[0], cmdHead->argv);
            perror("execvp failed");
            _exit(1);
        }
        if (prevPipeFd[0] != -1)
            close(prevPipeFd[0]);
        if (prevPipeFd[1] != -1)
            close(prevPipeFd[1]);
        prevPipeFd[0] = currPipeFd[0];
        prevPipeFd[1] = currPipeFd[1];
        if (currPipeFd[1] != -1)
            close(currPipeFd[1]);
        cmdHead = cmdHead->next;
    }
    int status;
    while (wait(&status) > 0)
        ;
    return RET_OK;
}