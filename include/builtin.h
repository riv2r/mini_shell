#ifndef BUILTIN_H
#define BUILTIN_H

#include "parser.h"
#include <stdbool.h>

const char builtinCommand[][MAX_CMD_LEN] = {
    "cd",
    "exit"};

bool IsBuiltinCommand(const commandStru *cmd);
UINT8 ExecuteBuiltinCommand(const commandStru *cmd);

#endif