cmake_minimum_required(VERSION 2.8)
project(freeopcua-test CXX)


set (EXE_NAME freeopcua-test-server)

include_directories(${PROJECT_SOURCE_DIR}/include)
aux_source_directory(src SRC_LIST)

add_library (freeopcuatest src/analogitem.cpp
                           src/basedatavariable.cpp
                           src/baseobject.cpp
                           src/dataitem.cpp
                           src/node.cpp
                           src/nodemanager.cpp
                           src/objecttype.cpp
                           src/opcserver.cpp
                           src/property.cpp
                           src/reference.cpp
                           src/typednode.cpp
                           src/typenode.cpp
                           src/variable.cpp)

add_executable(${EXE_NAME} src/main.cpp
                           src/nmtemperature.cpp
                           src/temperaturesensor.cpp) 
find_library(LIBOPCUASERVER opcuaserver)
find_library(LIBOPCUACORE opcuacore)
find_library(LIBOPCUAPROTOCOL opcuaprotocol)

target_compile_options(${EXE_NAME} PRIVATE "-std=c++11")
target_compile_options(freeopcuatest PRIVATE "-std=c++11")
target_link_libraries(${EXE_NAME} ${LIBOPCUASERVER}
                                  ${LIBOPCUACORE}
                                  ${LIBOPCUAPROTOCOL}
                                  freeopcuatest)

