#include <stdio.h>
#include <mlog.h>

int main(int argc, char **args)
{
    int i;
    
    mlog_err("test err");
    mlog_warm("test warm");
    mlog_info("test info");
    
    return 0;        
}
