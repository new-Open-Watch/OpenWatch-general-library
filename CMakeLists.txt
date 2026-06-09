add_library(owgl STATIC
    src/FS.cpp
)
if(ESP_PLATFORM)
    idf_component_register()
endif()
target_include_directories(owgl PUBLIC include)