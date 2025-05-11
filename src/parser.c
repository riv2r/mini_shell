#include "parser.h"

UINT8 ParserCommand(char *line, commandStru *cmd)
{
    UINT8 i = 0;
    char *token = strtok(line, " ");
    if (!token)
    {
        perror("command format fault");
        return 1;
    }
    while (i < MAX_ARGS_NUM - 1 && token != NULL)
    {
        cmd->argv[i++] = token;
        token = strtok(NULL, " ");
    }
    cmd->argv[i] = NULL;
    cmd->length = i;
    return 0;
}