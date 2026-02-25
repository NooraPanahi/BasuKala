cmake_minimum_required(VERSION 3.10)

project(BasuKala)

include_directories(include)

set(SOURCES
    src/BasuKala.cpp
    src/main.cpp
    src/data_structures/Hash/UserHashTable.cpp
    src/data_structures/Stack/ItemStack.cpp
    src/data_structures/BST.cc
    #src/data_structures/graph.cc
    src/data_structures/max_heap.cc
    src/data_structures/OrderPriorityQueue.cc
    src/services/DeliveryService.cc
    src/services/ProductService.cpp
    src/Basket.cpp
    src/PurchaseHistory.cpp
    src/PurchaseService.cpp
    src/data_structures/Trie/Trie.cpp
)
add_executable(BasuKala ${SOURCES})



