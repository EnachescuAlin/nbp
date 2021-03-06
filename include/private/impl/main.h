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

#ifndef NBP_PRIVATE_IMPL_MAIN_H
#define NBP_PRIVATE_IMPL_MAIN_H

extern nbp_module_details_t* nbpMainModule;
extern nbp_scheduler_interface_t* nbpSchedulerInterface;

int nbpSchedulerRunEnabled;

int nbp_string_equal(const char* a, const char* b)
{
    while (*a == *b && *a != '\0') {
        a++;
        b++;
    }

    return *a != *b ? 0 : 1;
}

int nbp_command_run_all()
{
    nbpSchedulerRunEnabled = 0;

    nbp_printer_notify_init();
    nbp_scheduler_notify_init();

    if (nbpSchedulerInterface->runCbk == NBP_MEMORY_NULL_POINTER) {
        NBP_ERROR_REPORT(NBP_ERROR_CODE_INVALID_SCHEDULER);
        NBP_EXIT(NBP_ERROR_CODE_INVALID_SCHEDULER);
    }

    nbp_module_run(
        nbpMainModule,
        NBP_MEMORY_NULL_POINTER,
        NBP_MEMORY_NULL_POINTER,
        NBP_MEMORY_NULL_POINTER
    );

    nbp_printer_notify_before_run(nbpMainModule);

    nbpSchedulerRunEnabled = 1;
    nbp_scheduler_notify_run();
    nbpSchedulerRunEnabled = 0;

    extern NBP_SYNC_ATOMIC_UINT_TYPE nbpNumberOfRunTests;
    extern unsigned int nbpTotalNumberOfTests;

    if (NBP_SYNC_ATOMIC_UINT_LOAD(&nbpNumberOfRunTests) != nbpTotalNumberOfTests) {
        NBP_ERROR_REPORT(NBP_ERROR_CODE_NOT_ALL_TESTS_RUN);
        NBP_EXIT(NBP_ERROR_CODE_NOT_ALL_TESTS_RUN);
    }

    if (nbpMainModule->isEmptyModule == 1) {
        nbp_scheduler_complete_empty_module(nbpMainModule);
    }

    nbp_printer_notify_after_run(nbpMainModule);

    nbp_scheduler_notify_uninit();
    nbp_printer_notify_uninit();

    if (NBP_MODULE_GET_STATE(nbpMainModule) == NBP_MODULE_STATE_PASSED) {
        return NBP_ERROR_CODE_SUCCESS;
    }

    return NBP_ERROR_CODE_TESTS_FAILED;
}

int nbp_command_version()
{
    nbp_printer_notify_init();
    nbp_printer_notify_handle_version_command();
    nbp_printer_notify_uninit();

    return NBP_ERROR_CODE_SUCCESS;
}

int main(int argc, const char** argv)
{
    if (argc < 1) {
        return NBP_ERROR_CODE_INVALID_CMDLINE;
    }

    if (argc == 1) {
        return nbp_command_run_all();
    }

    if (nbp_string_equal(argv[1], "--version") == 1) {
        return nbp_command_version();
    }

    return NBP_ERROR_CODE_INVALID_CMDLINE;
}

#endif // end if NBP_PRIVATE_IMPL_MAIN_H
