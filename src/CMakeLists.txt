INCLUDE_DIRECTORIES(/usr/include/glib) 
INCLUDE_DIRECTORIES(../include)

AUX_SOURCE_DIRECTORY(. LOGGER)
AUX_SOURCE_DIRECTORY(output OUTPUT)
AUX_SOURCE_DIRECTORY(format FORMAT)

ADD_LIBRARY (logger SHARED ${LOGGER} ${OUTPUT} ${FORMAT})
ADD_LIBRARY (logger_static STATIC ${LOGGER} ${OUTPUT} ${FORMAT})

# 指定静态库的输出名称
set_target_properties(logger_static PROPERTIES OUTPUT_NAME "logger")
# 使动态库和静态库同时存在
set_target_properties(logger PROPERTIES CLEAN_DIRECT_OUTPUT 1)
set_target_properties(logger_static PROPERTIES CLEAN_DIRECT_OUTPUT 1)
 
# 指定动态库版本
# VERSION 动态库版本
# SOVERSION API版本
set_target_properties(logger PROPERTIES VERSION 1.0 SOVERSION 1)