cmake_minimum_required(VERSION 3.11)

project(Exam CXX)

set(CMAKE_CXX_STANDARD 23)

if(MSVC)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS true)

    if(CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
        string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")   
    else()
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
    endif()
endif()

add_library(Exam SHARED 
     "include/list.h"
     "src/list.cc"
     "include/search.h"
     "src/search.cc"
     "include/stack.h"
     "src/stack.cc" 
     "include/gueue.h"
     "src/queue.cc"
     "include/sort.h"
     "src/sort.cc" 
     "include/tree.h"
     "src/tree.cc")
target_include_directories(Exam PUBLIC "include")

add_executable(main "main.cc" "include/stack.h" "include/gueue.h" "include/sort.h" "include/tree.h")
target_link_libraries(main Exam)