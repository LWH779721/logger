#ifndef __FORMAT_CODE_INFO_H__
#define __FORMAT_CODE_INFO_H__

#ifdef __cplusplus
extern "C"{
#endif

/*
*  tip: none and all is not for custom use, It's for logger use to close or open all print 
*/
#define NONE  	0   
#define INFO  	1
#define DEBUG 	2
#define WARM  	3
#define ERROR   4
#define ALL   	5

enum log_level {
	none,   
	info,
	debug,
	warm,
	err,
	all
};

#ifdef __cplusplus
}
#endif
#endif