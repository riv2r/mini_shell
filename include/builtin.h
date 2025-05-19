#ifndef BUILTIN_H
#define BUILTIN_H

#include "init.h"
#include "parser.h"

extern char builtinCommand[MAX_ARGS_NUM][MAX_CMD_LEN];
extern UINT8 builtinCommandNum;

typedef void (*builtinCommandHandler)(const commandStru *cmd);
typedef struct
{
    const char arg[MAX_CMD_LEN];
    builtinCommandHandler handler;
} builtinCommandMap;

extern builtinCommandMap builtinCmdMap[MAX_ARGS_NUM];

RET IsBuiltinCommand(const char command[MAX_CMD_LEN]);
RET ExecuteBuiltinCommand(const commandStru *cmd);

void ExitHandler(const commandStru *cmd);

#endif