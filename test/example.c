#include <stdio.h>
#include <logger.h>

int main(int argc, char **args)
{
    int ret;

	logger(info, "test info");
	logger(debug, "test debug");
	logger(warm, "test warm");
	logger(err, "test err");
	
    return 0;        
}
