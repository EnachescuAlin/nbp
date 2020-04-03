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

#ifndef NBP_PRIVATE_API_MODULE_H
#define NBP_PRIVATE_API_MODULE_H

/*
 * TODO: add docs
 */
#define NBP_NO_SETUP_FUNC                                                      \
    nbp_empty_setup_func

/*
 * TODO: add docs
 */
#define NBP_SETUP_MODULE(func)                                                 \
    void NBP_PRIVATE_PP_CONCAT(nbp_setup_module_, func)(                       \
        NBP_MAYBE_UNUSED_PARAMETER nbp_module_details_t* module                \
    )

/*
 * TODO: add docs
 */
#define NBP_NO_TEARDOWN_FUNC                                                   \
    nbp_empty_teardown_func

/*
 * TODO: add docs
 */
#define NBP_TEARDOWN_MODULE(func)                                              \
    void NBP_PRIVATE_PP_CONCAT(nbp_teardown_module_, func)(                    \
        NBP_MAYBE_UNUSED_PARAMETER nbp_module_details_t* module                \
    )

#define NBP_PRIVATE_MODULE(func, name, setupFunc, teardownFunc)                \
    void NBP_PRIVATE_PP_CONCAT(nbp_module_, func)(                             \
        nbp_module_details_t*,                                                 \
        nbp_before_test_pfn_t,                                                 \
        nbp_after_test_pfn_t                                                   \
    );                                                                         \
    nbp_module_details_t NBP_PRIVATE_PP_CONCAT(nbpModuleDetails, func) = {     \
        .moduleName        = name,                                             \
        .moduleId          = 0,                                                \
        .moduleFunc        = NBP_PRIVATE_PP_CONCAT(nbp_module_, func),         \
        .parent            = NBP_NULL_POINTER,                                 \
        .setup             = setupFunc,                                        \
        .teardown          = teardownFunc,                                     \
        .firstTest         = NBP_NULL_POINTER,                                 \
        .lastTest          = NBP_NULL_POINTER,                                 \
        .firstModule       = NBP_NULL_POINTER,                                 \
        .lastModule        = NBP_NULL_POINTER,                                 \
        .next              = NBP_NULL_POINTER,                                 \
        .prev              = NBP_NULL_POINTER,                                 \
        .depth             = 0,                                                \
        .runEvent          = NBP_EVENT_DEFAULT_VALUE,                          \
        .setupEvent        = NBP_EVENT_DEFAULT_VALUE,                          \
        .flags             =                                                   \
            NBP_ATOMIC_UINT_INIT(NBP_MODULE_FLAGS_NOT_INITIALIZED),            \
        .moduleState       =                                                   \
            NBP_ATOMIC_UINT_INIT(NBP_MODULE_STATE_NOT_INITIALIZED),            \
        .taskNum           = NBP_ATOMIC_UINT_INIT(0),                          \
        .completedTaskNum  = NBP_ATOMIC_UINT_INIT(0),                          \
        .ownTests = {                                                          \
            .num           = NBP_ATOMIC_UINT_INIT(0),                          \
            .numPassed     = NBP_ATOMIC_UINT_INIT(0),                          \
            .numFailed     = NBP_ATOMIC_UINT_INIT(0),                          \
            .numSkipped    = NBP_ATOMIC_UINT_INIT(0),                          \
        },                                                                     \
        .subTests = {                                                          \
            .num           = NBP_ATOMIC_UINT_INIT(0),                          \
            .numPassed     = NBP_ATOMIC_UINT_INIT(0),                          \
            .numFailed     = NBP_ATOMIC_UINT_INIT(0),                          \
            .numSkipped    = NBP_ATOMIC_UINT_INIT(0),                          \
        },                                                                     \
        .ownModules = {                                                        \
            .num           = NBP_ATOMIC_UINT_INIT(0),                          \
            .numPassed     = NBP_ATOMIC_UINT_INIT(0),                          \
            .numFailed     = NBP_ATOMIC_UINT_INIT(0),                          \
            .numSkipped    = NBP_ATOMIC_UINT_INIT(0),                          \
        },                                                                     \
        .subModules = {                                                        \
            .num           = NBP_ATOMIC_UINT_INIT(0),                          \
            .numPassed     = NBP_ATOMIC_UINT_INIT(0),                          \
            .numFailed     = NBP_ATOMIC_UINT_INIT(0),                          \
            .numSkipped    = NBP_ATOMIC_UINT_INIT(0),                          \
        },                                                                     \
        .own = {                                                               \
            .checks = {                                                        \
                .numPassed = NBP_ATOMIC_UINT_INIT(0),                          \
                .numFailed = NBP_ATOMIC_UINT_INIT(0),                          \
            },                                                                 \
            .testAsserts = {                                                   \
                .numPassed = NBP_ATOMIC_UINT_INIT(0),                          \
                .numFailed = NBP_ATOMIC_UINT_INIT(0),                          \
            },                                                                 \
            .moduleAsserts = {                                                 \
                .numPassed = NBP_ATOMIC_UINT_INIT(0),                          \
                .numFailed = NBP_ATOMIC_UINT_INIT(0),                          \
            },                                                                 \
            .asserts = {                                                       \
                .numPassed = NBP_ATOMIC_UINT_INIT(0),                          \
                .numFailed = NBP_ATOMIC_UINT_INIT(0),                          \
            },                                                                 \
        },                                                                     \
        .sub = {                                                               \
            .checks = {                                                        \
                .numPassed = NBP_ATOMIC_UINT_INIT(0),                          \
                .numFailed = NBP_ATOMIC_UINT_INIT(0),                          \
            },                                                                 \
            .testAsserts = {                                                   \
                .numPassed = NBP_ATOMIC_UINT_INIT(0),                          \
                .numFailed = NBP_ATOMIC_UINT_INIT(0),                          \
            },                                                                 \
            .moduleAsserts = {                                                 \
                .numPassed = NBP_ATOMIC_UINT_INIT(0),                          \
                .numFailed = NBP_ATOMIC_UINT_INIT(0),                          \
            },                                                                 \
            .asserts = {                                                       \
                .numPassed = NBP_ATOMIC_UINT_INIT(0),                          \
                .numFailed = NBP_ATOMIC_UINT_INIT(0),                          \
            },                                                                 \
        },                                                                     \
    };                                                                         \
    void NBP_PRIVATE_PP_CONCAT(nbp_module_, func)(                             \
        NBP_MAYBE_UNUSED_PARAMETER nbp_module_details_t* module,               \
        NBP_MAYBE_UNUSED_PARAMETER nbp_before_test_pfn_t beforeTest,           \
        NBP_MAYBE_UNUSED_PARAMETER nbp_after_test_pfn_t afterTest              \
    )

