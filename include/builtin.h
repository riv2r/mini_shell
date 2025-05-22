#ifndef BUILTIN_H
#define BUILTIN_H

#include "init.h"
#include "parser.h"
#include "uthash.h"

typedef void (*builtinCommandHandler)(const commandStru *cmd);
typedef struct
{
    char arg[MAX_CMD_LEN];
    builtinCommandHandler handler;
    UT_hash_handle hh;
} builtinCommandMap;

extern char builtinCommand[MAX_ARGS_NUM][MAX_CMD_LEN];
extern UINT8 builtinCommandNum;
extern builtinCommandMap *builtinCmdMap;

RET addBuiltinCommand(const char arg[MAX_CMD_LEN], builtinCommandHandler handler);
builtinCommandMap *IsBuiltinCommand(const commandStru *cmd);
void ExecuteBuiltinCommand(builtinCommandMap *item, const commandStru *cmd);

void ExitHandler(const commandStru *cmd);

#endif