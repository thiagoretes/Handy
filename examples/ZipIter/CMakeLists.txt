if(COMPILER_SUPPORTS_CXX14)
    file(GLOB ZIP_ITER_SRC_FILES ${PROJECT_SOURCE_DIR}/ZipIter/*.cpp)
    set(EXAMPLE_SRC_FILES ${EXAMPLE_SRC_FILES} ${ZIP_ITER_SRC_FILES})
endif()