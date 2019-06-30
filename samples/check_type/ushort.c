/*
No Bugs in Production (NBP)
Copyright (C) 2019-present Alin Enachescu

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <nbp.h>

#include "../sample_utils.h"

#include <limits.h>

unsigned short int get_ushort()
{
    return 2;
}

volatile unsigned short int ush_min = 0;
volatile unsigned short int ush_max = USHRT_MAX;
volatile unsigned short int ush = 2;

NBP_TEST(check_ushort_eq)
{
    SAMPLE_SLEEP();
    NBP_CHECK_USHORT_EQ(get_ushort(), ush);
    NBP_CHECK_USHORT_EQ_FAIL_MSG(get_ushort(), ush, "check failed");
    NBP_CHECK_USHORT_EQ_PASS_MSG(get_ushort(), ush, "check passed");
    NBP_CHECK_USHORT_EQ_MSG(get_ushort(), ush, "check failed", "check passed");
}

NBP_TEST(check_ushort_ne)
{
    SAMPLE_SLEEP();
    NBP_CHECK_USHORT_NE(get_ushort(), ush_min);
    NBP_CHECK_USHORT_NE_FAIL_MSG(get_ushort(), ush_min, "check failed");
    NBP_CHECK_USHORT_NE_PASS_MSG(get_ushort(), ush_min, "check passed");
    NBP_CHECK_USHORT_NE_MSG(get_ushort(), ush_min, "check failed", "check passed");
}

NBP_TEST(check_ushort_gt)
{
    SAMPLE_SLEEP();
    NBP_CHECK_USHORT_GT(get_ushort(), ush_min);
    NBP_CHECK_USHORT_GT_FAIL_MSG(get_ushort(), ush_min, "check failed");
    NBP_CHECK_USHORT_GT_PASS_MSG(get_ushort(), ush_min, "check passed");
    NBP_CHECK_USHORT_GT_MSG(get_ushort(), ush_min, "check failed", "check passed");
}

NBP_TEST(check_ushort_ge)
{
    SAMPLE_SLEEP();
    NBP_CHECK_USHORT_GE(get_ushort(), ush_min);
    NBP_CHECK_USHORT_GE_FAIL_MSG(get_ushort(), ush, "check failed");
    NBP_CHECK_USHORT_GE_PASS_MSG(get_ushort(), ush_min, "check passed");
    NBP_CHECK_USHORT_GE_MSG(get_ushort(), ush, "check failed", "check passed");
}

NBP_TEST(check_ushort_lt)
{
    SAMPLE_SLEEP();
    NBP_CHECK_USHORT_LT(get_ushort(), ush_max);
    NBP_CHECK_USHORT_LT_FAIL_MSG(get_ushort(), ush_max, "check failed");
    NBP_CHECK_USHORT_LT_PASS_MSG(get_ushort(), ush_max, "check passed");
    NBP_CHECK_USHORT_LT_MSG(get_ushort(), ush_max, "check failed", "check passed");
}

NBP_TEST(check_ushort_le)
{
    SAMPLE_SLEEP();
    NBP_CHECK_USHORT_LE(get_ushort(), ush_max);
    NBP_CHECK_USHORT_LE_FAIL_MSG(get_ushort(), ush, "check failed");
    NBP_CHECK_USHORT_LE_PASS_MSG(get_ushort(), ush_max, "check passed");
    NBP_CHECK_USHORT_LE_MSG(get_ushort(), ush, "check failed", "check passed");
}

NBP_MODULE(check_ushort)
{
    NBP_CALL_TEST(check_ushort_eq);
    NBP_CALL_TEST(check_ushort_ne);
    NBP_CALL_TEST(check_ushort_gt);
    NBP_CALL_TEST(check_ushort_ge);
    NBP_CALL_TEST(check_ushort_lt);
    NBP_CALL_TEST(check_ushort_le);
}