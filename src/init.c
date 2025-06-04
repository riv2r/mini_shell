#include "init.h"
#include "builtin.h"

RET RegBuiltinCommand()
{
    RET ret = RET_OK;
    ret = addBuiltinCommand("exit", ExitHandler);
    ret = addBuiltinCommand("cd", CdHandler);
    return ret;
}

RET init()
{
    RET ret = RET_OK;
    ret = RegBuiltinCommand();
    return ret;
}