#include "init.h"
#include "utils.h"
#include "builtin.h"

RET RegBuiltinCommand()
{
    RET ret = RET_OK;
    ret = addBuiltinCommand("exit", ExitHandler);
    return ret;
}

RET init()
{
    RET ret = RET_OK;
    ret = RegBuiltinCommand();
    return ret;
}