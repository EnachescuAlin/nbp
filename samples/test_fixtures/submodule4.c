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

NBP_TEST(test13)
{
    SAMPLE_SLEEP();
    NBP_CHECK(1);
}

NBP_TEST(test14)
{
    SAMPLE_SLEEP();
    NBP_CHECK(2);
}

NBP_TEST(test15)
{
    SAMPLE_SLEEP();
    NBP_CHECK(3);
}

NBP_TEST(test16)
{
    SAMPLE_SLEEP();
    NBP_CHECK(4);
}

NBP_MODULE(submodule4)
{
    NBP_TEST_USE_TEARDOWN(submodule4_test_teardown1);
    NBP_CALL_TEST(test13);

    NBP_TEST_RESET_TEARDOWN();
    NBP_CALL_TEST(test14);

    NBP_TEST_USE_TEARDOWN(submodule4_test_teardown2);
    NBP_CALL_TEST(test15);
    NBP_CALL_TEST(test16);
}
