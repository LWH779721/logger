#ifndef __MLOG_H__
#define __MLOG_H__

#ifdef __cplusplus
extern "C"{
#endif

#include "logger_compile_conf.h"
#include "output/output_file.h"

#define logger(LEVEL, sparam, arg...)\
do{\
	mlog_##LEVEL(sparam, ##arg);\
} while(0);

#ifdef LOGGER_COMPILE_LEVEL
	#if LOGGER_COMPILE_LEVEL >= ERR
		#define mlog_err(sparam,arg...) \
			do {\
				printf("[%s %s:%d %s] err:"sparam"\n", mlog_time(), __FILE__, __LINE__, __FUNCTION__, ##arg);\
			}while(0);
	#else
		#define mlog_err(sparam,arg...)	
	#endif
	
	#if LOGGER_COMPILE_LEVEL >= WARM
		#define mlog_warm(sparam,arg...) \
			do {\
				printf("[%s %s:%d %s] warm:"sparam"\n", mlog_time(), __FILE__, __LINE__, __FUNCTION__, ##arg);\
			}while(0);
	#else
		#define mlog_warm(sparam,arg...)	
	#endif
	
	#if LOGGER_COMPILE_LEVEL >= DEBUG
		#define mlog_debug(sparam,arg...) \
			do {\
				printf("[%s %s:%d %s] debug:"sparam"\n", mlog_time(), __FILE__, __LINE__, __FUNCTION__, ##arg);\
			}while(0);
	#else
		#define mlog_debug(sparam,arg...)	
	#endif
	
	#if LOGGER_COMPILE_LEVEL >= info
		#define mlog_info(sparam,arg...) \
			do {\
				printf("[%s %s:%d %s] info:"sparam"\n", mlog_time(), __FILE__, __LINE__, __FUNCTION__, ##arg);\
			}while(0);
	#else
		#define mlog_info(sparam,arg...)	
	#endif
#endif

extern long mlog_set_logfile(char *file);

#ifdef __cplusplus
}
#endif
#endif