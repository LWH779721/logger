# logger
日志模块

# 需求
1. 打印等级机制
* 编译时可以设置打印等级，小于该等级的打印会被替换成空语句，用来减小程序体积 
2. log time is millers

# 编译
## 编译 logger 库
* 使用 cmake 编译
```
在代码根目录下执行：
mkdir build
cd build
cmake ..
make
Tips:生成的库在 build/src/ 下
```

## 使用 logger 库
* 编译时需要设置打印等级，默认是打印所有
```
例如：
使用cmake 编译，需要在cmakelist.txt 加上 
ADD_DEFINITIONS(-DLOGGER_COMPILE_LEVEL=ERROR)
```
* 编译需要使用到include下的头文件和生成的库