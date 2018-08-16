#cmake_minimum_required(VERSION 2.8)  

#PROJECT(logger)  

ADD_SUBDIRECTORY(output)
AUX_SOURCE_DIRECTORY(. DIR_SRCS)

INCLUDE_DIRECTORIES(/usr/include/glib) 
INCLUDE_DIRECTORIES(../include) 

ADD_LIBRARY (logger ${DIR_SRCS})
 


#ADD_EXECUTABLE(hello ${DIR_SRCS})  
