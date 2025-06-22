#include "builtin.h"
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char builtinCommand[MAX_ARGS_NUM][MAX_CMD_LEN] = {
    "cd",
    "exit",
    "pwd",
    "echo"};

UINT8 builtinCommandNum = 4;

builtinCommandMap *builtinCmdMap = NULL;

RET addBuiltinCommand(const char *arg, builtinCommandHandler handler)
{
    builtinCommandMap *temp = malloc(sizeof(builtinCommandMap));
    strncpy(temp->arg, arg, MAX_CMD_LEN - 1);
    temp->handler = handler;
    HASH_ADD_STR(builtinCmdMap, arg, temp);
    return temp != NULL ? RET_OK : RET_ERROR;
}

builtinCommandMap *IsBuiltinCommand(const commandStru *cmd)
{
    builtinCommandMap *temp = NULL;
    HASH_FIND_STR(builtinCmdMap, cmd->argv[0], temp);
    return temp;
}

RET ExecuteBuiltinCommand(builtinCommandMap *item, const commandStru *cmd)
{
    return item->handler(cmd);
}

RET ExitHandler(const commandStru *cmd)
{
    exit(0);
    return RET_OK;
}

RET CdHandler(const commandStru *cmd)
{
    const char *path = cmd->argv[1] ? cmd->argv[1] : getenv("HOME");
    printf("%s\n", path);
    if (chdir(path) != 0)
    {
        perror("cd");
        return RET_ERROR;
    }
    return RET_OK;
}

RET PwdHandler(const commandStru *cmd)
{
    char *path = getcwd(NULL, 0);
    if (path != NULL)
    {
        printf("%s\n", path);
        free(path);
    }
    else
    {
        perror("pwd");
        return RET_ERROR;
    }
    return RET_OK;
}

RET EchoHandler(const commandStru *cmd)
{
    if (cmd->length > 1)
    {
        for (UINT8 i = 1; i < cmd->length; ++i)
        {
            printf("%s", cmd->argv[i]);
            printf(i == cmd->length - 1 ? "\n" : " ");
        }
    }
    return RET_OK;
}