/*
 * TODO: add docs
 */
#define NBP_MODULE_NAME(func, name)                                            \
    NBP_PRIVATE_MODULE(func, name, NBP_NULL_POINTER, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE(func)                                                       \
    NBP_MODULE_NAME(func, #func)

/*
 * TODO: add docs
 */
#define NBP_MODULE_NAME_FIXTURES(func, name, setupFunc, teardownFunc)          \
    NBP_SETUP_MODULE(setupFunc);                                               \
    NBP_TEARDOWN_MODULE(teardownFunc);                                         \
    NBP_PRIVATE_MODULE(                                                        \
        func,                                                                  \
        name,                                                                  \
        NBP_PRIVATE_PP_CONCAT(nbp_setup_module_, setupFunc),                   \
        NBP_PRIVATE_PP_CONCAT(nbp_teardown_module_, teardownFunc)              \
    )

/*
 * TODO: add docs
 */
#define NBP_MODULE_FIXTURES(func, setupFunc, teardownFunc)                     \
    NBP_MODULE_NAME_FIXTURES(func, #func, setupFunc, teardownFunc)

/*
 * TODO: add docs
 */
#define NBP_CALL_MODULE(func)                                                  \
    extern nbp_module_details_t NBP_PRIVATE_PP_CONCAT(nbpModuleDetails, func); \
    nbp_call_module(                                                           \
        & NBP_PRIVATE_PP_CONCAT(nbpModuleDetails, func),                       \
        module                                                                 \
    )

/*
 * TODO: add docs
 */
#define NBP_CALL_MODULE_CTX(func, ctx)                                         \
    extern nbp_module_details_t NBP_PRIVATE_PP_CONCAT(nbpModuleDetails, func); \
    nbp_call_module_ctx(                                                       \
        & NBP_PRIVATE_PP_CONCAT(nbpModuleDetails, func),                       \
        ctx,                                                                   \
        module                                                                 \
    )

/*
 * TODO: add docs
 */
#define NBP_INCLUDE_MODULE(func)                                               \
    extern nbp_module_details_t NBP_PRIVATE_PP_CONCAT(nbpModuleDetails, func);

/*
 * TODO: add docs
 */
#define NBP_GET_MODULE_PTR(func)                                               \
    & NBP_PRIVATE_PP_CONCAT(nbpModuleDetails, func)

/*
 * TODO: add docs
 */
#define NBP_THIS_MODULE module

/*
 * TODO: add docs
 */
#define NBP_GET_MODULE_NAME(module) module->moduleName

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_ID(module) module->moduleId

/*
 * TODO: add docs
 */
#define NBP_GET_MODULE_DEPTH(module) module->depth

/*
 * TODO: add docs
 */
#define NBP_GET_MODULE_STATE(module)                                           \
    NBP_ATOMIC_UINT_LOAD(&module->moduleState)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_STATE(module)                                           \
    NBP_ATOMIC_UINT_LOAD(&module->moduleState)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_OWN_TESTS_NUM(module)                                   \
    NBP_ATOMIC_UINT_LOAD(&module->ownTests.num)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_OWN_PASSED_TESTS_NUM(module)                            \
    NBP_ATOMIC_UINT_LOAD(&module->ownTests.numPassed)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_OWN_FAILED_TESTS_NUM(module)                            \
    NBP_ATOMIC_UINT_LOAD(&module->ownTests.numFailed)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_OWN_SKIPPED_TESTS_NUM(module)                           \
    NBP_ATOMIC_UINT_LOAD(&module->ownTests.numSkipped)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_SUBTESTS_NUM(module)                                    \
    NBP_ATOMIC_UINT_LOAD(&module->subTests.num)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_PASSED_SUBTESTS_NUM(module)                             \
    NBP_ATOMIC_UINT_LOAD(&module->subTests.numPassed)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_FAILED_SUBTESTS_NUM(module)                             \
    NBP_ATOMIC_UINT_LOAD(&module->subTests.numFailed)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_SKIPPED_SUBTESTS_NUM(module)                            \
    NBP_ATOMIC_UINT_LOAD(&module->subTests.numSkipped)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_TESTS_NUM(module)                                       \
    NBP_MODULE_GET_OWN_TESTS_NUM(module) +                                     \
    NBP_MODULE_GET_SUBTESTS_NUM(module)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_PASSED_TESTS_NUM(module)                                \
    NBP_MODULE_GET_OWN_PASSED_TESTS_NUM(module) +                              \
    NBP_MODULE_GET_PASSED_SUBTESTS_NUM(module)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_FAILED_TESTS_NUM(module)                                \
    NBP_MODULE_GET_OWN_FAILED_TESTS_NUM(module) +                              \
    NBP_MODULE_GET_FAILED_SUBTESTS_NUM(module)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_SKIPPED_TESTS_NUM(module)                               \
    NBP_MODULE_GET_OWN_SKIPPED_TESTS_NUM(module) +                             \
    NBP_MODULE_GET_SKIPPED_SUBTESTS_NUM(module)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_OWN_MODULES_NUM(module)                                 \
    NBP_ATOMIC_UINT_LOAD(&module->ownModules.num)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_OWN_PASSED_MODULES_NUM(module)                          \
    NBP_ATOMIC_UINT_LOAD(&module->ownModules.numPassed)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_OWN_FAILED_MODULES_NUM(module)                          \
    NBP_ATOMIC_UINT_LOAD(&module->ownModules.numFailed)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_OWN_SKIPPED_MODULES_NUM(module)                         \
    NBP_ATOMIC_UINT_LOAD(&module->ownModules.numSkipped)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_SUBMODULES_NUM(module)                                  \
    NBP_ATOMIC_UINT_LOAD(&module->subModules.num)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_PASSED_SUBMODULES_NUM(module)                           \
    NBP_ATOMIC_UINT_LOAD(&module->subModules.numPassed)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_FAILED_SUBMODULES_NUM(module)                           \
    NBP_ATOMIC_UINT_LOAD(&module->subModules.numFailed)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_SKIPPED_SUBMODULES_NUM(module)                          \
    NBP_ATOMIC_UINT_LOAD(&module->subModules.numSkipped)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_MODULES_NUM(module)                                     \
    NBP_MODULE_GET_OWN_MODULES_NUM(module) +                                   \
    NBP_MODULE_GET_SUBMODULES_NUM(module)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_PASSED_MODULES_NUM(module)                              \
    NBP_MODULE_GET_OWN_PASSED_MODULES_NUM(module) +                            \
    NBP_MODULE_GET_PASSED_SUBMODULES_NUM(module)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_FAILED_MODULES_NUM(module)                              \
    NBP_MODULE_GET_OWN_FAILED_MODULES_NUM(module) +                            \
    NBP_MODULE_GET_FAILED_SUBMODULES_NUM(module)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_SKIPPED_MODULES_NUM(module)                             \
    NBP_MODULE_GET_OWN_SKIPPED_MODULES_NUM(module) +                           \
    NBP_MODULE_GET_SKIPPED_SUBMODULES_NUM(module)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_OWN_CHECKS_NUM(module)                                  \
    NBP_MODULE_GET_OWN_PASSED_CHECKS_NUM(module) +                             \
    NBP_MODULE_GET_OWN_FAILED_CHECKS_NUM(module)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_OWN_PASSED_CHECKS_NUM(module)                           \
    NBP_ATOMIC_UINT_LOAD(&module->own.checks.numPassed)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_OWN_FAILED_CHECKS_NUM(module)                           \
    NBP_ATOMIC_UINT_LOAD(&module->own.checks.numFailed)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_SUB_CHECKS_NUM(module)                                  \
    NBP_MODULE_GET_SUB_PASSED_CHECKS_NUM(module) +                             \
    NBP_MODULE_GET_SUB_FAILED_CHECKS_NUM(module)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_SUB_PASSED_CHECKS_NUM(module)                           \
    NBP_ATOMIC_UINT_LOAD(&module->sub.checks.numPassed)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_SUB_FAILED_CHECKS_NUM(module)                           \
    NBP_ATOMIC_UINT_LOAD(&module->sub.checks.numFailed)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_CHECKS_NUM(module)                                      \
    NBP_MODULE_GET_PASSED_CHECKS_NUM(module) +                                 \
    NBP_MODULE_GET_FAILED_CHECKS_NUM(module)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_PASSED_CHECKS_NUM(module)                               \
    NBP_MODULE_GET_OWN_PASSED_CHECKS_NUM(module) +                             \
    NBP_MODULE_GET_SUB_PASSED_CHECKS_NUM(module)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_FAILED_CHECKS_NUM(module)                               \
    NBP_MODULE_GET_OWN_FAILED_CHECKS_NUM(module) +                             \
    NBP_MODULE_GET_SUB_FAILED_CHECKS_NUM(module)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_OWN_TEST_ASSERTS_NUM(module)                            \
    NBP_MODULE_GET_OWN_PASSED_TEST_ASSERTS_NUM(module) +                       \
    NBP_MODULE_GET_OWN_FAILED_TEST_ASSERTS_NUM(module)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_OWN_PASSED_TEST_ASSERTS_NUM(module)                     \
    NBP_ATOMIC_UINT_LOAD(&module->own.testAsserts.numPassed)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_OWN_FAILED_TEST_ASSERTS_NUM(module)                     \
    NBP_ATOMIC_UINT_LOAD(&module->own.testAsserts.numFailed)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_SUB_TEST_ASSERTS_NUM(module)                            \
    NBP_MODULE_GET_SUB_PASSED_TEST_ASSERTS_NUM(module) +                       \
    NBP_MODULE_GET_SUB_FAILED_TEST_ASSERTS_NUM(module)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_SUB_PASSED_TEST_ASSERTS_NUM(module)                     \
    NBP_ATOMIC_UINT_LOAD(&module->sub.testAsserts.numPassed)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_SUB_FAILED_TEST_ASSERTS_NUM(module)                     \
    NBP_ATOMIC_UINT_LOAD(&module->sub.testAsserts.numFailed)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_TEST_ASSERTS_NUM(module)                                \
    NBP_MODULE_GET_PASSED_TEST_ASSERTS_NUM(module) +                           \
    NBP_MODULE_GET_FAILED_TEST_ASSERTS_NUM(module)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_PASSED_TEST_ASSERTS_NUM(module)                         \
    NBP_MODULE_GET_OWN_PASSED_TEST_ASSERTS_NUM(module) +                       \
    NBP_MODULE_GET_SUB_PASSED_TEST_ASSERTS_NUM(module)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_FAILED_TEST_ASSERTS_NUM(module)                         \
    NBP_MODULE_GET_OWN_FAILED_TEST_ASSERTS_NUM(module) +                       \
    NBP_MODULE_GET_SUB_FAILED_TEST_ASSERTS_NUM(module)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_OWN_MODULE_ASSERTS_NUM(module)                          \
    NBP_MODULE_GET_OWN_PASSED_MODULE_ASSERTS_NUM(module) +                     \
    NBP_MODULE_GET_OWN_FAILED_MODULE_ASSERTS_NUM(module)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_OWN_PASSED_MODULE_ASSERTS_NUM(module)                   \
    NBP_ATOMIC_UINT_LOAD(&module->own.moduleAsserts.numPassed)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_OWN_FAILED_MODULE_ASSERTS_NUM(module)                   \
    NBP_ATOMIC_UINT_LOAD(&module->own.moduleAsserts.numFailed)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_SUB_MODULE_ASSERTS_NUM(module)                          \
    NBP_MODULE_GET_SUB_PASSED_MODULE_ASSERTS_NUM(module) +                     \
    NBP_MODULE_GET_SUB_FAILED_MODULE_ASSERTS_NUM(module)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_SUB_PASSED_MODULE_ASSERTS_NUM(module)                   \
    NBP_ATOMIC_UINT_LOAD(&module->sub.moduleAsserts.numPassed)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_SUB_FAILED_MODULE_ASSERTS_NUM(module)                   \
    NBP_ATOMIC_UINT_LOAD(&module->sub.moduleAsserts.numFailed)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_MODULE_ASSERTS_NUM(module)                              \
    NBP_MODULE_GET_PASSED_MODULE_ASSERTS_NUM(module) +                         \
    NBP_MODULE_GET_FAILED_MODULE_ASSERTS_NUM(module)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_PASSED_MODULE_ASSERTS_NUM(module)                       \
    NBP_MODULE_GET_OWN_PASSED_MODULE_ASSERTS_NUM(module) +                     \
    NBP_MODULE_GET_SUB_PASSED_MODULE_ASSERTS_NUM(module)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_FAILED_MODULE_ASSERTS_NUM(module)                       \
    NBP_MODULE_GET_OWN_FAILED_MODULE_ASSERTS_NUM(module) +                     \
    NBP_MODULE_GET_SUB_FAILED_MODULE_ASSERTS_NUM(module)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_OWN_ASSERTS_NUM(module)                                 \
    NBP_MODULE_GET_OWN_PASSED_ASSERTS_NUM(module) +                            \
    NBP_MODULE_GET_OWN_FAILED_ASSERTS_NUM(module)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_OWN_PASSED_ASSERTS_NUM(module)                          \
    NBP_ATOMIC_UINT_LOAD(&module->own.asserts.numPassed)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_OWN_FAILED_ASSERTS_NUM(module)                          \
    NBP_ATOMIC_UINT_LOAD(&module->own.asserts.numFailed)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_SUB_ASSERTS_NUM(module)                                 \
    NBP_MODULE_GET_SUB_PASSED_ASSERTS_NUM(module) +                            \
    NBP_MODULE_GET_SUB_FAILED_ASSERTS_NUM(module)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_SUB_PASSED_ASSERTS_NUM(module)                          \
    NBP_ATOMIC_UINT_LOAD(&module->sub.asserts.numPassed)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_SUB_FAILED_ASSERTS_NUM(module)                          \
    NBP_ATOMIC_UINT_LOAD(&module->sub.asserts.numFailed)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_ASSERTS_NUM(module)                                     \
    NBP_MODULE_GET_PASSED_ASSERTS_NUM(module) +                                \
    NBP_MODULE_GET_FAILED_ASSERTS_NUM(module)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_PASSED_ASSERTS_NUM(module)                              \
    NBP_MODULE_GET_OWN_PASSED_ASSERTS_NUM(module) +                            \
    NBP_MODULE_GET_SUB_PASSED_ASSERTS_NUM(module)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_FAILED_ASSERTS_NUM(module)                              \
    NBP_MODULE_GET_OWN_FAILED_ASSERTS_NUM(module) +                            \
    NBP_MODULE_GET_SUB_FAILED_ASSERTS_NUM(module)

#endif // end if NBP_PRIVATE_API_MODULE_H
