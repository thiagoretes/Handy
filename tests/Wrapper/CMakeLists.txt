if(COMPILER_SUPPORTS_CXX14)
    get_filename_component(PARENT_DIR ${PROJECT_SOURCE_DIR} DIRECTORY)

    include_directories(${GTEST_INCLUDE_DIRS} ${PARENT_DIR}/include)

    file(GLOB WRAPPER_SRC_FILES ${PROJECT_SOURCE_DIR}/Wrapper/*.cpp)

    set(TEST_SRC_FILES ${TEST_SRC_FILES} ${WRAPPER_SRC_FILES})
endif()