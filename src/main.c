#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "init.h"
#include "utils.h"
#include "parser.h"
#include "builtin.h"
#include "executor.h"

int main(int argc, char const *argv[])
{
    if (!init())
    {
        perror("initialize");
        return 0;
    }

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

        commandStru *cmd = NULL;
        if (ParserCommand(line, &cmd) && cmd->length)
        {
            builtinCommandMap *temp = IsBuiltinCommand(cmd);
            if (temp)
            {
                ExecuteBuiltinCommand(temp, cmd);
            }
            else
            {
                ExecuteCommand(cmd);
            }
        }

        free(cmd);
    }

    free(line);
    return 0;
}
