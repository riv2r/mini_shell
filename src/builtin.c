#include "builtin.h"
#include "utils.h"

char builtinCommand[MAX_ARGS_NUM][MAX_CMD_LEN] = {
    "cd",
    "exit",
    "pwd",
    "echo"};

UINT8 builtinCommandNum = 4;

builtinCommandMap *builtinCmdMap = NULL;

RET addBuiltinCommand(const char arg[MAX_CMD_LEN], builtinCommandHandler handler)
{
    builtinCommandMap *temp = malloc(sizeof(builtinCommandMap));
    strncpy(temp->arg, arg, MAX_CMD_LEN);
    temp->handler = handler;
    HASH_ADD_KEYPTR(hh, builtinCmdMap, temp->arg, strlen(temp->arg), temp);
    return temp != NULL ? RET_OK : RET_ERROR;
}

builtinCommandMap *IsBuiltinCommand(const commandStru *cmd)
{
    builtinCommandMap *temp = NULL;
    HASH_FIND_STR(builtinCmdMap, cmd->argv[0], temp);
    return temp;
}

void ExecuteBuiltinCommand(builtinCommandMap *item, const commandStru *cmd)
{
    item->handler(cmd);
}

void ExitHandler(const commandStru *cmd)
{
    exit(0);
}