#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "init.h"
#include "parser.h"
#include "executor.h"

int main(int argc, char const *argv[])
{
    char *line = NULL;
    size_t len = 0;

    while (1)
    {
        printf("mini_shell$ ");
        fflush(stdout);

        len = getline(&line, &len, stdin);
        if (len == -1)
        {
            perror("getline");
            break;
        }

        if (line[len - 1] == '\n')
        {
            line[len - 1] = '\0';
        }

        if (strcmp(line, "exit") == 0)
        {
            break;
        }

        commandStru *cmd = (commandStru *)malloc(sizeof(commandStru));
        if (!ParserCommand(line, cmd) && cmd->length)
        {
            ExecuteCommand(cmd);
        }
        for (UINT8 i = 0; i < cmd->length; i++)
        {
            printf("%s ", cmd->argv[i]);
        }
        printf("\n");

        free(cmd);
    }

    free(line);
    return 0;
}
