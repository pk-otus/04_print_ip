cmake_minimum_required(VERSION 3.2)

if (DEFINED ENV{TRAVIS_BUILD_NUMBER})
   project(print_ip VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})
else()
   project(print_ip VERSION 0.0.1)
endif()

configure_file(version.h.in ${PROJECT_SOURCE_DIR}/version.h)

add_executable(print_ip main.cpp)

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
	set_target_properties(print_ip PROPERTIES
		CXX_STANDARD 14
		CXX_STANDARD_REQUIRED ON
		COMPILE_OPTIONS -Wpedantic -Wall -Wextra
	)
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
	set_target_properties(print_ip PROPERTIES
		CXX_STANDARD 14
		CXX_STANDARD_REQUIRED ON
		COMPILE_OPTIONS -W3 
	)
endif()

install(TARGETS print_ip RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT vvz.otus@gmail.com)

include (CPack)

