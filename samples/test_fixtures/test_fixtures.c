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

NBP_TEST_SETUP(my_test_setup1)
{
    write_message_to_file_2(
        "my_test_setup1",
        NBP_GET_TEST_NAME(NBP_THIS_TEST)
    );
}

NBP_TEST_SETUP(my_test_setup2)
{
    write_message_to_file_2(
        "my_test_setup2",
        NBP_GET_TEST_NAME(NBP_THIS_TEST)
    );
}

NBP_TEST_TEARDOWN(my_test_teardown1)
{
    write_message_to_file_2(
        "my_test_teardown1",
        NBP_GET_TEST_NAME(NBP_THIS_TEST)
    );
}

NBP_TEST_TEARDOWN(my_test_teardown2)
{
    write_message_to_file_2(
        "my_test_teardown2",
        NBP_GET_TEST_NAME(NBP_THIS_TEST)
    );
}