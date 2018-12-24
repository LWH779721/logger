#include <stdio.h>
#include "logger.h"

int main(int argc, char **args)
{		
	logger(info, "test info");
	//logger(debug, "test debug");
	//logger(warm, "test warm");
	int a = 123;
	logger(err, "test err %d", a);
	
    return 0;        
}
