#cmake最低版本需求，不加入此行会受到警告信息
CMAKE_MINIMUM_REQUIRED(VERSION 3.1)

#cmake rpath
#SET(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE) 
#SET(CMAKE_INSTALL_RPATH ../lib/wf/lib)
PROJECT(test) #项目名称

#头文件
include_directories(.)
#库头文件


#源文件
aux_source_directory(. SRC_LIST)

#库源文件
#库目录
#link_directories(../lib/opencv/lib)


#编译标志
#set(CMAKE_CXX_FLAGS "${CAMKE_CXX_FLAGS} -std=c++14 -pthread -fopenmp")
set(CMAKE_CXX_FLAGS "${CAMKE_CXX_FLAGS} -std=c++14")

#生成应用程序 hello
add_executable(test ${SRC_LIST})
#库文件
#target_link_libraries(device camera opencv_core opencv_imgproc tbb zmq)
target_link_libraries(test)



