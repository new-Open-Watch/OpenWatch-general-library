cmake_minimum_required(VERSION 3.16)
idf_component_register(
    SRCS "${owgl_SOURCE_DIR}/src/FS.cpp"
    INCLUDE_DIRS "${owgl_SOURCE_DIR}/include"
)