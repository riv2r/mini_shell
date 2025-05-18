#ifndef BUILTIN_H
#define BUILTIN_H

#include "init.h"
#include "parser.h"

extern char builtinCommand[MAX_ARGS_NUM][MAX_CMD_LEN];
extern UINT8 builtinCommandNum;

RET IsBuiltinCommand(const char command[MAX_CMD_LEN]);
RET ExecuteBuiltinCommand(const commandStru *cmd);

#endif