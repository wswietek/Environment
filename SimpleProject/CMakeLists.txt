set(TARGET_NAME SimpleProject)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

set(PROJECT_SOURCES
    SimpleProject.cpp
)

set(PROJECT_HEADERS
    SimpleProject.hpp
				HelloWorld.hpp
)

add_library(${TARGET_NAME} STATIC ${PROJECT_SOURCES} ${PROJECT_HEADERS})
target_link_libraries(${TARGET_NAME} Messaging)

enable_testing()
set(TEST_SOURCES
    ut/TestSimpleProject.cpp
)
set(MOCK_LIST
    ut/mocks/MockScheduler.hpp
)

set(UT_DRIVER ${TARGET_NAME}_UT)
add_executable(${UT_DRIVER} ${TEST_SOURCES} ${MOCK_LIST})
target_link_libraries(${UT_DRIVER} ${TARGET_NAME} gtest_main gmock)

if (BUILD_COVERAGE_UNIT_TESTS)
    set_target_properties(${TARGET_NAME} PROPERTIES COMPILE_FLAGS ${CMAKE_CXX_FLAGS_COVERAGE})
    set_target_properties(${UT_DRIVER} PROPERTIES COMPILE_FLAGS ${CMAKE_CXX_FLAGS_COVERAGE})
    target_link_libraries(${UT_DRIVER} ${CMAKE_CXX_COVERAGE_LIBRARY})
    setup_target_for_coverage(${UT_DRIVER}_COV ${UT_DRIVER} ${COVERAGE_REPORT_LOCATION})
endif()