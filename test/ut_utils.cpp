#include <gtest/gtest.h>

#include <iostream>

#include "init.h"
#include "utils.h"

#include "parser.h"

void UTUtils_CmpStr_Expect(char strArr[][MAX_CMD_LEN])
{
    EXPECT_STREQ(strArr[0], "cd");
    EXPECT_STREQ(strArr[1], "echo");
    EXPECT_STREQ(strArr[2], "exit");
    EXPECT_STREQ(strArr[3], "pwd");
}

TEST(UTUtils, UTUtils_CmpStr)
{
    char strArr[][MAX_CMD_LEN] = {"cd", "exit", "pwd", "echo"};
    UINT8 sz = sizeof(strArr) / sizeof(strArr[0]);
    qsort(strArr, sz, MAX_CMD_LEN, CmpStr);
    UTUtils_CmpStr_Expect(strArr);
}