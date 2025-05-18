#include "builtin.h"
#include "utils.h"

char builtinCommand[MAX_ARGS_NUM][MAX_CMD_LEN] = {
    "cd",
    "exit",
    "pwd",
    "echo"};

UINT8 builtinCommandNum = 4;

RET IsBuiltinCommand(const char command[MAX_CMD_LEN])
{
    char *ret = bsearch(command, builtinCommand, builtinCommandNum, MAX_CMD_LEN, CmpStr);
    return ret != NULL ? RET_OK : RET_ERROR;
}

RET ExecuteBuiltinCommand(const commandStru *cmd)
{
    return RET_OK;
}