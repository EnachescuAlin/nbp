/*
No Bugs in Production (NBP)
https://github.com/aenachescu/nbp

Licensed under the MIT License <http://opensource.org/licenses/MIT>.
SPDX-License-Identifier: MIT
Copyright (c) 2019-2020 Alin Enachescu <https://github.com/aenachescu>

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#ifndef NBP_PRIVATE_SCHEDULER_BASIC_SCHEDULER_H
#define NBP_PRIVATE_SCHEDULER_BASIC_SCHEDULER_H

#ifdef NBP_LIBRARY_MAIN

struct nbp_basic_scheduler_data_t {
    nbp_test_details_t* test;
    struct nbp_basic_scheduler_data_t* next;
};
typedef struct nbp_basic_scheduler_data_t nbp_basic_scheduler_data_t;

static nbp_basic_scheduler_data_t nbpBasicSchedulerData;
static nbp_basic_scheduler_data_t* nbpBasicSchedulerDataLast;

NBP_SCHEDULER_CALLBACK_INIT(nbp_basic_scheduler_init)
{
    nbpBasicSchedulerData.test = NBP_MEMORY_NULL_POINTER;
    nbpBasicSchedulerData.next = NBP_MEMORY_NULL_POINTER;
    nbpBasicSchedulerDataLast = &nbpBasicSchedulerData;
}

NBP_SCHEDULER_CALLBACK_UNINIT(nbp_basic_scheduler_uninit)
{
    nbp_basic_scheduler_data_t* data = nbpBasicSchedulerData.next;
    nbp_basic_scheduler_data_t* tmp = NBP_MEMORY_NULL_POINTER;
    while (data != NBP_MEMORY_NULL_POINTER) {
        tmp = data;
        data = data->next;
        NBP_MEMORY_FREE(tmp);
    }
}

NBP_SCHEDULER_CALLBACK_RUN(nbp_basic_scheduler_run)
{
    nbp_basic_scheduler_data_t* data = &nbpBasicSchedulerData;
    while (data->test != NBP_MEMORY_NULL_POINTER) {
        NBP_SCHEDULER_RUN_TEST(data->test);
        data = data->next;
    }
}

NBP_SCHEDULER_CALLBACK_RUN_TEST(nbp_basic_scheduler_run_test)
{
    nbpBasicSchedulerDataLast->test = NBP_TEST_THIS;
    nbpBasicSchedulerDataLast->next = (nbp_basic_scheduler_data_t*)
        NBP_MEMORY_ALLOC(sizeof(nbp_basic_scheduler_data_t));

    if (nbpBasicSchedulerDataLast->next == NBP_MEMORY_NULL_POINTER) {
        // these lines are excluded from coverage because it is pretty hard
        // to trigger an error for memory allocation.
        // LCOV_EXCL_START
        NBP_ERROR_REPORT_CTX_STRING(
            NBP_ERROR_CODE_OUT_OF_MEMORY,
            "could not add test"
        );
        return;
        // LCOV_EXCL_STOP
    }

    nbpBasicSchedulerDataLast = nbpBasicSchedulerDataLast->next;
    nbpBasicSchedulerDataLast->next = NBP_MEMORY_NULL_POINTER;
    nbpBasicSchedulerDataLast->test = NBP_MEMORY_NULL_POINTER;
}

NBP_SCHEDULER(
    nbpBasicScheduler,
    NBP_SCHEDULER_CALLBACKS(
        NBP_SCHEDULER_CALLBACK_INIT(nbp_basic_scheduler_init),
        NBP_SCHEDULER_CALLBACK_UNINIT(nbp_basic_scheduler_uninit),
        NBP_SCHEDULER_CALLBACK_RUN(nbp_basic_scheduler_run),
        NBP_SCHEDULER_CALLBACK_RUN_TEST(nbp_basic_scheduler_run_test)
    )
);

#endif // end if NBP_LIBRARY_MAIN

#endif // end if NBP_PRIVATE_SCHEDULER_BASIC_SCHEDULER_H
