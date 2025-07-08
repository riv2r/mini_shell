#ifndef PARSER_H
#define PARSER_H

#include "init.h"

#define MAX_ARGS_NUM 256
#define MAX_CMD_LEN 16

typedef struct commandStru
{
    UINT8 length;
    char *argv[MAX_ARGS_NUM];
    struct commandStru *next;
} commandStru;

RET ParserCommand(char *line, commandStru *cmd);

#endif