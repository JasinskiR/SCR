set(HEADER_LIST inc/Data.hpp inc/Hash.hpp inc/PasswdCrack.hpp)
set(SRC_LIST src/Data.cpp src/Hash.cpp src/PasswdCrack.cpp)

add_library(crack STATIC ${SRC_LIST} ${HEADER_LIST})

target_include_directories(crack PUBLIC . inc src)