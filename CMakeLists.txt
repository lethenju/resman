cmake_minimum_required (VERSION 3.9)
project (resman VERSION 1.0.0 DESCRIPTION "A simple resource manager in C")

#[[ Building Library ]]

include(GNUInstallDirs)

set(CMAKE_BUILD_TYPE Debug)


set(LIBRARY_HEADER_FILES
	src/resman_types.h
)

set(LIBRARY_SOURCE_FILES
	src/resman.c
)


add_library(resman STATIC
	${LIBRARY_HEADER_FILES}
	${LIBRARY_SOURCE_FILES}
)

target_link_libraries(resman
	${ALL_LIBS}
)	

set_target_properties(resman PROPERTIES VERSION ${PROJECT_VERSION})
set_target_properties(resman PROPERTIES PUBLIC_HEADER inc/resman.h)

target_include_directories(resman PRIVATE inc)
target_include_directories(resman PRIVATE src)

install(TARGETS resman
	  	ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    	LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    	PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})



#[[ Building Tests ]]

	#[[ Compiling Main ]]

set(TESTS_SOURCE_FILES
	test/main.c
)

set(TESTS_INCLUDE_FILE
	inc/resman.h
)

add_executable(test_exe
	${TESTS_INCLUDE_FILE}
	${TESTS_SOURCE_FILES}
)

target_link_libraries(test_exe
	resman
)	
