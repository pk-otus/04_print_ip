cmake_minimum_required(VERSION 3.2)

if (DEFINED ENV{TRAVIS_BUILD_NUMBER})
   project(print_ip VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})
else()
   project(print_ip VERSION 0.0.1)
endif()

add_executable(print_ip main.cpp)

set_target_properties(print_ip PROPERTIES
	CXX_STANDARD 14
	CXX_STANDARD_REQUIRED ON
)

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
	set_target_properties(print_ip PROPERTIES COMPILE_OPTIONS -W3)
else()
	set_target_properties(print_ip PROPERTIES COMPILE_OPTIONS -Wpedantic -Wall -Wextra)
endif()

install(TARGETS print_ip RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT a@a.a)

include (CPack)

