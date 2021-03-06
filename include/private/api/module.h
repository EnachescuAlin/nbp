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

#ifndef NBP_PRIVATE_API_MODULE_H
#define NBP_PRIVATE_API_MODULE_H

/*
 * TODO: add docs
 */
#define NBP_MODULE_SETUP(func)                                                 \
    void NBP_PP_CONCAT(nbp_module_setup_, func)(                               \
        NBP_MAYBE_UNUSED_PARAMETER nbp_module_details_t* nbpParamModule        \
    )

/*
 * TODO: add docs
 */
#define NBP_MODULE_USE_SETUP(func)                                             \
    NBP_MODULE_SETUP(func);                                                    \
    nbpParamModuleSetup = NBP_PP_CONCAT(nbp_module_setup_, func)

/*
 * TODO: add docs
 */
#define NBP_MODULE_RESET_SETUP()                                               \
    nbpParamModuleSetup = NBP_MEMORY_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_MODULE_TEARDOWN(func)                                              \
    void NBP_PP_CONCAT(nbp_module_teardown_, func)(                            \
        NBP_MAYBE_UNUSED_PARAMETER nbp_module_details_t* nbpParamModule        \
    )

/*
 * TODO: add docs
 */
#define NBP_MODULE_USE_TEARDOWN(func)                                          \
    NBP_MODULE_TEARDOWN(func);                                                 \
    nbpParamModuleTeardown = NBP_PP_CONCAT(nbp_module_teardown_, func)

/*
 * TODO: add docs
 */
