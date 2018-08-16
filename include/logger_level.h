#ifndef __FORMAT_CODE_INFO_H__
#define __FORMAT_CODE_INFO_H__

#ifdef __cplusplus
extern "C"{
#endif

#define INFO  0
#define DEBUG 1
#define WARM  2
#define ERR   3
#define ALL   4

enum log_level {
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