#include "builtin.h"
#include "utils.h"

char builtinCommand[MAX_ARGS_NUM][MAX_CMD_LEN] = {
    "cd",
    "exit",
    "pwd",
    "echo"};

UINT8 builtinCommandNum = 4;

builtinCommandMap builtinCmdMap[MAX_ARGS_NUM] = {
    {"exit", ExitHandler}};

RET IsBuiltinCommand(const char command[MAX_CMD_LEN])
{
    char *ret = bsearch(command, builtinCommand, builtinCommandNum, MAX_CMD_LEN, CmpStr);
    return ret != NULL ? RET_OK : RET_ERROR;
}

RET ExecuteBuiltinCommand(const commandStru *cmd)
{
    for (UINT8 i = 0; i < builtinCommandNum; ++i)
    {
        if (strcmp(builtinCmdMap[i].arg, cmd->argv[0]) == 0)
        {
            builtinCmdMap[i].handler(cmd);
        }
    }
    return RET_OK;
}

void ExitHandler(const commandStru *cmd)
{
    exit(0);
}