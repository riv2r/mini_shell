#ifndef BUILTIN_H
#define BUILTIN_H

#include "init.h"
#include "parser.h"
#include "uthash.h"

typedef RET (*builtinCommandHandler)(const commandStru *cmd);
typedef struct
{
    char arg[MAX_CMD_LEN];
    builtinCommandHandler handler;
    UT_hash_handle hh;
} builtinCommandMap;

extern char builtinCommand[MAX_ARGS_NUM][MAX_CMD_LEN];
extern UINT8 builtinCommandNum;
extern builtinCommandMap *builtinCmdMap;
extern char **environ;

RET addBuiltinCommand(const char *arg, builtinCommandHandler handler);
builtinCommandMap *IsBuiltinCommand(const commandStru *cmd);
RET ExecuteBuiltinCommand(builtinCommandMap *item, const commandStru *cmd);

RET ExitHandler(const commandStru *cmd);
RET CdHandler(const commandStru *cmd);
RET PwdHandler(const commandStru *cmd);
RET EchoHandler(const commandStru *cmd);
RET ExportHandler(const commandStru *cmd);

#endif