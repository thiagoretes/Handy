if(COMPILER_SUPPORTS_CXX14)
    get_filename_component(PARENT_DIR ${PROJECT_SOURCE_DIR} DIRECTORY)

    include_directories(${GTEST_INCLUDE_DIRS} ${PARENT_DIR}/include)

    file(GLOB ZIP_ITER_SRC_FILES ${PROJECT_SOURCE_DIR}/ZipIter/*.cpp)

    set(TEST_SRC_FILES ${TEST_SRC_FILES} ${ZIP_ITER_SRC_FILES})
endif()