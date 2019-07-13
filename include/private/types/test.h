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

#ifndef NBP_PRIVATE_TYPES_TEST_H
#define NBP_PRIVATE_TYPES_TEST_H

#define NBP_TEST_STATE_NOT_INITIALIZED  0
#define NBP_TEST_STATE_READY            1
#define NBP_TEST_STATE_RUNNING          2
#define NBP_TEST_STATE_PASSED           3
#define NBP_TEST_STATE_FAILED           4
#define NBP_TEST_STATE_SKIPPED          5

struct nbp_test_details_t;

typedef void (*nbp_before_test_pfn_t)(
    struct nbp_test_details_t* /* current test */
);

typedef void (*nbp_after_test_pfn_t)(
    struct nbp_test_details_t* /* current test */
);

typedef void (*nbp_test_pfn_t)(
    struct nbp_test_details_t* /* current test */
);

struct nbp_test_details_t {
    const char* testName;
    nbp_test_pfn_t testFunc;
    struct nbp_module_details_t* module;

    nbp_before_test_pfn_t beforeTestFunc;
    nbp_after_test_pfn_t afterTestFunc;

    struct nbp_test_details_t* next;
    struct nbp_test_details_t* prev;

    unsigned int testState;

    struct {
        unsigned int numPassed;
        unsigned int numFailed;
    } checks, testAsserts, moduleAsserts, asserts;
};
typedef struct nbp_test_details_t nbp_test_details_t;

#endif // end if NBP_PRIVATE_TYPES_TEST_H
