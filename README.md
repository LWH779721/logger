# logger
日志模块

# features
1. log time is millers

# compile
* use cmake for compile
* 使用程序在cmakelist.txt 加上 ADD_DEFINITIONS(-DLOGGER_COMPILE_LEVEL=ERROR)，设置编译后的打印等级，
小于该等级的打印会被替换成空语句，用来减小程序体积
