cmake_minimum_required(VERSION 3.14.5)
project (aspartame-config LANGUAGES CXX)

include(${CMAKE_CURRENT_SOURCE_DIR}/deps/cpp-sugiyama-waller/sugiyama.cmake)
sugiyama_no_indir()

add_subdirectory(deps/cpp-sugiyama-waller)

file(GLOB_RECURSE hdrs LIST_DIRECTORIES true CONFIGURE_DEPENDS src/aspartame/*.h)
file(GLOB_RECURSE srcs LIST_DIRECTORIES true CONFIGURE_DEPENDS src/aspartame/*.cc)
add_library(${PROJECT_NAME} STATIC ${srcs})
target_sources(${PROJECT_NAME} INTERFACE ${hdrs})
target_include_directories(${PROJECT_NAME} PUBLIC src)
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)

## Deps: sugiyama-waller
target_link_libraries(${PROJECT_NAME} PUBLIC sugiyama-waller)
