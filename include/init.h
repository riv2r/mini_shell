#ifndef INIT_H
#define INIT_H

#include <stdbool.h>

#define RET_OK 1
#define RET_ERROR 0

typedef bool RET;
typedef unsigned char UINT8;
typedef unsigned short UINT16;

RET init();
RET GetSortedBuiltinCommand();

#endif