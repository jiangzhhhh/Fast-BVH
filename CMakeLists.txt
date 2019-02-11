cmake_minimum_required (VERSION 3.6)

# 指定项目名称
project (RayTracerTest)

# 添加源码搜索目录
aux_source_directory(${CMAKE_SOURCE_DIR} SOURCE_FILES)

# 改变执行文件目录
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

# Enable C++11
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 11)

# Enable OMP
FIND_PACKAGE( OpenMP REQUIRED)
if(OPENMP_FOUND)
	message("OPENMP FOUND")
	set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
	set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -msse -msse2 -msse3")
