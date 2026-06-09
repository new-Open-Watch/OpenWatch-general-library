add_library(owgl STATIC
    src/FS.cpp
)

target_include_directories(owgl PUBLIC include)

target_link_libraries(owgl PUBLIC idf::esp_log)