#include "init.h"
#include "utils.h"
#include "builtin.h"

RET GetSortedBuiltinCommand()
{
    qsort(builtinCommand, builtinCommandNum, MAX_CMD_LEN, CmpStr);
    return builtinCommand != NULL ? RET_OK : RET_ERROR;
}

RET init()
{
    RET ret = RET_OK;
    ret = GetSortedBuiltinCommand();
    return ret;
}