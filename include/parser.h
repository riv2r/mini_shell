#ifndef PARSER_H
#define PARSER_H

#include "init.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ARGS_NUM 256

typedef struct
{
    UINT8 length;
    char *argv[MAX_ARGS_NUM];
} commandStru;

UINT8 ParserCommand(char *line, commandStru *cmd);

#endif