#define NBP_MODULE_RESET_TEARDOWN()                                            \
    nbpParamModuleTeardown = NBP_MEMORY_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_MODULE(func, ...)                                                  \
    void NBP_PP_CONCAT(nbp_module_config_, func)(                              \
        NBP_MAYBE_UNUSED_PARAMETER nbp_module_details_t* nbpParamModule        \
    )                                                                          \
    {                                                                          \
        NBP_MODULE_PRIVATE_GENERATE_CONFIG(P_ ## __VA_ARGS__)                  \
    }                                                                          \
    NBP_MODULE_PRIVATE_BASE(func)

/*
 * TODO: add docs
 */
#define NBP_MODULE_NAME(name)

/*
 * TODO: add docs
 */
#define NBP_MODULE_FIXTURES(setupFunc, teardownFunc)

/*
 * TODO: add docs
 */
#define NBP_MODULE_RUN(func)                                                   \
    extern nbp_module_details_t NBP_PP_CONCAT(nbpModuleDetails, func);         \
    nbp_module_run(                                                            \
        & NBP_PP_CONCAT(nbpModuleDetails, func),                               \
        nbpParamModule,                                                        \
        nbpParamModuleSetup,                                                   \
        nbpParamModuleTeardown                                                 \
    )

/*
 * TODO: add docs
 */
#define NBP_MODULE_RUN_CTX(func, ctx)                                          \
    extern nbp_module_details_t NBP_PP_CONCAT(nbpModuleDetails, func);         \
    NBP_PRIVATE_SCHEDULER_PREPROCESSING_CONTEXT(P_ ## ctx)                     \
    nbp_module_run_ctx(                                                        \
        & NBP_PP_CONCAT(nbpModuleDetails, func),                               \
        ctx,                                                                   \
        nbpParamModule,                                                        \
        nbpParamModuleSetup,                                                   \
        nbpParamModuleTeardown                                                 \
    )

/*
 * TODO: add docs
 */
#define NBP_MODULE_INCLUDE(func)                                               \
    extern nbp_module_details_t NBP_PP_CONCAT(nbpModuleDetails, func);

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_PTR(func)                                               \
    & NBP_PP_CONCAT(nbpModuleDetails, func)

/*
 * TODO: add docs
 */
#define NBP_MODULE_FOR_EACH_TEST(module, it)                                   \
    for (it = module->firstTest; it != NBP_MEMORY_NULL_POINTER; it = it->next)

/*
 * TODO: add docs
 */
#define NBP_MODULE_FOR_EACH_SUBMODULE(module, it)                              \
    for (it = module->firstModule; it != NBP_MEMORY_NULL_POINTER; it = it->next)

/*
 * TODO: add docs
 */
#define NBP_MODULE_THIS nbpParamModule

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_PARENT(module) module->parent

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_NAME(module) module->moduleName

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_ID(module) module->moduleId

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_DEPTH(module) module->depth

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_STATE(module)                                           \
    NBP_SYNC_ATOMIC_UINT_LOAD(&module->moduleState)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_NUMBER_OF_TESTS(module)                                 \
    NBP_SYNC_ATOMIC_UINT_LOAD(&module->tests.num)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_NUMBER_OF_PASSED_TESTS(module)                          \
    NBP_SYNC_ATOMIC_UINT_LOAD(&module->tests.numPassed)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_NUMBER_OF_FAILED_TESTS(module)                          \
    NBP_SYNC_ATOMIC_UINT_LOAD(&module->tests.numFailed)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_NUMBER_OF_SKIPPED_TESTS(module)                         \
    NBP_SYNC_ATOMIC_UINT_LOAD(&module->tests.numSkipped)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_NUMBER_OF_MODULES(module)                               \
    NBP_SYNC_ATOMIC_UINT_LOAD(&module->modules.num)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_NUMBER_OF_PASSED_MODULES(module)                        \
    NBP_SYNC_ATOMIC_UINT_LOAD(&module->modules.numPassed)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_NUMBER_OF_FAILED_MODULES(module)                        \
    NBP_SYNC_ATOMIC_UINT_LOAD(&module->modules.numFailed)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_NUMBER_OF_SKIPPED_MODULES(module)                       \
    NBP_SYNC_ATOMIC_UINT_LOAD(&module->modules.numSkipped)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_NUMBER_OF_ASSERTS(module, assertType)                   \
    NBP_MODULE_GET_NUMBER_OF_PASSED_ASSERTS(module, assertType) +              \
    NBP_MODULE_GET_NUMBER_OF_FAILED_ASSERTS(module, assertType)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_NUMBER_OF_PASSED_ASSERTS(module, assertType)            \
    nbp_module_get_number_of_asserts(                                          \
        module,                                                                \
        NBP_ASSERT_STATUS_PASSED,                                              \
        assertType                                                             \
    )

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_NUMBER_OF_FAILED_ASSERTS(module, assertType)            \
    nbp_module_get_number_of_asserts(                                          \
        module,                                                                \
        NBP_ASSERT_STATUS_FAILED,                                              \
        assertType                                                             \
    )

#define NBP_MODULE_PRIVATE_GENERATE_CONFIG(...)                                \
    NBP_PP_CONCAT(                                                             \
        NBP_PP_PROCESSING_PARAM_,                                              \
        NBP_PP_VARCOUNT(P ## __VA_ARGS__)                                      \
    )(P ## __VA_ARGS__)

#define NBP_PP_EAT_PP_NBP_MODULE_NAME(name)                                    \
    nbpParamModule->moduleName = name;
#define NBP_PP_EAT_PP_NBP_MODULE_SETUP(setup)                                  \
    NBP_MODULE_SETUP(setup);                                                   \
    nbpParamModule->setupFunc = NBP_PP_CONCAT(nbp_module_setup_, setup);
#define NBP_PP_EAT_PP_NBP_MODULE_TEARDOWN(teardown)                            \
    NBP_MODULE_TEARDOWN(teardown);                                             \
    nbpParamModule->teardownFunc =                                             \
        NBP_PP_CONCAT(nbp_module_teardown_, teardown);
#define NBP_PP_EAT_PP_NBP_MODULE_FIXTURES(setup, teardown)                     \
    NBP_PP_EAT_PP_NBP_MODULE_SETUP(setup)                                      \
    NBP_PP_EAT_PP_NBP_MODULE_TEARDOWN(teardown)

#define NBP_MODULE_PRIVATE_BASE(func)                                          \
    void NBP_PP_CONCAT(nbp_module_, func)(                                     \
        nbp_module_details_t*,                                                 \
        nbp_module_setup_pfn_t,                                                \
        nbp_module_teardown_pfn_t,                                             \
        nbp_test_setup_pfn_t,                                                  \
        nbp_test_teardown_pfn_t                                                \
    );                                                                         \
    nbp_module_details_t NBP_PP_CONCAT(nbpModuleDetails, func) = {             \
        .moduleName             = #func,                                       \
        .moduleId               = 0,                                           \
        .moduleFunc             = NBP_PP_CONCAT(nbp_module_, func),            \
        .configFunc             = NBP_PP_CONCAT(nbp_module_config_, func),     \
        .parent                 = NBP_MEMORY_NULL_POINTER,                     \
        .setupFunc              = NBP_MEMORY_NULL_POINTER,                     \
        .teardownFunc           = NBP_MEMORY_NULL_POINTER,                     \
        .firstTest              = NBP_MEMORY_NULL_POINTER,                     \
        .lastTest               = NBP_MEMORY_NULL_POINTER,                     \
        .firstModule            = NBP_MEMORY_NULL_POINTER,                     \
        .lastModule             = NBP_MEMORY_NULL_POINTER,                     \
        .next                   = NBP_MEMORY_NULL_POINTER,                     \
        .prev                   = NBP_MEMORY_NULL_POINTER,                     \
        .depth                  = 0,                                           \
        .runEvent               = NBP_SYNC_EVENT_DEFAULT_VALUE,                \
        .setupEvent             = NBP_SYNC_EVENT_DEFAULT_VALUE,                \
        .isSkipped              =                                              \
            NBP_SYNC_ATOMIC_UINT_INIT(NBP_MODULE_PRIVATE_SKIP_NOT_SET),        \
        .moduleState            =                                              \
            NBP_SYNC_ATOMIC_UINT_INIT(NBP_MODULE_STATE_NOT_INITIALIZED),       \
        .taskNum                = 0,                                           \
        .completedTaskNum       = NBP_SYNC_ATOMIC_UINT_INIT(0),                \
        .isEmptyModule          = 1,                                           \
        .emptySubmodulesNum     = 0,                                           \
        .tests = {                                                             \
            .num                = 0,                                           \
            .numPassed          = NBP_SYNC_ATOMIC_UINT_INIT(0),                \
            .numFailed          = NBP_SYNC_ATOMIC_UINT_INIT(0),                \
            .numSkipped         = NBP_SYNC_ATOMIC_UINT_INIT(0),                \
        },                                                                     \
        .modules = {                                                           \
            .num                = 0,                                           \
            .numPassed          = NBP_SYNC_ATOMIC_UINT_INIT(0),                \
            .numFailed          = NBP_SYNC_ATOMIC_UINT_INIT(0),                \
            .numSkipped         = NBP_SYNC_ATOMIC_UINT_INIT(0),                \
        },                                                                     \
        .asserts = {                                                           \
            .nonFatal = {                                                      \
                .numPassed      = NBP_SYNC_ATOMIC_UINT_INIT(0),                \
                .numFailed      = NBP_SYNC_ATOMIC_UINT_INIT(0),                \
            },                                                                 \
            .fatal = {                                                         \
                .numPassed      = NBP_SYNC_ATOMIC_UINT_INIT(0),                \
                .numFailed      = NBP_SYNC_ATOMIC_UINT_INIT(0),                \
            },                                                                 \
            .fatalForTest = {                                                  \
                .numPassed      = NBP_SYNC_ATOMIC_UINT_INIT(0),                \
                .numFailed      = NBP_SYNC_ATOMIC_UINT_INIT(0),                \
            },                                                                 \
            .fatalForModule = {                                                \
                .numPassed      = NBP_SYNC_ATOMIC_UINT_INIT(0),                \
                .numFailed      = NBP_SYNC_ATOMIC_UINT_INIT(0),                \
            },                                                                 \
        },                                                                     \
    };                                                                         \
    void NBP_PP_CONCAT(nbp_module_, func)(                                     \
        NBP_MAYBE_UNUSED_PARAMETER nbp_module_details_t* nbpParamModule,       \
        NBP_MAYBE_UNUSED_PARAMETER nbp_module_setup_pfn_t nbpParamModuleSetup, \
        NBP_MAYBE_UNUSED_PARAMETER                                             \
            nbp_module_teardown_pfn_t nbpParamModuleTeardown,                  \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_setup_pfn_t nbpParamTestSetup,     \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_teardown_pfn_t nbpParamTestTeardown\
    )

#endif // end if NBP_PRIVATE_API_MODULE_H
