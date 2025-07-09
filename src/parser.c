#include "parser.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

RET ParserSingleCommand(char *line, commandStru *cmd)
{
    if (line == NULL || cmd == NULL)
        return RET_ERROR;
    UINT8 i = 0;
    char *token, *savePtr;
    token = strtok_r(line, " ", &savePtr);
    if (!token)
    {
        perror("command format fault");
        return RET_ERROR;
    }
    while (i < MAX_ARGS_NUM - 1 && token != NULL)
    {
        cmd->argv[i++] = token;
        token = strtok_r(NULL, " ", &savePtr);
    }
    cmd->argv[i] = NULL;
    cmd->length = i;
    cmd->next = NULL;
    return RET_OK;
}

RET ParserCommand(char *line, commandStru **cmdHead)
{
    if (line == NULL || cmdHead == NULL)
        return RET_ERROR;
    char *token, *savePtr;
    token = strtok_r(line, "|", &savePtr);
    if (!token)
    {
        perror("command format fault");
        return RET_ERROR;
    }
    commandStru *cur = NULL;
    while (token != NULL)
    {
        commandStru *node = (commandStru *)malloc(sizeof(commandStru));
        if (node == NULL)
            return RET_ERROR;
        if (ParserSingleCommand(token, node) != RET_OK)
        {
            free(node);
            return RET_ERROR;
        }
        if (*cmdHead == NULL)
        {
            *cmdHead = node;
        }
        else
        {
            cur->next = node;
        }
        cur = node;
        token = strtok_r(NULL, "|", &savePtr);
    }
    return RET_OK;
}