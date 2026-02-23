cmake_minimum_required(VERSION 3.10)

project(BasuKala)

include_directories(include)

set(SOURCES
    src/main.cpp
    src/data_structures/Hash/UserHashTable.cpp
    src/data_structures/Stack/ItemStack.cpp
    src/Basket.cpp
    src/PurchaseHistory.cpp
    src/PurchaseService.cpp
    src/data_structures/Trie/Trie.cpp
)
add_executable(BasuKala ${SOURCES})
