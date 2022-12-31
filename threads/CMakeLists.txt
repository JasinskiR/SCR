set(DEPENDENCIES_LIST crack)
set(HEADER_LIST inc/Threads.hpp)
set(SRC_LIST src/Threads.cpp)

add_library(threads STATIC ${SRC_LIST} ${HEADER_LIST})

target_include_directories(threads PUBLIC . inc src)

add_dependencies(threads ${DEPENDENCIES_LIST})
target_link_libraries(threads PUBLIC ${DEPENDENCIES_LIST})