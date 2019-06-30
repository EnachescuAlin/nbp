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

unsigned int get_uint()
{
    return 2U;
}

volatile unsigned int uint_min = 0;
volatile unsigned int uint_max = UINT_MAX;
volatile unsigned int uint_ = 2U;

NBP_TEST(check_uint_eq)
{
    SAMPLE_SLEEP();
    NBP_CHECK_UINT_EQ(get_uint(), uint_);
    NBP_CHECK_UINT_EQ_FAIL_MSG(get_uint(), uint_, "check failed");
    NBP_CHECK_UINT_EQ_PASS_MSG(get_uint(), uint_, "check passed");
    NBP_CHECK_UINT_EQ_MSG(get_uint(), uint_, "check failed", "check passed");
}

NBP_TEST(check_uint_ne)
{
    SAMPLE_SLEEP();
    NBP_CHECK_UINT_NE(get_uint(), uint_min);
    NBP_CHECK_UINT_NE_FAIL_MSG(get_uint(), uint_min, "check failed");
    NBP_CHECK_UINT_NE_PASS_MSG(get_uint(), uint_min, "check passed");
    NBP_CHECK_UINT_NE_MSG(get_uint(), uint_min, "check failed", "check passed");
}

NBP_TEST(check_uint_gt)
{
    SAMPLE_SLEEP();
    NBP_CHECK_UINT_GT(get_uint(), uint_min);
    NBP_CHECK_UINT_GT_FAIL_MSG(get_uint(), uint_min, "check failed");
    NBP_CHECK_UINT_GT_PASS_MSG(get_uint(), uint_min, "check passed");
    NBP_CHECK_UINT_GT_MSG(get_uint(), uint_min, "check failed", "check passed");
}

NBP_TEST(check_uint_ge)
{
    SAMPLE_SLEEP();
    NBP_CHECK_UINT_GE(get_uint(), uint_min);
    NBP_CHECK_UINT_GE_FAIL_MSG(get_uint(), uint_, "check failed");
    NBP_CHECK_UINT_GE_PASS_MSG(get_uint(), uint_min, "check passed");
    NBP_CHECK_UINT_GE_MSG(get_uint(), uint_, "check failed", "check passed");
}

NBP_TEST(check_uint_lt)
{
    SAMPLE_SLEEP();
    NBP_CHECK_UINT_LT(get_uint(), uint_max);
    NBP_CHECK_UINT_LT_FAIL_MSG(get_uint(), uint_max, "check failed");
    NBP_CHECK_UINT_LT_PASS_MSG(get_uint(), uint_max, "check passed");
    NBP_CHECK_UINT_LT_MSG(get_uint(), uint_max, "check failed", "check passed");
}

NBP_TEST(check_uint_le)
{
    SAMPLE_SLEEP();
    NBP_CHECK_UINT_LE(get_uint(), uint_max);
    NBP_CHECK_UINT_LE_FAIL_MSG(get_uint(), uint_, "check failed");
    NBP_CHECK_UINT_LE_PASS_MSG(get_uint(), uint_max, "check passed");
    NBP_CHECK_UINT_LE_MSG(get_uint(), uint_, "check failed", "check passed");
}

NBP_MODULE(check_uint)
{
    NBP_CALL_TEST(check_uint_eq);
    NBP_CALL_TEST(check_uint_ne);
    NBP_CALL_TEST(check_uint_gt);
    NBP_CALL_TEST(check_uint_ge);
    NBP_CALL_TEST(check_uint_lt);
    NBP_CALL_TEST(check_uint_le);
}