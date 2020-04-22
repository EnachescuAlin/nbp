include("${CMAKE_SOURCE_DIR}/CustomFlags.cmake")

# Samples list
list(APPEND SAMPLES basic
	modules
	submodules
	modules_one_file
	submodules_one_file
	main_module_fixtures
	main_module_fixtures_one_file
	main_module_setup
	main_module_setup_one_file
	main_module_teardown
	main_module_teardown_one_file
	module_fixtures
	module_fixtures_one_file
	test_fixtures
	test_fixtures_one_file
	check
	test_and_module
	test_and_module_fixtures
	test_and_module_name
	check_type
	check_operator
	assert_type
	test_assert_type
	module_assert_type
	assert_operator
	test_assert_operator
	module_assert_operator
	test_assert
	module_assert
	assert
	mt_scheduler_basic
	mt_scheduler_module_fixtures_ran_only_once
	mt_scheduler_run_test_fixtures_in_parallel
	mt_scheduler_run_module_fixtures_in_parallel
	empty_modules
)

# Custom flags lists for targets
list(APPEND SAMPLES_CFLAGS ""
    ""
    ""
    ""
    ""
    ""
    ""
    ""
    ""
    ""
    ""
    ""
    ""
    ""
    ""
    ""
    ""
    ""
    ""
    ""
    ""
    ""
    ""
    ""
    ""
    ""
    ""
    ""
    ""
    ""
    ${MT_SCHEDULER_FLAGS}
    ${MT_SCHEDULER_FLAGS}
    ${MT_SCHEDULER_FLAGS}
    ${MT_SCHEDULER_FLAGS}
    ""
)

list (APPEND SAMPLES_LFLAGS ""
    ""
    ""
    ""
    ""
    ""
    ""
    ""
    ""
    ""
    ""
    ""
    ""
    ""
    ""
    ""
    ""
    ""
    ""
    ""
    ""
    ""
    ""
    ""
    ""
    ""
    ""
    ""
    ""
    ""
    ${MT_SCHEDULER_LINK_FLAGS}
    ${MT_SCHEDULER_LINK_FLAGS}
    ${MT_SCHEDULER_LINK_FLAGS}
    ${MT_SCHEDULER_LINK_FLAGS}
    ""
)
