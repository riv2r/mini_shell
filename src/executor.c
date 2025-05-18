#include "executor.h"
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

void ExecuteCommand(const commandStru *cmd)
{
    pid_t pid = fork();
    if (pid < 0)
    {
        perror("fork");
        return;
    }
    if (pid == 0)
    {
        execvp(cmd->argv[0], cmd->argv);
        perror("execvp failed");
        _exit(1);
    }
    else
    {
        waitpid(pid, NULL, 0);
    }
}