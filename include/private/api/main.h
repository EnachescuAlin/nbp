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

#ifndef NBP_PRIVATE_API_MAIN_H
#define NBP_PRIVATE_API_MAIN_H

#ifdef NBP_LIBRARY_MAIN

#define NBP_PRIVATE_MAIN_MODULE(name, scheduler, printers, setupFunc,          \
    teardownFunc)                                                              \
    void name(                                                                 \
        nbp_module_details_t*,                                                 \
        nbp_before_test_pfn_t,                                                 \
        nbp_after_test_pfn_t                                                   \
    );                                                                         \
    extern nbp_module_details_t nbpModuleDetails ## name;                      \
    nbp_module_details_t* nbpMainModule = & nbpModuleDetails ## name;          \
    nbp_scheduler_interface_t* nbpSchedulerInterface = &scheduler;             \
    nbp_printer_interface_t* nbpPrinterInterfaces[] = printers;                \
    unsigned int nbpPrinterInterfacesSize =                                    \
        sizeof(nbpPrinterInterfaces) / sizeof(nbpPrinterInterfaces[0]);        \
    NBP_MODULE_FIXTURES(name, setupFunc, teardownFunc)

/*
 * TODO: add docs
 */
#define NBP_MAIN_MODULE(name)                                                  \
    NBP_PRIVATE_MAIN_MODULE(                                                   \
        name,                                                                  \
        nbpScheduler,                                                          \
        { &nbpPrinter },                                                       \
        nbp_empty_setup_func,                                                  \
        nbp_empty_teardown_func                                                \
    )

/*
 * TODO: add docs
 */
#define NBP_MAIN_MODULE_FIXTURES(name, setupFunc, teardownFunc)                \
    NBP_PRIVATE_MAIN_MODULE(                                                   \
        name,                                                                  \
        nbpScheduler,                                                          \
        { &nbpPrinter },                                                       \
        setupFunc,                                                             \
        teardownFunc                                                           \
    )

#endif // end if NBP_LIBRARY_MAIN

#endif // end if NBP_PRIVATE_API_MAIN_H