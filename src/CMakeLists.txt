set(build_switcher_SRCS
    build_switcher.cpp
)

ecm_qt_declare_logging_category(build_switcher_SRCS
    HEADER debug.h
    IDENTIFIER PLUGIN_BUILD_SWITCHER
    CATEGORY_NAME "kdevelop.plugins.build_switcher"
)

kdevplatform_add_plugin(build_switcher
    JSON build_switcher.json
    SOURCES ${build_switcher_SRCS}
)

target_link_libraries(build_switcher
    KDev::Interfaces
)

target_include_directories(build_switcher
PRIVATE
    ${CMAKE_BINARY_DIR}
)
